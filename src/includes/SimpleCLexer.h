
// Generated from src/grammar/SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  SimpleCLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, Break = 3, Case = 4, Char = 5, Const = 6, Continue = 7, 
    Default = 8, Do = 9, Double = 10, Else = 11, Extern = 12, Float = 13, 
    For = 14, Goto = 15, If = 16, Inline = 17, Int = 18, Long = 19, Register = 20, 
    Restrict = 21, Return = 22, Short = 23, Signed = 24, Sizeof = 25, Static = 26, 
    Struct = 27, Switch = 28, Typedef = 29, Union = 30, Unsigned = 31, Void = 32, 
    Volatile = 33, While = 34, Alignas = 35, Alignof = 36, Atomic = 37, 
    Bool = 38, Complex = 39, Generic = 40, Imaginary = 41, Noreturn = 42, 
    StaticAssert = 43, ThreadLocal = 44, LeftParen = 45, RightParen = 46, 
    LeftBracket = 47, RightBracket = 48, LeftBrace = 49, RightBrace = 50, 
    Less = 51, LessEqual = 52, Greater = 53, GreaterEqual = 54, LeftShift = 55, 
    RightShift = 56, Plus = 57, PlusPlus = 58, Minus = 59, MinusMinus = 60, 
    Star = 61, Div = 62, Mod = 63, And = 64, Or = 65, AndAnd = 66, OrOr = 67, 
    Caret = 68, Not = 69, Tilde = 70, Question = 71, Colon = 72, Semi = 73, 
    Comma = 74, Assign = 75, StarAssign = 76, DivAssign = 77, ModAssign = 78, 
    PlusAssign = 79, MinusAssign = 80, LeftShiftAssign = 81, RightShiftAssign = 82, 
    AndAssign = 83, XorAssign = 84, OrAssign = 85, Equal = 86, NotEqual = 87, 
    Arrow = 88, Dot = 89, Ellipsis = 90, Identifier = 91, Constant = 92, 
    DigitSequence = 93, StringLiteral = 94, Whitespace = 95, Newline = 96, 
    BlockComment = 97, LineComment = 98
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

