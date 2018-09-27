#include "BrainfuckCompiler.h"

using namespace antlr4;

BrainfuckCompiler::BrainfuckCompiler(
  istream& input,
  ostream& output
):input(input), output(output) {
  pointer = 0;
}

void BrainfuckCompiler::run() {
  ANTLRInputStream antlrInput(input);
  SimpleCLexer lexer(&antlrInput);
  CommonTokenStream tokens(&lexer);
  SimpleCParser parser(&tokens);
  SimpleCParser::CompilationUnitContext* tree = parser.compilationUnit();

  output << endl;
  visitCompilationUnit(tree);
  output << endl;
  output << endl << tree->toStringTree(&parser) << endl;
}

void BrainfuckCompiler::copyValue(int source, int destination) {
  int helperPointer = memory.getTemporaryCell();
  movePointer(source);
  output << "[-";
  movePointer(destination);
  output << "+";
  movePointer(helperPointer);
  output << "+";
  movePointer(source);
  output << "]";
  movePointer(helperPointer);
  output << "[-";
  movePointer(source);
  output << "+";
  movePointer(helperPointer);
  output << "]";
}

int BrainfuckCompiler::duplicateValue(int source) {
  int destination = memory.getTemporaryCell();
  copyValue(source, destination);
  return destination;
}

void BrainfuckCompiler::movePointer(int destination) {
  if (pointer == destination) {
    return;
  }
  char c = '>';
  if (pointer > destination) {
    c = '<';
  }
  for (int i = 0; i < abs(pointer - destination); ++i) {
    cout << c;
  }
  pointer = destination;
}

int BrainfuckCompiler::getPointerForConstValue(char value) {
  int pointer = memory.getTemporaryCell();
  movePointer(pointer);
  cout << "[-]";
  for (char i = 0; i < value; ++i) {
    cout << "+";
  }
  return pointer;
}

int BrainfuckCompiler::addValues(int a, int b) {
  int aCopy = duplicateValue(a);
  int bCopy = duplicateValue(b);
  int result = memory.getTemporaryCell();
  movePointer(aCopy);
  output << "[-";
  movePointer(result);
  output << "+";
  movePointer(aCopy);
  output << "]";
  movePointer(bCopy);
  output << "[-";
  movePointer(result);
  output << "+";
  movePointer(bCopy);
  output << "]";
  return result;
}
int BrainfuckCompiler::subtractValues(int a, int b) {
  int aCopy = duplicateValue(a);
  int bCopy = duplicateValue(b);
  int result = memory.getTemporaryCell();
  movePointer(aCopy);
  output << "[-";
  movePointer(result);
  output << "+";
  movePointer(aCopy);
  output << "]";
  movePointer(bCopy);
  output << "[-";
  movePointer(result);
  output << "-";
  movePointer(bCopy);
  output << "]";
  return result;
}

int BrainfuckCompiler::multiplyValues(int a, int b) {
  int aCopy = duplicateValue(a);
  int result = memory.getTemporaryCell();
  movePointer(aCopy);
  output << "[-";
  result = addValues(b, result);
  movePointer(aCopy);
  output << "]";
  return result;
}

antlrcpp::Any BrainfuckCompiler::visitAdditiveExpression(SimpleCParser::AdditiveExpressionContext *ctx) {
  if (ctx->children.size() == 1) {
    SimpleCParser::MultiplicativeExpressionContext *multiplicativeExpression = dynamic_cast<SimpleCParser::MultiplicativeExpressionContext*>(ctx->children[0]);
    if (multiplicativeExpression) {
      return visitMultiplicativeExpression(multiplicativeExpression);
    }
  } else if (ctx->children.size() == 3) {
    SimpleCParser::AdditiveExpressionContext *additiveExpression = dynamic_cast<SimpleCParser::AdditiveExpressionContext*>(ctx->children[0]);
    SimpleCParser::MultiplicativeExpressionContext *multiplicativeExpression = dynamic_cast<SimpleCParser::MultiplicativeExpressionContext*>(ctx->children[2]);
    if (additiveExpression && multiplicativeExpression) {
      int firstOperandPointer = visitAdditiveExpression(additiveExpression);
      int secondOperandPointer = visitMultiplicativeExpression(multiplicativeExpression);
      if (ctx->children[1]->getText() == "+") {
        return addValues(firstOperandPointer, secondOperandPointer);
      } else if (ctx->children[1]->getText() == "-") {
        return subtractValues(firstOperandPointer, secondOperandPointer);
      }
    }
  }
  throw "Unsupported additive expression";
}

