
// Generated from src/grammar/SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SimpleCParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SimpleCParser.
 */
class  SimpleCVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SimpleCParser.
   */
    virtual antlrcpp::Any visitProgram(SimpleCParser::ProgramContext *context) = 0;


};

