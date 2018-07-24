
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


//----------------- PrimaryExpressionContext ------------------------------------------------------------------

SimpleCParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::PrimaryExpressionContext::Identifier() {
  return getToken(SimpleCParser::Identifier, 0);
}

tree::TerminalNode* SimpleCParser::PrimaryExpressionContext::Constant() {
  return getToken(SimpleCParser::Constant, 0);
}

std::vector<tree::TerminalNode *> SimpleCParser::PrimaryExpressionContext::StringLiteral() {
  return getTokens(SimpleCParser::StringLiteral);
}

tree::TerminalNode* SimpleCParser::PrimaryExpressionContext::StringLiteral(size_t i) {
  return getToken(SimpleCParser::StringLiteral, i);
}

SimpleCParser::ExpressionContext* SimpleCParser::PrimaryExpressionContext::expression() {
  return getRuleContext<SimpleCParser::ExpressionContext>(0);
}


size_t SimpleCParser::PrimaryExpressionContext::getRuleIndex() const {
  return SimpleCParser::RulePrimaryExpression;
}

void SimpleCParser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void SimpleCParser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}


antlrcpp::Any SimpleCParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::PrimaryExpressionContext* SimpleCParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 0, SimpleCParser::RulePrimaryExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(111);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(100);
        match(SimpleCParser::Identifier);
        break;
      }

      case SimpleCParser::Constant: {
        enterOuterAlt(_localctx, 2);
        setState(101);
        match(SimpleCParser::Constant);
        break;
      }

      case SimpleCParser::StringLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(103); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(102);
                  match(SimpleCParser::StringLiteral);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(105); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case SimpleCParser::LeftParen: {
        enterOuterAlt(_localctx, 4);
        setState(107);
        match(SimpleCParser::LeftParen);
        setState(108);
        expression(0);
        setState(109);
        match(SimpleCParser::RightParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixExpressionContext ------------------------------------------------------------------

SimpleCParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::PrimaryExpressionContext* SimpleCParser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<SimpleCParser::PrimaryExpressionContext>(0);
}

SimpleCParser::PostfixExpressionContext* SimpleCParser::PostfixExpressionContext::postfixExpression() {
  return getRuleContext<SimpleCParser::PostfixExpressionContext>(0);
}

SimpleCParser::ArgumentExpressionListContext* SimpleCParser::PostfixExpressionContext::argumentExpressionList() {
  return getRuleContext<SimpleCParser::ArgumentExpressionListContext>(0);
}


size_t SimpleCParser::PostfixExpressionContext::getRuleIndex() const {
  return SimpleCParser::RulePostfixExpression;
}

void SimpleCParser::PostfixExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpression(this);
}

void SimpleCParser::PostfixExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpression(this);
}


antlrcpp::Any SimpleCParser::PostfixExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitPostfixExpression(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::PostfixExpressionContext* SimpleCParser::postfixExpression() {
   return postfixExpression(0);
}

SimpleCParser::PostfixExpressionContext* SimpleCParser::postfixExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, parentState);
  SimpleCParser::PostfixExpressionContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, SimpleCParser::RulePostfixExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(114);
    primaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(128);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(126);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(116);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(117);
          match(SimpleCParser::LeftParen);
          setState(119);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
            | (1ULL << SimpleCParser::PlusPlus)
            | (1ULL << SimpleCParser::MinusMinus)
            | (1ULL << SimpleCParser::Not)
            | (1ULL << SimpleCParser::Identifier)
            | (1ULL << SimpleCParser::Constant)
            | (1ULL << SimpleCParser::DigitSequence)
            | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
            setState(118);
            argumentExpressionList(0);
          }
          setState(121);
          match(SimpleCParser::RightParen);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(122);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(123);
          match(SimpleCParser::PlusPlus);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(124);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(125);
          match(SimpleCParser::MinusMinus);
          break;
        }

        } 
      }
      setState(130);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArgumentExpressionListContext ------------------------------------------------------------------

SimpleCParser::ArgumentExpressionListContext::ArgumentExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::AssignmentExpressionContext* SimpleCParser::ArgumentExpressionListContext::assignmentExpression() {
  return getRuleContext<SimpleCParser::AssignmentExpressionContext>(0);
}

SimpleCParser::ArgumentExpressionListContext* SimpleCParser::ArgumentExpressionListContext::argumentExpressionList() {
  return getRuleContext<SimpleCParser::ArgumentExpressionListContext>(0);
}


size_t SimpleCParser::ArgumentExpressionListContext::getRuleIndex() const {
  return SimpleCParser::RuleArgumentExpressionList;
}

void SimpleCParser::ArgumentExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentExpressionList(this);
}

void SimpleCParser::ArgumentExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentExpressionList(this);
}


antlrcpp::Any SimpleCParser::ArgumentExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitArgumentExpressionList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::ArgumentExpressionListContext* SimpleCParser::argumentExpressionList() {
   return argumentExpressionList(0);
}

SimpleCParser::ArgumentExpressionListContext* SimpleCParser::argumentExpressionList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::ArgumentExpressionListContext *_localctx = _tracker.createInstance<ArgumentExpressionListContext>(_ctx, parentState);
  SimpleCParser::ArgumentExpressionListContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, SimpleCParser::RuleArgumentExpressionList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(132);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(139);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentExpressionListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArgumentExpressionList);
        setState(134);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(135);
        match(SimpleCParser::Comma);
        setState(136);
        assignmentExpression(); 
      }
      setState(141);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

SimpleCParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::PostfixExpressionContext* SimpleCParser::UnaryExpressionContext::postfixExpression() {
  return getRuleContext<SimpleCParser::PostfixExpressionContext>(0);
}

SimpleCParser::UnaryExpressionContext* SimpleCParser::UnaryExpressionContext::unaryExpression() {
  return getRuleContext<SimpleCParser::UnaryExpressionContext>(0);
}


size_t SimpleCParser::UnaryExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleUnaryExpression;
}

void SimpleCParser::UnaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpression(this);
}

void SimpleCParser::UnaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpression(this);
}


antlrcpp::Any SimpleCParser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::UnaryExpressionContext* SimpleCParser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, SimpleCParser::RuleUnaryExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::LeftParen:
      case SimpleCParser::Identifier:
      case SimpleCParser::Constant:
      case SimpleCParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(142);
        postfixExpression(0);
        break;
      }

      case SimpleCParser::PlusPlus: {
        enterOuterAlt(_localctx, 2);
        setState(143);
        match(SimpleCParser::PlusPlus);
        setState(144);
        unaryExpression();
        break;
      }

      case SimpleCParser::MinusMinus: {
        enterOuterAlt(_localctx, 3);
        setState(145);
        match(SimpleCParser::MinusMinus);
        setState(146);
        unaryExpression();
        break;
      }

      case SimpleCParser::Not: {
        enterOuterAlt(_localctx, 4);
        setState(147);
        match(SimpleCParser::Not);
        setState(148);
        unaryExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleExpressionContext ------------------------------------------------------------------

SimpleCParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::UnaryExpressionContext* SimpleCParser::SimpleExpressionContext::unaryExpression() {
  return getRuleContext<SimpleCParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* SimpleCParser::SimpleExpressionContext::DigitSequence() {
  return getToken(SimpleCParser::DigitSequence, 0);
}


size_t SimpleCParser::SimpleExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleSimpleExpression;
}

void SimpleCParser::SimpleExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleExpression(this);
}

void SimpleCParser::SimpleExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleExpression(this);
}


antlrcpp::Any SimpleCParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::SimpleExpressionContext* SimpleCParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 8, SimpleCParser::RuleSimpleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::LeftParen:
      case SimpleCParser::PlusPlus:
      case SimpleCParser::MinusMinus:
      case SimpleCParser::Not:
      case SimpleCParser::Identifier:
      case SimpleCParser::Constant:
      case SimpleCParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(151);
        unaryExpression();
        break;
      }

      case SimpleCParser::DigitSequence: {
        enterOuterAlt(_localctx, 2);
        setState(152);
        match(SimpleCParser::DigitSequence);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

SimpleCParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::SimpleExpressionContext* SimpleCParser::MultiplicativeExpressionContext::simpleExpression() {
  return getRuleContext<SimpleCParser::SimpleExpressionContext>(0);
}

SimpleCParser::MultiplicativeExpressionContext* SimpleCParser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<SimpleCParser::MultiplicativeExpressionContext>(0);
}


size_t SimpleCParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleMultiplicativeExpression;
}

void SimpleCParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void SimpleCParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}


antlrcpp::Any SimpleCParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::MultiplicativeExpressionContext* SimpleCParser::multiplicativeExpression() {
   return multiplicativeExpression(0);
}

SimpleCParser::MultiplicativeExpressionContext* SimpleCParser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, parentState);
  SimpleCParser::MultiplicativeExpressionContext *previousContext = _localctx;
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, SimpleCParser::RuleMultiplicativeExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(156);
    simpleExpression();
    _ctx->stop = _input->LT(-1);
    setState(169);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(167);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(158);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(159);
          match(SimpleCParser::Star);
          setState(160);
          simpleExpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(161);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(162);
          match(SimpleCParser::Div);
          setState(163);
          simpleExpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(164);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(165);
          match(SimpleCParser::Mod);
          setState(166);
          simpleExpression();
          break;
        }

        } 
      }
      setState(171);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

SimpleCParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::MultiplicativeExpressionContext* SimpleCParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<SimpleCParser::MultiplicativeExpressionContext>(0);
}

SimpleCParser::AdditiveExpressionContext* SimpleCParser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<SimpleCParser::AdditiveExpressionContext>(0);
}


size_t SimpleCParser::AdditiveExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleAdditiveExpression;
}

void SimpleCParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void SimpleCParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}


antlrcpp::Any SimpleCParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::AdditiveExpressionContext* SimpleCParser::additiveExpression() {
   return additiveExpression(0);
}

SimpleCParser::AdditiveExpressionContext* SimpleCParser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  SimpleCParser::AdditiveExpressionContext *previousContext = _localctx;
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, SimpleCParser::RuleAdditiveExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(173);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(183);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(181);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(175);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(176);
          match(SimpleCParser::Plus);
          setState(177);
          multiplicativeExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(178);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(179);
          match(SimpleCParser::Minus);
          setState(180);
          multiplicativeExpression(0);
          break;
        }

        } 
      }
      setState(185);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelationalExpressionContext ------------------------------------------------------------------

SimpleCParser::RelationalExpressionContext::RelationalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::AdditiveExpressionContext* SimpleCParser::RelationalExpressionContext::additiveExpression() {
  return getRuleContext<SimpleCParser::AdditiveExpressionContext>(0);
}

SimpleCParser::RelationalExpressionContext* SimpleCParser::RelationalExpressionContext::relationalExpression() {
  return getRuleContext<SimpleCParser::RelationalExpressionContext>(0);
}


size_t SimpleCParser::RelationalExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleRelationalExpression;
}

void SimpleCParser::RelationalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpression(this);
}

void SimpleCParser::RelationalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpression(this);
}


antlrcpp::Any SimpleCParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::RelationalExpressionContext* SimpleCParser::relationalExpression() {
   return relationalExpression(0);
}

SimpleCParser::RelationalExpressionContext* SimpleCParser::relationalExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::RelationalExpressionContext *_localctx = _tracker.createInstance<RelationalExpressionContext>(_ctx, parentState);
  SimpleCParser::RelationalExpressionContext *previousContext = _localctx;
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, SimpleCParser::RuleRelationalExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(187);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(203);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(201);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(189);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(190);
          match(SimpleCParser::Less);
          setState(191);
          additiveExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(192);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(193);
          match(SimpleCParser::Greater);
          setState(194);
          additiveExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(195);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(196);
          match(SimpleCParser::LessEqual);
          setState(197);
          additiveExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(198);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(199);
          match(SimpleCParser::GreaterEqual);
          setState(200);
          additiveExpression(0);
          break;
        }

        } 
      }
      setState(205);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualityExpressionContext ------------------------------------------------------------------

SimpleCParser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::RelationalExpressionContext* SimpleCParser::EqualityExpressionContext::relationalExpression() {
  return getRuleContext<SimpleCParser::RelationalExpressionContext>(0);
}

SimpleCParser::EqualityExpressionContext* SimpleCParser::EqualityExpressionContext::equalityExpression() {
  return getRuleContext<SimpleCParser::EqualityExpressionContext>(0);
}


size_t SimpleCParser::EqualityExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleEqualityExpression;
}

void SimpleCParser::EqualityExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}

void SimpleCParser::EqualityExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}


antlrcpp::Any SimpleCParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::EqualityExpressionContext* SimpleCParser::equalityExpression() {
   return equalityExpression(0);
}

SimpleCParser::EqualityExpressionContext* SimpleCParser::equalityExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, parentState);
  SimpleCParser::EqualityExpressionContext *previousContext = _localctx;
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, SimpleCParser::RuleEqualityExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(207);
    relationalExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(217);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(215);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(209);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(210);
          match(SimpleCParser::Equal);
          setState(211);
          relationalExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(212);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(213);
          match(SimpleCParser::NotEqual);
          setState(214);
          relationalExpression(0);
          break;
        }

        } 
      }
      setState(219);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

SimpleCParser::LogicalAndExpressionContext::LogicalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::EqualityExpressionContext* SimpleCParser::LogicalAndExpressionContext::equalityExpression() {
  return getRuleContext<SimpleCParser::EqualityExpressionContext>(0);
}

SimpleCParser::LogicalAndExpressionContext* SimpleCParser::LogicalAndExpressionContext::logicalAndExpression() {
  return getRuleContext<SimpleCParser::LogicalAndExpressionContext>(0);
}


size_t SimpleCParser::LogicalAndExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleLogicalAndExpression;
}

void SimpleCParser::LogicalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpression(this);
}

void SimpleCParser::LogicalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpression(this);
}


antlrcpp::Any SimpleCParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::LogicalAndExpressionContext* SimpleCParser::logicalAndExpression() {
   return logicalAndExpression(0);
}

SimpleCParser::LogicalAndExpressionContext* SimpleCParser::logicalAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, parentState);
  SimpleCParser::LogicalAndExpressionContext *previousContext = _localctx;
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, SimpleCParser::RuleLogicalAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(221);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(228);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
        setState(223);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(224);
        match(SimpleCParser::AndAnd);
        setState(225);
        equalityExpression(0); 
      }
      setState(230);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

SimpleCParser::LogicalOrExpressionContext::LogicalOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::LogicalAndExpressionContext* SimpleCParser::LogicalOrExpressionContext::logicalAndExpression() {
  return getRuleContext<SimpleCParser::LogicalAndExpressionContext>(0);
}

