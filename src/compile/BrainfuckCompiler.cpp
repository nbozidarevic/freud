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
  // output << endl << tree->toStringTree(&parser) << endl;
  // output << endl << memory.getVariableCell("a") << endl;
}

int BrainfuckCompiler::copyValue(int source, int destination) {
  if (source == destination) {
    return destination;
  }
  int helperPointer = memory.getTemporaryCell();
  movePointer(helperPointer);
  output << "[-]";
  movePointer(destination);
  output << "[-]";
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
  return destination;
}

int BrainfuckCompiler::moveValue(int source, int destination) {
  if (source == destination) {
    return destination;
  }
  movePointer(destination);
  output << "[-]";
  movePointer(source);
  output << "[-";
  movePointer(destination);
  output << "+";
  movePointer(source);
  output << "]";
  return destination;
}

int BrainfuckCompiler::duplicateValue(int source) {
  int destination = memory.getTemporaryCell();
  copyValue(source, destination);
  return destination;
}

int BrainfuckCompiler::setValue(int destination, int value) {
  movePointer(destination);
  output << "[-]";
  for (int i = 0; i < value; ++i) {
    cout << "+";
  }
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
  return setValue(pointer, value);
}

int BrainfuckCompiler::addValues(int a, int b) {
  int aCopy = duplicateValue(a);
  int bCopy = duplicateValue(b);
  int result = memory.getTemporaryCell();
  movePointer(result);
  output << "[-]";
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
  movePointer(result);
  output << "[-]";
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
  int result = getPointerForConstValue(0);
  movePointer(aCopy);
  output << "[-";
  int newResult = addValues(b, result);
  moveValue(newResult, result);
  movePointer(aCopy);
  output << "]";
  return result;
}

int BrainfuckCompiler::divideValues(int a, int b) {
  int aCopy = duplicateValue(a);
  int result = getPointerForConstValue(0);
  performWhile(
    [&]() -> int {
      return this->greaterThanOrEqual(aCopy, b);
    },
    [&]() -> void {
      this->movePointer(result);
      this->output << "+";
      this->moveValue(this->subtractValues(aCopy, b), aCopy);
    }
  );
  return result;
}

int BrainfuckCompiler::modValues(int a, int b) {
  int result = getPointerForConstValue(0);
  moveValue(
    subtractValues(
      a,
      multiplyValues(
        divideValues(a, b),
        b
      )
    ),
    result
  );
  return result;
}

int BrainfuckCompiler::negate(int a) {
  int result = memory.getTemporaryCell();
  performIfElse(
    a,
    [&]() -> void {
      this->setValue(result, 0);
    },
    [&]() -> void {
      this->setValue(result, 1);
    }
  );
  return result;
}

int BrainfuckCompiler::isEqual(int a, int b) {
  int aCopy = duplicateValue(a);
  int bCopy = duplicateValue(b);
  int result = getPointerForConstValue(0);
  movePointer(aCopy);
  output << "[-";
  movePointer(bCopy);
  output << "-";
  movePointer(aCopy);
  output << "]";
  performIfElse(
    negate(aCopy),
    [&]() -> void {
      this->performIfElse(
        this->negate(bCopy),
        [&]() -> void {
          setValue(result, 1);
        },
        []() -> void {}
      );
    },
    []() -> void {}
  );
  return result;
}

int BrainfuckCompiler::logicalAnd(int a, int b) {
  int result = getPointerForConstValue(0);
  performIfElse(
    a,
    [&]() -> void {
      this->performIfElse(
        b,
        [&]() -> void {
          setValue(result, 1);
        },
        []() -> void {}
      );
    },
    []() -> void {}
  );
  return result;
}

int BrainfuckCompiler::logicalOr(int a, int b) {
  int result = getPointerForConstValue(0);
  this->performIfElse(
    a,
    [&]() -> void {
      setValue(result, 1);
    },
    []() -> void {}
  );
  this->performIfElse(
    b,
    [&]() -> void {
      setValue(result, 1);
    },
    []() -> void {}
  );
  return result;
}

int BrainfuckCompiler::lessThan(int a, int b) {
  int aCopy = duplicateValue(a);
  int bCopy = duplicateValue(b);
  int result = memory.getTemporaryCell();
  movePointer(result);
  output << "[-]";
  performWhile(
    [&]() -> int {
      return logicalAnd(aCopy, bCopy);
    },
    [&]() -> void {
      this->movePointer(aCopy);
      output << "-";
      this->movePointer(bCopy);
      output << "-";
    }
  );
  performIfElse(
    logicalAnd(negate(aCopy), bCopy),
    [&]() -> void {
      this->setValue(result, 1);
    },
    []() -> void {}
  );
  return result;
}
int BrainfuckCompiler::lessThanOrEqual(int a, int b) {
  return logicalOr(
    lessThan(a, b),
    isEqual(a, b)
  );
}
int BrainfuckCompiler::greaterThan(int a, int b) {
  return negate(lessThanOrEqual(a, b));
}
int BrainfuckCompiler::greaterThanOrEqual(int a, int b) {
  return negate(lessThan(a, b));
}

