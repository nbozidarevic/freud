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

  void copyValue(int source, int destination);
  int duplicateValue(int source);
  int getPointerForConstValue(char value);
  void movePointer(int destination);

  int addValues(int a, int b);
  int subtractValues(int a, int b);
  int multiplyValues(int a, int b);

  antlrcpp::Any visitAdditiveExpression(SimpleCParser::AdditiveExpressionContext *ctx);
  antlrcpp::Any visitAssignmentExpression(SimpleCParser::AssignmentExpressionContext *ctx);
  antlrcpp::Any visitDeclarator(SimpleCParser::DeclaratorContext *ctx);
  antlrcpp::Any visitDirectDeclarator(SimpleCParser::DirectDeclaratorContext *ctx);
  antlrcpp::Any visitEqualityExpression(SimpleCParser::EqualityExpressionContext *ctx);
  antlrcpp::Any visitInitializer(SimpleCParser::InitializerContext *ctx);
  antlrcpp::Any visitInitDeclarator(SimpleCParser::InitDeclaratorContext *ctx);
  antlrcpp::Any visitLogicalAndExpression(SimpleCParser::LogicalAndExpressionContext *ctx);
  antlrcpp::Any visitLogicalOrExpression(SimpleCParser::LogicalOrExpressionContext *ctx);
  antlrcpp::Any visitMultiplicativeExpression(SimpleCParser::MultiplicativeExpressionContext *ctx);
  antlrcpp::Any visitPostfixExpression(SimpleCParser::PostfixExpressionContext *ctx);
  antlrcpp::Any visitPrimaryExpression(SimpleCParser::PrimaryExpressionContext *ctx);
  antlrcpp::Any visitRelationalExpression(SimpleCParser::RelationalExpressionContext *ctx);
  antlrcpp::Any visitSimpleExpression(SimpleCParser::SimpleExpressionContext *ctx);
  antlrcpp::Any visitUnaryExpression(SimpleCParser::UnaryExpressionContext *ctx);
};

#endif
