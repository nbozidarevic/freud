
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
    setState(145);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(134);
        match(SimpleCParser::Identifier);
        break;
      }

      case SimpleCParser::Constant: {
        enterOuterAlt(_localctx, 2);
        setState(135);
        match(SimpleCParser::Constant);
        break;
      }

      case SimpleCParser::StringLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(137); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(136);
                  match(SimpleCParser::StringLiteral);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(139); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case SimpleCParser::LeftParen: {
        enterOuterAlt(_localctx, 4);
        setState(141);
        match(SimpleCParser::LeftParen);
        setState(142);
        expression(0);
        setState(143);
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
    setState(148);
    primaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(162);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(160);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(150);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(151);
          match(SimpleCParser::LeftParen);
          setState(153);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 45) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
            | (1ULL << (SimpleCParser::PlusPlus - 45))
            | (1ULL << (SimpleCParser::MinusMinus - 45))
            | (1ULL << (SimpleCParser::Not - 45))
            | (1ULL << (SimpleCParser::Identifier - 45))
            | (1ULL << (SimpleCParser::Constant - 45))
            | (1ULL << (SimpleCParser::DigitSequence - 45))
            | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
            setState(152);
            argumentExpressionList(0);
          }
          setState(155);
          match(SimpleCParser::RightParen);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(156);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(157);
          match(SimpleCParser::PlusPlus);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(158);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(159);
          match(SimpleCParser::MinusMinus);
          break;
        }

        } 
      }
      setState(164);
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
    setState(166);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(173);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentExpressionListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArgumentExpressionList);
        setState(168);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(169);
        match(SimpleCParser::Comma);
        setState(170);
        assignmentExpression(); 
      }
      setState(175);
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
    setState(183);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::LeftParen:
      case SimpleCParser::Identifier:
      case SimpleCParser::Constant:
      case SimpleCParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(176);
        postfixExpression(0);
        break;
      }

      case SimpleCParser::PlusPlus: {
        enterOuterAlt(_localctx, 2);
        setState(177);
        match(SimpleCParser::PlusPlus);
        setState(178);
        unaryExpression();
        break;
      }

      case SimpleCParser::MinusMinus: {
        enterOuterAlt(_localctx, 3);
        setState(179);
        match(SimpleCParser::MinusMinus);
        setState(180);
        unaryExpression();
        break;
      }

      case SimpleCParser::Not: {
        enterOuterAlt(_localctx, 4);
        setState(181);
        match(SimpleCParser::Not);
        setState(182);
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
    setState(187);
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
        setState(185);
        unaryExpression();
        break;
      }

      case SimpleCParser::DigitSequence: {
        enterOuterAlt(_localctx, 2);
        setState(186);
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
    setState(190);
    simpleExpression();
    _ctx->stop = _input->LT(-1);
    setState(203);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(201);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(192);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(193);
          match(SimpleCParser::Star);
          setState(194);
          simpleExpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(195);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(196);
          match(SimpleCParser::Div);
          setState(197);
          simpleExpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(198);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(199);
          match(SimpleCParser::Mod);
          setState(200);
          simpleExpression();
          break;
        }

        } 
      }
      setState(205);
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
    setState(207);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(217);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(215);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(209);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(210);
          match(SimpleCParser::Plus);
          setState(211);
          multiplicativeExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(212);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(213);
          match(SimpleCParser::Minus);
          setState(214);
          multiplicativeExpression(0);
          break;
        }

        } 
      }
      setState(219);
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
    setState(221);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(237);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(235);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(223);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(224);
          match(SimpleCParser::Less);
          setState(225);
          additiveExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(226);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(227);
          match(SimpleCParser::Greater);
          setState(228);
          additiveExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(229);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(230);
          match(SimpleCParser::LessEqual);
          setState(231);
          additiveExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(232);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(233);
          match(SimpleCParser::GreaterEqual);
          setState(234);
          additiveExpression(0);
          break;
        }

        } 
      }
      setState(239);
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
    setState(241);
    relationalExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(251);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(249);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(243);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(244);
          match(SimpleCParser::Equal);
          setState(245);
          relationalExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(246);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(247);
          match(SimpleCParser::NotEqual);
          setState(248);
          relationalExpression(0);
          break;
        }

        } 
      }
      setState(253);
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
    setState(255);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(262);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
        setState(257);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(258);
        match(SimpleCParser::AndAnd);
        setState(259);
        equalityExpression(0); 
      }
      setState(264);
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
    setState(266);
    logicalAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(273);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
        setState(268);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(269);
        match(SimpleCParser::OrOr);
        setState(270);
        logicalAndExpression(0); 
      }
      setState(275);
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
    setState(282);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(276);
      logicalOrExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(277);
      unaryExpression();
      setState(278);
      assignmentOperator();
      setState(279);
      assignmentExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(281);
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
    setState(284);
    _la = _input->LA(1);
    if (!(((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (SimpleCParser::Assign - 75))
      | (1ULL << (SimpleCParser::StarAssign - 75))
      | (1ULL << (SimpleCParser::DivAssign - 75))
      | (1ULL << (SimpleCParser::ModAssign - 75))
      | (1ULL << (SimpleCParser::PlusAssign - 75))
      | (1ULL << (SimpleCParser::MinusAssign - 75)))) != 0))) {
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
    setState(287);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(294);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(289);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(290);
        match(SimpleCParser::Comma);
        setState(291);
        assignmentExpression(); 
      }
      setState(296);
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
    setState(297);
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

SimpleCParser::DeclarationSpecifiersContext* SimpleCParser::DeclarationContext::declarationSpecifiers() {
  return getRuleContext<SimpleCParser::DeclarationSpecifiersContext>(0);
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
    setState(306);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(299);
      declarationSpecifiers();
      setState(300);
      initDeclaratorList(0);
      setState(301);
      match(SimpleCParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(303);
      declarationSpecifiers();
      setState(304);
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

//----------------- DeclarationSpecifiersContext ------------------------------------------------------------------

SimpleCParser::DeclarationSpecifiersContext::DeclarationSpecifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleCParser::DeclarationSpecifierContext *> SimpleCParser::DeclarationSpecifiersContext::declarationSpecifier() {
  return getRuleContexts<SimpleCParser::DeclarationSpecifierContext>();
}

SimpleCParser::DeclarationSpecifierContext* SimpleCParser::DeclarationSpecifiersContext::declarationSpecifier(size_t i) {
  return getRuleContext<SimpleCParser::DeclarationSpecifierContext>(i);
}


size_t SimpleCParser::DeclarationSpecifiersContext::getRuleIndex() const {
  return SimpleCParser::RuleDeclarationSpecifiers;
}

void SimpleCParser::DeclarationSpecifiersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifiers(this);
}

void SimpleCParser::DeclarationSpecifiersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifiers(this);
}


antlrcpp::Any SimpleCParser::DeclarationSpecifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::DeclarationSpecifiersContext* SimpleCParser::declarationSpecifiers() {
  DeclarationSpecifiersContext *_localctx = _tracker.createInstance<DeclarationSpecifiersContext>(_ctx, getState());
  enterRule(_localctx, 32, SimpleCParser::RuleDeclarationSpecifiers);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(309); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(308);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(311); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifiers2Context ------------------------------------------------------------------

SimpleCParser::DeclarationSpecifiers2Context::DeclarationSpecifiers2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleCParser::DeclarationSpecifierContext *> SimpleCParser::DeclarationSpecifiers2Context::declarationSpecifier() {
  return getRuleContexts<SimpleCParser::DeclarationSpecifierContext>();
}

SimpleCParser::DeclarationSpecifierContext* SimpleCParser::DeclarationSpecifiers2Context::declarationSpecifier(size_t i) {
  return getRuleContext<SimpleCParser::DeclarationSpecifierContext>(i);
}


size_t SimpleCParser::DeclarationSpecifiers2Context::getRuleIndex() const {
  return SimpleCParser::RuleDeclarationSpecifiers2;
}

void SimpleCParser::DeclarationSpecifiers2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifiers2(this);
}

void SimpleCParser::DeclarationSpecifiers2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifiers2(this);
}


antlrcpp::Any SimpleCParser::DeclarationSpecifiers2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers2(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::DeclarationSpecifiers2Context* SimpleCParser::declarationSpecifiers2() {
  DeclarationSpecifiers2Context *_localctx = _tracker.createInstance<DeclarationSpecifiers2Context>(_ctx, getState());
  enterRule(_localctx, 34, SimpleCParser::RuleDeclarationSpecifiers2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(314); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(313);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(316); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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

SimpleCParser::TypeSpecifierContext* SimpleCParser::DeclarationSpecifierContext::typeSpecifier() {
  return getRuleContext<SimpleCParser::TypeSpecifierContext>(0);
}

SimpleCParser::TypeQualifierContext* SimpleCParser::DeclarationSpecifierContext::typeQualifier() {
  return getRuleContext<SimpleCParser::TypeQualifierContext>(0);
}

SimpleCParser::AlignmentSpecifierContext* SimpleCParser::DeclarationSpecifierContext::alignmentSpecifier() {
  return getRuleContext<SimpleCParser::AlignmentSpecifierContext>(0);
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
  enterRule(_localctx, 36, SimpleCParser::RuleDeclarationSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(321);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::Char:
      case SimpleCParser::Int:
      case SimpleCParser::Short:
      case SimpleCParser::Void:
      case SimpleCParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(318);
        typeSpecifier();
        break;
      }

      case SimpleCParser::Const:
      case SimpleCParser::Restrict:
      case SimpleCParser::Volatile:
      case SimpleCParser::Atomic: {
        enterOuterAlt(_localctx, 2);
        setState(319);
        typeQualifier();
        break;
      }

      case SimpleCParser::Alignas: {
        enterOuterAlt(_localctx, 3);
        setState(320);
        alignmentSpecifier();
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
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, SimpleCParser::RuleInitDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(324);
    initDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(331);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitDeclaratorList);
        setState(326);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(327);
        match(SimpleCParser::Comma);
        setState(328);
        initDeclarator(); 
      }
      setState(333);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
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
  enterRule(_localctx, 40, SimpleCParser::RuleInitDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(339);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(334);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(335);
      declarator();
      setState(336);
      match(SimpleCParser::Assign);
      setState(337);
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

//----------------- TypeSpecifierContext ------------------------------------------------------------------

SimpleCParser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::TypedefNameContext* SimpleCParser::TypeSpecifierContext::typedefName() {
  return getRuleContext<SimpleCParser::TypedefNameContext>(0);
}


size_t SimpleCParser::TypeSpecifierContext::getRuleIndex() const {
  return SimpleCParser::RuleTypeSpecifier;
}

void SimpleCParser::TypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpecifier(this);
}

void SimpleCParser::TypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpecifier(this);
}


antlrcpp::Any SimpleCParser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::TypeSpecifierContext* SimpleCParser::typeSpecifier() {
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 42, SimpleCParser::RuleTypeSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(343);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::Char:
      case SimpleCParser::Int:
      case SimpleCParser::Short:
      case SimpleCParser::Void: {
        enterOuterAlt(_localctx, 1);
        setState(341);
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
        setState(342);
        typedefName();
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

//----------------- StructDeclarationListContext ------------------------------------------------------------------

SimpleCParser::StructDeclarationListContext::StructDeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::StructDeclarationContext* SimpleCParser::StructDeclarationListContext::structDeclaration() {
  return getRuleContext<SimpleCParser::StructDeclarationContext>(0);
}

SimpleCParser::StructDeclarationListContext* SimpleCParser::StructDeclarationListContext::structDeclarationList() {
  return getRuleContext<SimpleCParser::StructDeclarationListContext>(0);
}


size_t SimpleCParser::StructDeclarationListContext::getRuleIndex() const {
  return SimpleCParser::RuleStructDeclarationList;
}

void SimpleCParser::StructDeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclarationList(this);
}

void SimpleCParser::StructDeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclarationList(this);
}


antlrcpp::Any SimpleCParser::StructDeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitStructDeclarationList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::StructDeclarationListContext* SimpleCParser::structDeclarationList() {
   return structDeclarationList(0);
}

SimpleCParser::StructDeclarationListContext* SimpleCParser::structDeclarationList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::StructDeclarationListContext *_localctx = _tracker.createInstance<StructDeclarationListContext>(_ctx, parentState);
  SimpleCParser::StructDeclarationListContext *previousContext = _localctx;
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, SimpleCParser::RuleStructDeclarationList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(346);
    structDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(352);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StructDeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStructDeclarationList);
        setState(348);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(349);
        structDeclaration(); 
      }
      setState(354);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

SimpleCParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::SpecifierQualifierListContext* SimpleCParser::StructDeclarationContext::specifierQualifierList() {
  return getRuleContext<SimpleCParser::SpecifierQualifierListContext>(0);
}

SimpleCParser::StructDeclaratorListContext* SimpleCParser::StructDeclarationContext::structDeclaratorList() {
  return getRuleContext<SimpleCParser::StructDeclaratorListContext>(0);
}


size_t SimpleCParser::StructDeclarationContext::getRuleIndex() const {
  return SimpleCParser::RuleStructDeclaration;
}

void SimpleCParser::StructDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaration(this);
}

void SimpleCParser::StructDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaration(this);
}


antlrcpp::Any SimpleCParser::StructDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitStructDeclaration(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::StructDeclarationContext* SimpleCParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 46, SimpleCParser::RuleStructDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    specifierQualifierList();
    setState(357);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 45) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
      | (1ULL << (SimpleCParser::Colon - 45))
      | (1ULL << (SimpleCParser::Identifier - 45)))) != 0)) {
      setState(356);
      structDeclaratorList(0);
    }
    setState(359);
    match(SimpleCParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SpecifierQualifierListContext ------------------------------------------------------------------

SimpleCParser::SpecifierQualifierListContext::SpecifierQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::TypeSpecifierContext* SimpleCParser::SpecifierQualifierListContext::typeSpecifier() {
  return getRuleContext<SimpleCParser::TypeSpecifierContext>(0);
}

SimpleCParser::SpecifierQualifierListContext* SimpleCParser::SpecifierQualifierListContext::specifierQualifierList() {
  return getRuleContext<SimpleCParser::SpecifierQualifierListContext>(0);
}

SimpleCParser::TypeQualifierContext* SimpleCParser::SpecifierQualifierListContext::typeQualifier() {
  return getRuleContext<SimpleCParser::TypeQualifierContext>(0);
}


size_t SimpleCParser::SpecifierQualifierListContext::getRuleIndex() const {
  return SimpleCParser::RuleSpecifierQualifierList;
}

void SimpleCParser::SpecifierQualifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecifierQualifierList(this);
}

void SimpleCParser::SpecifierQualifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecifierQualifierList(this);
}


antlrcpp::Any SimpleCParser::SpecifierQualifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitSpecifierQualifierList(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::SpecifierQualifierListContext* SimpleCParser::specifierQualifierList() {
  SpecifierQualifierListContext *_localctx = _tracker.createInstance<SpecifierQualifierListContext>(_ctx, getState());
  enterRule(_localctx, 48, SimpleCParser::RuleSpecifierQualifierList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(369);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::Char:
      case SimpleCParser::Int:
      case SimpleCParser::Short:
      case SimpleCParser::Void:
      case SimpleCParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(361);
        typeSpecifier();
        setState(363);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
        case 1: {
          setState(362);
          specifierQualifierList();
          break;
        }

        }
        break;
      }

      case SimpleCParser::Const:
      case SimpleCParser::Restrict:
      case SimpleCParser::Volatile:
      case SimpleCParser::Atomic: {
        enterOuterAlt(_localctx, 2);
        setState(365);
        typeQualifier();
        setState(367);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
        case 1: {
          setState(366);
          specifierQualifierList();
          break;
        }

        }
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

//----------------- StructDeclaratorListContext ------------------------------------------------------------------

SimpleCParser::StructDeclaratorListContext::StructDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::StructDeclaratorContext* SimpleCParser::StructDeclaratorListContext::structDeclarator() {
  return getRuleContext<SimpleCParser::StructDeclaratorContext>(0);
}

SimpleCParser::StructDeclaratorListContext* SimpleCParser::StructDeclaratorListContext::structDeclaratorList() {
  return getRuleContext<SimpleCParser::StructDeclaratorListContext>(0);
}


size_t SimpleCParser::StructDeclaratorListContext::getRuleIndex() const {
  return SimpleCParser::RuleStructDeclaratorList;
}

void SimpleCParser::StructDeclaratorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaratorList(this);
}

void SimpleCParser::StructDeclaratorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaratorList(this);
}


antlrcpp::Any SimpleCParser::StructDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitStructDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::StructDeclaratorListContext* SimpleCParser::structDeclaratorList() {
   return structDeclaratorList(0);
}