SimpleCParser::LogicalOrExpressionContext* SimpleCParser::LogicalOrExpressionContext::logicalOrExpression() {
  return getRuleContext<SimpleCParser::LogicalOrExpressionContext>(0);
}


size_t SimpleCParser::LogicalOrExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleLogicalOrExpression;
}

void SimpleCParser::LogicalOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpression(this);
}

void SimpleCParser::LogicalOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpression(this);
}


antlrcpp::Any SimpleCParser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::LogicalOrExpressionContext* SimpleCParser::logicalOrExpression() {
   return logicalOrExpression(0);
}

SimpleCParser::LogicalOrExpressionContext* SimpleCParser::logicalOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::LogicalOrExpressionContext *_localctx = _tracker.createInstance<LogicalOrExpressionContext>(_ctx, parentState);
  SimpleCParser::LogicalOrExpressionContext *previousContext = _localctx;
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, SimpleCParser::RuleLogicalOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(232);
    logicalAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(239);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
        setState(234);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(235);
        match(SimpleCParser::OrOr);
        setState(236);
        logicalAndExpression(0); 
      }
      setState(241);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

SimpleCParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::LogicalOrExpressionContext* SimpleCParser::AssignmentExpressionContext::logicalOrExpression() {
  return getRuleContext<SimpleCParser::LogicalOrExpressionContext>(0);
}

SimpleCParser::UnaryExpressionContext* SimpleCParser::AssignmentExpressionContext::unaryExpression() {
  return getRuleContext<SimpleCParser::UnaryExpressionContext>(0);
}

SimpleCParser::AssignmentOperatorContext* SimpleCParser::AssignmentExpressionContext::assignmentOperator() {
  return getRuleContext<SimpleCParser::AssignmentOperatorContext>(0);
}

SimpleCParser::AssignmentExpressionContext* SimpleCParser::AssignmentExpressionContext::assignmentExpression() {
  return getRuleContext<SimpleCParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* SimpleCParser::AssignmentExpressionContext::DigitSequence() {
  return getToken(SimpleCParser::DigitSequence, 0);
}


size_t SimpleCParser::AssignmentExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleAssignmentExpression;
}

void SimpleCParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void SimpleCParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}


antlrcpp::Any SimpleCParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::AssignmentExpressionContext* SimpleCParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 22, SimpleCParser::RuleAssignmentExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(248);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(242);
      logicalOrExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(243);
      unaryExpression();
      setState(244);
      assignmentOperator();
      setState(245);
      assignmentExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(247);
      match(SimpleCParser::DigitSequence);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

SimpleCParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SimpleCParser::AssignmentOperatorContext::getRuleIndex() const {
  return SimpleCParser::RuleAssignmentOperator;
}

void SimpleCParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void SimpleCParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


antlrcpp::Any SimpleCParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::AssignmentOperatorContext* SimpleCParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 24, SimpleCParser::RuleAssignmentOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::Assign)
      | (1ULL << SimpleCParser::StarAssign)
      | (1ULL << SimpleCParser::DivAssign)
      | (1ULL << SimpleCParser::ModAssign)
      | (1ULL << SimpleCParser::PlusAssign)
      | (1ULL << SimpleCParser::MinusAssign))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SimpleCParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::AssignmentExpressionContext* SimpleCParser::ExpressionContext::assignmentExpression() {
  return getRuleContext<SimpleCParser::AssignmentExpressionContext>(0);
}

SimpleCParser::ExpressionContext* SimpleCParser::ExpressionContext::expression() {
  return getRuleContext<SimpleCParser::ExpressionContext>(0);
}


size_t SimpleCParser::ExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleExpression;
}

void SimpleCParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SimpleCParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any SimpleCParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::ExpressionContext* SimpleCParser::expression() {
   return expression(0);
}

SimpleCParser::ExpressionContext* SimpleCParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  SimpleCParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, SimpleCParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(253);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(260);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(255);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(256);
        match(SimpleCParser::Comma);
        setState(257);
        assignmentExpression(); 
      }
      setState(262);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstantExpressionContext ------------------------------------------------------------------

SimpleCParser::ConstantExpressionContext::ConstantExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::LogicalOrExpressionContext* SimpleCParser::ConstantExpressionContext::logicalOrExpression() {
  return getRuleContext<SimpleCParser::LogicalOrExpressionContext>(0);
}


size_t SimpleCParser::ConstantExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleConstantExpression;
}

void SimpleCParser::ConstantExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantExpression(this);
}

void SimpleCParser::ConstantExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantExpression(this);
}


antlrcpp::Any SimpleCParser::ConstantExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitConstantExpression(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::ConstantExpressionContext* SimpleCParser::constantExpression() {
  ConstantExpressionContext *_localctx = _tracker.createInstance<ConstantExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, SimpleCParser::RuleConstantExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    logicalOrExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

SimpleCParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DeclarationSpecifierContext* SimpleCParser::DeclarationContext::declarationSpecifier() {
  return getRuleContext<SimpleCParser::DeclarationSpecifierContext>(0);
}

SimpleCParser::InitDeclaratorListContext* SimpleCParser::DeclarationContext::initDeclaratorList() {
  return getRuleContext<SimpleCParser::InitDeclaratorListContext>(0);
}


size_t SimpleCParser::DeclarationContext::getRuleIndex() const {
  return SimpleCParser::RuleDeclaration;
}

void SimpleCParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void SimpleCParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any SimpleCParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::DeclarationContext* SimpleCParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 30, SimpleCParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(272);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(265);
      declarationSpecifier();
      setState(266);
      initDeclaratorList(0);
      setState(267);
      match(SimpleCParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(269);
      declarationSpecifier();
      setState(270);
      match(SimpleCParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifierContext ------------------------------------------------------------------

SimpleCParser::DeclarationSpecifierContext::DeclarationSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::DeclarationSpecifierContext::Identifier() {
  return getToken(SimpleCParser::Identifier, 0);
}


size_t SimpleCParser::DeclarationSpecifierContext::getRuleIndex() const {
  return SimpleCParser::RuleDeclarationSpecifier;
}

void SimpleCParser::DeclarationSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifier(this);
}

void SimpleCParser::DeclarationSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifier(this);
}


antlrcpp::Any SimpleCParser::DeclarationSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifier(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::DeclarationSpecifierContext* SimpleCParser::declarationSpecifier() {
  DeclarationSpecifierContext *_localctx = _tracker.createInstance<DeclarationSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 32, SimpleCParser::RuleDeclarationSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(276);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::Char:
      case SimpleCParser::Int:
      case SimpleCParser::Short:
      case SimpleCParser::Void: {
        enterOuterAlt(_localctx, 1);
        setState(274);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SimpleCParser::Char)
          | (1ULL << SimpleCParser::Int)
          | (1ULL << SimpleCParser::Short)
          | (1ULL << SimpleCParser::Void))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case SimpleCParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(275);
        match(SimpleCParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitDeclaratorListContext ------------------------------------------------------------------

SimpleCParser::InitDeclaratorListContext::InitDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::InitDeclaratorContext* SimpleCParser::InitDeclaratorListContext::initDeclarator() {
  return getRuleContext<SimpleCParser::InitDeclaratorContext>(0);
}

SimpleCParser::InitDeclaratorListContext* SimpleCParser::InitDeclaratorListContext::initDeclaratorList() {
  return getRuleContext<SimpleCParser::InitDeclaratorListContext>(0);
}


size_t SimpleCParser::InitDeclaratorListContext::getRuleIndex() const {
  return SimpleCParser::RuleInitDeclaratorList;
}

void SimpleCParser::InitDeclaratorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclaratorList(this);
}

void SimpleCParser::InitDeclaratorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclaratorList(this);
}


antlrcpp::Any SimpleCParser::InitDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitInitDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::InitDeclaratorListContext* SimpleCParser::initDeclaratorList() {
   return initDeclaratorList(0);
}

SimpleCParser::InitDeclaratorListContext* SimpleCParser::initDeclaratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::InitDeclaratorListContext *_localctx = _tracker.createInstance<InitDeclaratorListContext>(_ctx, parentState);
  SimpleCParser::InitDeclaratorListContext *previousContext = _localctx;
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, SimpleCParser::RuleInitDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(279);
    initDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(286);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitDeclaratorList);
        setState(281);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(282);
        match(SimpleCParser::Comma);
        setState(283);
        initDeclarator(); 
      }
      setState(288);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InitDeclaratorContext ------------------------------------------------------------------

SimpleCParser::InitDeclaratorContext::InitDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DeclaratorContext* SimpleCParser::InitDeclaratorContext::declarator() {
  return getRuleContext<SimpleCParser::DeclaratorContext>(0);
}

SimpleCParser::InitializerContext* SimpleCParser::InitDeclaratorContext::initializer() {
  return getRuleContext<SimpleCParser::InitializerContext>(0);
}


size_t SimpleCParser::InitDeclaratorContext::getRuleIndex() const {
  return SimpleCParser::RuleInitDeclarator;
}

void SimpleCParser::InitDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclarator(this);
}

void SimpleCParser::InitDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclarator(this);
}


antlrcpp::Any SimpleCParser::InitDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitInitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::InitDeclaratorContext* SimpleCParser::initDeclarator() {
  InitDeclaratorContext *_localctx = _tracker.createInstance<InitDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 36, SimpleCParser::RuleInitDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(294);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(289);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(290);
      declarator();
      setState(291);
      match(SimpleCParser::Assign);
      setState(292);
      initializer();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclaratorContext ------------------------------------------------------------------

SimpleCParser::DeclaratorContext::DeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DirectDeclaratorContext* SimpleCParser::DeclaratorContext::directDeclarator() {
  return getRuleContext<SimpleCParser::DirectDeclaratorContext>(0);
}


size_t SimpleCParser::DeclaratorContext::getRuleIndex() const {
  return SimpleCParser::RuleDeclarator;
}

void SimpleCParser::DeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarator(this);
}

void SimpleCParser::DeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarator(this);
}


antlrcpp::Any SimpleCParser::DeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::DeclaratorContext* SimpleCParser::declarator() {
  DeclaratorContext *_localctx = _tracker.createInstance<DeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 38, SimpleCParser::RuleDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    directDeclarator(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectDeclaratorContext ------------------------------------------------------------------

SimpleCParser::DirectDeclaratorContext::DirectDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::DirectDeclaratorContext::Identifier() {
  return getToken(SimpleCParser::Identifier, 0);
}

SimpleCParser::DeclaratorContext* SimpleCParser::DirectDeclaratorContext::declarator() {
  return getRuleContext<SimpleCParser::DeclaratorContext>(0);
}

tree::TerminalNode* SimpleCParser::DirectDeclaratorContext::DigitSequence() {
  return getToken(SimpleCParser::DigitSequence, 0);
}

SimpleCParser::DirectDeclaratorContext* SimpleCParser::DirectDeclaratorContext::directDeclarator() {
  return getRuleContext<SimpleCParser::DirectDeclaratorContext>(0);
}

SimpleCParser::AssignmentExpressionContext* SimpleCParser::DirectDeclaratorContext::assignmentExpression() {
  return getRuleContext<SimpleCParser::AssignmentExpressionContext>(0);
}

SimpleCParser::ParameterTypeListContext* SimpleCParser::DirectDeclaratorContext::parameterTypeList() {
  return getRuleContext<SimpleCParser::ParameterTypeListContext>(0);
}

SimpleCParser::IdentifierListContext* SimpleCParser::DirectDeclaratorContext::identifierList() {
  return getRuleContext<SimpleCParser::IdentifierListContext>(0);
}


size_t SimpleCParser::DirectDeclaratorContext::getRuleIndex() const {
  return SimpleCParser::RuleDirectDeclarator;
}

void SimpleCParser::DirectDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectDeclarator(this);
}

void SimpleCParser::DirectDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectDeclarator(this);
}


antlrcpp::Any SimpleCParser::DirectDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDirectDeclarator(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::DirectDeclaratorContext* SimpleCParser::directDeclarator() {
   return directDeclarator(0);
}

SimpleCParser::DirectDeclaratorContext* SimpleCParser::directDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::DirectDeclaratorContext *_localctx = _tracker.createInstance<DirectDeclaratorContext>(_ctx, parentState);
  SimpleCParser::DirectDeclaratorContext *previousContext = _localctx;
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, SimpleCParser::RuleDirectDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(307);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(299);
      match(SimpleCParser::Identifier);
      break;
    }

    case 2: {
      setState(300);
      match(SimpleCParser::LeftParen);
      setState(301);
      declarator();
      setState(302);
      match(SimpleCParser::RightParen);
      break;
    }

    case 3: {
      setState(304);
      match(SimpleCParser::Identifier);
      setState(305);
      match(SimpleCParser::Colon);
      setState(306);
      match(SimpleCParser::DigitSequence);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(328);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(326);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(309);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(310);
          match(SimpleCParser::LeftBracket);
          setState(312);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
            | (1ULL << SimpleCParser::PlusPlus)
            | (1ULL << SimpleCParser::MinusMinus)
            | (1ULL << SimpleCParser::Not)
            | (1ULL << SimpleCParser::Identifier)
            | (1ULL << SimpleCParser::Constant)
            | (1ULL << SimpleCParser::DigitSequence)
            | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
            setState(311);
            assignmentExpression();
          }
          setState(314);
          match(SimpleCParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(315);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(316);
          match(SimpleCParser::LeftParen);
          setState(317);
          parameterTypeList();
          setState(318);
          match(SimpleCParser::RightParen);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(320);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(321);
          match(SimpleCParser::LeftParen);
          setState(323);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SimpleCParser::Identifier) {
            setState(322);
            identifierList(0);
          }
          setState(325);
          match(SimpleCParser::RightParen);
          break;
        }

        } 
      }
      setState(330);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NestedParenthesesBlockContext ------------------------------------------------------------------

SimpleCParser::NestedParenthesesBlockContext::NestedParenthesesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleCParser::NestedParenthesesBlockContext *> SimpleCParser::NestedParenthesesBlockContext::nestedParenthesesBlock() {
  return getRuleContexts<SimpleCParser::NestedParenthesesBlockContext>();
}

SimpleCParser::NestedParenthesesBlockContext* SimpleCParser::NestedParenthesesBlockContext::nestedParenthesesBlock(size_t i) {
  return getRuleContext<SimpleCParser::NestedParenthesesBlockContext>(i);
}


size_t SimpleCParser::NestedParenthesesBlockContext::getRuleIndex() const {
  return SimpleCParser::RuleNestedParenthesesBlock;
}

void SimpleCParser::NestedParenthesesBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedParenthesesBlock(this);
}

void SimpleCParser::NestedParenthesesBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedParenthesesBlock(this);
}


