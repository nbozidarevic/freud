
// Generated from src/grammar/SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SimpleCParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SimpleCParser.
 */
class  SimpleCListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(SimpleCParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(SimpleCParser::ProgramContext *ctx) = 0;


};