SimpleCParser::StructDeclaratorListContext* SimpleCParser::structDeclaratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::StructDeclaratorListContext *_localctx = _tracker.createInstance<StructDeclaratorListContext>(_ctx, parentState);
  SimpleCParser::StructDeclaratorListContext *previousContext = _localctx;
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, SimpleCParser::RuleStructDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(372);
    structDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(379);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StructDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStructDeclaratorList);
        setState(374);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(375);
        match(SimpleCParser::Comma);
        setState(376);
        structDeclarator(); 
      }
      setState(381);
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

//----------------- StructDeclaratorContext ------------------------------------------------------------------

SimpleCParser::StructDeclaratorContext::StructDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::DeclaratorContext* SimpleCParser::StructDeclaratorContext::declarator() {
  return getRuleContext<SimpleCParser::DeclaratorContext>(0);
}

SimpleCParser::ConstantExpressionContext* SimpleCParser::StructDeclaratorContext::constantExpression() {
  return getRuleContext<SimpleCParser::ConstantExpressionContext>(0);
}


size_t SimpleCParser::StructDeclaratorContext::getRuleIndex() const {
  return SimpleCParser::RuleStructDeclarator;
}

void SimpleCParser::StructDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclarator(this);
}

void SimpleCParser::StructDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclarator(this);
}


antlrcpp::Any SimpleCParser::StructDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitStructDeclarator(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::StructDeclaratorContext* SimpleCParser::structDeclarator() {
  StructDeclaratorContext *_localctx = _tracker.createInstance<StructDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 52, SimpleCParser::RuleStructDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(388);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(382);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(384);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SimpleCParser::LeftParen

      || _la == SimpleCParser::Identifier) {
        setState(383);
        declarator();
      }
      setState(386);
      match(SimpleCParser::Colon);
      setState(387);
      constantExpression();
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

//----------------- TypeQualifierContext ------------------------------------------------------------------

SimpleCParser::TypeQualifierContext::TypeQualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SimpleCParser::TypeQualifierContext::getRuleIndex() const {
  return SimpleCParser::RuleTypeQualifier;
}

void SimpleCParser::TypeQualifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeQualifier(this);
}

void SimpleCParser::TypeQualifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeQualifier(this);
}


antlrcpp::Any SimpleCParser::TypeQualifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitTypeQualifier(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::TypeQualifierContext* SimpleCParser::typeQualifier() {
  TypeQualifierContext *_localctx = _tracker.createInstance<TypeQualifierContext>(_ctx, getState());
  enterRule(_localctx, 54, SimpleCParser::RuleTypeQualifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::Const)
      | (1ULL << SimpleCParser::Restrict)
      | (1ULL << SimpleCParser::Volatile)
      | (1ULL << SimpleCParser::Atomic))) != 0))) {
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

//----------------- AlignmentSpecifierContext ------------------------------------------------------------------

SimpleCParser::AlignmentSpecifierContext::AlignmentSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::TypeNameContext* SimpleCParser::AlignmentSpecifierContext::typeName() {
  return getRuleContext<SimpleCParser::TypeNameContext>(0);
}

SimpleCParser::ConstantExpressionContext* SimpleCParser::AlignmentSpecifierContext::constantExpression() {
  return getRuleContext<SimpleCParser::ConstantExpressionContext>(0);
}


size_t SimpleCParser::AlignmentSpecifierContext::getRuleIndex() const {
  return SimpleCParser::RuleAlignmentSpecifier;
}

void SimpleCParser::AlignmentSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlignmentSpecifier(this);
}

void SimpleCParser::AlignmentSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlignmentSpecifier(this);
}


antlrcpp::Any SimpleCParser::AlignmentSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitAlignmentSpecifier(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::AlignmentSpecifierContext* SimpleCParser::alignmentSpecifier() {
  AlignmentSpecifierContext *_localctx = _tracker.createInstance<AlignmentSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 56, SimpleCParser::RuleAlignmentSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(402);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(392);
      match(SimpleCParser::Alignas);
      setState(393);
      match(SimpleCParser::LeftParen);
      setState(394);
      typeName();
      setState(395);
      match(SimpleCParser::RightParen);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(397);
      match(SimpleCParser::Alignas);
      setState(398);
      match(SimpleCParser::LeftParen);
      setState(399);
      constantExpression();
      setState(400);
      match(SimpleCParser::RightParen);
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

std::vector<SimpleCParser::GccDeclaratorExtensionContext *> SimpleCParser::DeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<SimpleCParser::GccDeclaratorExtensionContext>();
}

SimpleCParser::GccDeclaratorExtensionContext* SimpleCParser::DeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<SimpleCParser::GccDeclaratorExtensionContext>(i);
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
  enterRule(_localctx, 58, SimpleCParser::RuleDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(404);
    directDeclarator(0);
    setState(408);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(405);
        gccDeclaratorExtension(); 
      }
      setState(410);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
   
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

SimpleCParser::TypeQualifierListContext* SimpleCParser::DirectDeclaratorContext::typeQualifierList() {
  return getRuleContext<SimpleCParser::TypeQualifierListContext>(0);
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
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, SimpleCParser::RuleDirectDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(420);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      setState(412);
      match(SimpleCParser::Identifier);
      break;
    }

    case 2: {
      setState(413);
      match(SimpleCParser::LeftParen);
      setState(414);
      declarator();
      setState(415);
      match(SimpleCParser::RightParen);
      break;
    }

    case 3: {
      setState(417);
      match(SimpleCParser::Identifier);
      setState(418);
      match(SimpleCParser::Colon);
      setState(419);
      match(SimpleCParser::DigitSequence);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(467);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(465);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(422);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(423);
          match(SimpleCParser::LeftBracket);
          setState(425);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SimpleCParser::Const)
            | (1ULL << SimpleCParser::Restrict)
            | (1ULL << SimpleCParser::Volatile)
            | (1ULL << SimpleCParser::Atomic))) != 0)) {
            setState(424);
            typeQualifierList(0);
          }
          setState(428);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 45) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
            | (1ULL << (SimpleCParser::PlusPlus - 45))
            | (1ULL << (SimpleCParser::MinusMinus - 45))
            | (1ULL << (SimpleCParser::Not - 45))
            | (1ULL << (SimpleCParser::Identifier - 45))
            | (1ULL << (SimpleCParser::Constant - 45))
            | (1ULL << (SimpleCParser::DigitSequence - 45))
            | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
            setState(427);
            assignmentExpression();
          }
          setState(430);
          match(SimpleCParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(431);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(432);
          match(SimpleCParser::LeftBracket);
          setState(433);
          match(SimpleCParser::Static);
          setState(435);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SimpleCParser::Const)
            | (1ULL << SimpleCParser::Restrict)
            | (1ULL << SimpleCParser::Volatile)
            | (1ULL << SimpleCParser::Atomic))) != 0)) {
            setState(434);
            typeQualifierList(0);
          }
          setState(437);
          assignmentExpression();
          setState(438);
          match(SimpleCParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(440);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(441);
          match(SimpleCParser::LeftBracket);
          setState(442);
          typeQualifierList(0);
          setState(443);
          match(SimpleCParser::Static);
          setState(444);
          assignmentExpression();
          setState(445);
          match(SimpleCParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(447);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(448);
          match(SimpleCParser::LeftBracket);
          setState(450);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SimpleCParser::Const)
            | (1ULL << SimpleCParser::Restrict)
            | (1ULL << SimpleCParser::Volatile)
            | (1ULL << SimpleCParser::Atomic))) != 0)) {
            setState(449);
            typeQualifierList(0);
          }
          setState(452);
          match(SimpleCParser::Star);
          setState(453);
          match(SimpleCParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(454);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(455);
          match(SimpleCParser::LeftParen);
          setState(456);
          parameterTypeList();
          setState(457);
          match(SimpleCParser::RightParen);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(459);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(460);
          match(SimpleCParser::LeftParen);
          setState(462);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SimpleCParser::Identifier) {
            setState(461);
            identifierList(0);
          }
          setState(464);
          match(SimpleCParser::RightParen);
          break;
        }

        } 
      }
      setState(469);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- GccDeclaratorExtensionContext ------------------------------------------------------------------

SimpleCParser::GccDeclaratorExtensionContext::GccDeclaratorExtensionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SimpleCParser::GccDeclaratorExtensionContext::StringLiteral() {
  return getTokens(SimpleCParser::StringLiteral);
}

tree::TerminalNode* SimpleCParser::GccDeclaratorExtensionContext::StringLiteral(size_t i) {
  return getToken(SimpleCParser::StringLiteral, i);
}

SimpleCParser::GccAttributeSpecifierContext* SimpleCParser::GccDeclaratorExtensionContext::gccAttributeSpecifier() {
  return getRuleContext<SimpleCParser::GccAttributeSpecifierContext>(0);
}


size_t SimpleCParser::GccDeclaratorExtensionContext::getRuleIndex() const {
  return SimpleCParser::RuleGccDeclaratorExtension;
}

void SimpleCParser::GccDeclaratorExtensionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccDeclaratorExtension(this);
}

void SimpleCParser::GccDeclaratorExtensionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccDeclaratorExtension(this);
}


antlrcpp::Any SimpleCParser::GccDeclaratorExtensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitGccDeclaratorExtension(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::GccDeclaratorExtensionContext* SimpleCParser::gccDeclaratorExtension() {
  GccDeclaratorExtensionContext *_localctx = _tracker.createInstance<GccDeclaratorExtensionContext>(_ctx, getState());
  enterRule(_localctx, 62, SimpleCParser::RuleGccDeclaratorExtension);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(479);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(470);
        match(SimpleCParser::T__0);
        setState(471);
        match(SimpleCParser::LeftParen);
        setState(473); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(472);
          match(SimpleCParser::StringLiteral);
          setState(475); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == SimpleCParser::StringLiteral);
        setState(477);
        match(SimpleCParser::RightParen);
        break;
      }

      case SimpleCParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(478);
        gccAttributeSpecifier();
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

//----------------- GccAttributeSpecifierContext ------------------------------------------------------------------

SimpleCParser::GccAttributeSpecifierContext::GccAttributeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::GccAttributeListContext* SimpleCParser::GccAttributeSpecifierContext::gccAttributeList() {
  return getRuleContext<SimpleCParser::GccAttributeListContext>(0);
}


size_t SimpleCParser::GccAttributeSpecifierContext::getRuleIndex() const {
  return SimpleCParser::RuleGccAttributeSpecifier;
}

void SimpleCParser::GccAttributeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccAttributeSpecifier(this);
}

void SimpleCParser::GccAttributeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccAttributeSpecifier(this);
}


antlrcpp::Any SimpleCParser::GccAttributeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitGccAttributeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::GccAttributeSpecifierContext* SimpleCParser::gccAttributeSpecifier() {
  GccAttributeSpecifierContext *_localctx = _tracker.createInstance<GccAttributeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 64, SimpleCParser::RuleGccAttributeSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(481);
    match(SimpleCParser::T__1);
    setState(482);
    match(SimpleCParser::LeftParen);
    setState(483);
    match(SimpleCParser::LeftParen);
    setState(484);
    gccAttributeList();
    setState(485);
    match(SimpleCParser::RightParen);
    setState(486);
    match(SimpleCParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GccAttributeListContext ------------------------------------------------------------------

SimpleCParser::GccAttributeListContext::GccAttributeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleCParser::GccAttributeContext *> SimpleCParser::GccAttributeListContext::gccAttribute() {
  return getRuleContexts<SimpleCParser::GccAttributeContext>();
}

SimpleCParser::GccAttributeContext* SimpleCParser::GccAttributeListContext::gccAttribute(size_t i) {
  return getRuleContext<SimpleCParser::GccAttributeContext>(i);
}


size_t SimpleCParser::GccAttributeListContext::getRuleIndex() const {
  return SimpleCParser::RuleGccAttributeList;
}

void SimpleCParser::GccAttributeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccAttributeList(this);
}

void SimpleCParser::GccAttributeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccAttributeList(this);
}