antlrcpp::Any SimpleCParser::NestedParenthesesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitNestedParenthesesBlock(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::NestedParenthesesBlockContext* SimpleCParser::nestedParenthesesBlock() {
  NestedParenthesesBlockContext *_localctx = _tracker.createInstance<NestedParenthesesBlockContext>(_ctx, getState());
  enterRule(_localctx, 42, SimpleCParser::RuleNestedParenthesesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::T__0)
      | (1ULL << SimpleCParser::T__1)
      | (1ULL << SimpleCParser::Break)
      | (1ULL << SimpleCParser::Case)
      | (1ULL << SimpleCParser::Char)
      | (1ULL << SimpleCParser::Continue)
      | (1ULL << SimpleCParser::Default)
      | (1ULL << SimpleCParser::Do)
      | (1ULL << SimpleCParser::Else)
      | (1ULL << SimpleCParser::For)
      | (1ULL << SimpleCParser::Goto)
      | (1ULL << SimpleCParser::If)
      | (1ULL << SimpleCParser::Int)
      | (1ULL << SimpleCParser::Long)
      | (1ULL << SimpleCParser::Return)
      | (1ULL << SimpleCParser::Short)
      | (1ULL << SimpleCParser::Switch)
      | (1ULL << SimpleCParser::Void)
      | (1ULL << SimpleCParser::While)
      | (1ULL << SimpleCParser::LeftParen)
      | (1ULL << SimpleCParser::LeftBracket)
      | (1ULL << SimpleCParser::RightBracket)
      | (1ULL << SimpleCParser::LeftBrace)
      | (1ULL << SimpleCParser::RightBrace)
      | (1ULL << SimpleCParser::Less)
      | (1ULL << SimpleCParser::LessEqual)
      | (1ULL << SimpleCParser::Greater)
      | (1ULL << SimpleCParser::GreaterEqual)
      | (1ULL << SimpleCParser::Plus)
      | (1ULL << SimpleCParser::PlusPlus)
      | (1ULL << SimpleCParser::Minus)
      | (1ULL << SimpleCParser::MinusMinus)
      | (1ULL << SimpleCParser::Star)
      | (1ULL << SimpleCParser::Div)
      | (1ULL << SimpleCParser::Mod)
      | (1ULL << SimpleCParser::AndAnd)
      | (1ULL << SimpleCParser::OrOr)
      | (1ULL << SimpleCParser::Not)
      | (1ULL << SimpleCParser::Question)
      | (1ULL << SimpleCParser::Colon)
      | (1ULL << SimpleCParser::Semi)
      | (1ULL << SimpleCParser::Comma)
      | (1ULL << SimpleCParser::Assign)
      | (1ULL << SimpleCParser::StarAssign)
      | (1ULL << SimpleCParser::DivAssign)
      | (1ULL << SimpleCParser::ModAssign)
      | (1ULL << SimpleCParser::PlusAssign)
      | (1ULL << SimpleCParser::MinusAssign)
      | (1ULL << SimpleCParser::Equal)
      | (1ULL << SimpleCParser::NotEqual)
      | (1ULL << SimpleCParser::Identifier)
      | (1ULL << SimpleCParser::Constant)
      | (1ULL << SimpleCParser::DigitSequence)
      | (1ULL << SimpleCParser::StringLiteral)
      | (1ULL << SimpleCParser::Whitespace)
      | (1ULL << SimpleCParser::Newline)
      | (1ULL << SimpleCParser::BlockComment)
      | (1ULL << SimpleCParser::LineComment))) != 0)) {
      setState(336);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SimpleCParser::T__0:
        case SimpleCParser::T__1:
        case SimpleCParser::Break:
        case SimpleCParser::Case:
        case SimpleCParser::Char:
        case SimpleCParser::Continue:
        case SimpleCParser::Default:
        case SimpleCParser::Do:
        case SimpleCParser::Else:
        case SimpleCParser::For:
        case SimpleCParser::Goto:
        case SimpleCParser::If:
        case SimpleCParser::Int:
        case SimpleCParser::Long:
        case SimpleCParser::Return:
        case SimpleCParser::Short:
        case SimpleCParser::Switch:
        case SimpleCParser::Void:
        case SimpleCParser::While:
        case SimpleCParser::LeftBracket:
        case SimpleCParser::RightBracket:
        case SimpleCParser::LeftBrace:
        case SimpleCParser::RightBrace:
        case SimpleCParser::Less:
        case SimpleCParser::LessEqual:
        case SimpleCParser::Greater:
        case SimpleCParser::GreaterEqual:
        case SimpleCParser::Plus:
        case SimpleCParser::PlusPlus:
        case SimpleCParser::Minus:
        case SimpleCParser::MinusMinus:
        case SimpleCParser::Star:
        case SimpleCParser::Div:
        case SimpleCParser::Mod:
        case SimpleCParser::AndAnd:
        case SimpleCParser::OrOr:
        case SimpleCParser::Not:
        case SimpleCParser::Question:
        case SimpleCParser::Colon:
        case SimpleCParser::Semi:
        case SimpleCParser::Comma:
        case SimpleCParser::Assign:
        case SimpleCParser::StarAssign:
        case SimpleCParser::DivAssign:
        case SimpleCParser::ModAssign:
        case SimpleCParser::PlusAssign:
        case SimpleCParser::MinusAssign:
        case SimpleCParser::Equal:
        case SimpleCParser::NotEqual:
        case SimpleCParser::Identifier:
        case SimpleCParser::Constant:
        case SimpleCParser::DigitSequence:
        case SimpleCParser::StringLiteral:
        case SimpleCParser::Whitespace:
        case SimpleCParser::Newline:
        case SimpleCParser::BlockComment:
        case SimpleCParser::LineComment: {
          setState(331);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == SimpleCParser::LeftParen

          || _la == SimpleCParser::RightParen)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case SimpleCParser::LeftParen: {
          setState(332);
          match(SimpleCParser::LeftParen);
          setState(333);
          nestedParenthesesBlock();
          setState(334);
          match(SimpleCParser::RightParen);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(340);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterTypeListContext ------------------------------------------------------------------

SimpleCParser::ParameterTypeListContext::ParameterTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ParameterListContext* SimpleCParser::ParameterTypeListContext::parameterList() {
  return getRuleContext<SimpleCParser::ParameterListContext>(0);
}


size_t SimpleCParser::ParameterTypeListContext::getRuleIndex() const {
  return SimpleCParser::RuleParameterTypeList;
}

void SimpleCParser::ParameterTypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterTypeList(this);
}

void SimpleCParser::ParameterTypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterTypeList(this);
}


antlrcpp::Any SimpleCParser::ParameterTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitParameterTypeList(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::ParameterTypeListContext* SimpleCParser::parameterTypeList() {
  ParameterTypeListContext *_localctx = _tracker.createInstance<ParameterTypeListContext>(_ctx, getState());
  enterRule(_localctx, 44, SimpleCParser::RuleParameterTypeList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(346);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(341);
      parameterList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(342);
      parameterList(0);
      setState(343);
      match(SimpleCParser::Comma);
      setState(344);
      match(SimpleCParser::T__0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

SimpleCParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ParameterDeclarationContext* SimpleCParser::ParameterListContext::parameterDeclaration() {
  return getRuleContext<SimpleCParser::ParameterDeclarationContext>(0);
}

SimpleCParser::ParameterListContext* SimpleCParser::ParameterListContext::parameterList() {
  return getRuleContext<SimpleCParser::ParameterListContext>(0);
}


size_t SimpleCParser::ParameterListContext::getRuleIndex() const {
  return SimpleCParser::RuleParameterList;
}

void SimpleCParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void SimpleCParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


antlrcpp::Any SimpleCParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::ParameterListContext* SimpleCParser::parameterList() {
   return parameterList(0);
}

SimpleCParser::ParameterListContext* SimpleCParser::parameterList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, parentState);
  SimpleCParser::ParameterListContext *previousContext = _localctx;
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, SimpleCParser::RuleParameterList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(349);
    parameterDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(356);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterList);
        setState(351);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(352);
        match(SimpleCParser::Comma);
        setState(353);
        parameterDeclaration(); 
      }
      setState(358);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

SimpleCParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DeclarationSpecifierContext* SimpleCParser::ParameterDeclarationContext::declarationSpecifier() {
  return getRuleContext<SimpleCParser::DeclarationSpecifierContext>(0);
}

SimpleCParser::DeclaratorContext* SimpleCParser::ParameterDeclarationContext::declarator() {
  return getRuleContext<SimpleCParser::DeclaratorContext>(0);
}

SimpleCParser::AbstractDeclaratorContext* SimpleCParser::ParameterDeclarationContext::abstractDeclarator() {
  return getRuleContext<SimpleCParser::AbstractDeclaratorContext>(0);
}


size_t SimpleCParser::ParameterDeclarationContext::getRuleIndex() const {
  return SimpleCParser::RuleParameterDeclaration;
}

void SimpleCParser::ParameterDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDeclaration(this);
}

void SimpleCParser::ParameterDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDeclaration(this);
}


antlrcpp::Any SimpleCParser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::ParameterDeclarationContext* SimpleCParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 48, SimpleCParser::RuleParameterDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(366);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(359);
      declarationSpecifier();
      setState(360);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(362);
      declarationSpecifier();
      setState(364);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
      case 1: {
        setState(363);
        abstractDeclarator();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

SimpleCParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::IdentifierListContext::Identifier() {
  return getToken(SimpleCParser::Identifier, 0);
}

SimpleCParser::IdentifierListContext* SimpleCParser::IdentifierListContext::identifierList() {
  return getRuleContext<SimpleCParser::IdentifierListContext>(0);
}


size_t SimpleCParser::IdentifierListContext::getRuleIndex() const {
  return SimpleCParser::RuleIdentifierList;
}

void SimpleCParser::IdentifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierList(this);
}

void SimpleCParser::IdentifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierList(this);
}


antlrcpp::Any SimpleCParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::IdentifierListContext* SimpleCParser::identifierList() {
   return identifierList(0);
}

SimpleCParser::IdentifierListContext* SimpleCParser::identifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, parentState);
  SimpleCParser::IdentifierListContext *previousContext = _localctx;
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, SimpleCParser::RuleIdentifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(369);
    match(SimpleCParser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(376);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdentifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdentifierList);
        setState(371);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(372);
        match(SimpleCParser::Comma);
        setState(373);
        match(SimpleCParser::Identifier); 
      }
      setState(378);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AbstractDeclaratorContext ------------------------------------------------------------------

SimpleCParser::AbstractDeclaratorContext::AbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DirectAbstractDeclaratorContext* SimpleCParser::AbstractDeclaratorContext::directAbstractDeclarator() {
  return getRuleContext<SimpleCParser::DirectAbstractDeclaratorContext>(0);
}


size_t SimpleCParser::AbstractDeclaratorContext::getRuleIndex() const {
  return SimpleCParser::RuleAbstractDeclarator;
}

void SimpleCParser::AbstractDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAbstractDeclarator(this);
}

void SimpleCParser::AbstractDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAbstractDeclarator(this);
}


antlrcpp::Any SimpleCParser::AbstractDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitAbstractDeclarator(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::AbstractDeclaratorContext* SimpleCParser::abstractDeclarator() {
  AbstractDeclaratorContext *_localctx = _tracker.createInstance<AbstractDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 52, SimpleCParser::RuleAbstractDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    directAbstractDeclarator(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectAbstractDeclaratorContext ------------------------------------------------------------------

SimpleCParser::DirectAbstractDeclaratorContext::DirectAbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::AbstractDeclaratorContext* SimpleCParser::DirectAbstractDeclaratorContext::abstractDeclarator() {
  return getRuleContext<SimpleCParser::AbstractDeclaratorContext>(0);
}

SimpleCParser::AssignmentExpressionContext* SimpleCParser::DirectAbstractDeclaratorContext::assignmentExpression() {
  return getRuleContext<SimpleCParser::AssignmentExpressionContext>(0);
}

SimpleCParser::ParameterTypeListContext* SimpleCParser::DirectAbstractDeclaratorContext::parameterTypeList() {
  return getRuleContext<SimpleCParser::ParameterTypeListContext>(0);
}

SimpleCParser::DirectAbstractDeclaratorContext* SimpleCParser::DirectAbstractDeclaratorContext::directAbstractDeclarator() {
  return getRuleContext<SimpleCParser::DirectAbstractDeclaratorContext>(0);
}


size_t SimpleCParser::DirectAbstractDeclaratorContext::getRuleIndex() const {
  return SimpleCParser::RuleDirectAbstractDeclarator;
}

void SimpleCParser::DirectAbstractDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectAbstractDeclarator(this);
}

void SimpleCParser::DirectAbstractDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectAbstractDeclarator(this);
}


antlrcpp::Any SimpleCParser::DirectAbstractDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDirectAbstractDeclarator(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::DirectAbstractDeclaratorContext* SimpleCParser::directAbstractDeclarator() {
   return directAbstractDeclarator(0);
}

SimpleCParser::DirectAbstractDeclaratorContext* SimpleCParser::directAbstractDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::DirectAbstractDeclaratorContext *_localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(_ctx, parentState);
  SimpleCParser::DirectAbstractDeclaratorContext *previousContext = _localctx;
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, SimpleCParser::RuleDirectAbstractDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(396);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(382);
      match(SimpleCParser::LeftParen);
      setState(383);
      abstractDeclarator();
      setState(384);
      match(SimpleCParser::RightParen);
      break;
    }

    case 2: {
      setState(386);
      match(SimpleCParser::LeftBracket);
      setState(388);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
        | (1ULL << SimpleCParser::PlusPlus)
        | (1ULL << SimpleCParser::MinusMinus)
        | (1ULL << SimpleCParser::Not)
        | (1ULL << SimpleCParser::Identifier)
        | (1ULL << SimpleCParser::Constant)
        | (1ULL << SimpleCParser::DigitSequence)
        | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
        setState(387);
        assignmentExpression();
      }
      setState(390);
      match(SimpleCParser::RightBracket);
      break;
    }

    case 3: {
      setState(391);
      match(SimpleCParser::LeftParen);
      setState(393);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SimpleCParser::Char)
        | (1ULL << SimpleCParser::Int)
        | (1ULL << SimpleCParser::Short)
        | (1ULL << SimpleCParser::Void)
        | (1ULL << SimpleCParser::Identifier))) != 0)) {
        setState(392);
        parameterTypeList();
      }
      setState(395);
      match(SimpleCParser::RightParen);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(412);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(410);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(398);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(399);
          match(SimpleCParser::LeftBracket);
          setState(401);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
            | (1ULL << SimpleCParser::PlusPlus)
            | (1ULL << SimpleCParser::MinusMinus)
            | (1ULL << SimpleCParser::Not)
            | (1ULL << SimpleCParser::Identifier)
            | (1ULL << SimpleCParser::Constant)
            | (1ULL << SimpleCParser::DigitSequence)
            | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
            setState(400);
            assignmentExpression();
          }
          setState(403);
          match(SimpleCParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(404);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(405);
          match(SimpleCParser::LeftParen);
          setState(407);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SimpleCParser::Char)
            | (1ULL << SimpleCParser::Int)
            | (1ULL << SimpleCParser::Short)
            | (1ULL << SimpleCParser::Void)
            | (1ULL << SimpleCParser::Identifier))) != 0)) {
            setState(406);
            parameterTypeList();
          }
          setState(409);
          match(SimpleCParser::RightParen);
          break;
        }

        } 
      }
      setState(414);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InitializerContext ------------------------------------------------------------------

