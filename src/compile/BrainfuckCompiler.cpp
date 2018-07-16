#include "BrainfuckCompiler.h"

using namespace antlr4;

BrainfuckCompiler::BrainfuckCompiler(
  istream& input,
  ostream& output
):input(input), output(output) {}

void BrainfuckCompiler::run() {
  ANTLRInputStream antlrInput(input);
  SimpleCLexer lexer(&antlrInput);
  CommonTokenStream tokens(&lexer);
  SimpleCParser parser(&tokens);
  SimpleCParser::CompilationUnitContext* tree = parser.compilationUnit();

  output << tree->toStringTree(&parser) << endl;
}