antlrcpp::Any SimpleCParser::GccAttributeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitGccAttributeList(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::GccAttributeListContext* SimpleCParser::gccAttributeList() {
  GccAttributeListContext *_localctx = _tracker.createInstance<GccAttributeListContext>(_ctx, getState());
  enterRule(_localctx, 66, SimpleCParser::RuleGccAttributeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(497);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(488);
      gccAttribute();
      setState(493);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SimpleCParser::Comma) {
        setState(489);
        match(SimpleCParser::Comma);
        setState(490);
        gccAttribute();
        setState(495);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

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

//----------------- GccAttributeContext ------------------------------------------------------------------

SimpleCParser::GccAttributeContext::GccAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ArgumentExpressionListContext* SimpleCParser::GccAttributeContext::argumentExpressionList() {
  return getRuleContext<SimpleCParser::ArgumentExpressionListContext>(0);
}


size_t SimpleCParser::GccAttributeContext::getRuleIndex() const {
  return SimpleCParser::RuleGccAttribute;
}

void SimpleCParser::GccAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccAttribute(this);
}

void SimpleCParser::GccAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccAttribute(this);
}


antlrcpp::Any SimpleCParser::GccAttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitGccAttribute(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::GccAttributeContext* SimpleCParser::gccAttribute() {
  GccAttributeContext *_localctx = _tracker.createInstance<GccAttributeContext>(_ctx, getState());
  enterRule(_localctx, 68, SimpleCParser::RuleGccAttribute);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(508);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::T__0:
      case SimpleCParser::T__1:
      case SimpleCParser::Break:
      case SimpleCParser::Case:
      case SimpleCParser::Char:
      case SimpleCParser::Const:
      case SimpleCParser::Continue:
      case SimpleCParser::Default:
      case SimpleCParser::Do:
      case SimpleCParser::Double:
      case SimpleCParser::Else:
      case SimpleCParser::Extern:
      case SimpleCParser::Float:
      case SimpleCParser::For:
      case SimpleCParser::Goto:
      case SimpleCParser::If:
      case SimpleCParser::Inline:
      case SimpleCParser::Int:
      case SimpleCParser::Long:
      case SimpleCParser::Register:
      case SimpleCParser::Restrict:
      case SimpleCParser::Return:
      case SimpleCParser::Short:
      case SimpleCParser::Signed:
      case SimpleCParser::Sizeof:
      case SimpleCParser::Static:
      case SimpleCParser::Struct:
      case SimpleCParser::Switch:
      case SimpleCParser::Typedef:
      case SimpleCParser::Union:
      case SimpleCParser::Unsigned:
      case SimpleCParser::Void:
      case SimpleCParser::Volatile:
      case SimpleCParser::While:
      case SimpleCParser::Alignas:
      case SimpleCParser::Alignof:
      case SimpleCParser::Atomic:
      case SimpleCParser::Bool:
      case SimpleCParser::Complex:
      case SimpleCParser::Generic:
      case SimpleCParser::Imaginary:
      case SimpleCParser::Noreturn:
      case SimpleCParser::StaticAssert:
      case SimpleCParser::ThreadLocal:
      case SimpleCParser::LeftBracket:
      case SimpleCParser::RightBracket:
      case SimpleCParser::LeftBrace:
      case SimpleCParser::RightBrace:
      case SimpleCParser::Less:
      case SimpleCParser::LessEqual:
      case SimpleCParser::Greater:
      case SimpleCParser::GreaterEqual:
      case SimpleCParser::LeftShift:
      case SimpleCParser::RightShift:
      case SimpleCParser::Plus:
      case SimpleCParser::PlusPlus:
      case SimpleCParser::Minus:
      case SimpleCParser::MinusMinus:
      case SimpleCParser::Star:
      case SimpleCParser::Div:
      case SimpleCParser::Mod:
      case SimpleCParser::And:
      case SimpleCParser::Or:
      case SimpleCParser::AndAnd:
      case SimpleCParser::OrOr:
      case SimpleCParser::Caret:
      case SimpleCParser::Not:
      case SimpleCParser::Tilde:
      case SimpleCParser::Question:
      case SimpleCParser::Colon:
      case SimpleCParser::Semi:
      case SimpleCParser::Assign:
      case SimpleCParser::StarAssign:
      case SimpleCParser::DivAssign:
      case SimpleCParser::ModAssign:
      case SimpleCParser::PlusAssign:
      case SimpleCParser::MinusAssign:
      case SimpleCParser::LeftShiftAssign:
      case SimpleCParser::RightShiftAssign:
      case SimpleCParser::AndAssign:
      case SimpleCParser::XorAssign:
      case SimpleCParser::OrAssign:
      case SimpleCParser::Equal:
      case SimpleCParser::NotEqual:
      case SimpleCParser::Arrow:
      case SimpleCParser::Dot:
      case SimpleCParser::Ellipsis:
      case SimpleCParser::Identifier:
      case SimpleCParser::Constant:
      case SimpleCParser::DigitSequence:
      case SimpleCParser::StringLiteral:
      case SimpleCParser::Whitespace:
      case SimpleCParser::Newline:
      case SimpleCParser::BlockComment:
      case SimpleCParser::LineComment: {
        enterOuterAlt(_localctx, 1);
        setState(499);
        _la = _input->LA(1);
        if (_la == 0 || _la == Token::EOF || (((((_la - 45) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
          | (1ULL << (SimpleCParser::RightParen - 45))
          | (1ULL << (SimpleCParser::Comma - 45)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(505);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleCParser::LeftParen) {
          setState(500);
          match(SimpleCParser::LeftParen);
          setState(502);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 45) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
            | (1ULL << (SimpleCParser::PlusPlus - 45))
            | (1ULL << (SimpleCParser::MinusMinus - 45))
            | (1ULL << (SimpleCParser::Not - 45))
            | (1ULL << (SimpleCParser::Identifier - 45))
            | (1ULL << (SimpleCParser::Constant - 45))
            | (1ULL << (SimpleCParser::DigitSequence - 45))
            | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
            setState(501);
            argumentExpressionList(0);
          }
          setState(504);
          match(SimpleCParser::RightParen);
        }
        break;
      }

      case SimpleCParser::RightParen:
      case SimpleCParser::Comma: {
        enterOuterAlt(_localctx, 2);

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
  enterRule(_localctx, 70, SimpleCParser::RuleNestedParenthesesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::T__0)
      | (1ULL << SimpleCParser::T__1)
      | (1ULL << SimpleCParser::Break)
      | (1ULL << SimpleCParser::Case)
      | (1ULL << SimpleCParser::Char)
      | (1ULL << SimpleCParser::Const)
      | (1ULL << SimpleCParser::Continue)
      | (1ULL << SimpleCParser::Default)
      | (1ULL << SimpleCParser::Do)
      | (1ULL << SimpleCParser::Double)
      | (1ULL << SimpleCParser::Else)
      | (1ULL << SimpleCParser::Extern)
      | (1ULL << SimpleCParser::Float)
      | (1ULL << SimpleCParser::For)
      | (1ULL << SimpleCParser::Goto)
      | (1ULL << SimpleCParser::If)
      | (1ULL << SimpleCParser::Inline)
      | (1ULL << SimpleCParser::Int)
      | (1ULL << SimpleCParser::Long)
      | (1ULL << SimpleCParser::Register)
      | (1ULL << SimpleCParser::Restrict)
      | (1ULL << SimpleCParser::Return)
      | (1ULL << SimpleCParser::Short)
      | (1ULL << SimpleCParser::Signed)
      | (1ULL << SimpleCParser::Sizeof)
      | (1ULL << SimpleCParser::Static)
      | (1ULL << SimpleCParser::Struct)
      | (1ULL << SimpleCParser::Switch)
      | (1ULL << SimpleCParser::Typedef)
      | (1ULL << SimpleCParser::Union)
      | (1ULL << SimpleCParser::Unsigned)
      | (1ULL << SimpleCParser::Void)
      | (1ULL << SimpleCParser::Volatile)
      | (1ULL << SimpleCParser::While)
      | (1ULL << SimpleCParser::Alignas)
      | (1ULL << SimpleCParser::Alignof)
      | (1ULL << SimpleCParser::Atomic)
      | (1ULL << SimpleCParser::Bool)
      | (1ULL << SimpleCParser::Complex)
      | (1ULL << SimpleCParser::Generic)
      | (1ULL << SimpleCParser::Imaginary)
      | (1ULL << SimpleCParser::Noreturn)
      | (1ULL << SimpleCParser::StaticAssert)
      | (1ULL << SimpleCParser::ThreadLocal)
      | (1ULL << SimpleCParser::LeftParen)
      | (1ULL << SimpleCParser::LeftBracket)
      | (1ULL << SimpleCParser::RightBracket)
      | (1ULL << SimpleCParser::LeftBrace)
      | (1ULL << SimpleCParser::RightBrace)
      | (1ULL << SimpleCParser::Less)
      | (1ULL << SimpleCParser::LessEqual)
      | (1ULL << SimpleCParser::Greater)
      | (1ULL << SimpleCParser::GreaterEqual)
      | (1ULL << SimpleCParser::LeftShift)
      | (1ULL << SimpleCParser::RightShift)
      | (1ULL << SimpleCParser::Plus)
      | (1ULL << SimpleCParser::PlusPlus)
      | (1ULL << SimpleCParser::Minus)
      | (1ULL << SimpleCParser::MinusMinus)
      | (1ULL << SimpleCParser::Star)
      | (1ULL << SimpleCParser::Div)
      | (1ULL << SimpleCParser::Mod))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SimpleCParser::And - 64))
      | (1ULL << (SimpleCParser::Or - 64))
      | (1ULL << (SimpleCParser::AndAnd - 64))
      | (1ULL << (SimpleCParser::OrOr - 64))
      | (1ULL << (SimpleCParser::Caret - 64))
      | (1ULL << (SimpleCParser::Not - 64))
      | (1ULL << (SimpleCParser::Tilde - 64))
      | (1ULL << (SimpleCParser::Question - 64))
      | (1ULL << (SimpleCParser::Colon - 64))
      | (1ULL << (SimpleCParser::Semi - 64))
      | (1ULL << (SimpleCParser::Comma - 64))
      | (1ULL << (SimpleCParser::Assign - 64))
      | (1ULL << (SimpleCParser::StarAssign - 64))
      | (1ULL << (SimpleCParser::DivAssign - 64))
      | (1ULL << (SimpleCParser::ModAssign - 64))
      | (1ULL << (SimpleCParser::PlusAssign - 64))
      | (1ULL << (SimpleCParser::MinusAssign - 64))
      | (1ULL << (SimpleCParser::LeftShiftAssign - 64))
      | (1ULL << (SimpleCParser::RightShiftAssign - 64))
      | (1ULL << (SimpleCParser::AndAssign - 64))
      | (1ULL << (SimpleCParser::XorAssign - 64))
      | (1ULL << (SimpleCParser::OrAssign - 64))
      | (1ULL << (SimpleCParser::Equal - 64))
      | (1ULL << (SimpleCParser::NotEqual - 64))
      | (1ULL << (SimpleCParser::Arrow - 64))
      | (1ULL << (SimpleCParser::Dot - 64))
      | (1ULL << (SimpleCParser::Ellipsis - 64))
      | (1ULL << (SimpleCParser::Identifier - 64))
      | (1ULL << (SimpleCParser::Constant - 64))
      | (1ULL << (SimpleCParser::DigitSequence - 64))
      | (1ULL << (SimpleCParser::StringLiteral - 64))
      | (1ULL << (SimpleCParser::Whitespace - 64))
      | (1ULL << (SimpleCParser::Newline - 64))
      | (1ULL << (SimpleCParser::BlockComment - 64))
      | (1ULL << (SimpleCParser::LineComment - 64)))) != 0)) {
      setState(515);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SimpleCParser::T__0:
        case SimpleCParser::T__1:
        case SimpleCParser::Break:
        case SimpleCParser::Case:
        case SimpleCParser::Char:
        case SimpleCParser::Const:
        case SimpleCParser::Continue:
        case SimpleCParser::Default:
        case SimpleCParser::Do:
        case SimpleCParser::Double:
        case SimpleCParser::Else:
        case SimpleCParser::Extern:
        case SimpleCParser::Float:
        case SimpleCParser::For:
        case SimpleCParser::Goto:
        case SimpleCParser::If:
        case SimpleCParser::Inline:
        case SimpleCParser::Int:
        case SimpleCParser::Long:
        case SimpleCParser::Register:
        case SimpleCParser::Restrict:
        case SimpleCParser::Return:
        case SimpleCParser::Short:
        case SimpleCParser::Signed:
        case SimpleCParser::Sizeof:
        case SimpleCParser::Static:
        case SimpleCParser::Struct:
        case SimpleCParser::Switch:
        case SimpleCParser::Typedef:
        case SimpleCParser::Union:
        case SimpleCParser::Unsigned:
        case SimpleCParser::Void:
        case SimpleCParser::Volatile:
        case SimpleCParser::While:
        case SimpleCParser::Alignas:
        case SimpleCParser::Alignof:
        case SimpleCParser::Atomic:
        case SimpleCParser::Bool:
        case SimpleCParser::Complex:
        case SimpleCParser::Generic:
        case SimpleCParser::Imaginary:
        case SimpleCParser::Noreturn:
        case SimpleCParser::StaticAssert:
        case SimpleCParser::ThreadLocal:
        case SimpleCParser::LeftBracket:
        case SimpleCParser::RightBracket:
        case SimpleCParser::LeftBrace:
        case SimpleCParser::RightBrace:
        case SimpleCParser::Less:
        case SimpleCParser::LessEqual:
        case SimpleCParser::Greater:
        case SimpleCParser::GreaterEqual:
        case SimpleCParser::LeftShift:
        case SimpleCParser::RightShift:
        case SimpleCParser::Plus:
        case SimpleCParser::PlusPlus:
        case SimpleCParser::Minus:
        case SimpleCParser::MinusMinus:
        case SimpleCParser::Star:
        case SimpleCParser::Div:
        case SimpleCParser::Mod:
        case SimpleCParser::And:
        case SimpleCParser::Or:
        case SimpleCParser::AndAnd:
        case SimpleCParser::OrOr:
        case SimpleCParser::Caret:
        case SimpleCParser::Not:
        case SimpleCParser::Tilde:
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
        case SimpleCParser::LeftShiftAssign:
        case SimpleCParser::RightShiftAssign:
        case SimpleCParser::AndAssign:
        case SimpleCParser::XorAssign:
        case SimpleCParser::OrAssign:
        case SimpleCParser::Equal:
        case SimpleCParser::NotEqual:
        case SimpleCParser::Arrow:
        case SimpleCParser::Dot:
        case SimpleCParser::Ellipsis:
        case SimpleCParser::Identifier:
        case SimpleCParser::Constant:
        case SimpleCParser::DigitSequence:
        case SimpleCParser::StringLiteral:
        case SimpleCParser::Whitespace:
        case SimpleCParser::Newline:
        case SimpleCParser::BlockComment:
        case SimpleCParser::LineComment: {
          setState(510);
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
          setState(511);
          match(SimpleCParser::LeftParen);
          setState(512);
          nestedParenthesesBlock();
          setState(513);
          match(SimpleCParser::RightParen);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(519);
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

//----------------- TypeQualifierListContext ------------------------------------------------------------------

SimpleCParser::TypeQualifierListContext::TypeQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::TypeQualifierContext* SimpleCParser::TypeQualifierListContext::typeQualifier() {
  return getRuleContext<SimpleCParser::TypeQualifierContext>(0);
}

SimpleCParser::TypeQualifierListContext* SimpleCParser::TypeQualifierListContext::typeQualifierList() {
  return getRuleContext<SimpleCParser::TypeQualifierListContext>(0);
}


size_t SimpleCParser::TypeQualifierListContext::getRuleIndex() const {
  return SimpleCParser::RuleTypeQualifierList;
}

void SimpleCParser::TypeQualifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeQualifierList(this);
}

void SimpleCParser::TypeQualifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeQualifierList(this);
}


antlrcpp::Any SimpleCParser::TypeQualifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitTypeQualifierList(this);
  else
    return visitor->visitChildren(this);
}


SimpleCParser::TypeQualifierListContext* SimpleCParser::typeQualifierList() {
   return typeQualifierList(0);
}

SimpleCParser::TypeQualifierListContext* SimpleCParser::typeQualifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::TypeQualifierListContext *_localctx = _tracker.createInstance<TypeQualifierListContext>(_ctx, parentState);
  SimpleCParser::TypeQualifierListContext *previousContext = _localctx;
  size_t startState = 72;
  enterRecursionRule(_localctx, 72, SimpleCParser::RuleTypeQualifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(521);
    typeQualifier();
    _ctx->stop = _input->LT(-1);
    setState(527);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeQualifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeQualifierList);
        setState(523);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(524);
        typeQualifier(); 
      }
      setState(529);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
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
  enterRule(_localctx, 74, SimpleCParser::RuleParameterTypeList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(535);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(530);
      parameterList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(531);
      parameterList(0);
      setState(532);
      match(SimpleCParser::Comma);
      setState(533);
      match(SimpleCParser::Ellipsis);
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
  size_t startState = 76;
  enterRecursionRule(_localctx, 76, SimpleCParser::RuleParameterList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(538);
    parameterDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(545);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterList);
        setState(540);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(541);
        match(SimpleCParser::Comma);
        setState(542);
        parameterDeclaration(); 
      }
      setState(547);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
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

SimpleCParser::DeclarationSpecifiersContext* SimpleCParser::ParameterDeclarationContext::declarationSpecifiers() {
  return getRuleContext<SimpleCParser::DeclarationSpecifiersContext>(0);
}

SimpleCParser::DeclaratorContext* SimpleCParser::ParameterDeclarationContext::declarator() {
  return getRuleContext<SimpleCParser::DeclaratorContext>(0);
}

SimpleCParser::DeclarationSpecifiers2Context* SimpleCParser::ParameterDeclarationContext::declarationSpecifiers2() {
  return getRuleContext<SimpleCParser::DeclarationSpecifiers2Context>(0);
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
  enterRule(_localctx, 78, SimpleCParser::RuleParameterDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(555);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(548);
      declarationSpecifiers();
      setState(549);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(551);
      declarationSpecifiers2();
      setState(553);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
      case 1: {
        setState(552);
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
  size_t startState = 80;
  enterRecursionRule(_localctx, 80, SimpleCParser::RuleIdentifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(558);
    match(SimpleCParser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(565);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdentifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdentifierList);
        setState(560);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(561);
        match(SimpleCParser::Comma);
        setState(562);
        match(SimpleCParser::Identifier); 
      }
      setState(567);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

SimpleCParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::SpecifierQualifierListContext* SimpleCParser::TypeNameContext::specifierQualifierList() {
  return getRuleContext<SimpleCParser::SpecifierQualifierListContext>(0);
}

SimpleCParser::AbstractDeclaratorContext* SimpleCParser::TypeNameContext::abstractDeclarator() {
  return getRuleContext<SimpleCParser::AbstractDeclaratorContext>(0);
}


size_t SimpleCParser::TypeNameContext::getRuleIndex() const {
  return SimpleCParser::RuleTypeName;
}

void SimpleCParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeName(this);
}

void SimpleCParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeName(this);
}


antlrcpp::Any SimpleCParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::TypeNameContext* SimpleCParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 82, SimpleCParser::RuleTypeName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(568);
    specifierQualifierList();
    setState(570);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimpleCParser::LeftParen

    || _la == SimpleCParser::LeftBracket) {
      setState(569);
      abstractDeclarator();
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

std::vector<SimpleCParser::GccDeclaratorExtensionContext *> SimpleCParser::AbstractDeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<SimpleCParser::GccDeclaratorExtensionContext>();
}

SimpleCParser::GccDeclaratorExtensionContext* SimpleCParser::AbstractDeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<SimpleCParser::GccDeclaratorExtensionContext>(i);
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
  enterRule(_localctx, 84, SimpleCParser::RuleAbstractDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(572);
    directAbstractDeclarator(0);
    setState(576);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(573);
        gccDeclaratorExtension(); 
      }
      setState(578);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    }
   
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

std::vector<SimpleCParser::GccDeclaratorExtensionContext *> SimpleCParser::DirectAbstractDeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<SimpleCParser::GccDeclaratorExtensionContext>();
}

SimpleCParser::GccDeclaratorExtensionContext* SimpleCParser::DirectAbstractDeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<SimpleCParser::GccDeclaratorExtensionContext>(i);
}