SimpleCParser::InitializerContext::InitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::AssignmentExpressionContext* SimpleCParser::InitializerContext::assignmentExpression() {
  return getRuleContext<SimpleCParser::AssignmentExpressionContext>(0);
}

SimpleCParser::InitializerListContext* SimpleCParser::InitializerContext::initializerList() {
  return getRuleContext<SimpleCParser::InitializerListContext>(0);
}


size_t SimpleCParser::InitializerContext::getRuleIndex() const {
  return SimpleCParser::RuleInitializer;
}

void SimpleCParser::InitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializer(this);
}

void SimpleCParser::InitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializer(this);
}


antlrcpp::Any SimpleCParser::InitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitInitializer(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::InitializerContext* SimpleCParser::initializer() {
  InitializerContext *_localctx = _tracker.createInstance<InitializerContext>(_ctx, getState());
  enterRule(_localctx, 56, SimpleCParser::RuleInitializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(425);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(415);
      assignmentExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(416);
      match(SimpleCParser::LeftBrace);
      setState(417);
      initializerList(0);
      setState(418);
      match(SimpleCParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(420);
      match(SimpleCParser::LeftBrace);
      setState(421);
      initializerList(0);
      setState(422);
      match(SimpleCParser::Comma);
      setState(423);
      match(SimpleCParser::RightBrace);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializerListContext ------------------------------------------------------------------

SimpleCParser::InitializerListContext::InitializerListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::InitializerContext* SimpleCParser::InitializerListContext::initializer() {
  return getRuleContext<SimpleCParser::InitializerContext>(0);
}

SimpleCParser::DesignationContext* SimpleCParser::InitializerListContext::designation() {
  return getRuleContext<SimpleCParser::DesignationContext>(0);
}

SimpleCParser::InitializerListContext* SimpleCParser::InitializerListContext::initializerList() {
  return getRuleContext<SimpleCParser::InitializerListContext>(0);
}


size_t SimpleCParser::InitializerListContext::getRuleIndex() const {
  return SimpleCParser::RuleInitializerList;
}

void SimpleCParser::InitializerListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializerList(this);
}

void SimpleCParser::InitializerListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializerList(this);
}


antlrcpp::Any SimpleCParser::InitializerListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitInitializerList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::InitializerListContext* SimpleCParser::initializerList() {
   return initializerList(0);
}

SimpleCParser::InitializerListContext* SimpleCParser::initializerList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::InitializerListContext *_localctx = _tracker.createInstance<InitializerListContext>(_ctx, parentState);
  SimpleCParser::InitializerListContext *previousContext = _localctx;
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, SimpleCParser::RuleInitializerList, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(429);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimpleCParser::T__1

    || _la == SimpleCParser::LeftBracket) {
      setState(428);
      designation();
    }
    setState(431);
    initializer();
    _ctx->stop = _input->LT(-1);
    setState(441);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitializerListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitializerList);
        setState(433);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(434);
        match(SimpleCParser::Comma);
        setState(436);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleCParser::T__1

        || _la == SimpleCParser::LeftBracket) {
          setState(435);
          designation();
        }
        setState(438);
        initializer(); 
      }
      setState(443);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DesignationContext ------------------------------------------------------------------

SimpleCParser::DesignationContext::DesignationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DesignatorListContext* SimpleCParser::DesignationContext::designatorList() {
  return getRuleContext<SimpleCParser::DesignatorListContext>(0);
}


size_t SimpleCParser::DesignationContext::getRuleIndex() const {
  return SimpleCParser::RuleDesignation;
}

void SimpleCParser::DesignationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignation(this);
}

void SimpleCParser::DesignationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignation(this);
}


antlrcpp::Any SimpleCParser::DesignationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDesignation(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::DesignationContext* SimpleCParser::designation() {
  DesignationContext *_localctx = _tracker.createInstance<DesignationContext>(_ctx, getState());
  enterRule(_localctx, 60, SimpleCParser::RuleDesignation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    designatorList(0);
    setState(445);
    match(SimpleCParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorListContext ------------------------------------------------------------------

SimpleCParser::DesignatorListContext::DesignatorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DesignatorContext* SimpleCParser::DesignatorListContext::designator() {
  return getRuleContext<SimpleCParser::DesignatorContext>(0);
}

SimpleCParser::DesignatorListContext* SimpleCParser::DesignatorListContext::designatorList() {
  return getRuleContext<SimpleCParser::DesignatorListContext>(0);
}


size_t SimpleCParser::DesignatorListContext::getRuleIndex() const {
  return SimpleCParser::RuleDesignatorList;
}

void SimpleCParser::DesignatorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignatorList(this);
}

void SimpleCParser::DesignatorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignatorList(this);
}


antlrcpp::Any SimpleCParser::DesignatorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDesignatorList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::DesignatorListContext* SimpleCParser::designatorList() {
   return designatorList(0);
}

SimpleCParser::DesignatorListContext* SimpleCParser::designatorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::DesignatorListContext *_localctx = _tracker.createInstance<DesignatorListContext>(_ctx, parentState);
  SimpleCParser::DesignatorListContext *previousContext = _localctx;
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, SimpleCParser::RuleDesignatorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(448);
    designator();
    _ctx->stop = _input->LT(-1);
    setState(454);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DesignatorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDesignatorList);
        setState(450);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(451);
        designator(); 
      }
      setState(456);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

SimpleCParser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ConstantExpressionContext* SimpleCParser::DesignatorContext::constantExpression() {
  return getRuleContext<SimpleCParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* SimpleCParser::DesignatorContext::Identifier() {
  return getToken(SimpleCParser::Identifier, 0);
}


size_t SimpleCParser::DesignatorContext::getRuleIndex() const {
  return SimpleCParser::RuleDesignator;
}

void SimpleCParser::DesignatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignator(this);
}

void SimpleCParser::DesignatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignator(this);
}


antlrcpp::Any SimpleCParser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::DesignatorContext* SimpleCParser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 64, SimpleCParser::RuleDesignator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(463);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::LeftBracket: {
        enterOuterAlt(_localctx, 1);
        setState(457);
        match(SimpleCParser::LeftBracket);
        setState(458);
        constantExpression();
        setState(459);
        match(SimpleCParser::RightBracket);
        break;
      }

      case SimpleCParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(461);
        match(SimpleCParser::T__1);
        setState(462);
        match(SimpleCParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

SimpleCParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::LabeledStatementContext* SimpleCParser::StatementContext::labeledStatement() {
  return getRuleContext<SimpleCParser::LabeledStatementContext>(0);
}

SimpleCParser::CompoundStatementContext* SimpleCParser::StatementContext::compoundStatement() {
  return getRuleContext<SimpleCParser::CompoundStatementContext>(0);
}

SimpleCParser::ExpressionStatementContext* SimpleCParser::StatementContext::expressionStatement() {
  return getRuleContext<SimpleCParser::ExpressionStatementContext>(0);
}

SimpleCParser::SelectionStatementContext* SimpleCParser::StatementContext::selectionStatement() {
  return getRuleContext<SimpleCParser::SelectionStatementContext>(0);
}

SimpleCParser::IterationStatementContext* SimpleCParser::StatementContext::iterationStatement() {
  return getRuleContext<SimpleCParser::IterationStatementContext>(0);
}

SimpleCParser::JumpStatementContext* SimpleCParser::StatementContext::jumpStatement() {
  return getRuleContext<SimpleCParser::JumpStatementContext>(0);
}


size_t SimpleCParser::StatementContext::getRuleIndex() const {
  return SimpleCParser::RuleStatement;
}

void SimpleCParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void SimpleCParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any SimpleCParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::StatementContext* SimpleCParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 66, SimpleCParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(471);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(465);
      labeledStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(466);
      compoundStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(467);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(468);
      selectionStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(469);
      iterationStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(470);
      jumpStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabeledStatementContext ------------------------------------------------------------------

SimpleCParser::LabeledStatementContext::LabeledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::LabeledStatementContext::Identifier() {
  return getToken(SimpleCParser::Identifier, 0);
}

SimpleCParser::StatementContext* SimpleCParser::LabeledStatementContext::statement() {
  return getRuleContext<SimpleCParser::StatementContext>(0);
}

SimpleCParser::ConstantExpressionContext* SimpleCParser::LabeledStatementContext::constantExpression() {
  return getRuleContext<SimpleCParser::ConstantExpressionContext>(0);
}


size_t SimpleCParser::LabeledStatementContext::getRuleIndex() const {
  return SimpleCParser::RuleLabeledStatement;
}

void SimpleCParser::LabeledStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabeledStatement(this);
}

void SimpleCParser::LabeledStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabeledStatement(this);
}


antlrcpp::Any SimpleCParser::LabeledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitLabeledStatement(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::LabeledStatementContext* SimpleCParser::labeledStatement() {
  LabeledStatementContext *_localctx = _tracker.createInstance<LabeledStatementContext>(_ctx, getState());
  enterRule(_localctx, 68, SimpleCParser::RuleLabeledStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(484);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(473);
        match(SimpleCParser::Identifier);
        setState(474);
        match(SimpleCParser::Colon);
        setState(475);
        statement();
        break;
      }

      case SimpleCParser::Case: {
        enterOuterAlt(_localctx, 2);
        setState(476);
        match(SimpleCParser::Case);
        setState(477);
        constantExpression();
        setState(478);
        match(SimpleCParser::Colon);
        setState(479);
        statement();
        break;
      }

      case SimpleCParser::Default: {
        enterOuterAlt(_localctx, 3);
        setState(481);
        match(SimpleCParser::Default);
        setState(482);
        match(SimpleCParser::Colon);
        setState(483);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

SimpleCParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::BlockItemListContext* SimpleCParser::CompoundStatementContext::blockItemList() {
  return getRuleContext<SimpleCParser::BlockItemListContext>(0);
}


size_t SimpleCParser::CompoundStatementContext::getRuleIndex() const {
  return SimpleCParser::RuleCompoundStatement;
}

void SimpleCParser::CompoundStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundStatement(this);
}

void SimpleCParser::CompoundStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundStatement(this);
}


antlrcpp::Any SimpleCParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::CompoundStatementContext* SimpleCParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 70, SimpleCParser::RuleCompoundStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(486);
    match(SimpleCParser::LeftBrace);
    setState(488);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::Break)
      | (1ULL << SimpleCParser::Case)
      | (1ULL << SimpleCParser::Char)
      | (1ULL << SimpleCParser::Continue)
      | (1ULL << SimpleCParser::Default)
      | (1ULL << SimpleCParser::For)
      | (1ULL << SimpleCParser::If)
      | (1ULL << SimpleCParser::Int)
      | (1ULL << SimpleCParser::Return)
      | (1ULL << SimpleCParser::Short)
      | (1ULL << SimpleCParser::Switch)
      | (1ULL << SimpleCParser::Void)
      | (1ULL << SimpleCParser::While)
      | (1ULL << SimpleCParser::LeftParen)
      | (1ULL << SimpleCParser::LeftBrace)
      | (1ULL << SimpleCParser::PlusPlus)
      | (1ULL << SimpleCParser::MinusMinus)
      | (1ULL << SimpleCParser::Not)
      | (1ULL << SimpleCParser::Semi)
      | (1ULL << SimpleCParser::Identifier)
      | (1ULL << SimpleCParser::Constant)
      | (1ULL << SimpleCParser::DigitSequence)
      | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
      setState(487);
      blockItemList(0);
    }
    setState(490);
    match(SimpleCParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemListContext ------------------------------------------------------------------

SimpleCParser::BlockItemListContext::BlockItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::BlockItemContext* SimpleCParser::BlockItemListContext::blockItem() {
  return getRuleContext<SimpleCParser::BlockItemContext>(0);
}

SimpleCParser::BlockItemListContext* SimpleCParser::BlockItemListContext::blockItemList() {
  return getRuleContext<SimpleCParser::BlockItemListContext>(0);
}


size_t SimpleCParser::BlockItemListContext::getRuleIndex() const {
  return SimpleCParser::RuleBlockItemList;
}

void SimpleCParser::BlockItemListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItemList(this);
}

void SimpleCParser::BlockItemListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItemList(this);
}


antlrcpp::Any SimpleCParser::BlockItemListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitBlockItemList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::BlockItemListContext* SimpleCParser::blockItemList() {
   return blockItemList(0);
}

SimpleCParser::BlockItemListContext* SimpleCParser::blockItemList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::BlockItemListContext *_localctx = _tracker.createInstance<BlockItemListContext>(_ctx, parentState);
  SimpleCParser::BlockItemListContext *previousContext = _localctx;
  size_t startState = 72;
  enterRecursionRule(_localctx, 72, SimpleCParser::RuleBlockItemList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(493);
    blockItem();
    _ctx->stop = _input->LT(-1);
    setState(499);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BlockItemListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBlockItemList);
        setState(495);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(496);
        blockItem(); 
      }
      setState(501);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

SimpleCParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::StatementContext* SimpleCParser::BlockItemContext::statement() {
  return getRuleContext<SimpleCParser::StatementContext>(0);
}

SimpleCParser::DeclarationContext* SimpleCParser::BlockItemContext::declaration() {
  return getRuleContext<SimpleCParser::DeclarationContext>(0);
}


size_t SimpleCParser::BlockItemContext::getRuleIndex() const {
  return SimpleCParser::RuleBlockItem;
}

void SimpleCParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void SimpleCParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}


antlrcpp::Any SimpleCParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::BlockItemContext* SimpleCParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 74, SimpleCParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(504);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(502);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(503);
      declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

SimpleCParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ExpressionContext* SimpleCParser::ExpressionStatementContext::expression() {
  return getRuleContext<SimpleCParser::ExpressionContext>(0);
}


size_t SimpleCParser::ExpressionStatementContext::getRuleIndex() const {
  return SimpleCParser::RuleExpressionStatement;
}

void SimpleCParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void SimpleCParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