void BrainfuckCompiler::performIfElse(int expression, function<void ()> ifFn, function<void ()> elseFn) {
  int ifValue = duplicateValue(expression);
  int elseValue = getPointerForConstValue(1);
  movePointer(ifValue);
  output << "[";
  setValue(ifValue, 0);
  setValue(elseValue, 0);
  ifFn();
  movePointer(ifValue);
  output << "]";
  movePointer(elseValue);
  output << "[";
  setValue(elseValue, 0);
  elseFn();
  movePointer(elseValue);
  output << "]";
}

void BrainfuckCompiler::performWhile(function<int ()> expressionFn, function<void ()> loopFn) {
  int expression = expressionFn();
  movePointer(expression);
  output << "[";
  movePointer(expression);
  loopFn();
  int newExpression = expressionFn();
  moveValue(newExpression, expression);
  movePointer(expression);
  output << "]";
}

void BrainfuckCompiler::performFor(
  function<void ()> initFn,
  function<int ()> expressionFn,
  function<void ()> updateFn,
  function<void ()> loopFn
) {
  initFn();
  performWhile(
    expressionFn,
    [&]() -> void {
      loopFn();
      updateFn();
    }
  ); 
}

void BrainfuckCompiler::printAsChar(int a) {
  movePointer(a);
  output << ".";
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
  } else if (ctx->children.size() == 3) {
    if (ctx->assignmentOperator()->getText() == "=") {
      return copyValue(
        ctx->assignmentExpression()->accept(this),
        ctx->unaryExpression()->accept(this)
      );
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
  SimpleCParser::DirectDeclaratorContext *directDeclarator = dynamic_cast<SimpleCParser::DirectDeclaratorContext*>(ctx->children[0]);
  if (directDeclarator) {
    if (ctx->children[1]->getText() == "(" && ctx->children[2]->getText() == ")") {
      if (directDeclarator->getText() == "main") {
        return true;
      }
    }
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
  if (ctx->children[1]->getText() == "==") {
    return isEqual(
      ctx->equalityExpression()->accept(this),
      ctx->relationalExpression()->accept(this)
    );
  }
  if (ctx->children[1]->getText() == "!=") {
    return negate(isEqual(
      ctx->equalityExpression()->accept(this),
      ctx->relationalExpression()->accept(this)
    ));
  }
  throw "Unsupported equality expression";
}

antlrcpp::Any BrainfuckCompiler::visitFunctionDefinition(SimpleCParser::FunctionDefinitionContext *ctx) {
  if (ctx->declarator()->directDeclarator()->directDeclarator()->getText() == "main") {
    return ctx->compoundStatement()->accept(this);
  }
  throw "Unsupported function definition";
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

antlrcpp::Any BrainfuckCompiler::visitIterationStatement(SimpleCParser::IterationStatementContext *ctx) {
  if (ctx->While()) {
    performWhile(
      [&]() -> int {
        return ctx->expression()->accept(this);
      },
      [&]() -> void {
        ctx->statement()->accept(this);
      }
    );
    return NULL;
  }
  if (ctx->For()) {
    SimpleCParser::ForConditionContext *forCondition = dynamic_cast<SimpleCParser::ForConditionContext*>(ctx->forCondition());
    function<void ()> initFn = [&]() -> void {};
    function<int ()> expressionFn = [&]() -> int {
      return 0;
    };
    function<void ()> updateFn = [&]() -> void {};

    int firstPos = 0;
    int secondPos = 1;
    int thirdPos = 2;
    if (forCondition->children[firstPos]->getText() != ";") {
      initFn = [&]() -> void {
        forCondition->children[firstPos]->accept(this);
      };
      secondPos = firstPos + 2;
      thirdPos = firstPos + 3;
    }

    if (forCondition->children[secondPos]->getText() != ";") {
      expressionFn = [&]() -> int {
        return forCondition->children[secondPos]->accept(this);
      };
      thirdPos = secondPos + 2;
    }

    if (thirdPos < forCondition->children.size()) {
      updateFn = [&]() -> void {
        forCondition->children[thirdPos]->accept(this);
      };
    }

    performFor(
      initFn,
      expressionFn,
      updateFn,
      [&]() -> void {
        ctx->statement()->accept(this);
      }
    );
    return NULL;
  }
  output << endl << ctx->getText() << endl;
  throw "Unsupported iteration statement";
}

antlrcpp::Any BrainfuckCompiler::visitLogicalAndExpression(SimpleCParser::LogicalAndExpressionContext *ctx) {
  if (ctx->children.size() == 1) {
    SimpleCParser::EqualityExpressionContext *equalityExpression = dynamic_cast<SimpleCParser::EqualityExpressionContext*>(ctx->children[0]);
    if (equalityExpression) {
      return visitEqualityExpression(equalityExpression);
    }
  }
  return logicalAnd(
    ctx->logicalAndExpression()->accept(this),
    ctx->equalityExpression()->accept(this)
  );
  throw "Unsupported logical AND expression";
}

antlrcpp::Any BrainfuckCompiler::visitLogicalOrExpression(SimpleCParser::LogicalOrExpressionContext *ctx) {
  if (ctx->children.size() == 1) {
    SimpleCParser::LogicalAndExpressionContext *logicalAndExpression = dynamic_cast<SimpleCParser::LogicalAndExpressionContext*>(ctx->children[0]);
    if (logicalAndExpression) {
      return visitLogicalAndExpression(logicalAndExpression);
    }
  }
  return logicalOr(
    ctx->logicalOrExpression()->accept(this),
    ctx->logicalAndExpression()->accept(this)
  );
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
      if (ctx->children[1]->getText() == "/") {
        return divideValues(firstOperandPointer, secondOperandPointer);
      }
      if (ctx->children[1]->getText() == "%") {
        return modValues(firstOperandPointer, secondOperandPointer);
      }
    }
  }
  throw "Unsupported multiplicative expression";
}

antlrcpp::Any BrainfuckCompiler::visitPostfixExpression(SimpleCParser::PostfixExpressionContext *ctx) {
  if (ctx->primaryExpression()) {
    return visitPrimaryExpression(ctx->primaryExpression());
  }
  if (ctx->children[1]->getText() == "(") {
    if (ctx->postfixExpression()->getText() == "printf") {
      printAsChar(memory.getVariableCell("a"));
      // printAsChar(memory.getVariableCell("b"));
      return NULL;
      // vector<antlrcpp::Any> arguments;
      // if (ctx->argumentExpressionList()) {
      //   arguments = (vector<antlrcpp::Any>)(ctx->argumentExpressionList()->accept(this));
      // }
    }
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
  if (ctx->children[1]->getText() == "<") {
    return lessThan(
      ctx->relationalExpression()->accept(this),
      ctx->additiveExpression()->accept(this)
    );
  }
  if (ctx->children[1]->getText() == "<=") {
    return lessThanOrEqual(
      ctx->relationalExpression()->accept(this),
      ctx->additiveExpression()->accept(this)
    );
  }
  if (ctx->children[1]->getText() == ">") {
    return greaterThan(
      ctx->relationalExpression()->accept(this),
      ctx->additiveExpression()->accept(this)
    );
  }
  if (ctx->children[1]->getText() == ">=") {
    return greaterThanOrEqual(
      ctx->relationalExpression()->accept(this),
      ctx->additiveExpression()->accept(this)
    );
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

antlrcpp::Any BrainfuckCompiler::visitSelectionStatement(SimpleCParser::SelectionStatementContext *ctx) {
  if (ctx->children[0]->getText() == "if") {
    SimpleCParser::StatementContext *ifStatement = dynamic_cast<SimpleCParser::StatementContext*>(ctx->children[4]);
    SimpleCParser::StatementContext *elseStatement = NULL;
    if (ctx->children.size() == 7) {
      elseStatement = dynamic_cast<SimpleCParser::StatementContext*>(ctx->children[6]);
    }

    performIfElse(
      ctx->expression()->accept(this),
      [&]() -> void {
        ifStatement->accept(this);
      },
      [&]() -> void {
        if (elseStatement) {
          elseStatement->accept(this);
        } 
      }
    );
    return NULL;
  }
  throw "Unsupported selection statement";
}

antlrcpp::Any BrainfuckCompiler::visitUnaryExpression(SimpleCParser::UnaryExpressionContext *ctx) {
  if (ctx->postfixExpression()) {
    return visitPostfixExpression(ctx->postfixExpression());
  }
  if (ctx->children[0]->getText() == "!") {
    return negate(ctx->unaryExpression()->accept(this));
  }
  throw "Unsupported unary expression";
}