SimpleCParser::TypeQualifierListContext* SimpleCParser::DirectAbstractDeclaratorContext::typeQualifierList() {
  return getRuleContext<SimpleCParser::TypeQualifierListContext>(0);
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
  size_t startState = 86;
  enterRecursionRule(_localctx, 86, SimpleCParser::RuleDirectAbstractDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(625);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      setState(580);
      match(SimpleCParser::LeftParen);
      setState(581);
      abstractDeclarator();
      setState(582);
      match(SimpleCParser::RightParen);
      setState(586);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(583);
          gccDeclaratorExtension(); 
        }
        setState(588);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
      }
      break;
    }

    case 2: {
      setState(589);
      match(SimpleCParser::LeftBracket);
      setState(591);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SimpleCParser::Const)
        | (1ULL << SimpleCParser::Restrict)
        | (1ULL << SimpleCParser::Volatile)
        | (1ULL << SimpleCParser::Atomic))) != 0)) {
        setState(590);
        typeQualifierList(0);
      }
      setState(594);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 45) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
        | (1ULL << (SimpleCParser::PlusPlus - 45))
        | (1ULL << (SimpleCParser::MinusMinus - 45))
        | (1ULL << (SimpleCParser::Not - 45))
        | (1ULL << (SimpleCParser::Identifier - 45))
        | (1ULL << (SimpleCParser::Constant - 45))
        | (1ULL << (SimpleCParser::DigitSequence - 45))
        | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
        setState(593);
        assignmentExpression();
      }
      setState(596);
      match(SimpleCParser::RightBracket);
      break;
    }

    case 3: {
      setState(597);
      match(SimpleCParser::LeftBracket);
      setState(598);
      match(SimpleCParser::Static);
      setState(600);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SimpleCParser::Const)
        | (1ULL << SimpleCParser::Restrict)
        | (1ULL << SimpleCParser::Volatile)
        | (1ULL << SimpleCParser::Atomic))) != 0)) {
        setState(599);
        typeQualifierList(0);
      }
      setState(602);
      assignmentExpression();
      setState(603);
      match(SimpleCParser::RightBracket);
      break;
    }

    case 4: {
      setState(605);
      match(SimpleCParser::LeftBracket);
      setState(606);
      typeQualifierList(0);
      setState(607);
      match(SimpleCParser::Static);
      setState(608);
      assignmentExpression();
      setState(609);
      match(SimpleCParser::RightBracket);
      break;
    }

    case 5: {
      setState(611);
      match(SimpleCParser::LeftBracket);
      setState(612);
      match(SimpleCParser::Star);
      setState(613);
      match(SimpleCParser::RightBracket);
      break;
    }

    case 6: {
      setState(614);
      match(SimpleCParser::LeftParen);
      setState(616);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SimpleCParser::Char)
        | (1ULL << SimpleCParser::Const)
        | (1ULL << SimpleCParser::Int)
        | (1ULL << SimpleCParser::Restrict)
        | (1ULL << SimpleCParser::Short)
        | (1ULL << SimpleCParser::Void)
        | (1ULL << SimpleCParser::Volatile)
        | (1ULL << SimpleCParser::Alignas)
        | (1ULL << SimpleCParser::Atomic))) != 0) || _la == SimpleCParser::Identifier) {
        setState(615);
        parameterTypeList();
      }
      setState(618);
      match(SimpleCParser::RightParen);
      setState(622);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(619);
          gccDeclaratorExtension(); 
        }
        setState(624);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(670);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(668);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(627);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(628);
          match(SimpleCParser::LeftBracket);
          setState(630);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SimpleCParser::Const)
            | (1ULL << SimpleCParser::Restrict)
            | (1ULL << SimpleCParser::Volatile)
            | (1ULL << SimpleCParser::Atomic))) != 0)) {
            setState(629);
            typeQualifierList(0);
          }
          setState(633);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 45) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
            | (1ULL << (SimpleCParser::PlusPlus - 45))
            | (1ULL << (SimpleCParser::MinusMinus - 45))
            | (1ULL << (SimpleCParser::Not - 45))
            | (1ULL << (SimpleCParser::Identifier - 45))
            | (1ULL << (SimpleCParser::Constant - 45))
            | (1ULL << (SimpleCParser::DigitSequence - 45))
            | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
            setState(632);
            assignmentExpression();
          }
          setState(635);
          match(SimpleCParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(636);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(637);
          match(SimpleCParser::LeftBracket);
          setState(638);
          match(SimpleCParser::Static);
          setState(640);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SimpleCParser::Const)
            | (1ULL << SimpleCParser::Restrict)
            | (1ULL << SimpleCParser::Volatile)
            | (1ULL << SimpleCParser::Atomic))) != 0)) {
            setState(639);
            typeQualifierList(0);
          }
          setState(642);
          assignmentExpression();
          setState(643);
          match(SimpleCParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(645);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(646);
          match(SimpleCParser::LeftBracket);
          setState(647);
          typeQualifierList(0);
          setState(648);
          match(SimpleCParser::Static);
          setState(649);
          assignmentExpression();
          setState(650);
          match(SimpleCParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(652);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(653);
          match(SimpleCParser::LeftBracket);
          setState(654);
          match(SimpleCParser::Star);
          setState(655);
          match(SimpleCParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(656);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(657);
          match(SimpleCParser::LeftParen);
          setState(659);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SimpleCParser::Char)
            | (1ULL << SimpleCParser::Const)
            | (1ULL << SimpleCParser::Int)
            | (1ULL << SimpleCParser::Restrict)
            | (1ULL << SimpleCParser::Short)
            | (1ULL << SimpleCParser::Void)
            | (1ULL << SimpleCParser::Volatile)
            | (1ULL << SimpleCParser::Alignas)
            | (1ULL << SimpleCParser::Atomic))) != 0) || _la == SimpleCParser::Identifier) {
            setState(658);
            parameterTypeList();
          }
          setState(661);
          match(SimpleCParser::RightParen);
          setState(665);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(662);
              gccDeclaratorExtension(); 
            }
            setState(667);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
          }
          break;
        }

        } 
      }
      setState(672);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypedefNameContext ------------------------------------------------------------------

SimpleCParser::TypedefNameContext::TypedefNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::TypedefNameContext::Identifier() {
  return getToken(SimpleCParser::Identifier, 0);
}


size_t SimpleCParser::TypedefNameContext::getRuleIndex() const {
  return SimpleCParser::RuleTypedefName;
}

void SimpleCParser::TypedefNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypedefName(this);
}

void SimpleCParser::TypedefNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SimpleCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypedefName(this);
}


antlrcpp::Any SimpleCParser::TypedefNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitTypedefName(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::TypedefNameContext* SimpleCParser::typedefName() {
  TypedefNameContext *_localctx = _tracker.createInstance<TypedefNameContext>(_ctx, getState());
  enterRule(_localctx, 88, SimpleCParser::RuleTypedefName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(673);
    match(SimpleCParser::Identifier);
   
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
  enterRule(_localctx, 90, SimpleCParser::RuleInitializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(685);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(675);
      assignmentExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(676);
      match(SimpleCParser::LeftBrace);
      setState(677);
      initializerList(0);
      setState(678);
      match(SimpleCParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(680);
      match(SimpleCParser::LeftBrace);
      setState(681);
      initializerList(0);
      setState(682);
      match(SimpleCParser::Comma);
      setState(683);
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
  size_t startState = 92;
  enterRecursionRule(_localctx, 92, SimpleCParser::RuleInitializerList, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(689);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimpleCParser::LeftBracket

    || _la == SimpleCParser::Dot) {
      setState(688);
      designation();
    }
    setState(691);
    initializer();
    _ctx->stop = _input->LT(-1);
    setState(701);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitializerListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitializerList);
        setState(693);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(694);
        match(SimpleCParser::Comma);
        setState(696);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleCParser::LeftBracket

        || _la == SimpleCParser::Dot) {
          setState(695);
          designation();
        }
        setState(698);
        initializer(); 
      }
      setState(703);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
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
  enterRule(_localctx, 94, SimpleCParser::RuleDesignation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(704);
    designatorList(0);
    setState(705);
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
  size_t startState = 96;
  enterRecursionRule(_localctx, 96, SimpleCParser::RuleDesignatorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(708);
    designator();
    _ctx->stop = _input->LT(-1);
    setState(714);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DesignatorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDesignatorList);
        setState(710);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(711);
        designator(); 
      }
      setState(716);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx);
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
  enterRule(_localctx, 98, SimpleCParser::RuleDesignator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(723);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::LeftBracket: {
        enterOuterAlt(_localctx, 1);
        setState(717);
        match(SimpleCParser::LeftBracket);
        setState(718);
        constantExpression();
        setState(719);
        match(SimpleCParser::RightBracket);
        break;
      }

      case SimpleCParser::Dot: {
        enterOuterAlt(_localctx, 2);
        setState(721);
        match(SimpleCParser::Dot);
        setState(722);
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
  enterRule(_localctx, 100, SimpleCParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(731);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(725);
      labeledStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(726);
      compoundStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(727);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(728);
      selectionStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(729);
      iterationStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(730);
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
  enterRule(_localctx, 102, SimpleCParser::RuleLabeledStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(744);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(733);
        match(SimpleCParser::Identifier);
        setState(734);
        match(SimpleCParser::Colon);
        setState(735);
        statement();
        break;
      }

      case SimpleCParser::Case: {
        enterOuterAlt(_localctx, 2);
        setState(736);
        match(SimpleCParser::Case);
        setState(737);
        constantExpression();
        setState(738);
        match(SimpleCParser::Colon);
        setState(739);
        statement();
        break;
      }

      case SimpleCParser::Default: {
        enterOuterAlt(_localctx, 3);
        setState(741);
        match(SimpleCParser::Default);
        setState(742);
        match(SimpleCParser::Colon);
        setState(743);
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
  enterRule(_localctx, 104, SimpleCParser::RuleCompoundStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(746);
    match(SimpleCParser::LeftBrace);
    setState(748);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::Break)
      | (1ULL << SimpleCParser::Case)
      | (1ULL << SimpleCParser::Char)
      | (1ULL << SimpleCParser::Const)
      | (1ULL << SimpleCParser::Continue)
      | (1ULL << SimpleCParser::Default)
      | (1ULL << SimpleCParser::For)
      | (1ULL << SimpleCParser::If)
      | (1ULL << SimpleCParser::Int)
      | (1ULL << SimpleCParser::Restrict)
      | (1ULL << SimpleCParser::Return)
      | (1ULL << SimpleCParser::Short)
      | (1ULL << SimpleCParser::Switch)
      | (1ULL << SimpleCParser::Void)
      | (1ULL << SimpleCParser::Volatile)
      | (1ULL << SimpleCParser::While)
      | (1ULL << SimpleCParser::Alignas)
      | (1ULL << SimpleCParser::Atomic)
      | (1ULL << SimpleCParser::LeftParen)
      | (1ULL << SimpleCParser::LeftBrace)
      | (1ULL << SimpleCParser::PlusPlus)
      | (1ULL << SimpleCParser::MinusMinus))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (SimpleCParser::Not - 69))
      | (1ULL << (SimpleCParser::Semi - 69))
      | (1ULL << (SimpleCParser::Identifier - 69))
      | (1ULL << (SimpleCParser::Constant - 69))
      | (1ULL << (SimpleCParser::DigitSequence - 69))
      | (1ULL << (SimpleCParser::StringLiteral - 69)))) != 0)) {
      setState(747);
      blockItemList(0);
    }
    setState(750);
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
  size_t startState = 106;
  enterRecursionRule(_localctx, 106, SimpleCParser::RuleBlockItemList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(753);
    blockItem();
    _ctx->stop = _input->LT(-1);
    setState(759);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BlockItemListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBlockItemList);
        setState(755);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(756);
        blockItem(); 
      }
      setState(761);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
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
  enterRule(_localctx, 108, SimpleCParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(764);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(762);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(763);
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
  enterRule(_localctx, 110, SimpleCParser::RuleExpressionStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(767);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 45) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
      | (1ULL << (SimpleCParser::PlusPlus - 45))
      | (1ULL << (SimpleCParser::MinusMinus - 45))
      | (1ULL << (SimpleCParser::Not - 45))
      | (1ULL << (SimpleCParser::Identifier - 45))
      | (1ULL << (SimpleCParser::Constant - 45))
      | (1ULL << (SimpleCParser::DigitSequence - 45))
      | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
      setState(766);
      expression(0);
    }
    setState(769);
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
  enterRule(_localctx, 112, SimpleCParser::RuleSelectionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(786);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(771);
        match(SimpleCParser::If);
        setState(772);
        match(SimpleCParser::LeftParen);
        setState(773);
        expression(0);
        setState(774);
        match(SimpleCParser::RightParen);
        setState(775);
        statement();
        setState(778);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
        case 1: {
          setState(776);
          match(SimpleCParser::Else);
          setState(777);
          statement();
          break;
        }

        }
        break;
      }

      case SimpleCParser::Switch: {
        enterOuterAlt(_localctx, 2);
        setState(780);
        match(SimpleCParser::Switch);
        setState(781);
        match(SimpleCParser::LeftParen);
        setState(782);
        expression(0);
        setState(783);
        match(SimpleCParser::RightParen);
        setState(784);
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
  enterRule(_localctx, 114, SimpleCParser::RuleIterationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(800);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(788);
        match(SimpleCParser::While);
        setState(789);
        match(SimpleCParser::LeftParen);
        setState(790);
        expression(0);
        setState(791);
        match(SimpleCParser::RightParen);
        setState(792);
        statement();
        break;
      }

      case SimpleCParser::For: {
        enterOuterAlt(_localctx, 2);
        setState(794);
        match(SimpleCParser::For);
        setState(795);
        match(SimpleCParser::LeftParen);
        setState(796);
        forCondition();
        setState(797);
        match(SimpleCParser::RightParen);
        setState(798);
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
  enterRule(_localctx, 116, SimpleCParser::RuleForCondition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(822);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(802);
      forDeclaration();
      setState(803);
      match(SimpleCParser::Semi);
      setState(805);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 45) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
        | (1ULL << (SimpleCParser::PlusPlus - 45))
        | (1ULL << (SimpleCParser::MinusMinus - 45))
        | (1ULL << (SimpleCParser::Not - 45))
        | (1ULL << (SimpleCParser::Identifier - 45))
        | (1ULL << (SimpleCParser::Constant - 45))
        | (1ULL << (SimpleCParser::DigitSequence - 45))
        | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
        setState(804);
        forExpression(0);
      }
      setState(807);
      match(SimpleCParser::Semi);
      setState(809);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 45) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
        | (1ULL << (SimpleCParser::PlusPlus - 45))
        | (1ULL << (SimpleCParser::MinusMinus - 45))
        | (1ULL << (SimpleCParser::Not - 45))
        | (1ULL << (SimpleCParser::Identifier - 45))
        | (1ULL << (SimpleCParser::Constant - 45))
        | (1ULL << (SimpleCParser::DigitSequence - 45))
        | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
        setState(808);
        forExpression(0);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(812);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 45) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
        | (1ULL << (SimpleCParser::PlusPlus - 45))
        | (1ULL << (SimpleCParser::MinusMinus - 45))
        | (1ULL << (SimpleCParser::Not - 45))
        | (1ULL << (SimpleCParser::Identifier - 45))
        | (1ULL << (SimpleCParser::Constant - 45))
        | (1ULL << (SimpleCParser::DigitSequence - 45))
        | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
        setState(811);
        expression(0);
      }
      setState(814);
      match(SimpleCParser::Semi);
      setState(816);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 45) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
        | (1ULL << (SimpleCParser::PlusPlus - 45))
        | (1ULL << (SimpleCParser::MinusMinus - 45))
        | (1ULL << (SimpleCParser::Not - 45))
        | (1ULL << (SimpleCParser::Identifier - 45))
        | (1ULL << (SimpleCParser::Constant - 45))
        | (1ULL << (SimpleCParser::DigitSequence - 45))
        | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
        setState(815);
        forExpression(0);
      }
      setState(818);
      match(SimpleCParser::Semi);
      setState(820);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 45) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
        | (1ULL << (SimpleCParser::PlusPlus - 45))
        | (1ULL << (SimpleCParser::MinusMinus - 45))
        | (1ULL << (SimpleCParser::Not - 45))
        | (1ULL << (SimpleCParser::Identifier - 45))
        | (1ULL << (SimpleCParser::Constant - 45))
        | (1ULL << (SimpleCParser::DigitSequence - 45))
        | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
        setState(819);
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

