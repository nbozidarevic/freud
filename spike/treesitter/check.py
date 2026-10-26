#!/usr/bin/env python3
"""Tree-sitter spike: parse the C-subset corpus with tree-sitter-c.

Exits 1 if any tests/compile fixture fails to parse cleanly (any
ERROR or MISSING node). Inline invalid snippets are informational:
they show error-recovery behavior, not pass/fail.
"""
import glob
import sys


def load_parser():
    import tree_sitter
    import tree_sitter_c
    try:
        lang = tree_sitter.Language(tree_sitter_c.language())
    except Exception as e:
        raise SystemExit("cannot build Language: %r" % (e,))
    try:
        return tree_sitter.Parser(lang)
    except TypeError:
        p = tree_sitter.Parser()
        p.language = lang
        return p


def walk(node):
    yield node
    for c in node.children:
        for n in walk(c):
            yield n


def main():
    try:
        from importlib.metadata import version
        print("tree-sitter", version("tree-sitter"),
              "| tree-sitter-c", version("tree-sitter-c"))
    except Exception:
        pass
    parser = load_parser()
    failed = False
    files = sorted(glob.glob("tests/compile/*.c"))
    for path in files:
        with open(path, "rb") as f:
            tree = parser.parse(f.read())
        nodes = list(walk(tree.root_node))
        bad = sum(1 for n in nodes
                  if n.type == "ERROR" or n.is_missing)
        print(("OK    " if bad == 0 else "BROKEN"), path,
              "nodes=%d bad=%d" % (len(nodes), bad))
        if bad:
            failed = True
    print("--- inline invalid snippets (informational) ---")
    for i, src in enumerate(["int main( { return 0; }",
                             "int x = ;",
                             "while (1) { if (x) }"]):
        tree = parser.parse(src.encode())
        nodes = list(walk(tree.root_node))
        bad = sum(1 for n in nodes
                  if n.type == "ERROR" or n.is_missing)
        print("snippet%d bad=%d nodes=%d root=%s"
              % (i, bad, len(nodes), tree.root_node.type))
    print("fixtures=%d failed=%s" % (len(files), failed))
    return 1 if failed or not files else 0


if __name__ == "__main__":
    sys.exit(main())