antlrcpp::Any SimpleCParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::ExpressionStatementContext* SimpleCParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 76, SimpleCParser::RuleExpressionStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(507);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
      | (1ULL << SimpleCParser::PlusPlus)
      | (1ULL << SimpleCParser::MinusMinus)
      | (1ULL << SimpleCParser::Not)
      | (1ULL << SimpleCParser::Identifier)
      | (1ULL << SimpleCParser::Constant)
      | (1ULL << SimpleCParser::DigitSequence)
      | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
      setState(506);
      expression(0);
    }
    setState(509);
    match(SimpleCParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

SimpleCParser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ExpressionContext* SimpleCParser::SelectionStatementContext::expression() {
  return getRuleContext<SimpleCParser::ExpressionContext>(0);
}

std::vector<SimpleCParser::StatementContext *> SimpleCParser::SelectionStatementContext::statement() {
  return getRuleContexts<SimpleCParser::StatementContext>();
}

SimpleCParser::StatementContext* SimpleCParser::SelectionStatementContext::statement(size_t i) {
  return getRuleContext<SimpleCParser::StatementContext>(i);
}


size_t SimpleCParser::SelectionStatementContext::getRuleIndex() const {
  return SimpleCParser::RuleSelectionStatement;
}

void SimpleCParser::SelectionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectionStatement(this);
}

void SimpleCParser::SelectionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectionStatement(this);
}


antlrcpp::Any SimpleCParser::SelectionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitSelectionStatement(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::SelectionStatementContext* SimpleCParser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 78, SimpleCParser::RuleSelectionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(526);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(511);
        match(SimpleCParser::If);
        setState(512);
        match(SimpleCParser::LeftParen);
        setState(513);
        expression(0);
        setState(514);
        match(SimpleCParser::RightParen);
        setState(515);
        statement();
        setState(518);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
        case 1: {
          setState(516);
          match(SimpleCParser::Else);
          setState(517);
          statement();
          break;
        }

        }
        break;
      }

      case SimpleCParser::Switch: {
        enterOuterAlt(_localctx, 2);
        setState(520);
        match(SimpleCParser::Switch);
        setState(521);
        match(SimpleCParser::LeftParen);
        setState(522);
        expression(0);
        setState(523);
        match(SimpleCParser::RightParen);
        setState(524);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

SimpleCParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::IterationStatementContext::While() {
  return getToken(SimpleCParser::While, 0);
}

SimpleCParser::ExpressionContext* SimpleCParser::IterationStatementContext::expression() {
  return getRuleContext<SimpleCParser::ExpressionContext>(0);
}

SimpleCParser::StatementContext* SimpleCParser::IterationStatementContext::statement() {
  return getRuleContext<SimpleCParser::StatementContext>(0);
}

tree::TerminalNode* SimpleCParser::IterationStatementContext::For() {
  return getToken(SimpleCParser::For, 0);
}

SimpleCParser::ForConditionContext* SimpleCParser::IterationStatementContext::forCondition() {
  return getRuleContext<SimpleCParser::ForConditionContext>(0);
}


size_t SimpleCParser::IterationStatementContext::getRuleIndex() const {
  return SimpleCParser::RuleIterationStatement;
}

void SimpleCParser::IterationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationStatement(this);
}

void SimpleCParser::IterationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationStatement(this);
}


antlrcpp::Any SimpleCParser::IterationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitIterationStatement(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::IterationStatementContext* SimpleCParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 80, SimpleCParser::RuleIterationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(540);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(528);
        match(SimpleCParser::While);
        setState(529);
        match(SimpleCParser::LeftParen);
        setState(530);
        expression(0);
        setState(531);
        match(SimpleCParser::RightParen);
        setState(532);
        statement();
        break;
      }

      case SimpleCParser::For: {
        enterOuterAlt(_localctx, 2);
        setState(534);
        match(SimpleCParser::For);
        setState(535);
        match(SimpleCParser::LeftParen);
        setState(536);
        forCondition();
        setState(537);
        match(SimpleCParser::RightParen);
        setState(538);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForConditionContext ------------------------------------------------------------------

SimpleCParser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ForDeclarationContext* SimpleCParser::ForConditionContext::forDeclaration() {
  return getRuleContext<SimpleCParser::ForDeclarationContext>(0);
}

std::vector<SimpleCParser::ForExpressionContext *> SimpleCParser::ForConditionContext::forExpression() {
  return getRuleContexts<SimpleCParser::ForExpressionContext>();
}

SimpleCParser::ForExpressionContext* SimpleCParser::ForConditionContext::forExpression(size_t i) {
  return getRuleContext<SimpleCParser::ForExpressionContext>(i);
}

SimpleCParser::ExpressionContext* SimpleCParser::ForConditionContext::expression() {
  return getRuleContext<SimpleCParser::ExpressionContext>(0);
}


size_t SimpleCParser::ForConditionContext::getRuleIndex() const {
  return SimpleCParser::RuleForCondition;
}

void SimpleCParser::ForConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForCondition(this);
}

void SimpleCParser::ForConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForCondition(this);
}


antlrcpp::Any SimpleCParser::ForConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitForCondition(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::ForConditionContext* SimpleCParser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 82, SimpleCParser::RuleForCondition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(562);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(542);
      forDeclaration();
      setState(543);
      match(SimpleCParser::Semi);
      setState(545);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
        | (1ULL << SimpleCParser::PlusPlus)
        | (1ULL << SimpleCParser::MinusMinus)
        | (1ULL << SimpleCParser::Not)
        | (1ULL << SimpleCParser::Identifier)
        | (1ULL << SimpleCParser::Constant)
        | (1ULL << SimpleCParser::DigitSequence)
        | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
        setState(544);
        forExpression(0);
      }
      setState(547);
      match(SimpleCParser::Semi);
      setState(549);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
        | (1ULL << SimpleCParser::PlusPlus)
        | (1ULL << SimpleCParser::MinusMinus)
        | (1ULL << SimpleCParser::Not)
        | (1ULL << SimpleCParser::Identifier)
        | (1ULL << SimpleCParser::Constant)
        | (1ULL << SimpleCParser::DigitSequence)
        | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
        setState(548);
        forExpression(0);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(552);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
        | (1ULL << SimpleCParser::PlusPlus)
        | (1ULL << SimpleCParser::MinusMinus)
        | (1ULL << SimpleCParser::Not)
        | (1ULL << SimpleCParser::Identifier)
        | (1ULL << SimpleCParser::Constant)
        | (1ULL << SimpleCParser::DigitSequence)
        | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
        setState(551);
        expression(0);
      }
      setState(554);
      match(SimpleCParser::Semi);
      setState(556);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
        | (1ULL << SimpleCParser::PlusPlus)
        | (1ULL << SimpleCParser::MinusMinus)
        | (1ULL << SimpleCParser::Not)
        | (1ULL << SimpleCParser::Identifier)
        | (1ULL << SimpleCParser::Constant)
        | (1ULL << SimpleCParser::DigitSequence)
        | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
        setState(555);
        forExpression(0);
      }
      setState(558);
      match(SimpleCParser::Semi);
      setState(560);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
        | (1ULL << SimpleCParser::PlusPlus)
        | (1ULL << SimpleCParser::MinusMinus)
        | (1ULL << SimpleCParser::Not)
        | (1ULL << SimpleCParser::Identifier)
        | (1ULL << SimpleCParser::Constant)
        | (1ULL << SimpleCParser::DigitSequence)
        | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
        setState(559);
        forExpression(0);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForDeclarationContext ------------------------------------------------------------------

SimpleCParser::ForDeclarationContext::ForDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DeclarationSpecifierContext* SimpleCParser::ForDeclarationContext::declarationSpecifier() {
  return getRuleContext<SimpleCParser::DeclarationSpecifierContext>(0);
}

SimpleCParser::InitDeclaratorListContext* SimpleCParser::ForDeclarationContext::initDeclaratorList() {
  return getRuleContext<SimpleCParser::InitDeclaratorListContext>(0);
}


size_t SimpleCParser::ForDeclarationContext::getRuleIndex() const {
  return SimpleCParser::RuleForDeclaration;
}

void SimpleCParser::ForDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForDeclaration(this);
}

void SimpleCParser::ForDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForDeclaration(this);
}


antlrcpp::Any SimpleCParser::ForDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitForDeclaration(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::ForDeclarationContext* SimpleCParser::forDeclaration() {
  ForDeclarationContext *_localctx = _tracker.createInstance<ForDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 84, SimpleCParser::RuleForDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(568);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(564);
      declarationSpecifier();
      setState(565);
      initDeclaratorList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(567);
      declarationSpecifier();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForExpressionContext ------------------------------------------------------------------

SimpleCParser::ForExpressionContext::ForExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::AssignmentExpressionContext* SimpleCParser::ForExpressionContext::assignmentExpression() {
  return getRuleContext<SimpleCParser::AssignmentExpressionContext>(0);
}

SimpleCParser::ForExpressionContext* SimpleCParser::ForExpressionContext::forExpression() {
  return getRuleContext<SimpleCParser::ForExpressionContext>(0);
}


size_t SimpleCParser::ForExpressionContext::getRuleIndex() const {
  return SimpleCParser::RuleForExpression;
}

void SimpleCParser::ForExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForExpression(this);
}

void SimpleCParser::ForExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForExpression(this);
}


antlrcpp::Any SimpleCParser::ForExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitForExpression(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::ForExpressionContext* SimpleCParser::forExpression() {
   return forExpression(0);
}

SimpleCParser::ForExpressionContext* SimpleCParser::forExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::ForExpressionContext *_localctx = _tracker.createInstance<ForExpressionContext>(_ctx, parentState);
  SimpleCParser::ForExpressionContext *previousContext = _localctx;
  size_t startState = 86;
  enterRecursionRule(_localctx, 86, SimpleCParser::RuleForExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(571);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(578);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ForExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleForExpression);
        setState(573);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(574);
        match(SimpleCParser::Comma);
        setState(575);
        assignmentExpression(); 
      }
      setState(580);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- JumpStatementContext ------------------------------------------------------------------

SimpleCParser::JumpStatementContext::JumpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ExpressionContext* SimpleCParser::JumpStatementContext::expression() {
  return getRuleContext<SimpleCParser::ExpressionContext>(0);
}


size_t SimpleCParser::JumpStatementContext::getRuleIndex() const {
  return SimpleCParser::RuleJumpStatement;
}

void SimpleCParser::JumpStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpStatement(this);
}

void SimpleCParser::JumpStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpStatement(this);
}


antlrcpp::Any SimpleCParser::JumpStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitJumpStatement(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::JumpStatementContext* SimpleCParser::jumpStatement() {
  JumpStatementContext *_localctx = _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 88, SimpleCParser::RuleJumpStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(590);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::Continue: {
        enterOuterAlt(_localctx, 1);
        setState(581);
        match(SimpleCParser::Continue);
        setState(582);
        match(SimpleCParser::Semi);
        break;
      }

      case SimpleCParser::Break: {
        enterOuterAlt(_localctx, 2);
        setState(583);
        match(SimpleCParser::Break);
        setState(584);
        match(SimpleCParser::Semi);
        break;
      }

      case SimpleCParser::Return: {
        enterOuterAlt(_localctx, 3);
        setState(585);
        match(SimpleCParser::Return);
        setState(587);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SimpleCParser::LeftParen)
          | (1ULL << SimpleCParser::PlusPlus)
          | (1ULL << SimpleCParser::MinusMinus)
          | (1ULL << SimpleCParser::Not)
          | (1ULL << SimpleCParser::Identifier)
          | (1ULL << SimpleCParser::Constant)
          | (1ULL << SimpleCParser::DigitSequence)
          | (1ULL << SimpleCParser::StringLiteral))) != 0)) {
          setState(586);
          expression(0);
        }
        setState(589);
        match(SimpleCParser::Semi);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompilationUnitContext ------------------------------------------------------------------

SimpleCParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::CompilationUnitContext::EOF() {
  return getToken(SimpleCParser::EOF, 0);
}

SimpleCParser::TranslationUnitContext* SimpleCParser::CompilationUnitContext::translationUnit() {
  return getRuleContext<SimpleCParser::TranslationUnitContext>(0);
}


size_t SimpleCParser::CompilationUnitContext::getRuleIndex() const {
  return SimpleCParser::RuleCompilationUnit;
}

void SimpleCParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void SimpleCParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


antlrcpp::Any SimpleCParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::CompilationUnitContext* SimpleCParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 90, SimpleCParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(593);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::Char)
      | (1ULL << SimpleCParser::Int)
      | (1ULL << SimpleCParser::Short)
      | (1ULL << SimpleCParser::Void)
      | (1ULL << SimpleCParser::LeftParen)
      | (1ULL << SimpleCParser::Semi)
      | (1ULL << SimpleCParser::Identifier))) != 0)) {
      setState(592);
      translationUnit(0);
    }
    setState(595);
    match(SimpleCParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranslationUnitContext ------------------------------------------------------------------

SimpleCParser::TranslationUnitContext::TranslationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ExternalDeclarationContext* SimpleCParser::TranslationUnitContext::externalDeclaration() {
  return getRuleContext<SimpleCParser::ExternalDeclarationContext>(0);
}

SimpleCParser::TranslationUnitContext* SimpleCParser::TranslationUnitContext::translationUnit() {
  return getRuleContext<SimpleCParser::TranslationUnitContext>(0);
}


size_t SimpleCParser::TranslationUnitContext::getRuleIndex() const {
  return SimpleCParser::RuleTranslationUnit;
}

void SimpleCParser::TranslationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTranslationUnit(this);
}

void SimpleCParser::TranslationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTranslationUnit(this);
}


antlrcpp::Any SimpleCParser::TranslationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitTranslationUnit(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::TranslationUnitContext* SimpleCParser::translationUnit() {
   return translationUnit(0);
}

SimpleCParser::TranslationUnitContext* SimpleCParser::translationUnit(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::TranslationUnitContext *_localctx = _tracker.createInstance<TranslationUnitContext>(_ctx, parentState);
  SimpleCParser::TranslationUnitContext *previousContext = _localctx;
  size_t startState = 92;
  enterRecursionRule(_localctx, 92, SimpleCParser::RuleTranslationUnit, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(598);
    externalDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(604);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TranslationUnitContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTranslationUnit);
        setState(600);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(601);
        externalDeclaration(); 
      }
      setState(606);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExternalDeclarationContext ------------------------------------------------------------------

SimpleCParser::ExternalDeclarationContext::ExternalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::FunctionDefinitionContext* SimpleCParser::ExternalDeclarationContext::functionDefinition() {
  return getRuleContext<SimpleCParser::FunctionDefinitionContext>(0);
}

SimpleCParser::DeclarationContext* SimpleCParser::ExternalDeclarationContext::declaration() {
  return getRuleContext<SimpleCParser::DeclarationContext>(0);
}


size_t SimpleCParser::ExternalDeclarationContext::getRuleIndex() const {
  return SimpleCParser::RuleExternalDeclaration;
}

void SimpleCParser::ExternalDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternalDeclaration(this);
}

void SimpleCParser::ExternalDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternalDeclaration(this);
}


