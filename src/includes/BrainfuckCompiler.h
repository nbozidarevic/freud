#ifndef __BRAINFUCK_COMPILER_H_INCLUDED__
#define __BRAINFUCK_COMPILER_H_INCLUDED__

#include <iostream>
#include "antlr4-runtime.h"
#include "BrainfuckMemory.h"
#include "SimpleCBaseVisitor.h"
#include "SimpleCLexer.h"
#include "SimpleCParser.h"

using namespace std;

class BrainfuckCompiler: public SimpleCBaseVisitor {
public:
  BrainfuckCompiler(istream& input, ostream& output);
  void run();
private:
  istream& input;
  ostream& output;
  BrainfuckMemory memory;
  int pointer;

  int copyValue(int source, int destination);
  int duplicateValue(int source);
  int getPointerForConstValue(char value);
  void movePointer(int destination);
  int setValue(int destination, int value);

  int addValues(int a, int b);
  int subtractValues(int a, int b);
  int multiplyValues(int a, int b);
  int negate(int a);
  int isEqual(int a, int b);
  int logicalAnd(int a, int b);
  int logicalOr(int a, int b);
  int lessThan(int a, int b);
  int lessThanOrEqual(int a, int b);
  int greaterThan(int a, int b);
  int greaterThanOrEqual(int a, int b);

  void performIfElse(int expression, function<void ()> ifFn, function<void ()> elseFn);
  void performWhile(function<int ()> expressionFn, function<void ()> loopFn);

  antlrcpp::Any visitAdditiveExpression(SimpleCParser::AdditiveExpressionContext *ctx);
  antlrcpp::Any visitAssignmentExpression(SimpleCParser::AssignmentExpressionContext *ctx);
  antlrcpp::Any visitDeclarator(SimpleCParser::DeclaratorContext *ctx);
  antlrcpp::Any visitDirectDeclarator(SimpleCParser::DirectDeclaratorContext *ctx);
  antlrcpp::Any visitEqualityExpression(SimpleCParser::EqualityExpressionContext *ctx);
  antlrcpp::Any visitFunctionDefinition(SimpleCParser::FunctionDefinitionContext *ctx);
  antlrcpp::Any visitInitializer(SimpleCParser::InitializerContext *ctx);
  antlrcpp::Any visitInitDeclarator(SimpleCParser::InitDeclaratorContext *ctx);
  antlrcpp::Any visitIterationStatement(SimpleCParser::IterationStatementContext *ctx);
  antlrcpp::Any visitLogicalAndExpression(SimpleCParser::LogicalAndExpressionContext *ctx);
  antlrcpp::Any visitLogicalOrExpression(SimpleCParser::LogicalOrExpressionContext *ctx);
  antlrcpp::Any visitMultiplicativeExpression(SimpleCParser::MultiplicativeExpressionContext *ctx);
  antlrcpp::Any visitPostfixExpression(SimpleCParser::PostfixExpressionContext *ctx);
  antlrcpp::Any visitPrimaryExpression(SimpleCParser::PrimaryExpressionContext *ctx);
  antlrcpp::Any visitRelationalExpression(SimpleCParser::RelationalExpressionContext *ctx);
  antlrcpp::Any visitSimpleExpression(SimpleCParser::SimpleExpressionContext *ctx);
  antlrcpp::Any visitSelectionStatement(SimpleCParser::SelectionStatementContext *ctx);
  antlrcpp::Any visitUnaryExpression(SimpleCParser::UnaryExpressionContext *ctx);
};

#endif