antlrcpp::Any BrainfuckCompiler::visitAssignmentExpression(SimpleCParser::AssignmentExpressionContext *ctx) {
  if (ctx->children.size() == 1) {
    SimpleCParser::LogicalOrExpressionContext *logicalOrExpression = dynamic_cast<SimpleCParser::LogicalOrExpressionContext*>(ctx->children[0]);
    if (logicalOrExpression) {
      return visitLogicalOrExpression(logicalOrExpression);
    }
  }
  throw "Unsupported assignment expression";
}

antlrcpp::Any BrainfuckCompiler::visitDeclarator(SimpleCParser::DeclaratorContext *ctx) {
  return visitDirectDeclarator(ctx->directDeclarator());
}

antlrcpp::Any BrainfuckCompiler::visitDirectDeclarator(SimpleCParser::DirectDeclaratorContext *ctx) {
  if (ctx->Identifier()) {
    return memory.getVariableCell(ctx->Identifier()->getText());
  }
  throw "Unsupported direct declarator";
}

antlrcpp::Any BrainfuckCompiler::visitEqualityExpression(SimpleCParser::EqualityExpressionContext *ctx) {
  if (ctx->children.size() == 1) {
    SimpleCParser::RelationalExpressionContext *relationalExpression = dynamic_cast<SimpleCParser::RelationalExpressionContext*>(ctx->children[0]);
    if (relationalExpression) {
      return visitRelationalExpression(relationalExpression);
    }
  }
  throw "Unsupported equality expression";
}

antlrcpp::Any BrainfuckCompiler::visitInitializer(SimpleCParser::InitializerContext *ctx) {
  if (ctx->children.size() == 1) {
    SimpleCParser::AssignmentExpressionContext *assignmentExpression = dynamic_cast<SimpleCParser::AssignmentExpressionContext*>(ctx->children[0]);
    if (assignmentExpression) {
      return visitAssignmentExpression(assignmentExpression);
    }
  }
  throw "Unsupported initializer";
}

antlrcpp::Any BrainfuckCompiler::visitInitDeclarator(SimpleCParser::InitDeclaratorContext *ctx) {
  if (ctx->children.size() == 3) {
    SimpleCParser::DeclaratorContext *declarator = dynamic_cast<SimpleCParser::DeclaratorContext*>(ctx->children[0]);
    SimpleCParser::InitializerContext *initializer = dynamic_cast<SimpleCParser::InitializerContext*>(ctx->children[2]);
    if (declarator && ctx->children[1]->getText() == "=" && initializer) {
      int dest = visitDeclarator(declarator);
      int src = visitInitializer(initializer);
      copyValue(src, dest);
      return src;
    }
  }
  throw "Unsupported init declarator";
}

antlrcpp::Any BrainfuckCompiler::visitLogicalAndExpression(SimpleCParser::LogicalAndExpressionContext *ctx) {
  if (ctx->children.size() == 1) {
    SimpleCParser::EqualityExpressionContext *equalityExpression = dynamic_cast<SimpleCParser::EqualityExpressionContext*>(ctx->children[0]);
    if (equalityExpression) {
      return visitEqualityExpression(equalityExpression);
    }
  }
  throw "Unsupported logical AND expression";
}

