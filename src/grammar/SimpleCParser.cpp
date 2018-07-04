
// Generated from src/grammar/SimpleC.g4 by ANTLR 4.7.1


#include "SimpleCListener.h"
#include "SimpleCVisitor.h"

#include "SimpleCParser.h"


using namespace antlrcpp;
using namespace antlr4;

SimpleCParser::SimpleCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SimpleCParser::~SimpleCParser() {
  delete _interpreter;
}

std::string SimpleCParser::getGrammarFileName() const {
  return "SimpleC.g4";
}

const std::vector<std::string>& SimpleCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SimpleCParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

SimpleCParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SimpleCParser::ProgramContext::Print() {
  return getTokens(SimpleCParser::Print);
}

tree::TerminalNode* SimpleCParser::ProgramContext::Print(size_t i) {
  return getToken(SimpleCParser::Print, i);
}


size_t SimpleCParser::ProgramContext::getRuleIndex() const {
  return SimpleCParser::RuleProgram;
}

void SimpleCParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void SimpleCParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any SimpleCParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::ProgramContext* SimpleCParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, SimpleCParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(3); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2);
      match(SimpleCParser::Print);
      setState(5); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SimpleCParser::Print);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> SimpleCParser::_decisionToDFA;
atn::PredictionContextCache SimpleCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SimpleCParser::_atn;
std::vector<uint16_t> SimpleCParser::_serializedATN;

std::vector<std::string> SimpleCParser::_ruleNames = {
  "program"
};

std::vector<std::string> SimpleCParser::_literalNames = {
};

std::vector<std::string> SimpleCParser::_symbolicNames = {
  "", "Print", "String", "Char", "Whitespace", "Newline"
};

dfa::Vocabulary SimpleCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SimpleCParser::_tokenNames;

SimpleCParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x7, 0xa, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x6, 0x2, 0x6, 0xa, 0x2, 
    0xd, 0x2, 0xe, 0x2, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3, 0x2, 0x2, 0x2, 0x2, 
    0x9, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4, 0x6, 0x7, 0x3, 0x2, 0x2, 0x5, 
    0x4, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7, 0x3, 0x2, 0x2, 0x2, 0x7, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x7, 0x8, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x3, 0x7, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SimpleCParser::Initializer SimpleCParser::_init;