antlrcpp::Any SimpleCParser::ExternalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitExternalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::ExternalDeclarationContext* SimpleCParser::externalDeclaration() {
  ExternalDeclarationContext *_localctx = _tracker.createInstance<ExternalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 94, SimpleCParser::RuleExternalDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(610);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(607);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(608);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(609);
      match(SimpleCParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

SimpleCParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DeclaratorContext* SimpleCParser::FunctionDefinitionContext::declarator() {
  return getRuleContext<SimpleCParser::DeclaratorContext>(0);
}

SimpleCParser::CompoundStatementContext* SimpleCParser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<SimpleCParser::CompoundStatementContext>(0);
}

SimpleCParser::DeclarationSpecifierContext* SimpleCParser::FunctionDefinitionContext::declarationSpecifier() {
  return getRuleContext<SimpleCParser::DeclarationSpecifierContext>(0);
}

SimpleCParser::DeclarationListContext* SimpleCParser::FunctionDefinitionContext::declarationList() {
  return getRuleContext<SimpleCParser::DeclarationListContext>(0);
}


size_t SimpleCParser::FunctionDefinitionContext::getRuleIndex() const {
  return SimpleCParser::RuleFunctionDefinition;
}

void SimpleCParser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void SimpleCParser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}


antlrcpp::Any SimpleCParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::FunctionDefinitionContext* SimpleCParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 96, SimpleCParser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(613);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      setState(612);
      declarationSpecifier();
      break;
    }

    }
    setState(615);
    declarator();
    setState(617);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::Char)
      | (1ULL << SimpleCParser::Int)
      | (1ULL << SimpleCParser::Short)
      | (1ULL << SimpleCParser::Void)
      | (1ULL << SimpleCParser::Identifier))) != 0)) {
      setState(616);
      declarationList(0);
    }
    setState(619);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationListContext ------------------------------------------------------------------

SimpleCParser::DeclarationListContext::DeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DeclarationContext* SimpleCParser::DeclarationListContext::declaration() {
  return getRuleContext<SimpleCParser::DeclarationContext>(0);
}

SimpleCParser::DeclarationListContext* SimpleCParser::DeclarationListContext::declarationList() {
  return getRuleContext<SimpleCParser::DeclarationListContext>(0);
}


size_t SimpleCParser::DeclarationListContext::getRuleIndex() const {
  return SimpleCParser::RuleDeclarationList;
}

void SimpleCParser::DeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationList(this);
}

void SimpleCParser::DeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationList(this);
}


antlrcpp::Any SimpleCParser::DeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDeclarationList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::DeclarationListContext* SimpleCParser::declarationList() {
   return declarationList(0);
}

