
// Generated from src/grammar/SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  SimpleCLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, Break = 3, Case = 4, Char = 5, Continue = 6, Default = 7, 
    Do = 8, Else = 9, For = 10, Goto = 11, If = 12, Int = 13, Long = 14, 
    Return = 15, Short = 16, Switch = 17, Void = 18, While = 19, LeftParen = 20, 
    RightParen = 21, LeftBracket = 22, RightBracket = 23, LeftBrace = 24, 
    RightBrace = 25, Less = 26, LessEqual = 27, Greater = 28, GreaterEqual = 29, 
    Plus = 30, PlusPlus = 31, Minus = 32, MinusMinus = 33, Star = 34, Div = 35, 
    Mod = 36, AndAnd = 37, OrOr = 38, Not = 39, Question = 40, Colon = 41, 
    Semi = 42, Comma = 43, Assign = 44, StarAssign = 45, DivAssign = 46, 
    ModAssign = 47, PlusAssign = 48, MinusAssign = 49, Equal = 50, NotEqual = 51, 
    Identifier = 52, Constant = 53, DigitSequence = 54, StringLiteral = 55, 
    Whitespace = 56, Newline = 57, BlockComment = 58, LineComment = 59
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

