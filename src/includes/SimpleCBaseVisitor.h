
// Generated from src/grammar/SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SimpleCVisitor.h"


/**
 * This class provides an empty implementation of SimpleCVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SimpleCBaseVisitor : public SimpleCVisitor {
public:

  virtual antlrcpp::Any visitProgram(SimpleCParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }


};