SimpleCParser::DeclarationListContext* SimpleCParser::declarationList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::DeclarationListContext *_localctx = _tracker.createInstance<DeclarationListContext>(_ctx, parentState);
  SimpleCParser::DeclarationListContext *previousContext = _localctx;
  size_t startState = 98;
  enterRecursionRule(_localctx, 98, SimpleCParser::RuleDeclarationList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(622);
    declaration();
    _ctx->stop = _input->LT(-1);
    setState(628);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDeclarationList);
        setState(624);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(625);
        declaration(); 
      }
      setState(630);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool SimpleCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return postfixExpressionSempred(dynamic_cast<PostfixExpressionContext *>(context), predicateIndex);
    case 2: return argumentExpressionListSempred(dynamic_cast<ArgumentExpressionListContext *>(context), predicateIndex);
    case 5: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 6: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 7: return relationalExpressionSempred(dynamic_cast<RelationalExpressionContext *>(context), predicateIndex);
    case 8: return equalityExpressionSempred(dynamic_cast<EqualityExpressionContext *>(context), predicateIndex);
    case 9: return logicalAndExpressionSempred(dynamic_cast<LogicalAndExpressionContext *>(context), predicateIndex);
    case 10: return logicalOrExpressionSempred(dynamic_cast<LogicalOrExpressionContext *>(context), predicateIndex);
    case 13: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 17: return initDeclaratorListSempred(dynamic_cast<InitDeclaratorListContext *>(context), predicateIndex);
    case 20: return directDeclaratorSempred(dynamic_cast<DirectDeclaratorContext *>(context), predicateIndex);
    case 23: return parameterListSempred(dynamic_cast<ParameterListContext *>(context), predicateIndex);
    case 25: return identifierListSempred(dynamic_cast<IdentifierListContext *>(context), predicateIndex);
    case 27: return directAbstractDeclaratorSempred(dynamic_cast<DirectAbstractDeclaratorContext *>(context), predicateIndex);
    case 29: return initializerListSempred(dynamic_cast<InitializerListContext *>(context), predicateIndex);
    case 31: return designatorListSempred(dynamic_cast<DesignatorListContext *>(context), predicateIndex);
    case 36: return blockItemListSempred(dynamic_cast<BlockItemListContext *>(context), predicateIndex);
    case 43: return forExpressionSempred(dynamic_cast<ForExpressionContext *>(context), predicateIndex);
    case 46: return translationUnitSempred(dynamic_cast<TranslationUnitContext *>(context), predicateIndex);
    case 49: return declarationListSempred(dynamic_cast<DeclarationListContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::postfixExpressionSempred(PostfixExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::argumentExpressionListSempred(ArgumentExpressionListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::relationalExpressionSempred(RelationalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 4);
    case 10: return precpred(_ctx, 3);
    case 11: return precpred(_ctx, 2);
    case 12: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 13: return precpred(_ctx, 2);
    case 14: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 15: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::logicalOrExpressionSempred(LogicalOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 16: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 17: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::initDeclaratorListSempred(InitDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 18: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 19: return precpred(_ctx, 4);
    case 20: return precpred(_ctx, 3);
    case 21: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::parameterListSempred(ParameterListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 22: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::identifierListSempred(IdentifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 23: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::directAbstractDeclaratorSempred(DirectAbstractDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 24: return precpred(_ctx, 2);
    case 25: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::initializerListSempred(InitializerListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 26: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::designatorListSempred(DesignatorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::blockItemListSempred(BlockItemListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 28: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::forExpressionSempred(ForExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 29: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::translationUnitSempred(TranslationUnitContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 30: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::declarationListSempred(DeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 31: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SimpleCParser::_decisionToDFA;
atn::PredictionContextCache SimpleCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SimpleCParser::_atn;
std::vector<uint16_t> SimpleCParser::_serializedATN;

std::vector<std::string> SimpleCParser::_ruleNames = {
  "primaryExpression", "postfixExpression", "argumentExpressionList", "unaryExpression", 
  "simpleExpression", "multiplicativeExpression", "additiveExpression", 
  "relationalExpression", "equalityExpression", "logicalAndExpression", 
  "logicalOrExpression", "assignmentExpression", "assignmentOperator", "expression", 
  "constantExpression", "declaration", "declarationSpecifier", "initDeclaratorList", 
  "initDeclarator", "declarator", "directDeclarator", "nestedParenthesesBlock", 
  "parameterTypeList", "parameterList", "parameterDeclaration", "identifierList", 
  "abstractDeclarator", "directAbstractDeclarator", "initializer", "initializerList", 
  "designation", "designatorList", "designator", "statement", "labeledStatement", 
  "compoundStatement", "blockItemList", "blockItem", "expressionStatement", 
  "selectionStatement", "iterationStatement", "forCondition", "forDeclaration", 
  "forExpression", "jumpStatement", "compilationUnit", "translationUnit", 
  "externalDeclaration", "functionDefinition", "declarationList"
};

std::vector<std::string> SimpleCParser::_literalNames = {
  "", "'...'", "'.'", "'break'", "'case'", "'char'", "'continue'", "'default'", 
  "'do'", "'else'", "'for'", "'goto'", "'if'", "'int'", "'long'", "'return'", 
  "'short'", "'switch'", "'void'", "'while'", "'('", "')'", "'['", "']'", 
  "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", "'+'", "'++'", "'-'", "'--'", 
  "'*'", "'/'", "'%'", "'&&'", "'||'", "'!'", "'?'", "':'", "';'", "','", 
  "'='", "'*='", "'/='", "'%='", "'+='", "'-='", "'=='", "'!='"
};

std::vector<std::string> SimpleCParser::_symbolicNames = {
  "", "", "", "Break", "Case", "Char", "Continue", "Default", "Do", "Else", 
  "For", "Goto", "If", "Int", "Long", "Return", "Short", "Switch", "Void", 
  "While", "LeftParen", "RightParen", "LeftBracket", "RightBracket", "LeftBrace", 
  "RightBrace", "Less", "LessEqual", "Greater", "GreaterEqual", "Plus", 
  "PlusPlus", "Minus", "MinusMinus", "Star", "Div", "Mod", "AndAnd", "OrOr", 
  "Not", "Question", "Colon", "Semi", "Comma", "Assign", "StarAssign", "DivAssign", 
  "ModAssign", "PlusAssign", "MinusAssign", "Equal", "NotEqual", "Identifier", 
  "Constant", "DigitSequence", "StringLiteral", "Whitespace", "Newline", 
  "BlockComment", "LineComment"
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
    0x3, 0x3d, 0x27a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 
    0x6a, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x6b, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x5, 0x2, 0x72, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x7a, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x81, 0xa, 0x3, 0xc, 0x3, 0xe, 
    0x3, 0x84, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x8c, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x8f, 0xb, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x98, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x9c, 0xa, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0xaa, 0xa, 
    0x7, 0xc, 0x7, 0xe, 0x7, 0xad, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 
    0xb8, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xbb, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 
    0xcc, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xcf, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x7, 0xa, 0xda, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xdd, 0xb, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xe5, 0xa, 
    0xb, 0xc, 0xb, 0xe, 0xb, 0xe8, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xf0, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0xf3, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x5, 0xd, 0xfb, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x105, 0xa, 0xf, 
    0xc, 0xf, 0xe, 0xf, 0x108, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 
    0x11, 0x113, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x117, 0xa, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x7, 0x13, 0x11f, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x122, 0xb, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x129, 
    0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 
    0x136, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x13b, 
    0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x146, 0xa, 0x16, 
    0x3, 0x16, 0x7, 0x16, 0x149, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x14c, 
    0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 
    0x17, 0x153, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x156, 0xb, 0x17, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x15d, 
    0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x7, 0x19, 0x165, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x168, 0xb, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 
    0x16f, 0xa, 0x1a, 0x5, 0x1a, 0x171, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x179, 0xa, 0x1b, 
    0xc, 0x1b, 0xe, 0x1b, 0x17c, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 
    0x1d, 0x187, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 
    0x18c, 0xa, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x18f, 0xa, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x194, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x19a, 0xa, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 
    0x19d, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x1a0, 0xb, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1ac, 0xa, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x5, 0x1f, 0x1b0, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1b7, 0xa, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 
    0x1ba, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x1bd, 0xb, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x7, 0x21, 0x1c7, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x1ca, 0xb, 
    0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x5, 0x22, 0x1d2, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1da, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x1e7, 0xa, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x5, 0x25, 0x1eb, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x1f4, 0xa, 0x26, 
    0xc, 0x26, 0xe, 0x26, 0x1f7, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 
    0x1fb, 0xa, 0x27, 0x3, 0x28, 0x5, 0x28, 0x1fe, 0xa, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x5, 0x29, 0x209, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x211, 0xa, 0x29, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 
    0x21f, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x224, 
    0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x228, 0xa, 0x2b, 0x3, 0x2b, 
    0x5, 0x2b, 0x22b, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x22f, 
    0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x233, 0xa, 0x2b, 0x5, 0x2b, 
    0x235, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x23b, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x7, 0x2d, 0x243, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x246, 
    0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x5, 0x2e, 0x24e, 0xa, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x251, 0xa, 
    0x2e, 0x3, 0x2f, 0x5, 0x2f, 0x254, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x25d, 
    0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x260, 0xb, 0x30, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x5, 0x31, 0x265, 0xa, 0x31, 0x3, 0x32, 0x5, 0x32, 0x268, 
    0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x26c, 0xa, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x7, 
    0x33, 0x275, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 0x278, 0xb, 0x33, 0x3, 
    0x33, 0x2, 0x16, 0x4, 0x6, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x1c, 0x24, 
    0x2a, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x4a, 0x58, 0x5e, 0x64, 0x34, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
    0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 
    0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 
    0x2, 0x5, 0x3, 0x2, 0x2e, 0x33, 0x6, 0x2, 0x7, 0x7, 0xf, 0xf, 0x12, 
    0x12, 0x14, 0x14, 0x3, 0x2, 0x16, 0x17, 0x2, 0x2a5, 0x2, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x73, 0x3, 0x2, 0x2, 0x2, 0x6, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x97, 0x3, 0x2, 0x2, 0x2, 0xa, 0x9b, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0xe, 0xae, 0x3, 0x2, 0x2, 0x2, 0x10, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x14, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x18, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xfe, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x109, 0x3, 0x2, 0x2, 0x2, 0x20, 0x112, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x116, 0x3, 0x2, 0x2, 0x2, 0x24, 0x118, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x128, 0x3, 0x2, 0x2, 0x2, 0x28, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x135, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x154, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x15c, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x32, 0x170, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x172, 0x3, 0x2, 0x2, 0x2, 0x36, 0x17d, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1ab, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x1c1, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1d9, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1e8, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1fa, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x50, 0x210, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x54, 0x234, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x58, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x250, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x253, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x257, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x264, 0x3, 0x2, 0x2, 0x2, 0x62, 0x267, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x66, 0x72, 0x7, 0x36, 
    0x2, 0x2, 0x67, 0x72, 0x7, 0x37, 0x2, 0x2, 0x68, 0x6a, 0x7, 0x39, 0x2, 
    0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x16, 0x2, 0x2, 0x6e, 0x6f, 
    0x5, 0x1c, 0xf, 0x2, 0x6f, 0x70, 0x7, 0x17, 0x2, 0x2, 0x70, 0x72, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x66, 0x3, 0x2, 0x2, 0x2, 0x71, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x69, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x3, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x8, 0x3, 0x1, 0x2, 
    0x74, 0x75, 0x5, 0x2, 0x2, 0x2, 0x75, 0x82, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x77, 0xc, 0x5, 0x2, 0x2, 0x77, 0x79, 0x7, 0x16, 0x2, 0x2, 0x78, 0x7a, 
    0x5, 0x6, 0x4, 0x2, 0x79, 0x78, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x81, 0x7, 0x17, 
    0x2, 0x2, 0x7c, 0x7d, 0xc, 0x4, 0x2, 0x2, 0x7d, 0x81, 0x7, 0x21, 0x2, 
    0x2, 0x7e, 0x7f, 0xc, 0x3, 0x2, 0x2, 0x7f, 0x81, 0x7, 0x23, 0x2, 0x2, 
    0x80, 0x76, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x7e, 0x3, 0x2, 0x2, 0x2, 0x81, 0x84, 0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x8, 0x4, 
    0x1, 0x2, 0x86, 0x87, 0x5, 0x18, 0xd, 0x2, 0x87, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x88, 0x89, 0xc, 0x3, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x2d, 0x2, 0x2, 
    0x8a, 0x8c, 0x5, 0x18, 0xd, 0x2, 0x8b, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x98, 0x5, 0x4, 0x3, 0x2, 0x91, 0x92, 0x7, 0x21, 
    0x2, 0x2, 0x92, 0x98, 0x5, 0x8, 0x5, 0x2, 0x93, 0x94, 0x7, 0x23, 0x2, 
    0x2, 0x94, 0x98, 0x5, 0x8, 0x5, 0x2, 0x95, 0x96, 0x7, 0x29, 0x2, 0x2, 
    0x96, 0x98, 0x5, 0x8, 0x5, 0x2, 0x97, 0x90, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x97, 0x93, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x9, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9c, 0x5, 
    0x8, 0x5, 0x2, 0x9a, 0x9c, 0x7, 0x38, 0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0x9e, 0x8, 0x7, 0x1, 0x2, 0x9e, 0x9f, 0x5, 0xa, 0x6, 0x2, 
    0x9f, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0xc, 0x5, 0x2, 0x2, 0xa1, 
    0xa2, 0x7, 0x24, 0x2, 0x2, 0xa2, 0xaa, 0x5, 0xa, 0x6, 0x2, 0xa3, 0xa4, 
    0xc, 0x4, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x25, 0x2, 0x2, 0xa5, 0xaa, 0x5, 
    0xa, 0x6, 0x2, 0xa6, 0xa7, 0xc, 0x3, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x26, 
    0x2, 0x2, 0xa8, 0xaa, 0x5, 0xa, 0x6, 0x2, 0xa9, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0xa9, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0xad, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 
    0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0xd, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x8, 0x8, 0x1, 0x2, 0xaf, 0xb0, 0x5, 
    0xc, 0x7, 0x2, 0xb0, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0xc, 0x4, 
    0x2, 0x2, 0xb2, 0xb3, 0x7, 0x20, 0x2, 0x2, 0xb3, 0xb8, 0x5, 0xc, 0x7, 
    0x2, 0xb4, 0xb5, 0xc, 0x3, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x22, 0x2, 0x2, 
    0xb6, 0xb8, 0x5, 0xc, 0x7, 0x2, 0xb7, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xb4, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x8, 0x9, 
    0x1, 0x2, 0xbd, 0xbe, 0x5, 0xe, 0x8, 0x2, 0xbe, 0xcd, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xc0, 0xc, 0x6, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0x1c, 0x2, 0x2, 
    0xc1, 0xcc, 0x5, 0xe, 0x8, 0x2, 0xc2, 0xc3, 0xc, 0x5, 0x2, 0x2, 0xc3, 
    0xc4, 0x7, 0x1e, 0x2, 0x2, 0xc4, 0xcc, 0x5, 0xe, 0x8, 0x2, 0xc5, 0xc6, 
    0xc, 0x4, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x1d, 0x2, 0x2, 0xc7, 0xcc, 0x5, 
    0xe, 0x8, 0x2, 0xc8, 0xc9, 0xc, 0x3, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x1f, 
    0x2, 0x2, 0xca, 0xcc, 0x5, 0xe, 0x8, 0x2, 0xcb, 0xbf, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcd, 
    0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x8, 
    0xa, 0x1, 0x2, 0xd1, 0xd2, 0x5, 0x10, 0x9, 0x2, 0xd2, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xd4, 0xc, 0x4, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x34, 0x2, 
    0x2, 0xd5, 0xda, 0x5, 0x10, 0x9, 0x2, 0xd6, 0xd7, 0xc, 0x3, 0x2, 0x2, 
    0xd7, 0xd8, 0x7, 0x35, 0x2, 0x2, 0xd8, 0xda, 0x5, 0x10, 0x9, 0x2, 0xd9, 
    0xd3, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 
    0x2, 0x2, 0x2, 0xdc, 0x13, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0xde, 0xdf, 0x8, 0xb, 0x1, 0x2, 0xdf, 0xe0, 0x5, 0x12, 0xa, 
    0x2, 0xe0, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0xc, 0x3, 0x2, 0x2, 
    0xe2, 0xe3, 0x7, 0x27, 0x2, 0x2, 0xe3, 0xe5, 0x5, 0x12, 0xa, 0x2, 0xe4, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x8, 0xc, 
    0x1, 0x2, 0xea, 0xeb, 0x5, 0x14, 0xb, 0x2, 0xeb, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0xec, 0xed, 0xc, 0x3, 0x2, 0x2, 0xed, 0xee, 0x7, 0x28, 0x2, 0x2, 
    0xee, 0xf0, 0x5, 0x14, 0xb, 0x2, 0xef, 0xec, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0x17, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xf4, 0xfb, 0x5, 0x16, 0xc, 0x2, 0xf5, 0xf6, 0x5, 0x8, 
    0x5, 0x2, 0xf6, 0xf7, 0x5, 0x1a, 0xe, 0x2, 0xf7, 0xf8, 0x5, 0x18, 0xd, 
    0x2, 0xf8, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfb, 0x7, 0x38, 0x2, 0x2, 
    0xfa, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xf9, 0x3, 0x2, 0x2, 0x2, 0xfb, 0x19, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 
    0x9, 0x2, 0x2, 0x2, 0xfd, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x8, 
    0xf, 0x1, 0x2, 0xff, 0x100, 0x5, 0x18, 0xd, 0x2, 0x100, 0x106, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0x102, 0xc, 0x3, 0x2, 0x2, 0x102, 0x103, 0x7, 
    0x2d, 0x2, 0x2, 0x103, 0x105, 0x5, 0x18, 0xd, 0x2, 0x104, 0x101, 0x3, 
    0x2, 0x2, 0x2, 0x105, 0x108, 0x3, 0x2, 0x2, 0x2, 0x106, 0x104, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x16, 
    0xc, 0x2, 0x10a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x5, 0x22, 
    0x12, 0x2, 0x10c, 0x10d, 0x5, 0x24, 0x13, 0x2, 0x10d, 0x10e, 0x7, 0x2c, 
    0x2, 0x2, 0x10e, 0x113, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x5, 0x22, 
    0x12, 0x2, 0x110, 0x111, 0x7, 0x2c, 0x2, 0x2, 0x111, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x112, 0x10f, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0x21, 0x3, 0x2, 0x2, 0x2, 0x114, 0x117, 0x9, 0x3, 0x2, 
    0x2, 0x115, 0x117, 0x7, 0x36, 0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x118, 0x119, 0x8, 0x13, 0x1, 0x2, 0x119, 0x11a, 0x5, 0x26, 0x14, 0x2, 
    0x11a, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0xc, 0x3, 0x2, 0x2, 
    0x11c, 0x11d, 0x7, 0x2d, 0x2, 0x2, 0x11d, 0x11f, 0x5, 0x26, 0x14, 0x2, 
    0x11e, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x122, 0x3, 0x2, 0x2, 0x2, 
    0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 0x2, 
    0x121, 0x25, 0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 0x123, 
    0x129, 0x5, 0x28, 0x15, 0x2, 0x124, 0x125, 0x5, 0x28, 0x15, 0x2, 0x125, 
    0x126, 0x7, 0x2e, 0x2, 0x2, 0x126, 0x127, 0x5, 0x3a, 0x1e, 0x2, 0x127, 
    0x129, 0x3, 0x2, 0x2, 0x2, 0x128, 0x123, 0x3, 0x2, 0x2, 0x2, 0x128, 
    0x124, 0x3, 0x2, 0x2, 0x2, 0x129, 0x27, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 
    0x5, 0x2a, 0x16, 0x2, 0x12b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 
    0x8, 0x16, 0x1, 0x2, 0x12d, 0x136, 0x7, 0x36, 0x2, 0x2, 0x12e, 0x12f, 
    0x7, 0x16, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x28, 0x15, 0x2, 0x130, 0x131, 
    0x7, 0x17, 0x2, 0x2, 0x131, 0x136, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 
    0x7, 0x36, 0x2, 0x2, 0x133, 0x134, 0x7, 0x2b, 0x2, 0x2, 0x134, 0x136, 
    0x7, 0x38, 0x2, 0x2, 0x135, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x135, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x135, 0x132, 0x3, 0x2, 0x2, 0x2, 0x136, 0x14a, 
    0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0xc, 0x6, 0x2, 0x2, 0x138, 0x13a, 
    0x7, 0x18, 0x2, 0x2, 0x139, 0x13b, 0x5, 0x18, 0xd, 0x2, 0x13a, 0x139, 
    0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x13c, 0x149, 0x7, 0x19, 0x2, 0x2, 0x13d, 0x13e, 
    0xc, 0x5, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x16, 0x2, 0x2, 0x13f, 0x140, 
    0x5, 0x2e, 0x18, 0x2, 0x140, 0x141, 0x7, 0x17, 0x2, 0x2, 0x141, 0x149, 
    0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0xc, 0x4, 0x2, 0x2, 0x143, 0x145, 
    0x7, 0x16, 0x2, 0x2, 0x144, 0x146, 0x5, 0x34, 0x1b, 0x2, 0x145, 0x144, 
    0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 
    0x3, 0x2, 0x2, 0x2, 0x147, 0x149, 0x7, 0x17, 0x2, 0x2, 0x148, 0x137, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x148, 0x142, 
    0x3, 0x2, 0x2, 0x2, 0x149, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 
    0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x14c, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x153, 0xa, 
    0x4, 0x2, 0x2, 0x14e, 0x14f, 0x7, 0x16, 0x2, 0x2, 0x14f, 0x150, 0x5, 
    0x2c, 0x17, 0x2, 0x150, 0x151, 0x7, 0x17, 0x2, 0x2, 0x151, 0x153, 0x3, 
    0x2, 0x2, 0x2, 0x152, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x152, 0x14e, 0x3, 
    0x2, 0x2, 0x2, 0x153, 0x156, 0x3, 0x2, 0x2, 0x2, 0x154, 0x152, 0x3, 
    0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x156, 0x154, 0x3, 0x2, 0x2, 0x2, 0x157, 0x15d, 0x5, 0x30, 
    0x19, 0x2, 0x158, 0x159, 0x5, 0x30, 0x19, 0x2, 0x159, 0x15a, 0x7, 0x2d, 
    0x2, 0x2, 0x15a, 0x15b, 0x7, 0x3, 0x2, 0x2, 0x15b, 0x15d, 0x3, 0x2, 
    0x2, 0x2, 0x15c, 0x157, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x158, 0x3, 0x2, 
    0x2, 0x2, 0x15d, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x8, 0x19, 
    0x1, 0x2, 0x15f, 0x160, 0x5, 0x32, 0x1a, 0x2, 0x160, 0x166, 0x3, 0x2, 
    0x2, 0x2, 0x161, 0x162, 0xc, 0x3, 0x2, 0x2, 0x162, 0x163, 0x7, 0x2d, 
    0x2, 0x2, 0x163, 0x165, 0x5, 0x32, 0x1a, 0x2, 0x164, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x165, 0x168, 0x3, 0x2, 0x2, 0x2, 0x166, 0x164, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 0x2, 0x2, 0x167, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x168, 0x166, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x5, 0x22, 0x12, 
    0x2, 0x16a, 0x16b, 0x5, 0x28, 0x15, 0x2, 0x16b, 0x171, 0x3, 0x2, 0x2, 
    0x2, 0x16c, 0x16e, 0x5, 0x22, 0x12, 0x2, 0x16d, 0x16f, 0x5, 0x36, 0x1c, 
    0x2, 0x16e, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 
    0x2, 0x16f, 0x171, 0x3, 0x2, 0x2, 0x2, 0x170, 0x169, 0x3, 0x2, 0x2, 
    0x2, 0x170, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x171, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x172, 0x173, 0x8, 0x1b, 0x1, 0x2, 0x173, 0x174, 0x7, 0x36, 0x2, 0x2, 
    0x174, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0xc, 0x3, 0x2, 0x2, 
    0x176, 0x177, 0x7, 0x2d, 0x2, 0x2, 0x177, 0x179, 0x7, 0x36, 0x2, 0x2, 
    0x178, 0x175, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17c, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 0x2, 0x2, 
    0x17b, 0x35, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17d, 
    0x17e, 0x5, 0x38, 0x1d, 0x2, 0x17e, 0x37, 0x3, 0x2, 0x2, 0x2, 0x17f, 
    0x180, 0x8, 0x1d, 0x1, 0x2, 0x180, 0x181, 0x7, 0x16, 0x2, 0x2, 0x181, 
    0x182, 0x5, 0x36, 0x1c, 0x2, 0x182, 0x183, 0x7, 0x17, 0x2, 0x2, 0x183, 
    0x18f, 0x3, 0x2, 0x2, 0x2, 0x184, 0x186, 0x7, 0x18, 0x2, 0x2, 0x185, 
    0x187, 0x5, 0x18, 0xd, 0x2, 0x186, 0x185, 0x3, 0x2, 0x2, 0x2, 0x186, 
    0x187, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x3, 0x2, 0x2, 0x2, 0x188, 
    0x18f, 0x7, 0x19, 0x2, 0x2, 0x189, 0x18b, 0x7, 0x16, 0x2, 0x2, 0x18a, 
    0x18c, 0x5, 0x2e, 0x18, 0x2, 0x18b, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18b, 
    0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18d, 
    0x18f, 0x7, 0x17, 0x2, 0x2, 0x18e, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x18e, 
    0x184, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18f, 
    0x19e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0xc, 0x4, 0x2, 0x2, 0x191, 
    0x193, 0x7, 0x18, 0x2, 0x2, 0x192, 0x194, 0x5, 0x18, 0xd, 0x2, 0x193, 
    0x192, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x3, 0x2, 0x2, 0x2, 0x194, 
    0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x19d, 0x7, 0x19, 0x2, 0x2, 0x196, 
    0x197, 0xc, 0x3, 0x2, 0x2, 0x197, 0x199, 0x7, 0x16, 0x2, 0x2, 0x198, 
    0x19a, 0x5, 0x2e, 0x18, 0x2, 0x199, 0x198, 0x3, 0x2, 0x2, 0x2, 0x199, 
    0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19b, 
    0x19d, 0x7, 0x17, 0x2, 0x2, 0x19c, 0x190, 0x3, 0x2, 0x2, 0x2, 0x19c, 
    0x196, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x19e, 
    0x19c, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1ac, 
    0x5, 0x18, 0xd, 0x2, 0x1a2, 0x1a3, 0x7, 0x1a, 0x2, 0x2, 0x1a3, 0x1a4, 
    0x5, 0x3c, 0x1f, 0x2, 0x1a4, 0x1a5, 0x7, 0x1b, 0x2, 0x2, 0x1a5, 0x1ac, 
    0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x7, 0x1a, 0x2, 0x2, 0x1a7, 0x1a8, 
    0x5, 0x3c, 0x1f, 0x2, 0x1a8, 0x1a9, 0x7, 0x2d, 0x2, 0x2, 0x1a9, 0x1aa, 
    0x7, 0x1b, 0x2, 0x2, 0x1aa, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1a1, 
    0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1a6, 
    0x3, 0x2, 0x2, 0x2, 0x1ac, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1af, 0x8, 
    0x1f, 0x1, 0x2, 0x1ae, 0x1b0, 0x5, 0x3e, 0x20, 0x2, 0x1af, 0x1ae, 0x3, 
    0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x3, 
    0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x5, 0x3a, 0x1e, 0x2, 0x1b2, 0x1bb, 0x3, 
    0x2, 0x2, 0x2, 0x1b3, 0x1b4, 0xc, 0x3, 0x2, 0x2, 0x1b4, 0x1b6, 0x7, 
    0x2d, 0x2, 0x2, 0x1b5, 0x1b7, 0x5, 0x3e, 0x20, 0x2, 0x1b6, 0x1b5, 0x3, 
    0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x3, 
    0x2, 0x2, 0x2, 0x1b8, 0x1ba, 0x5, 0x3a, 0x1e, 0x2, 0x1b9, 0x1b3, 0x3, 
    0x2, 0x2, 0x2, 0x1ba, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b9, 0x3, 
    0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x1bd, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bf, 0x5, 0x40, 
    0x21, 0x2, 0x1bf, 0x1c0, 0x7, 0x2e, 0x2, 0x2, 0x1c0, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x1c1, 0x1c2, 0x8, 0x21, 0x1, 0x2, 0x1c2, 0x1c3, 0x5, 0x42, 
    0x22, 0x2, 0x1c3, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0xc, 0x3, 
    0x2, 0x2, 0x1c5, 0x1c7, 0x5, 0x42, 0x22, 0x2, 0x1c6, 0x1c4, 0x3, 0x2, 
    0x2, 0x2, 0x1c7, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c6, 0x3, 0x2, 
    0x2, 0x2, 0x1c8, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x1ca, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x7, 0x18, 0x2, 
    0x2, 0x1cc, 0x1cd, 0x5, 0x1e, 0x10, 0x2, 0x1cd, 0x1ce, 0x7, 0x19, 0x2, 
    0x2, 0x1ce, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x7, 0x4, 0x2, 
    0x2, 0x1d0, 0x1d2, 0x7, 0x36, 0x2, 0x2, 0x1d1, 0x1cb, 0x3, 0x2, 0x2, 
    0x2, 0x1d1, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x1d3, 0x1da, 0x5, 0x46, 0x24, 0x2, 0x1d4, 0x1da, 0x5, 0x48, 0x25, 0x2, 
    0x1d5, 0x1da, 0x5, 0x4e, 0x28, 0x2, 0x1d6, 0x1da, 0x5, 0x50, 0x29, 0x2, 
    0x1d7, 0x1da, 0x5, 0x52, 0x2a, 0x2, 0x1d8, 0x1da, 0x5, 0x5a, 0x2e, 0x2, 
    0x1d9, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1d4, 0x3, 0x2, 0x2, 0x2, 
    0x1d9, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1d6, 0x3, 0x2, 0x2, 0x2, 
    0x1d9, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1d8, 0x3, 0x2, 0x2, 0x2, 
    0x1da, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 0x7, 0x36, 0x2, 0x2, 
    0x1dc, 0x1dd, 0x7, 0x2b, 0x2, 0x2, 0x1dd, 0x1e7, 0x5, 0x44, 0x23, 0x2, 
    0x1de, 0x1df, 0x7, 0x6, 0x2, 0x2, 0x1df, 0x1e0, 0x5, 0x1e, 0x10, 0x2, 
    0x1e0, 0x1e1, 0x7, 0x2b, 0x2, 0x2, 0x1e1, 0x1e2, 0x5, 0x44, 0x23, 0x2, 
    0x1e2, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x7, 0x9, 0x2, 0x2, 
    0x1e4, 0x1e5, 0x7, 0x2b, 0x2, 0x2, 0x1e5, 0x1e7, 0x5, 0x44, 0x23, 0x2, 
    0x1e6, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1de, 0x3, 0x2, 0x2, 0x2, 
    0x1e6, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1e8, 
    0x1ea, 0x7, 0x1a, 0x2, 0x2, 0x1e9, 0x1eb, 0x5, 0x4a, 0x26, 0x2, 0x1ea, 
    0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1eb, 
    0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ed, 0x7, 0x1b, 0x2, 0x2, 0x1ed, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x8, 0x26, 0x1, 0x2, 0x1ef, 
    0x1f0, 0x5, 0x4c, 0x27, 0x2, 0x1f0, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
    0x1f2, 0xc, 0x3, 0x2, 0x2, 0x1f2, 0x1f4, 0x5, 0x4c, 0x27, 0x2, 0x1f3, 
    0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
    0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f6, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1fb, 
    0x5, 0x44, 0x23, 0x2, 0x1f9, 0x1fb, 0x5, 0x20, 0x11, 0x2, 0x1fa, 0x1f8, 
    0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x1fc, 0x1fe, 0x5, 0x1c, 0xf, 0x2, 0x1fd, 0x1fc, 0x3, 
    0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x3, 
    0x2, 0x2, 0x2, 0x1ff, 0x200, 0x7, 0x2c, 0x2, 0x2, 0x200, 0x4f, 0x3, 
    0x2, 0x2, 0x2, 0x201, 0x202, 0x7, 0xe, 0x2, 0x2, 0x202, 0x203, 0x7, 
    0x16, 0x2, 0x2, 0x203, 0x204, 0x5, 0x1c, 0xf, 0x2, 0x204, 0x205, 0x7, 
    0x17, 0x2, 0x2, 0x205, 0x208, 0x5, 0x44, 0x23, 0x2, 0x206, 0x207, 0x7, 
    0xb, 0x2, 0x2, 0x207, 0x209, 0x5, 0x44, 0x23, 0x2, 0x208, 0x206, 0x3, 
    0x2, 0x2, 0x2, 0x208, 0x209, 0x3, 0x2, 0x2, 0x2, 0x209, 0x211, 0x3, 
    0x2, 0x2, 0x2, 0x20a, 0x20b, 0x7, 0x13, 0x2, 0x2, 0x20b, 0x20c, 0x7, 
    0x16, 0x2, 0x2, 0x20c, 0x20d, 0x5, 0x1c, 0xf, 0x2, 0x20d, 0x20e, 0x7, 
    0x17, 0x2, 0x2, 0x20e, 0x20f, 0x5, 0x44, 0x23, 0x2, 0x20f, 0x211, 0x3, 
    0x2, 0x2, 0x2, 0x210, 0x201, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20a, 0x3, 
    0x2, 0x2, 0x2, 0x211, 0x51, 0x3, 0x2, 0x2, 0x2, 0x212, 0x213, 0x7, 0x15, 
    0x2, 0x2, 0x213, 0x214, 0x7, 0x16, 0x2, 0x2, 0x214, 0x215, 0x5, 0x1c, 
    0xf, 0x2, 0x215, 0x216, 0x7, 0x17, 0x2, 0x2, 0x216, 0x217, 0x5, 0x44, 
    0x23, 0x2, 0x217, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x218, 0x219, 0x7, 0xc, 
    0x2, 0x2, 0x219, 0x21a, 0x7, 0x16, 0x2, 0x2, 0x21a, 0x21b, 0x5, 0x54, 
    0x2b, 0x2, 0x21b, 0x21c, 0x7, 0x17, 0x2, 0x2, 0x21c, 0x21d, 0x5, 0x44, 
    0x23, 0x2, 0x21d, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x212, 0x3, 0x2, 
    0x2, 0x2, 0x21e, 0x218, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x220, 0x221, 0x5, 0x56, 0x2c, 0x2, 0x221, 0x223, 0x7, 0x2c, 0x2, 
    0x2, 0x222, 0x224, 0x5, 0x58, 0x2d, 0x2, 0x223, 0x222, 0x3, 0x2, 0x2, 
    0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x3, 0x2, 0x2, 
    0x2, 0x225, 0x227, 0x7, 0x2c, 0x2, 0x2, 0x226, 0x228, 0x5, 0x58, 0x2d, 
    0x2, 0x227, 0x226, 0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 0x3, 0x2, 0x2, 
    0x2, 0x228, 0x235, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22b, 0x5, 0x1c, 0xf, 
    0x2, 0x22a, 0x229, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 0x3, 0x2, 0x2, 
    0x2, 0x22b, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22e, 0x7, 0x2c, 0x2, 
    0x2, 0x22d, 0x22f, 0x5, 0x58, 0x2d, 0x2, 0x22e, 0x22d, 0x3, 0x2, 0x2, 
    0x2, 0x22e, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 0x3, 0x2, 0x2, 
    0x2, 0x230, 0x232, 0x7, 0x2c, 0x2, 0x2, 0x231, 0x233, 0x5, 0x58, 0x2d, 
    0x2, 0x232, 0x231, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 0x3, 0x2, 0x2, 
    0x2, 0x233, 0x235, 0x3, 0x2, 0x2, 0x2, 0x234, 0x220, 0x3, 0x2, 0x2, 
    0x2, 0x234, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x235, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x236, 0x237, 0x5, 0x22, 0x12, 0x2, 0x237, 0x238, 0x5, 0x24, 0x13, 0x2, 
    0x238, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23b, 0x5, 0x22, 0x12, 0x2, 
    0x23a, 0x236, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x239, 0x3, 0x2, 0x2, 0x2, 
    0x23b, 0x57, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23d, 0x8, 0x2d, 0x1, 0x2, 
    0x23d, 0x23e, 0x5, 0x18, 0xd, 0x2, 0x23e, 0x244, 0x3, 0x2, 0x2, 0x2, 
    0x23f, 0x240, 0xc, 0x3, 0x2, 0x2, 0x240, 0x241, 0x7, 0x2d, 0x2, 0x2, 
    0x241, 0x243, 0x5, 0x18, 0xd, 0x2, 0x242, 0x23f, 0x3, 0x2, 0x2, 0x2, 
    0x243, 0x246, 0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 
    0x244, 0x245, 0x3, 0x2, 0x2, 0x2, 0x245, 0x59, 0x3, 0x2, 0x2, 0x2, 0x246, 
    0x244, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 0x7, 0x8, 0x2, 0x2, 0x248, 
    0x251, 0x7, 0x2c, 0x2, 0x2, 0x249, 0x24a, 0x7, 0x5, 0x2, 0x2, 0x24a, 
    0x251, 0x7, 0x2c, 0x2, 0x2, 0x24b, 0x24d, 0x7, 0x11, 0x2, 0x2, 0x24c, 
    0x24e, 0x5, 0x1c, 0xf, 0x2, 0x24d, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24d, 
    0x24e, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24f, 
    0x251, 0x7, 0x2c, 0x2, 0x2, 0x250, 0x247, 0x3, 0x2, 0x2, 0x2, 0x250, 
    0x249, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x251, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x252, 0x254, 0x5, 0x5e, 0x30, 0x2, 0x253, 
    0x252, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x3, 0x2, 0x2, 0x2, 0x254, 
    0x255, 0x3, 0x2, 0x2, 0x2, 0x255, 0x256, 0x7, 0x2, 0x2, 0x3, 0x256, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 0x8, 0x30, 0x1, 0x2, 0x258, 
    0x259, 0x5, 0x60, 0x31, 0x2, 0x259, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x25a, 
    0x25b, 0xc, 0x3, 0x2, 0x2, 0x25b, 0x25d, 0x5, 0x60, 0x31, 0x2, 0x25c, 
    0x25a, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x260, 0x3, 0x2, 0x2, 0x2, 0x25e, 
    0x25c, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x25f, 
    0x5f, 0x3, 0x2, 0x2, 0x2, 0x260, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x261, 0x265, 
    0x5, 0x62, 0x32, 0x2, 0x262, 0x265, 0x5, 0x20, 0x11, 0x2, 0x263, 0x265, 
    0x7, 0x2c, 0x2, 0x2, 0x264, 0x261, 0x3, 0x2, 0x2, 0x2, 0x264, 0x262, 
    0x3, 0x2, 0x2, 0x2, 0x264, 0x263, 0x3, 0x2, 0x2, 0x2, 0x265, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x266, 0x268, 0x5, 0x22, 0x12, 0x2, 0x267, 0x266, 0x3, 
    0x2, 0x2, 0x2, 0x267, 0x268, 0x3, 0x2, 0x2, 0x2, 0x268, 0x269, 0x3, 
    0x2, 0x2, 0x2, 0x269, 0x26b, 0x5, 0x28, 0x15, 0x2, 0x26a, 0x26c, 0x5, 
    0x64, 0x33, 0x2, 0x26b, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 0x3, 
    0x2, 0x2, 0x2, 0x26c, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x5, 
    0x48, 0x25, 0x2, 0x26e, 0x63, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x8, 
    0x33, 0x1, 0x2, 0x270, 0x271, 0x5, 0x20, 0x11, 0x2, 0x271, 0x276, 0x3, 
    0x2, 0x2, 0x2, 0x272, 0x273, 0xc, 0x3, 0x2, 0x2, 0x273, 0x275, 0x5, 
    0x20, 0x11, 0x2, 0x274, 0x272, 0x3, 0x2, 0x2, 0x2, 0x275, 0x278, 0x3, 
    0x2, 0x2, 0x2, 0x276, 0x274, 0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x3, 
    0x2, 0x2, 0x2, 0x277, 0x65, 0x3, 0x2, 0x2, 0x2, 0x278, 0x276, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x6b, 0x71, 0x79, 0x80, 0x82, 0x8d, 0x97, 0x9b, 0xa9, 
    0xab, 0xb7, 0xb9, 0xcb, 0xcd, 0xd9, 0xdb, 0xe6, 0xf1, 0xfa, 0x106, 0x112, 
    0x116, 0x120, 0x128, 0x135, 0x13a, 0x145, 0x148, 0x14a, 0x152, 0x154, 
    0x15c, 0x166, 0x16e, 0x170, 0x17a, 0x186, 0x18b, 0x18e, 0x193, 0x199, 
    0x19c, 0x19e, 0x1ab, 0x1af, 0x1b6, 0x1bb, 0x1c8, 0x1d1, 0x1d9, 0x1e6, 
    0x1ea, 0x1f5, 0x1fa, 0x1fd, 0x208, 0x210, 0x21e, 0x223, 0x227, 0x22a, 
    0x22e, 0x232, 0x234, 0x23a, 0x244, 0x24d, 0x250, 0x253, 0x25e, 0x264, 
    0x267, 0x26b, 0x276, 
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
