
// Generated from src/grammar/SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  SimpleCLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, Break = 2, Case = 3, Char = 4, Continue = 5, Default = 6, 
    Do = 7, Else = 8, For = 9, Goto = 10, If = 11, Int = 12, Long = 13, 
    Return = 14, Short = 15, Switch = 16, Void = 17, While = 18, LeftParen = 19, 
    RightParen = 20, LeftBracket = 21, RightBracket = 22, LeftBrace = 23, 
    RightBrace = 24, Less = 25, LessEqual = 26, Greater = 27, GreaterEqual = 28, 
    Plus = 29, PlusPlus = 30, Minus = 31, MinusMinus = 32, Star = 33, Div = 34, 
    Mod = 35, AndAnd = 36, OrOr = 37, Not = 38, Question = 39, Colon = 40, 
    Semi = 41, Comma = 42, Assign = 43, StarAssign = 44, DivAssign = 45, 
    ModAssign = 46, PlusAssign = 47, MinusAssign = 48, Equal = 49, NotEqual = 50, 
    Identifier = 51, Constant = 52, DigitSequence = 53, StringLiteral = 54, 
    Whitespace = 55, Newline = 56, BlockComment = 57, LineComment = 58
  };

  SimpleCLexer(antlr4::CharStream *input);
  ~SimpleCLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