SimpleCParser::DeclarationSpecifiersContext* SimpleCParser::ForDeclarationContext::declarationSpecifiers() {
  return getRuleContext<SimpleCParser::DeclarationSpecifiersContext>(0);
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
  enterRule(_localctx, 118, SimpleCParser::RuleForDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(828);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(824);
      declarationSpecifiers();
      setState(825);
      initDeclaratorList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(827);
      declarationSpecifiers();
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
  size_t startState = 120;
  enterRecursionRule(_localctx, 120, SimpleCParser::RuleForExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(831);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(838);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ForExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleForExpression);
        setState(833);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(834);
        match(SimpleCParser::Comma);
        setState(835);
        assignmentExpression(); 
      }
      setState(840);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx);
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
  enterRule(_localctx, 122, SimpleCParser::RuleJumpStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(850);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::Continue: {
        enterOuterAlt(_localctx, 1);
        setState(841);
        match(SimpleCParser::Continue);
        setState(842);
        match(SimpleCParser::Semi);
        break;
      }

      case SimpleCParser::Break: {
        enterOuterAlt(_localctx, 2);
        setState(843);
        match(SimpleCParser::Break);
        setState(844);
        match(SimpleCParser::Semi);
        break;
      }

      case SimpleCParser::Return: {
        enterOuterAlt(_localctx, 3);
        setState(845);
        match(SimpleCParser::Return);
        setState(847);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 45) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 45)) & ((1ULL << (SimpleCParser::LeftParen - 45))
          | (1ULL << (SimpleCParser::PlusPlus - 45))
          | (1ULL << (SimpleCParser::MinusMinus - 45))
          | (1ULL << (SimpleCParser::Not - 45))
          | (1ULL << (SimpleCParser::Identifier - 45))
          | (1ULL << (SimpleCParser::Constant - 45))
          | (1ULL << (SimpleCParser::DigitSequence - 45))
          | (1ULL << (SimpleCParser::StringLiteral - 45)))) != 0)) {
          setState(846);
          expression(0);
        }
        setState(849);
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
  enterRule(_localctx, 124, SimpleCParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(853);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::Char)
      | (1ULL << SimpleCParser::Const)
      | (1ULL << SimpleCParser::Int)
      | (1ULL << SimpleCParser::Restrict)
      | (1ULL << SimpleCParser::Short)
      | (1ULL << SimpleCParser::Void)
      | (1ULL << SimpleCParser::Volatile)
      | (1ULL << SimpleCParser::Alignas)
      | (1ULL << SimpleCParser::Atomic)
      | (1ULL << SimpleCParser::LeftParen))) != 0) || _la == SimpleCParser::Semi

    || _la == SimpleCParser::Identifier) {
      setState(852);
      translationUnit(0);
    }
    setState(855);
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
  size_t startState = 126;
  enterRecursionRule(_localctx, 126, SimpleCParser::RuleTranslationUnit, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(858);
    externalDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(864);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TranslationUnitContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTranslationUnit);
        setState(860);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(861);
        externalDeclaration(); 
      }
      setState(866);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
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
  enterRule(_localctx, 128, SimpleCParser::RuleExternalDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(870);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(867);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(868);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(869);
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

SimpleCParser::DeclarationSpecifiersContext* SimpleCParser::FunctionDefinitionContext::declarationSpecifiers() {
  return getRuleContext<SimpleCParser::DeclarationSpecifiersContext>(0);
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
  enterRule(_localctx, 130, SimpleCParser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(873);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx)) {
    case 1: {
      setState(872);
      declarationSpecifiers();
      break;
    }

    }
    setState(875);
    declarator();
    setState(877);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::Char)
      | (1ULL << SimpleCParser::Const)
      | (1ULL << SimpleCParser::Int)
      | (1ULL << SimpleCParser::Restrict)
      | (1ULL << SimpleCParser::Short)
      | (1ULL << SimpleCParser::Void)
      | (1ULL << SimpleCParser::Volatile)
      | (1ULL << SimpleCParser::Alignas)
      | (1ULL << SimpleCParser::Atomic))) != 0) || _la == SimpleCParser::Identifier) {
      setState(876);
      declarationList(0);
    }
    setState(879);
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
  size_t startState = 132;
  enterRecursionRule(_localctx, 132, SimpleCParser::RuleDeclarationList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(882);
    declaration();
    _ctx->stop = _input->LT(-1);
    setState(888);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDeclarationList);
        setState(884);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(885);
        declaration(); 
      }
      setState(890);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx);
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
    case 19: return initDeclaratorListSempred(dynamic_cast<InitDeclaratorListContext *>(context), predicateIndex);
    case 22: return structDeclarationListSempred(dynamic_cast<StructDeclarationListContext *>(context), predicateIndex);
    case 25: return structDeclaratorListSempred(dynamic_cast<StructDeclaratorListContext *>(context), predicateIndex);
    case 30: return directDeclaratorSempred(dynamic_cast<DirectDeclaratorContext *>(context), predicateIndex);
    case 36: return typeQualifierListSempred(dynamic_cast<TypeQualifierListContext *>(context), predicateIndex);
    case 38: return parameterListSempred(dynamic_cast<ParameterListContext *>(context), predicateIndex);
    case 40: return identifierListSempred(dynamic_cast<IdentifierListContext *>(context), predicateIndex);
    case 43: return directAbstractDeclaratorSempred(dynamic_cast<DirectAbstractDeclaratorContext *>(context), predicateIndex);
    case 46: return initializerListSempred(dynamic_cast<InitializerListContext *>(context), predicateIndex);
    case 48: return designatorListSempred(dynamic_cast<DesignatorListContext *>(context), predicateIndex);
    case 53: return blockItemListSempred(dynamic_cast<BlockItemListContext *>(context), predicateIndex);
    case 60: return forExpressionSempred(dynamic_cast<ForExpressionContext *>(context), predicateIndex);
    case 63: return translationUnitSempred(dynamic_cast<TranslationUnitContext *>(context), predicateIndex);
    case 66: return declarationListSempred(dynamic_cast<DeclarationListContext *>(context), predicateIndex);

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