antlrcpp::Any BrainfuckCompiler::visitLogicalOrExpression(SimpleCParser::LogicalOrExpressionContext *ctx) {
  if (ctx->children.size() == 1) {
    SimpleCParser::LogicalAndExpressionContext *logicalAndExpression = dynamic_cast<SimpleCParser::LogicalAndExpressionContext*>(ctx->children[0]);
    if (logicalAndExpression) {
      return visitLogicalAndExpression(logicalAndExpression);
    }
  }
  throw "Unsupported logical OR expression";
}

antlrcpp::Any BrainfuckCompiler::visitMultiplicativeExpression(SimpleCParser::MultiplicativeExpressionContext *ctx) {
  if (ctx->children.size() == 1) {
    SimpleCParser::SimpleExpressionContext *simpleExpression = dynamic_cast<SimpleCParser::SimpleExpressionContext*>(ctx->children[0]);
    if (simpleExpression) {
      return visitSimpleExpression(simpleExpression);
    }
  } else if (ctx->children.size() == 3) {
    SimpleCParser::MultiplicativeExpressionContext *multiplicativeExpression = dynamic_cast<SimpleCParser::MultiplicativeExpressionContext*>(ctx->children[0]);
    SimpleCParser::SimpleExpressionContext *simpleExpression = dynamic_cast<SimpleCParser::SimpleExpressionContext*>(ctx->children[2]);
    if (multiplicativeExpression && simpleExpression) {
      int firstOperandPointer = visitMultiplicativeExpression(multiplicativeExpression);
      int secondOperandPointer = visitSimpleExpression(simpleExpression);
      if (ctx->children[1]->getText() == "*") {
        return multiplyValues(firstOperandPointer, secondOperandPointer);
      }
    }
  }
  throw "Unsupported multiplicative expression";
}

antlrcpp::Any BrainfuckCompiler::visitPostfixExpression(SimpleCParser::PostfixExpressionContext *ctx) {
  if (ctx->primaryExpression()) {
    return visitPrimaryExpression(ctx->primaryExpression());
  }
  throw "Unsupported postfix expression";
}

antlrcpp::Any BrainfuckCompiler::visitPrimaryExpression(SimpleCParser::PrimaryExpressionContext *ctx) {
  if (ctx->Constant()) {
    // If it is a constant, store it in a temporary memory cell and return its address
    string value = ctx->Constant()->getText();
    if (value[0] == '\'') {
      return getPointerForConstValue(value[1]);
    } else {
      return getPointerForConstValue(atoi(value.c_str()));
    }
  } else if (ctx->Identifier()) {
    // If it is an identifier, return its mmoery address
    string name = ctx->Identifier()->getText();
    return memory.getVariableCell(name);
  }
  throw "Unsupported primary expression";
}

antlrcpp::Any BrainfuckCompiler::visitRelationalExpression(SimpleCParser::RelationalExpressionContext *ctx) {
  if (ctx->children.size() == 1) {
    SimpleCParser::AdditiveExpressionContext *additiveExpression = dynamic_cast<SimpleCParser::AdditiveExpressionContext*>(ctx->children[0]);
    if (additiveExpression) {
      return visitAdditiveExpression(additiveExpression);
    }
  }
  throw "Unsupported relational expression";
}

antlrcpp::Any BrainfuckCompiler::visitSimpleExpression(SimpleCParser::SimpleExpressionContext *ctx) {
  if (ctx->unaryExpression()) {
    return visitUnaryExpression(ctx->unaryExpression());
  } else if (ctx->DigitSequence()) {
    return getPointerForConstValue(atoi(ctx->DigitSequence()->getText().c_str()));
  }
  throw "Unsupported simple expression";
}

antlrcpp::Any BrainfuckCompiler::visitUnaryExpression(SimpleCParser::UnaryExpressionContext *ctx) {
  if (ctx->postfixExpression()) {
    return visitPostfixExpression(ctx->postfixExpression());
  }
  throw "Unsupported unary expression";
}