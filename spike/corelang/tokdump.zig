// Differential tokenizer (Zig port) for the core-language spike.
// Mirrors spike/corelang/tokdump.cpp byte-for-byte on stdout:
// one `LINE:COL KIND TEXT` line per token, TEXT escaped.
const std = @import("std");

const Tokenizer = struct {
    src: []const u8,
    file: []const u8,
    out: *std.ArrayList(u8),
    alloc: std.mem.Allocator,
    i: usize = 0,
    line: usize = 1,
    col: usize = 1,

    fn fail(self: *Tokenizer, ln: usize, cl: usize, msg: []const u8) noreturn {
        const err = std.io.getStdErr().writer();
        err.print("{s}:{d}:{d}: error: {s}\n", .{ self.file, ln, cl, msg }) catch {};
        std.process.exit(1);
    }

    fn failChar(self: *Tokenizer, ln: usize, cl: usize, c: u8) noreturn {
        const err = std.io.getStdErr().writer();
        err.print("{s}:{d}:{d}: error: unexpected character '{c}'\n", .{ self.file, ln, cl, c }) catch {};
        std.process.exit(1);
    }

    fn escapeVal(self: *Tokenizer, c: u8, ecol: usize) u8 {
        const v: ?u8 = switch (c) {
            'n' => '\n',
            't' => '\t',
            'r' => '\r',
            '0' => 0,
            '\\' => '\\',
            '\'' => '\'',
            '"' => '"',
            'a' => 7,
            'b' => 8,
            else => null,
        };
        return v orelse self.fail(self.line, ecol, "bad escape in literal");
    }

    fn isKeyword(word: []const u8) bool {
        const kws = [_][]const u8{
            "int", "char",  "short", "void",     "if",    "else",
            "switch", "case", "default",  "while",    "for",
            "break", "continue", "return",
        };
        for (kws) |k| {
            if (std.mem.eql(u8, word, k)) return true;
        }
        return false;
    }

    fn isTwoChar(a: u8, b: u8) bool {
        const pairs = [_][2]u8{
            .{ '=', '=' }, .{ '!', '=' }, .{ '<', '=' }, .{ '>', '=' },
            .{ '+', '+' }, .{ '-', '-' }, .{ '&', '&' }, .{ '|', '|' },
            .{ '+', '=' }, .{ '-', '=' }, .{ '*', '=' }, .{ '/', '=' },
            .{ '%', '=' }, .{ '<', '<' }, .{ '>', '>' }, .{ '-', '>' },
        };
        for (pairs) |p| {
            if (a == p[0] and b == p[1]) return true;
        }
        return false;
    }

    fn isOneChar(c: u8) bool {
        return switch (c) {
            '(', ')', '{', '}', '[', ']', ';', ',', ':', '?',
            '+', '-', '*', '/', '%', '<', '>', '!', '&', '|',
            '^', '~', '=', '.' => true,
            else => false,
        };
    }

    fn isDigit(c: u8) bool {
        return c >= '0' and c <= '9';
    }

    fn isAlpha(c: u8) bool {
        return (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or c == '_';
    }

    fn isAlnum(c: u8) bool {
        return isAlpha(c) or isDigit(c);
    }

    fn appendEscaped(self: *Tokenizer, text: []const u8) !void {
        for (text) |b| {
            switch (b) {
                '\\' => try self.out.appendSlice("\\\\"),
                '\n' => try self.out.appendSlice("\\n"),
                '\t' => try self.out.appendSlice("\\t"),
                '\r' => try self.out.appendSlice("\\r"),
                0 => try self.out.appendSlice("\\0"),
                else => try self.out.append(b),
            }
        }
    }

    fn emit(self: *Tokenizer, kind: []const u8, text: []const u8) !void {
        try self.out.writer().print("{d}:{d} {s}", .{ self.line, self.col, kind });
        if (!std.mem.eql(u8, kind, "end")) {
            try self.out.append(' ');
            try self.appendEscaped(text);
        }
        try self.out.append('\n');
    }

    fn run(self: *Tokenizer) !void {
        const n = self.src.len;
        while (self.i < n) {
            const c = self.src[self.i];
            if (c == ' ' or c == '\t' or c == '\r') {
                self.i += 1;
                self.col += 1;
            } else if (c == '\n') {
                self.i += 1;
                self.line += 1;
                self.col = 1;
            } else if (c == '/' and self.i + 1 < n and self.src[self.i + 1] == '/') {
                while (self.i < n and self.src[self.i] != '\n') {
                    self.i += 1;
                }
            } else if (c == '/' and self.i + 1 < n and self.src[self.i + 1] == '*') {
                self.i += 2;
                self.col += 2;
                var closed = false;
                while (self.i < n) {
                    if (self.src[self.i] == '*' and self.i + 1 < n and self.src[self.i + 1] == '/') {
                        self.i += 2;
                        self.col += 2;
                        closed = true;
                        break;
                    }
                    if (self.src[self.i] == '\n') {
                        self.line += 1;
                        self.col = 1;
                    } else {
                        self.col += 1;
                    }
                    self.i += 1;
                }
                if (!closed) {
                    self.fail(self.line, self.col, "unterminated block comment");
                }
            } else if (c == '#') {
                while (self.i < n and self.src[self.i] != '\n') {
                    self.i += 1;
                }
            } else if (isDigit(c)) {
                const j0 = self.i;
                while (self.i < n and isDigit(self.src[self.i])) {
                    self.i += 1;
                }
                try self.emit("int", self.src[j0..self.i]);
                self.col += self.i - j0;
            } else if (isAlpha(c)) {
                const j0 = self.i;
                while (self.i < n and isAlnum(self.src[self.i])) {
                    self.i += 1;
                }
                const word = self.src[j0..self.i];
                const kind: []const u8 = if (isKeyword(word)) "kw" else "ident";
                try self.emit(kind, word);
                self.col += self.i - j0;
            } else if (c == '\'') {
                var j = self.i + 1;
                if (j < n and self.src[j] == '\\') {
                    if (j + 1 >= n) {
                        self.fail(self.line, self.col, "bad character literal");
                    }
                    _ = self.escapeVal(self.src[j + 1], self.col + (j - self.i));
                    j += 2;
                } else if (j < n and self.src[j] != '\'' and self.src[j] != '\n') {
                    j += 1;
                } else {
                    self.fail(self.line, self.col, "bad character literal");
                }
                if (j >= n or self.src[j] != '\'') {
                    self.fail(self.line, self.col, "unterminated character literal");
                }
                j += 1;
                try self.emit("char", self.src[self.i..j]);
                self.col += j - self.i;
                self.i = j;
            } else if (c == '"') {
                var parts = std.ArrayList(u8).init(self.alloc);
                defer parts.deinit();
                var j = self.i + 1;
                while (true) {
                    if (j >= n or self.src[j] == '\n') {
                        self.fail(self.line, self.col, "unterminated string literal");
                    }
                    if (self.src[j] == '"') break;
                    if (self.src[j] == '\\') {
                        if (j + 1 >= n) {
                            self.fail(self.line, self.col, "bad escape in string literal");
                        }
                        const v = self.escapeVal(self.src[j + 1], self.col + (j - self.i));
                        try parts.append(v);
                        j += 2;
                    } else {
                        try parts.append(self.src[j]);
                        j += 1;
                    }
                }
                j += 1;
                try self.emit("string", parts.items);
                self.col += j - self.i;
                self.i = j;
            } else if (self.i + 1 < n and isTwoChar(self.src[self.i], self.src[self.i + 1])) {
                try self.emit("punct", self.src[self.i .. self.i + 2]);
                self.i += 2;
                self.col += 2;
            } else if (isOneChar(c)) {
                try self.emit("punct", self.src[self.i .. self.i + 1]);
                self.i += 1;
                self.col += 1;
            } else {
                self.failChar(self.line, self.col, c);
            }
        }
        try self.emit("end", "");
    }
};

pub fn main() !void {
    const alloc = std.heap.page_allocator;
    const args = try std.process.argsAlloc(alloc);
    defer std.process.argsFree(alloc, args);
    if (args.len != 2) {
        const err = std.io.getStdErr().writer();
        try err.print("usage: tokdump FILE\n", .{});
        std.process.exit(2);
    }
    const file: []const u8 = args[1];
    const src = std.fs.cwd().readFileAlloc(alloc, file, 1 << 20) catch {
        const err = std.io.getStdErr().writer();
        err.print("{s}: cannot open file\n", .{file}) catch {};
        std.process.exit(2);
    };
    defer alloc.free(src);
    var out = std.ArrayList(u8).init(alloc);
    defer out.deinit();
    var tz = Tokenizer{
        .src = src,
        .file = file,
        .out = &out,
        .alloc = alloc,
    };
    try tz.run();
    const stdout = std.io.getStdOut().writer();
    try stdout.writeAll(out.items);
}