bool SimpleCParser::structDeclarationListSempred(StructDeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 19: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::structDeclaratorListSempred(StructDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 20: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 21: return precpred(_ctx, 7);
    case 22: return precpred(_ctx, 6);
    case 23: return precpred(_ctx, 5);
    case 24: return precpred(_ctx, 4);
    case 25: return precpred(_ctx, 3);
    case 26: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::typeQualifierListSempred(TypeQualifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::parameterListSempred(ParameterListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 28: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::identifierListSempred(IdentifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 29: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::directAbstractDeclaratorSempred(DirectAbstractDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 30: return precpred(_ctx, 5);
    case 31: return precpred(_ctx, 4);
    case 32: return precpred(_ctx, 3);
    case 33: return precpred(_ctx, 2);
    case 34: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::initializerListSempred(InitializerListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 35: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::designatorListSempred(DesignatorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 36: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::blockItemListSempred(BlockItemListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 37: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::forExpressionSempred(ForExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 38: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::translationUnitSempred(TranslationUnitContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 39: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::declarationListSempred(DeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 40: return precpred(_ctx, 1);

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
  "constantExpression", "declaration", "declarationSpecifiers", "declarationSpecifiers2", 
  "declarationSpecifier", "initDeclaratorList", "initDeclarator", "typeSpecifier", 
  "structDeclarationList", "structDeclaration", "specifierQualifierList", 
  "structDeclaratorList", "structDeclarator", "typeQualifier", "alignmentSpecifier", 
  "declarator", "directDeclarator", "gccDeclaratorExtension", "gccAttributeSpecifier", 
  "gccAttributeList", "gccAttribute", "nestedParenthesesBlock", "typeQualifierList", 
  "parameterTypeList", "parameterList", "parameterDeclaration", "identifierList", 
  "typeName", "abstractDeclarator", "directAbstractDeclarator", "typedefName", 
  "initializer", "initializerList", "designation", "designatorList", "designator", 
  "statement", "labeledStatement", "compoundStatement", "blockItemList", 
  "blockItem", "expressionStatement", "selectionStatement", "iterationStatement", 
  "forCondition", "forDeclaration", "forExpression", "jumpStatement", "compilationUnit", 
  "translationUnit", "externalDeclaration", "functionDefinition", "declarationList"
};

std::vector<std::string> SimpleCParser::_literalNames = {
  "", "'__asm'", "'__attribute__'", "'break'", "'case'", "'char'", "'const'", 
  "'continue'", "'default'", "'do'", "'double'", "'else'", "'extern'", "'float'", 
  "'for'", "'goto'", "'if'", "'inline'", "'int'", "'long'", "'register'", 
  "'restrict'", "'return'", "'short'", "'signed'", "'sizeof'", "'static'", 
  "'struct'", "'switch'", "'typedef'", "'union'", "'unsigned'", "'void'", 
  "'volatile'", "'while'", "'_Alignas'", "'_Alignof'", "'_Atomic'", "'_Bool'", 
  "'_Complex'", "'_Generic'", "'_Imaginary'", "'_Noreturn'", "'_Static_assert'", 
  "'_Thread_local'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", 
  "'>'", "'>='", "'<<'", "'>>'", "'+'", "'++'", "'-'", "'--'", "'*'", "'/'", 
  "'%'", "'&'", "'|'", "'&&'", "'||'", "'^'", "'!'", "'~'", "'?'", "':'", 
  "';'", "','", "'='", "'*='", "'/='", "'%='", "'+='", "'-='", "'<<='", 
  "'>>='", "'&='", "'^='", "'|='", "'=='", "'!='", "'->'", "'.'", "'...'"
};

std::vector<std::string> SimpleCParser::_symbolicNames = {
  "", "", "", "Break", "Case", "Char", "Const", "Continue", "Default", "Do", 
  "Double", "Else", "Extern", "Float", "For", "Goto", "If", "Inline", "Int", 
  "Long", "Register", "Restrict", "Return", "Short", "Signed", "Sizeof", 
  "Static", "Struct", "Switch", "Typedef", "Union", "Unsigned", "Void", 
  "Volatile", "While", "Alignas", "Alignof", "Atomic", "Bool", "Complex", 
  "Generic", "Imaginary", "Noreturn", "StaticAssert", "ThreadLocal", "LeftParen", 
  "RightParen", "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", 
  "Less", "LessEqual", "Greater", "GreaterEqual", "LeftShift", "RightShift", 
  "Plus", "PlusPlus", "Minus", "MinusMinus", "Star", "Div", "Mod", "And", 
  "Or", "AndAnd", "OrOr", "Caret", "Not", "Tilde", "Question", "Colon", 
  "Semi", "Comma", "Assign", "StarAssign", "DivAssign", "ModAssign", "PlusAssign", 
  "MinusAssign", "LeftShiftAssign", "RightShiftAssign", "AndAssign", "XorAssign", 
  "OrAssign", "Equal", "NotEqual", "Arrow", "Dot", "Ellipsis", "Identifier", 
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
    0x3, 0x64, 0x37e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x6, 0x2, 0x8c, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x8d, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x94, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x9c, 0xa, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0xa3, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0xa6, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0xae, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0xb1, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0xba, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 
    0xbe, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 
    0x7, 0xcc, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xcf, 0xb, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x7, 0x8, 0xda, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xdd, 0xb, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x7, 0x9, 0xee, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xf1, 0xb, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x7, 0xa, 0xfc, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xff, 0xb, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 
    0xb, 0x107, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x10a, 0xb, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x112, 0xa, 
    0xc, 0xc, 0xc, 0xe, 0xc, 0x115, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x11d, 0xa, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 
    0xf, 0x127, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x12a, 0xb, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x5, 0x11, 0x135, 0xa, 0x11, 0x3, 0x12, 0x6, 0x12, 
    0x138, 0xa, 0x12, 0xd, 0x12, 0xe, 0x12, 0x139, 0x3, 0x13, 0x6, 0x13, 
    0x13d, 0xa, 0x13, 0xd, 0x13, 0xe, 0x13, 0x13e, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0x144, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x14c, 0xa, 0x15, 0xc, 0x15, 
    0xe, 0x15, 0x14f, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x5, 0x16, 0x156, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 
    0x15a, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x7, 0x18, 0x161, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x164, 0xb, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x168, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x16e, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x5, 0x1a, 0x172, 0xa, 0x1a, 0x5, 0x1a, 0x174, 0xa, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x17c, 
    0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x17f, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
    0x5, 0x1c, 0x183, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x187, 
    0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x5, 0x1e, 0x195, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x199, 
    0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x19c, 0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x20, 0x5, 0x20, 0x1a7, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x5, 0x20, 0x1ac, 0xa, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1af, 0xa, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1b6, 
    0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x5, 0x20, 0x1c5, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x20, 0x5, 0x20, 0x1d1, 0xa, 0x20, 0x3, 0x20, 0x7, 0x20, 0x1d4, 0xa, 
    0x20, 0xc, 0x20, 0xe, 0x20, 0x1d7, 0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x6, 0x21, 0x1dc, 0xa, 0x21, 0xd, 0x21, 0xe, 0x21, 0x1dd, 
    0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x1e2, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x7, 0x23, 0x1ee, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 
    0x1f1, 0xb, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1f4, 0xa, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x1f9, 0xa, 0x24, 0x3, 0x24, 0x5, 0x24, 
    0x1fc, 0xa, 0x24, 0x3, 0x24, 0x5, 0x24, 0x1ff, 0xa, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x206, 0xa, 0x25, 
    0xc, 0x25, 0xe, 0x25, 0x209, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x210, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 
    0x213, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x5, 0x27, 0x21a, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x222, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 
    0x225, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x5, 0x29, 0x22c, 0xa, 0x29, 0x5, 0x29, 0x22e, 0xa, 0x29, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x236, 
    0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x239, 0xb, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
    0x5, 0x2b, 0x23d, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x241, 
    0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x244, 0xb, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x24b, 0xa, 0x2d, 0xc, 0x2d, 
    0xe, 0x2d, 0x24e, 0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x252, 
    0xa, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x255, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x25b, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
    0x26b, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x26f, 0xa, 0x2d, 
    0xc, 0x2d, 0xe, 0x2d, 0x272, 0xb, 0x2d, 0x5, 0x2d, 0x274, 0xa, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x279, 0xa, 0x2d, 0x3, 0x2d, 
    0x5, 0x2d, 0x27c, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x5, 0x2d, 0x283, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x5, 0x2d, 0x296, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 
    0x29a, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x29d, 0xb, 0x2d, 0x7, 0x2d, 
    0x29f, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x2a2, 0xb, 0x2d, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x2b0, 
    0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x2b4, 0xa, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x2bb, 0xa, 0x30, 
    0x3, 0x30, 0x7, 0x30, 0x2be, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x2c1, 
    0xb, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x2cb, 0xa, 0x32, 0xc, 0x32, 
    0xe, 0x32, 0x2ce, 0xb, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x2d6, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x2de, 0xa, 0x34, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
    0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x2eb, 
    0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x2ef, 0xa, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 
    0x37, 0x2f8, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 0x2fb, 0xb, 0x37, 0x3, 
    0x38, 0x3, 0x38, 0x5, 0x38, 0x2ff, 0xa, 0x38, 0x3, 0x39, 0x5, 0x39, 
    0x302, 0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x30d, 0xa, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 
    0x3a, 0x315, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
    0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x323, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x5, 0x3c, 0x328, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 
    0x32c, 0xa, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x32f, 0xa, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x5, 0x3c, 0x333, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 
    0x337, 0xa, 0x3c, 0x5, 0x3c, 0x339, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x33f, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x347, 0xa, 0x3e, 
    0xc, 0x3e, 0xe, 0x3e, 0x34a, 0xb, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x352, 0xa, 0x3f, 0x3, 0x3f, 
    0x5, 0x3f, 0x355, 0xa, 0x3f, 0x3, 0x40, 0x5, 0x40, 0x358, 0xa, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x7, 0x41, 0x361, 0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x364, 0xb, 
    0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x369, 0xa, 0x42, 
    0x3, 0x43, 0x5, 0x43, 0x36c, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 
    0x370, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x7, 0x44, 0x379, 0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 
    0x37c, 0xb, 0x44, 0x3, 0x44, 0x2, 0x19, 0x4, 0x6, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x1c, 0x28, 0x2e, 0x34, 0x3e, 0x4a, 0x4e, 0x52, 0x58, 0x5e, 
    0x62, 0x6c, 0x7a, 0x80, 0x86, 0x45, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
    0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 
    0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 
    0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 
    0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 
    0x2, 0x7, 0x3, 0x2, 0x4d, 0x52, 0x6, 0x2, 0x7, 0x7, 0x14, 0x14, 0x19, 
    0x19, 0x22, 0x22, 0x6, 0x2, 0x8, 0x8, 0x17, 0x17, 0x23, 0x23, 0x27, 
    0x27, 0x4, 0x2, 0x2f, 0x30, 0x4c, 0x4c, 0x3, 0x2, 0x2f, 0x30, 0x2, 0x3c3, 
    0x2, 0x93, 0x3, 0x2, 0x2, 0x2, 0x4, 0x95, 0x3, 0x2, 0x2, 0x2, 0x6, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xa, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xe, 0xd0, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0xde, 0x3, 0x2, 0x2, 0x2, 0x12, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x100, 0x3, 0x2, 0x2, 0x2, 0x16, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x11c, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x120, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x20, 0x134, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x137, 0x3, 0x2, 0x2, 0x2, 0x24, 0x13c, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x143, 0x3, 0x2, 0x2, 0x2, 0x28, 0x145, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x155, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x159, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x15b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x165, 0x3, 0x2, 0x2, 0x2, 0x32, 0x173, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x175, 0x3, 0x2, 0x2, 0x2, 0x36, 0x186, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x188, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x194, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x196, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1a6, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1e3, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x207, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x219, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x50, 0x22d, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x54, 0x23a, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x58, 0x273, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x2af, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x60, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x2c5, 0x3, 0x2, 0x2, 0x2, 0x64, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x66, 0x2dd, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x2ec, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x2fe, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x301, 0x3, 0x2, 0x2, 0x2, 0x72, 0x314, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x322, 0x3, 0x2, 0x2, 0x2, 0x76, 0x338, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x340, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x354, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x357, 0x3, 0x2, 0x2, 0x2, 0x80, 0x35b, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x368, 0x3, 0x2, 0x2, 0x2, 0x84, 0x36b, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x373, 0x3, 0x2, 0x2, 0x2, 0x88, 0x94, 0x7, 0x5d, 
    0x2, 0x2, 0x89, 0x94, 0x7, 0x5e, 0x2, 0x2, 0x8a, 0x8c, 0x7, 0x60, 0x2, 
    0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x2f, 0x2, 0x2, 0x90, 0x91, 
    0x5, 0x1c, 0xf, 0x2, 0x91, 0x92, 0x7, 0x30, 0x2, 0x2, 0x92, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x93, 0x88, 0x3, 0x2, 0x2, 0x2, 0x93, 0x89, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x93, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x3, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x8, 0x3, 0x1, 0x2, 
    0x96, 0x97, 0x5, 0x2, 0x2, 0x2, 0x97, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x99, 0xc, 0x5, 0x2, 0x2, 0x99, 0x9b, 0x7, 0x2f, 0x2, 0x2, 0x9a, 0x9c, 
    0x5, 0x6, 0x4, 0x2, 0x9b, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa3, 0x7, 0x30, 
    0x2, 0x2, 0x9e, 0x9f, 0xc, 0x4, 0x2, 0x2, 0x9f, 0xa3, 0x7, 0x3c, 0x2, 
    0x2, 0xa0, 0xa1, 0xc, 0x3, 0x2, 0x2, 0xa1, 0xa3, 0x7, 0x3e, 0x2, 0x2, 
    0xa2, 0x98, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0xa0, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa2, 
    0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x8, 0x4, 
    0x1, 0x2, 0xa8, 0xa9, 0x5, 0x18, 0xd, 0x2, 0xa9, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0xaa, 0xab, 0xc, 0x3, 0x2, 0x2, 0xab, 0xac, 0x7, 0x4c, 0x2, 0x2, 
    0xac, 0xae, 0x5, 0x18, 0xd, 0x2, 0xad, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xae, 
    0xb1, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0x7, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0xba, 0x5, 0x4, 0x3, 0x2, 0xb3, 0xb4, 0x7, 0x3c, 
    0x2, 0x2, 0xb4, 0xba, 0x5, 0x8, 0x5, 0x2, 0xb5, 0xb6, 0x7, 0x3e, 0x2, 
    0x2, 0xb6, 0xba, 0x5, 0x8, 0x5, 0x2, 0xb7, 0xb8, 0x7, 0x47, 0x2, 0x2, 
    0xb8, 0xba, 0x5, 0x8, 0x5, 0x2, 0xb9, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb9, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xba, 0x9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbe, 0x5, 
    0x8, 0x5, 0x2, 0xbc, 0xbe, 0x7, 0x5f, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 
    0x2, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xc0, 0x8, 0x7, 0x1, 0x2, 0xc0, 0xc1, 0x5, 0xa, 0x6, 0x2, 
    0xc1, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0xc, 0x5, 0x2, 0x2, 0xc3, 
    0xc4, 0x7, 0x3f, 0x2, 0x2, 0xc4, 0xcc, 0x5, 0xa, 0x6, 0x2, 0xc5, 0xc6, 
    0xc, 0x4, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x40, 0x2, 0x2, 0xc7, 0xcc, 0x5, 
    0xa, 0x6, 0x2, 0xc8, 0xc9, 0xc, 0x3, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x41, 
    0x2, 0x2, 0xca, 0xcc, 0x5, 0xa, 0x6, 0x2, 0xcb, 0xc2, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc8, 0x3, 0x2, 0x2, 0x2, 
    0xcc, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x8, 0x8, 0x1, 0x2, 0xd1, 0xd2, 0x5, 
    0xc, 0x7, 0x2, 0xd2, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0xc, 0x4, 
    0x2, 0x2, 0xd4, 0xd5, 0x7, 0x3b, 0x2, 0x2, 0xd5, 0xda, 0x5, 0xc, 0x7, 
    0x2, 0xd6, 0xd7, 0xc, 0x3, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x3d, 0x2, 0x2, 
    0xd8, 0xda, 0x5, 0xc, 0x7, 0x2, 0xd9, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x8, 0x9, 
    0x1, 0x2, 0xdf, 0xe0, 0x5, 0xe, 0x8, 0x2, 0xe0, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xe1, 0xe2, 0xc, 0x6, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x35, 0x2, 0x2, 
    0xe3, 0xee, 0x5, 0xe, 0x8, 0x2, 0xe4, 0xe5, 0xc, 0x5, 0x2, 0x2, 0xe5, 
    0xe6, 0x7, 0x37, 0x2, 0x2, 0xe6, 0xee, 0x5, 0xe, 0x8, 0x2, 0xe7, 0xe8, 
    0xc, 0x4, 0x2, 0x2, 0xe8, 0xe9, 0x7, 0x36, 0x2, 0x2, 0xe9, 0xee, 0x5, 
    0xe, 0x8, 0x2, 0xea, 0xeb, 0xc, 0x3, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x38, 
    0x2, 0x2, 0xec, 0xee, 0x5, 0xe, 0x8, 0x2, 0xed, 0xe1, 0x3, 0x2, 0x2, 
    0x2, 0xed, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xed, 0xe7, 0x3, 0x2, 0x2, 0x2, 
    0xed, 0xea, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x8, 
    0xa, 0x1, 0x2, 0xf3, 0xf4, 0x5, 0x10, 0x9, 0x2, 0xf4, 0xfd, 0x3, 0x2, 
    0x2, 0x2, 0xf5, 0xf6, 0xc, 0x4, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x58, 0x2, 
    0x2, 0xf7, 0xfc, 0x5, 0x10, 0x9, 0x2, 0xf8, 0xf9, 0xc, 0x3, 0x2, 0x2, 
    0xf9, 0xfa, 0x7, 0x59, 0x2, 0x2, 0xfa, 0xfc, 0x5, 0x10, 0x9, 0x2, 0xfb, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xff, 
    0x3, 0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 
    0x2, 0x2, 0x2, 0xfe, 0x13, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfd, 0x3, 0x2, 
    0x2, 0x2, 0x100, 0x101, 0x8, 0xb, 0x1, 0x2, 0x101, 0x102, 0x5, 0x12, 
    0xa, 0x2, 0x102, 0x108, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0xc, 0x3, 
    0x2, 0x2, 0x104, 0x105, 0x7, 0x44, 0x2, 0x2, 0x105, 0x107, 0x5, 0x12, 
    0xa, 0x2, 0x106, 0x103, 0x3, 0x2, 0x2, 0x2, 0x107, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x3, 0x2, 
    0x2, 0x2, 0x109, 0x15, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x10c, 0x8, 0xc, 0x1, 0x2, 0x10c, 0x10d, 0x5, 0x14, 0xb, 
    0x2, 0x10d, 0x113, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0xc, 0x3, 0x2, 
    0x2, 0x10f, 0x110, 0x7, 0x45, 0x2, 0x2, 0x110, 0x112, 0x5, 0x14, 0xb, 
    0x2, 0x111, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x112, 0x115, 0x3, 0x2, 0x2, 
    0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 0x2, 
    0x2, 0x114, 0x17, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 
    0x116, 0x11d, 0x5, 0x16, 0xc, 0x2, 0x117, 0x118, 0x5, 0x8, 0x5, 0x2, 
    0x118, 0x119, 0x5, 0x1a, 0xe, 0x2, 0x119, 0x11a, 0x5, 0x18, 0xd, 0x2, 
    0x11a, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11d, 0x7, 0x5f, 0x2, 0x2, 
    0x11c, 0x116, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x117, 0x3, 0x2, 0x2, 0x2, 
    0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x19, 0x3, 0x2, 0x2, 0x2, 0x11e, 
    0x11f, 0x9, 0x2, 0x2, 0x2, 0x11f, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 
    0x8, 0xf, 0x1, 0x2, 0x121, 0x122, 0x5, 0x18, 0xd, 0x2, 0x122, 0x128, 
    0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0xc, 0x3, 0x2, 0x2, 0x124, 0x125, 
    0x7, 0x4c, 0x2, 0x2, 0x125, 0x127, 0x5, 0x18, 0xd, 0x2, 0x126, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x127, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x128, 0x126, 
    0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x5, 
    0x16, 0xc, 0x2, 0x12c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x5, 
    0x22, 0x12, 0x2, 0x12e, 0x12f, 0x5, 0x28, 0x15, 0x2, 0x12f, 0x130, 0x7, 
    0x4b, 0x2, 0x2, 0x130, 0x135, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x5, 
    0x22, 0x12, 0x2, 0x132, 0x133, 0x7, 0x4b, 0x2, 0x2, 0x133, 0x135, 0x3, 
    0x2, 0x2, 0x2, 0x134, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x134, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x135, 0x21, 0x3, 0x2, 0x2, 0x2, 0x136, 0x138, 0x5, 0x26, 
    0x14, 0x2, 0x137, 0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 
    0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 
    0x2, 0x2, 0x13a, 0x23, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13d, 0x5, 0x26, 
    0x14, 0x2, 0x13c, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 
    0x2, 0x2, 0x13e, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x3, 0x2, 
    0x2, 0x2, 0x13f, 0x25, 0x3, 0x2, 0x2, 0x2, 0x140, 0x144, 0x5, 0x2c, 
    0x17, 0x2, 0x141, 0x144, 0x5, 0x38, 0x1d, 0x2, 0x142, 0x144, 0x5, 0x3a, 
    0x1e, 0x2, 0x143, 0x140, 0x3, 0x2, 0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 
    0x2, 0x2, 0x143, 0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x145, 0x146, 0x8, 0x15, 0x1, 0x2, 0x146, 0x147, 0x5, 0x2a, 0x16, 
    0x2, 0x147, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0xc, 0x3, 0x2, 
    0x2, 0x149, 0x14a, 0x7, 0x4c, 0x2, 0x2, 0x14a, 0x14c, 0x5, 0x2a, 0x16, 
    0x2, 0x14b, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14f, 0x3, 0x2, 0x2, 
    0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x29, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 
    0x150, 0x156, 0x5, 0x3c, 0x1f, 0x2, 0x151, 0x152, 0x5, 0x3c, 0x1f, 0x2, 
    0x152, 0x153, 0x7, 0x4d, 0x2, 0x2, 0x153, 0x154, 0x5, 0x5c, 0x2f, 0x2, 
    0x154, 0x156, 0x3, 0x2, 0x2, 0x2, 0x155, 0x150, 0x3, 0x2, 0x2, 0x2, 
    0x155, 0x151, 0x3, 0x2, 0x2, 0x2, 0x156, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x157, 
    0x15a, 0x9, 0x3, 0x2, 0x2, 0x158, 0x15a, 0x5, 0x5a, 0x2e, 0x2, 0x159, 
    0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15a, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x8, 0x18, 0x1, 0x2, 0x15c, 
    0x15d, 0x5, 0x30, 0x19, 0x2, 0x15d, 0x162, 0x3, 0x2, 0x2, 0x2, 0x15e, 
    0x15f, 0xc, 0x3, 0x2, 0x2, 0x15f, 0x161, 0x5, 0x30, 0x19, 0x2, 0x160, 
    0x15e, 0x3, 0x2, 0x2, 0x2, 0x161, 0x164, 0x3, 0x2, 0x2, 0x2, 0x162, 
    0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x3, 0x2, 0x2, 0x2, 0x163, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 0x3, 0x2, 0x2, 0x2, 0x165, 0x167, 
    0x5, 0x32, 0x1a, 0x2, 0x166, 0x168, 0x5, 0x34, 0x1b, 0x2, 0x167, 0x166, 
    0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 
    0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x7, 0x4b, 0x2, 0x2, 0x16a, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x16b, 0x16d, 0x5, 0x2c, 0x17, 0x2, 0x16c, 0x16e, 
    0x5, 0x32, 0x1a, 0x2, 0x16d, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 
    0x3, 0x2, 0x2, 0x2, 0x16e, 0x174, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x171, 
    0x5, 0x38, 0x1d, 0x2, 0x170, 0x172, 0x5, 0x32, 0x1a, 0x2, 0x171, 0x170, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x3, 0x2, 0x2, 0x2, 0x172, 0x174, 
    0x3, 0x2, 0x2, 0x2, 0x173, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x173, 0x16f, 
    0x3, 0x2, 0x2, 0x2, 0x174, 0x33, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x8, 
    0x1b, 0x1, 0x2, 0x176, 0x177, 0x5, 0x36, 0x1c, 0x2, 0x177, 0x17d, 0x3, 
    0x2, 0x2, 0x2, 0x178, 0x179, 0xc, 0x3, 0x2, 0x2, 0x179, 0x17a, 0x7, 
    0x4c, 0x2, 0x2, 0x17a, 0x17c, 0x5, 0x36, 0x1c, 0x2, 0x17b, 0x178, 0x3, 
    0x2, 0x2, 0x2, 0x17c, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17b, 0x3, 
    0x2, 0x2, 0x2, 0x17d, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x17f, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x180, 0x187, 0x5, 0x3c, 
    0x1f, 0x2, 0x181, 0x183, 0x5, 0x3c, 0x1f, 0x2, 0x182, 0x181, 0x3, 0x2, 
    0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x184, 0x185, 0x7, 0x4a, 0x2, 0x2, 0x185, 0x187, 0x5, 0x1e, 
    0x10, 0x2, 0x186, 0x180, 0x3, 0x2, 0x2, 0x2, 0x186, 0x182, 0x3, 0x2, 
    0x2, 0x2, 0x187, 0x37, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x9, 0x4, 0x2, 
    0x2, 0x189, 0x39, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x7, 0x25, 0x2, 
    0x2, 0x18b, 0x18c, 0x7, 0x2f, 0x2, 0x2, 0x18c, 0x18d, 0x5, 0x54, 0x2b, 
    0x2, 0x18d, 0x18e, 0x7, 0x30, 0x2, 0x2, 0x18e, 0x195, 0x3, 0x2, 0x2, 
    0x2, 0x18f, 0x190, 0x7, 0x25, 0x2, 0x2, 0x190, 0x191, 0x7, 0x2f, 0x2, 
    0x2, 0x191, 0x192, 0x5, 0x1e, 0x10, 0x2, 0x192, 0x193, 0x7, 0x30, 0x2, 
    0x2, 0x193, 0x195, 0x3, 0x2, 0x2, 0x2, 0x194, 0x18a, 0x3, 0x2, 0x2, 
    0x2, 0x194, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x195, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x196, 0x19a, 0x5, 0x3e, 0x20, 0x2, 0x197, 0x199, 0x5, 0x40, 0x21, 0x2, 
    0x198, 0x197, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19c, 0x3, 0x2, 0x2, 0x2, 
    0x19a, 0x198, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 
    0x19b, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19d, 
    0x19e, 0x8, 0x20, 0x1, 0x2, 0x19e, 0x1a7, 0x7, 0x5d, 0x2, 0x2, 0x19f, 
    0x1a0, 0x7, 0x2f, 0x2, 0x2, 0x1a0, 0x1a1, 0x5, 0x3c, 0x1f, 0x2, 0x1a1, 
    0x1a2, 0x7, 0x30, 0x2, 0x2, 0x1a2, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a3, 
    0x1a4, 0x7, 0x5d, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x4a, 0x2, 0x2, 0x1a5, 
    0x1a7, 0x7, 0x5f, 0x2, 0x2, 0x1a6, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x1a6, 
    0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a7, 
    0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0xc, 0x9, 0x2, 0x2, 0x1a9, 
    0x1ab, 0x7, 0x31, 0x2, 0x2, 0x1aa, 0x1ac, 0x5, 0x4a, 0x26, 0x2, 0x1ab, 
    0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ac, 
    0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1af, 0x5, 0x18, 0xd, 0x2, 0x1ae, 
    0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1af, 
    0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1d4, 0x7, 0x32, 0x2, 0x2, 0x1b1, 
    0x1b2, 0xc, 0x8, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0x31, 0x2, 0x2, 0x1b3, 
    0x1b5, 0x7, 0x1c, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 0x4a, 0x26, 0x2, 0x1b5, 
    0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b6, 
    0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x5, 0x18, 0xd, 0x2, 0x1b8, 
    0x1b9, 0x7, 0x32, 0x2, 0x2, 0x1b9, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1ba, 
    0x1bb, 0xc, 0x7, 0x2, 0x2, 0x1bb, 0x1bc, 0x7, 0x31, 0x2, 0x2, 0x1bc, 
    0x1bd, 0x5, 0x4a, 0x26, 0x2, 0x1bd, 0x1be, 0x7, 0x1c, 0x2, 0x2, 0x1be, 
    0x1bf, 0x5, 0x18, 0xd, 0x2, 0x1bf, 0x1c0, 0x7, 0x32, 0x2, 0x2, 0x1c0, 
    0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0xc, 0x6, 0x2, 0x2, 0x1c2, 
    0x1c4, 0x7, 0x31, 0x2, 0x2, 0x1c3, 0x1c5, 0x5, 0x4a, 0x26, 0x2, 0x1c4, 
    0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
    0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x7, 0x3f, 0x2, 0x2, 0x1c7, 
    0x1d4, 0x7, 0x32, 0x2, 0x2, 0x1c8, 0x1c9, 0xc, 0x5, 0x2, 0x2, 0x1c9, 
    0x1ca, 0x7, 0x2f, 0x2, 0x2, 0x1ca, 0x1cb, 0x5, 0x4c, 0x27, 0x2, 0x1cb, 
    0x1cc, 0x7, 0x30, 0x2, 0x2, 0x1cc, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1cd, 
    0x1ce, 0xc, 0x4, 0x2, 0x2, 0x1ce, 0x1d0, 0x7, 0x2f, 0x2, 0x2, 0x1cf, 
    0x1d1, 0x5, 0x52, 0x2a, 0x2, 0x1d0, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d0, 
    0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d2, 
    0x1d4, 0x7, 0x30, 0x2, 0x2, 0x1d3, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d5, 
    0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 
    0x7, 0x3, 0x2, 0x2, 0x1d9, 0x1db, 0x7, 0x2f, 0x2, 0x2, 0x1da, 0x1dc, 
    0x7, 0x60, 0x2, 0x2, 0x1db, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1dd, 
    0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 
    0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e2, 
    0x7, 0x30, 0x2, 0x2, 0x1e0, 0x1e2, 0x5, 0x42, 0x22, 0x2, 0x1e1, 0x1d8, 
    0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x7, 0x4, 0x2, 0x2, 0x1e4, 0x1e5, 0x7, 
    0x2f, 0x2, 0x2, 0x1e5, 0x1e6, 0x7, 0x2f, 0x2, 0x2, 0x1e6, 0x1e7, 0x5, 
    0x44, 0x23, 0x2, 0x1e7, 0x1e8, 0x7, 0x30, 0x2, 0x2, 0x1e8, 0x1e9, 0x7, 
    0x30, 0x2, 0x2, 0x1e9, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ef, 0x5, 
    0x46, 0x24, 0x2, 0x1eb, 0x1ec, 0x7, 0x4c, 0x2, 0x2, 0x1ec, 0x1ee, 0x5, 
    0x46, 0x24, 0x2, 0x1ed, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1f1, 0x3, 
    0x2, 0x2, 0x2, 0x1ef, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f0, 0x3, 
    0x2, 0x2, 0x2, 0x1f0, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1ef, 0x3, 
    0x2, 0x2, 0x2, 0x1f2, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1ea, 0x3, 
    0x2, 0x2, 0x2, 0x1f3, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x1f5, 0x1fb, 0xa, 0x5, 0x2, 0x2, 0x1f6, 0x1f8, 0x7, 0x2f, 
    0x2, 0x2, 0x1f7, 0x1f9, 0x5, 0x6, 0x4, 0x2, 0x1f8, 0x1f7, 0x3, 0x2, 
    0x2, 0x2, 0x1f8, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x3, 0x2, 
    0x2, 0x2, 0x1fa, 0x1fc, 0x7, 0x30, 0x2, 0x2, 0x1fb, 0x1f6, 0x3, 0x2, 
    0x2, 0x2, 0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1ff, 0x3, 0x2, 
    0x2, 0x2, 0x1fd, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1f5, 0x3, 0x2, 
    0x2, 0x2, 0x1fe, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x200, 0x206, 0xa, 0x6, 0x2, 0x2, 0x201, 0x202, 0x7, 0x2f, 0x2, 
    0x2, 0x202, 0x203, 0x5, 0x48, 0x25, 0x2, 0x203, 0x204, 0x7, 0x30, 0x2, 
    0x2, 0x204, 0x206, 0x3, 0x2, 0x2, 0x2, 0x205, 0x200, 0x3, 0x2, 0x2, 
    0x2, 0x205, 0x201, 0x3, 0x2, 0x2, 0x2, 0x206, 0x209, 0x3, 0x2, 0x2, 
    0x2, 0x207, 0x205, 0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x3, 0x2, 0x2, 
    0x2, 0x208, 0x49, 0x3, 0x2, 0x2, 0x2, 0x209, 0x207, 0x3, 0x2, 0x2, 0x2, 
    0x20a, 0x20b, 0x8, 0x26, 0x1, 0x2, 0x20b, 0x20c, 0x5, 0x38, 0x1d, 0x2, 
    0x20c, 0x211, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 0xc, 0x3, 0x2, 0x2, 
    0x20e, 0x210, 0x5, 0x38, 0x1d, 0x2, 0x20f, 0x20d, 0x3, 0x2, 0x2, 0x2, 
    0x210, 0x213, 0x3, 0x2, 0x2, 0x2, 0x211, 0x20f, 0x3, 0x2, 0x2, 0x2, 
    0x211, 0x212, 0x3, 0x2, 0x2, 0x2, 0x212, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x213, 
    0x211, 0x3, 0x2, 0x2, 0x2, 0x214, 0x21a, 0x5, 0x4e, 0x28, 0x2, 0x215, 
    0x216, 0x5, 0x4e, 0x28, 0x2, 0x216, 0x217, 0x7, 0x4c, 0x2, 0x2, 0x217, 
    0x218, 0x7, 0x5c, 0x2, 0x2, 0x218, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x219, 
    0x214, 0x3, 0x2, 0x2, 0x2, 0x219, 0x215, 0x3, 0x2, 0x2, 0x2, 0x21a, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x8, 0x28, 0x1, 0x2, 0x21c, 
    0x21d, 0x5, 0x50, 0x29, 0x2, 0x21d, 0x223, 0x3, 0x2, 0x2, 0x2, 0x21e, 
    0x21f, 0xc, 0x3, 0x2, 0x2, 0x21f, 0x220, 0x7, 0x4c, 0x2, 0x2, 0x220, 
    0x222, 0x5, 0x50, 0x29, 0x2, 0x221, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x222, 
    0x225, 0x3, 0x2, 0x2, 0x2, 0x223, 0x221, 0x3, 0x2, 0x2, 0x2, 0x223, 
    0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x225, 0x223, 
    0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 0x5, 0x22, 0x12, 0x2, 0x227, 0x228, 
    0x5, 0x3c, 0x1f, 0x2, 0x228, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22b, 
    0x5, 0x24, 0x13, 0x2, 0x22a, 0x22c, 0x5, 0x56, 0x2c, 0x2, 0x22b, 0x22a, 
    0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22e, 
    0x3, 0x2, 0x2, 0x2, 0x22d, 0x226, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x229, 
    0x3, 0x2, 0x2, 0x2, 0x22e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 0x8, 
    0x2a, 0x1, 0x2, 0x230, 0x231, 0x7, 0x5d, 0x2, 0x2, 0x231, 0x237, 0x3, 
    0x2, 0x2, 0x2, 0x232, 0x233, 0xc, 0x3, 0x2, 0x2, 0x233, 0x234, 0x7, 
    0x4c, 0x2, 0x2, 0x234, 0x236, 0x7, 0x5d, 0x2, 0x2, 0x235, 0x232, 0x3, 
    0x2, 0x2, 0x2, 0x236, 0x239, 0x3, 0x2, 0x2, 0x2, 0x237, 0x235, 0x3, 
    0x2, 0x2, 0x2, 0x237, 0x238, 0x3, 0x2, 0x2, 0x2, 0x238, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x239, 0x237, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23c, 0x5, 0x32, 
    0x1a, 0x2, 0x23b, 0x23d, 0x5, 0x56, 0x2c, 0x2, 0x23c, 0x23b, 0x3, 0x2, 
    0x2, 0x2, 0x23c, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x23e, 0x242, 0x5, 0x58, 0x2d, 0x2, 0x23f, 0x241, 0x5, 0x40, 0x21, 
    0x2, 0x240, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x241, 0x244, 0x3, 0x2, 0x2, 
    0x2, 0x242, 0x240, 0x3, 0x2, 0x2, 0x2, 0x242, 0x243, 0x3, 0x2, 0x2, 
    0x2, 0x243, 0x57, 0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 
    0x245, 0x246, 0x8, 0x2d, 0x1, 0x2, 0x246, 0x247, 0x7, 0x2f, 0x2, 0x2, 
    0x247, 0x248, 0x5, 0x56, 0x2c, 0x2, 0x248, 0x24c, 0x7, 0x30, 0x2, 0x2, 
    0x249, 0x24b, 0x5, 0x40, 0x21, 0x2, 0x24a, 0x249, 0x3, 0x2, 0x2, 0x2, 
    0x24b, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24a, 0x3, 0x2, 0x2, 0x2, 
    0x24c, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x274, 0x3, 0x2, 0x2, 0x2, 
    0x24e, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x251, 0x7, 0x31, 0x2, 0x2, 
    0x250, 0x252, 0x5, 0x4a, 0x26, 0x2, 0x251, 0x250, 0x3, 0x2, 0x2, 0x2, 
    0x251, 0x252, 0x3, 0x2, 0x2, 0x2, 0x252, 0x254, 0x3, 0x2, 0x2, 0x2, 
    0x253, 0x255, 0x5, 0x18, 0xd, 0x2, 0x254, 0x253, 0x3, 0x2, 0x2, 0x2, 
    0x254, 0x255, 0x3, 0x2, 0x2, 0x2, 0x255, 0x256, 0x3, 0x2, 0x2, 0x2, 
    0x256, 0x274, 0x7, 0x32, 0x2, 0x2, 0x257, 0x258, 0x7, 0x31, 0x2, 0x2, 
    0x258, 0x25a, 0x7, 0x1c, 0x2, 0x2, 0x259, 0x25b, 0x5, 0x4a, 0x26, 0x2, 
    0x25a, 0x259, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25b, 0x3, 0x2, 0x2, 0x2, 
    0x25b, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 0x5, 0x18, 0xd, 0x2, 
    0x25d, 0x25e, 0x7, 0x32, 0x2, 0x2, 0x25e, 0x274, 0x3, 0x2, 0x2, 0x2, 
    0x25f, 0x260, 0x7, 0x31, 0x2, 0x2, 0x260, 0x261, 0x5, 0x4a, 0x26, 0x2, 
    0x261, 0x262, 0x7, 0x1c, 0x2, 0x2, 0x262, 0x263, 0x5, 0x18, 0xd, 0x2, 
    0x263, 0x264, 0x7, 0x32, 0x2, 0x2, 0x264, 0x274, 0x3, 0x2, 0x2, 0x2, 
    0x265, 0x266, 0x7, 0x31, 0x2, 0x2, 0x266, 0x267, 0x7, 0x3f, 0x2, 0x2, 
    0x267, 0x274, 0x7, 0x32, 0x2, 0x2, 0x268, 0x26a, 0x7, 0x2f, 0x2, 0x2, 
    0x269, 0x26b, 0x5, 0x4c, 0x27, 0x2, 0x26a, 0x269, 0x3, 0x2, 0x2, 0x2, 
    0x26a, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 0x3, 0x2, 0x2, 0x2, 
    0x26c, 0x270, 0x7, 0x30, 0x2, 0x2, 0x26d, 0x26f, 0x5, 0x40, 0x21, 0x2, 
    0x26e, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x272, 0x3, 0x2, 0x2, 0x2, 
    0x270, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x270, 0x271, 0x3, 0x2, 0x2, 0x2, 
    0x271, 0x274, 0x3, 0x2, 0x2, 0x2, 0x272, 0x270, 0x3, 0x2, 0x2, 0x2, 
    0x273, 0x245, 0x3, 0x2, 0x2, 0x2, 0x273, 0x24f, 0x3, 0x2, 0x2, 0x2, 
    0x273, 0x257, 0x3, 0x2, 0x2, 0x2, 0x273, 0x25f, 0x3, 0x2, 0x2, 0x2, 
    0x273, 0x265, 0x3, 0x2, 0x2, 0x2, 0x273, 0x268, 0x3, 0x2, 0x2, 0x2, 
    0x274, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x275, 0x276, 0xc, 0x7, 0x2, 0x2, 
    0x276, 0x278, 0x7, 0x31, 0x2, 0x2, 0x277, 0x279, 0x5, 0x4a, 0x26, 0x2, 
    0x278, 0x277, 0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 0x3, 0x2, 0x2, 0x2, 
    0x279, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27c, 0x5, 0x18, 0xd, 0x2, 
    0x27b, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x27c, 0x3, 0x2, 0x2, 0x2, 
    0x27c, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x29f, 0x7, 0x32, 0x2, 0x2, 
    0x27e, 0x27f, 0xc, 0x6, 0x2, 0x2, 0x27f, 0x280, 0x7, 0x31, 0x2, 0x2, 
    0x280, 0x282, 0x7, 0x1c, 0x2, 0x2, 0x281, 0x283, 0x5, 0x4a, 0x26, 0x2, 
    0x282, 0x281, 0x3, 0x2, 0x2, 0x2, 0x282, 0x283, 0x3, 0x2, 0x2, 0x2, 
    0x283, 0x284, 0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 0x5, 0x18, 0xd, 0x2, 
    0x285, 0x286, 0x7, 0x32, 0x2, 0x2, 0x286, 0x29f, 0x3, 0x2, 0x2, 0x2, 
    0x287, 0x288, 0xc, 0x5, 0x2, 0x2, 0x288, 0x289, 0x7, 0x31, 0x2, 0x2, 
    0x289, 0x28a, 0x5, 0x4a, 0x26, 0x2, 0x28a, 0x28b, 0x7, 0x1c, 0x2, 0x2, 
    0x28b, 0x28c, 0x5, 0x18, 0xd, 0x2, 0x28c, 0x28d, 0x7, 0x32, 0x2, 0x2, 
    0x28d, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 0xc, 0x4, 0x2, 0x2, 
    0x28f, 0x290, 0x7, 0x31, 0x2, 0x2, 0x290, 0x291, 0x7, 0x3f, 0x2, 0x2, 
    0x291, 0x29f, 0x7, 0x32, 0x2, 0x2, 0x292, 0x293, 0xc, 0x3, 0x2, 0x2, 
    0x293, 0x295, 0x7, 0x2f, 0x2, 0x2, 0x294, 0x296, 0x5, 0x4c, 0x27, 0x2, 
    0x295, 0x294, 0x3, 0x2, 0x2, 0x2, 0x295, 0x296, 0x3, 0x2, 0x2, 0x2, 
    0x296, 0x297, 0x3, 0x2, 0x2, 0x2, 0x297, 0x29b, 0x7, 0x30, 0x2, 0x2, 
    0x298, 0x29a, 0x5, 0x40, 0x21, 0x2, 0x299, 0x298, 0x3, 0x2, 0x2, 0x2, 
    0x29a, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x299, 0x3, 0x2, 0x2, 0x2, 
    0x29b, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29f, 0x3, 0x2, 0x2, 0x2, 
    0x29d, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x275, 0x3, 0x2, 0x2, 0x2, 
    0x29e, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x287, 0x3, 0x2, 0x2, 0x2, 
    0x29e, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x292, 0x3, 0x2, 0x2, 0x2, 
    0x29f, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x29e, 0x3, 0x2, 0x2, 0x2, 
    0x2a0, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x59, 0x3, 0x2, 0x2, 0x2, 0x2a2, 
    0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a4, 0x7, 0x5d, 0x2, 0x2, 0x2a4, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2b0, 0x5, 0x18, 0xd, 0x2, 0x2a6, 
    0x2a7, 0x7, 0x33, 0x2, 0x2, 0x2a7, 0x2a8, 0x5, 0x5e, 0x30, 0x2, 0x2a8, 
    0x2a9, 0x7, 0x34, 0x2, 0x2, 0x2a9, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2aa, 
    0x2ab, 0x7, 0x33, 0x2, 0x2, 0x2ab, 0x2ac, 0x5, 0x5e, 0x30, 0x2, 0x2ac, 
    0x2ad, 0x7, 0x4c, 0x2, 0x2, 0x2ad, 0x2ae, 0x7, 0x34, 0x2, 0x2, 0x2ae, 
    0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2af, 
    0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2b0, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b3, 0x8, 0x30, 0x1, 0x2, 0x2b2, 
    0x2b4, 0x5, 0x60, 0x31, 0x2, 0x2b3, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b3, 
    0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b5, 
    0x2b6, 0x5, 0x5c, 0x2f, 0x2, 0x2b6, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2b7, 
    0x2b8, 0xc, 0x3, 0x2, 0x2, 0x2b8, 0x2ba, 0x7, 0x4c, 0x2, 0x2, 0x2b9, 
    0x2bb, 0x5, 0x60, 0x31, 0x2, 0x2ba, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2ba, 
    0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2bc, 
    0x2be, 0x5, 0x5c, 0x2f, 0x2, 0x2bd, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2be, 
    0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2bf, 
    0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2bf, 
    0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c3, 0x5, 0x62, 0x32, 0x2, 0x2c3, 0x2c4, 
    0x7, 0x4d, 0x2, 0x2, 0x2c4, 0x61, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 
    0x8, 0x32, 0x1, 0x2, 0x2c6, 0x2c7, 0x5, 0x64, 0x33, 0x2, 0x2c7, 0x2cc, 
    0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0xc, 0x3, 0x2, 0x2, 0x2c9, 0x2cb, 
    0x5, 0x64, 0x33, 0x2, 0x2ca, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2ce, 
    0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cd, 
    0x3, 0x2, 0x2, 0x2, 0x2cd, 0x63, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cc, 0x3, 
    0x2, 0x2, 0x2, 0x2cf, 0x2d0, 0x7, 0x31, 0x2, 0x2, 0x2d0, 0x2d1, 0x5, 
    0x1e, 0x10, 0x2, 0x2d1, 0x2d2, 0x7, 0x32, 0x2, 0x2, 0x2d2, 0x2d6, 0x3, 
    0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x7, 0x5b, 0x2, 0x2, 0x2d4, 0x2d6, 0x7, 
    0x5d, 0x2, 0x2, 0x2d5, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d3, 0x3, 
    0x2, 0x2, 0x2, 0x2d6, 0x65, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2de, 0x5, 0x68, 
    0x35, 0x2, 0x2d8, 0x2de, 0x5, 0x6a, 0x36, 0x2, 0x2d9, 0x2de, 0x5, 0x70, 
    0x39, 0x2, 0x2da, 0x2de, 0x5, 0x72, 0x3a, 0x2, 0x2db, 0x2de, 0x5, 0x74, 
    0x3b, 0x2, 0x2dc, 0x2de, 0x5, 0x7c, 0x3f, 0x2, 0x2dd, 0x2d7, 0x3, 0x2, 
    0x2, 0x2, 0x2dd, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2d9, 0x3, 0x2, 
    0x2, 0x2, 0x2dd, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2db, 0x3, 0x2, 
    0x2, 0x2, 0x2dd, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x2df, 0x2e0, 0x7, 0x5d, 0x2, 0x2, 0x2e0, 0x2e1, 0x7, 0x4a, 0x2, 
    0x2, 0x2e1, 0x2eb, 0x5, 0x66, 0x34, 0x2, 0x2e2, 0x2e3, 0x7, 0x6, 0x2, 
    0x2, 0x2e3, 0x2e4, 0x5, 0x1e, 0x10, 0x2, 0x2e4, 0x2e5, 0x7, 0x4a, 0x2, 
    0x2, 0x2e5, 0x2e6, 0x5, 0x66, 0x34, 0x2, 0x2e6, 0x2eb, 0x3, 0x2, 0x2, 
    0x2, 0x2e7, 0x2e8, 0x7, 0xa, 0x2, 0x2, 0x2e8, 0x2e9, 0x7, 0x4a, 0x2, 
    0x2, 0x2e9, 0x2eb, 0x5, 0x66, 0x34, 0x2, 0x2ea, 0x2df, 0x3, 0x2, 0x2, 
    0x2, 0x2ea, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2e7, 0x3, 0x2, 0x2, 
    0x2, 0x2eb, 0x69, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ee, 0x7, 0x33, 0x2, 
    0x2, 0x2ed, 0x2ef, 0x5, 0x6c, 0x37, 0x2, 0x2ee, 0x2ed, 0x3, 0x2, 0x2, 
    0x2, 0x2ee, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f0, 0x3, 0x2, 0x2, 
    0x2, 0x2f0, 0x2f1, 0x7, 0x34, 0x2, 0x2, 0x2f1, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x2f2, 0x2f3, 0x8, 0x37, 0x1, 0x2, 0x2f3, 0x2f4, 0x5, 0x6e, 0x38, 
    0x2, 0x2f4, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f6, 0xc, 0x3, 0x2, 
    0x2, 0x2f6, 0x2f8, 0x5, 0x6e, 0x38, 0x2, 0x2f7, 0x2f5, 0x3, 0x2, 0x2, 
    0x2, 0x2f8, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2f7, 0x3, 0x2, 0x2, 
    0x2, 0x2f9, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x2fb, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2ff, 0x5, 0x66, 0x34, 0x2, 
    0x2fd, 0x2ff, 0x5, 0x20, 0x11, 0x2, 0x2fe, 0x2fc, 0x3, 0x2, 0x2, 0x2, 
    0x2fe, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x300, 
    0x302, 0x5, 0x1c, 0xf, 0x2, 0x301, 0x300, 0x3, 0x2, 0x2, 0x2, 0x301, 
    0x302, 0x3, 0x2, 0x2, 0x2, 0x302, 0x303, 0x3, 0x2, 0x2, 0x2, 0x303, 
    0x304, 0x7, 0x4b, 0x2, 0x2, 0x304, 0x71, 0x3, 0x2, 0x2, 0x2, 0x305, 
    0x306, 0x7, 0x12, 0x2, 0x2, 0x306, 0x307, 0x7, 0x2f, 0x2, 0x2, 0x307, 
    0x308, 0x5, 0x1c, 0xf, 0x2, 0x308, 0x309, 0x7, 0x30, 0x2, 0x2, 0x309, 
    0x30c, 0x5, 0x66, 0x34, 0x2, 0x30a, 0x30b, 0x7, 0xd, 0x2, 0x2, 0x30b, 
    0x30d, 0x5, 0x66, 0x34, 0x2, 0x30c, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x30c, 
    0x30d, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x315, 0x3, 0x2, 0x2, 0x2, 0x30e, 
    0x30f, 0x7, 0x1e, 0x2, 0x2, 0x30f, 0x310, 0x7, 0x2f, 0x2, 0x2, 0x310, 
    0x311, 0x5, 0x1c, 0xf, 0x2, 0x311, 0x312, 0x7, 0x30, 0x2, 0x2, 0x312, 
    0x313, 0x5, 0x66, 0x34, 0x2, 0x313, 0x315, 0x3, 0x2, 0x2, 0x2, 0x314, 
    0x305, 0x3, 0x2, 0x2, 0x2, 0x314, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x315, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x316, 0x317, 0x7, 0x24, 0x2, 0x2, 0x317, 
    0x318, 0x7, 0x2f, 0x2, 0x2, 0x318, 0x319, 0x5, 0x1c, 0xf, 0x2, 0x319, 
    0x31a, 0x7, 0x30, 0x2, 0x2, 0x31a, 0x31b, 0x5, 0x66, 0x34, 0x2, 0x31b, 
    0x323, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31d, 0x7, 0x10, 0x2, 0x2, 0x31d, 
    0x31e, 0x7, 0x2f, 0x2, 0x2, 0x31e, 0x31f, 0x5, 0x76, 0x3c, 0x2, 0x31f, 
    0x320, 0x7, 0x30, 0x2, 0x2, 0x320, 0x321, 0x5, 0x66, 0x34, 0x2, 0x321, 
    0x323, 0x3, 0x2, 0x2, 0x2, 0x322, 0x316, 0x3, 0x2, 0x2, 0x2, 0x322, 
    0x31c, 0x3, 0x2, 0x2, 0x2, 0x323, 0x75, 0x3, 0x2, 0x2, 0x2, 0x324, 0x325, 
    0x5, 0x78, 0x3d, 0x2, 0x325, 0x327, 0x7, 0x4b, 0x2, 0x2, 0x326, 0x328, 
    0x5, 0x7a, 0x3e, 0x2, 0x327, 0x326, 0x3, 0x2, 0x2, 0x2, 0x327, 0x328, 
    0x3, 0x2, 0x2, 0x2, 0x328, 0x329, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32b, 
    0x7, 0x4b, 0x2, 0x2, 0x32a, 0x32c, 0x5, 0x7a, 0x3e, 0x2, 0x32b, 0x32a, 
    0x3, 0x2, 0x2, 0x2, 0x32b, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x339, 
    0x3, 0x2, 0x2, 0x2, 0x32d, 0x32f, 0x5, 0x1c, 0xf, 0x2, 0x32e, 0x32d, 
    0x3, 0x2, 0x2, 0x2, 0x32e, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x330, 
    0x3, 0x2, 0x2, 0x2, 0x330, 0x332, 0x7, 0x4b, 0x2, 0x2, 0x331, 0x333, 
    0x5, 0x7a, 0x3e, 0x2, 0x332, 0x331, 0x3, 0x2, 0x2, 0x2, 0x332, 0x333, 
    0x3, 0x2, 0x2, 0x2, 0x333, 0x334, 0x3, 0x2, 0x2, 0x2, 0x334, 0x336, 
    0x7, 0x4b, 0x2, 0x2, 0x335, 0x337, 0x5, 0x7a, 0x3e, 0x2, 0x336, 0x335, 
    0x3, 0x2, 0x2, 0x2, 0x336, 0x337, 0x3, 0x2, 0x2, 0x2, 0x337, 0x339, 
    0x3, 0x2, 0x2, 0x2, 0x338, 0x324, 0x3, 0x2, 0x2, 0x2, 0x338, 0x32e, 
    0x3, 0x2, 0x2, 0x2, 0x339, 0x77, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x33b, 0x5, 
    0x22, 0x12, 0x2, 0x33b, 0x33c, 0x5, 0x28, 0x15, 0x2, 0x33c, 0x33f, 0x3, 
    0x2, 0x2, 0x2, 0x33d, 0x33f, 0x5, 0x22, 0x12, 0x2, 0x33e, 0x33a, 0x3, 
    0x2, 0x2, 0x2, 0x33e, 0x33d, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x340, 0x341, 0x8, 0x3e, 0x1, 0x2, 0x341, 0x342, 0x5, 0x18, 
    0xd, 0x2, 0x342, 0x348, 0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 0xc, 0x3, 
    0x2, 0x2, 0x344, 0x345, 0x7, 0x4c, 0x2, 0x2, 0x345, 0x347, 0x5, 0x18, 
    0xd, 0x2, 0x346, 0x343, 0x3, 0x2, 0x2, 0x2, 0x347, 0x34a, 0x3, 0x2, 
    0x2, 0x2, 0x348, 0x346, 0x3, 0x2, 0x2, 0x2, 0x348, 0x349, 0x3, 0x2, 
    0x2, 0x2, 0x349, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x348, 0x3, 0x2, 0x2, 
    0x2, 0x34b, 0x34c, 0x7, 0x9, 0x2, 0x2, 0x34c, 0x355, 0x7, 0x4b, 0x2, 
    0x2, 0x34d, 0x34e, 0x7, 0x5, 0x2, 0x2, 0x34e, 0x355, 0x7, 0x4b, 0x2, 
    0x2, 0x34f, 0x351, 0x7, 0x18, 0x2, 0x2, 0x350, 0x352, 0x5, 0x1c, 0xf, 
    0x2, 0x351, 0x350, 0x3, 0x2, 0x2, 0x2, 0x351, 0x352, 0x3, 0x2, 0x2, 
    0x2, 0x352, 0x353, 0x3, 0x2, 0x2, 0x2, 0x353, 0x355, 0x7, 0x4b, 0x2, 
    0x2, 0x354, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x354, 0x34d, 0x3, 0x2, 0x2, 
    0x2, 0x354, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x355, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x356, 0x358, 0x5, 0x80, 0x41, 0x2, 0x357, 0x356, 0x3, 0x2, 0x2, 0x2, 
    0x357, 0x358, 0x3, 0x2, 0x2, 0x2, 0x358, 0x359, 0x3, 0x2, 0x2, 0x2, 
    0x359, 0x35a, 0x7, 0x2, 0x2, 0x3, 0x35a, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x35b, 
    0x35c, 0x8, 0x41, 0x1, 0x2, 0x35c, 0x35d, 0x5, 0x82, 0x42, 0x2, 0x35d, 
    0x362, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35f, 0xc, 0x3, 0x2, 0x2, 0x35f, 
    0x361, 0x5, 0x82, 0x42, 0x2, 0x360, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x361, 
    0x364, 0x3, 0x2, 0x2, 0x2, 0x362, 0x360, 0x3, 0x2, 0x2, 0x2, 0x362, 
    0x363, 0x3, 0x2, 0x2, 0x2, 0x363, 0x81, 0x3, 0x2, 0x2, 0x2, 0x364, 0x362, 
    0x3, 0x2, 0x2, 0x2, 0x365, 0x369, 0x5, 0x84, 0x43, 0x2, 0x366, 0x369, 
    0x5, 0x20, 0x11, 0x2, 0x367, 0x369, 0x7, 0x4b, 0x2, 0x2, 0x368, 0x365, 
    0x3, 0x2, 0x2, 0x2, 0x368, 0x366, 0x3, 0x2, 0x2, 0x2, 0x368, 0x367, 
    0x3, 0x2, 0x2, 0x2, 0x369, 0x83, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x36c, 0x5, 
    0x22, 0x12, 0x2, 0x36b, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36c, 0x3, 
    0x2, 0x2, 0x2, 0x36c, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x36f, 0x5, 
    0x3c, 0x1f, 0x2, 0x36e, 0x370, 0x5, 0x86, 0x44, 0x2, 0x36f, 0x36e, 0x3, 
    0x2, 0x2, 0x2, 0x36f, 0x370, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 0x3, 
    0x2, 0x2, 0x2, 0x371, 0x372, 0x5, 0x6a, 0x36, 0x2, 0x372, 0x85, 0x3, 
    0x2, 0x2, 0x2, 0x373, 0x374, 0x8, 0x44, 0x1, 0x2, 0x374, 0x375, 0x5, 
    0x20, 0x11, 0x2, 0x375, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x376, 0x377, 0xc, 
    0x3, 0x2, 0x2, 0x377, 0x379, 0x5, 0x20, 0x11, 0x2, 0x378, 0x376, 0x3, 
    0x2, 0x2, 0x2, 0x379, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x378, 0x3, 
    0x2, 0x2, 0x2, 0x37a, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x37c, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x8d, 0x93, 0x9b, 
    0xa2, 0xa4, 0xaf, 0xb9, 0xbd, 0xcb, 0xcd, 0xd9, 0xdb, 0xed, 0xef, 0xfb, 
    0xfd, 0x108, 0x113, 0x11c, 0x128, 0x134, 0x139, 0x13e, 0x143, 0x14d, 
    0x155, 0x159, 0x162, 0x167, 0x16d, 0x171, 0x173, 0x17d, 0x182, 0x186, 
    0x194, 0x19a, 0x1a6, 0x1ab, 0x1ae, 0x1b5, 0x1c4, 0x1d0, 0x1d3, 0x1d5, 
    0x1dd, 0x1e1, 0x1ef, 0x1f3, 0x1f8, 0x1fb, 0x1fe, 0x205, 0x207, 0x211, 
    0x219, 0x223, 0x22b, 0x22d, 0x237, 0x23c, 0x242, 0x24c, 0x251, 0x254, 
    0x25a, 0x26a, 0x270, 0x273, 0x278, 0x27b, 0x282, 0x295, 0x29b, 0x29e, 
    0x2a0, 0x2af, 0x2b3, 0x2ba, 0x2bf, 0x2cc, 0x2d5, 0x2dd, 0x2ea, 0x2ee, 
    0x2f9, 0x2fe, 0x301, 0x30c, 0x314, 0x322, 0x327, 0x32b, 0x32e, 0x332, 
    0x336, 0x338, 0x33e, 0x348, 0x351, 0x354, 0x357, 0x362, 0x368, 0x36b, 
    0x36f, 0x37a, 
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
