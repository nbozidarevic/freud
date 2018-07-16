
// Generated from src/grammar/SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SimpleCListener.h"


/**
 * This class provides an empty implementation of SimpleCListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SimpleCBaseListener : public SimpleCListener {
public:

  virtual void enterPrimaryExpression(SimpleCParser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(SimpleCParser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterPostfixExpression(SimpleCParser::PostfixExpressionContext * /*ctx*/) override { }
  virtual void exitPostfixExpression(SimpleCParser::PostfixExpressionContext * /*ctx*/) override { }

  virtual void enterArgumentExpressionList(SimpleCParser::ArgumentExpressionListContext * /*ctx*/) override { }
  virtual void exitArgumentExpressionList(SimpleCParser::ArgumentExpressionListContext * /*ctx*/) override { }

  virtual void enterUnaryExpression(SimpleCParser::UnaryExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryExpression(SimpleCParser::UnaryExpressionContext * /*ctx*/) override { }

  virtual void enterSimpleExpression(SimpleCParser::SimpleExpressionContext * /*ctx*/) override { }
  virtual void exitSimpleExpression(SimpleCParser::SimpleExpressionContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpression(SimpleCParser::MultiplicativeExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpression(SimpleCParser::MultiplicativeExpressionContext * /*ctx*/) override { }

  virtual void enterAdditiveExpression(SimpleCParser::AdditiveExpressionContext * /*ctx*/) override { }
  virtual void exitAdditiveExpression(SimpleCParser::AdditiveExpressionContext * /*ctx*/) override { }

  virtual void enterRelationalExpression(SimpleCParser::RelationalExpressionContext * /*ctx*/) override { }
  virtual void exitRelationalExpression(SimpleCParser::RelationalExpressionContext * /*ctx*/) override { }

  virtual void enterEqualityExpression(SimpleCParser::EqualityExpressionContext * /*ctx*/) override { }
  virtual void exitEqualityExpression(SimpleCParser::EqualityExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalAndExpression(SimpleCParser::LogicalAndExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalAndExpression(SimpleCParser::LogicalAndExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalOrExpression(SimpleCParser::LogicalOrExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalOrExpression(SimpleCParser::LogicalOrExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentExpression(SimpleCParser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(SimpleCParser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(SimpleCParser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(SimpleCParser::AssignmentOperatorContext * /*ctx*/) override { }

  virtual void enterExpression(SimpleCParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SimpleCParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterConstantExpression(SimpleCParser::ConstantExpressionContext * /*ctx*/) override { }
  virtual void exitConstantExpression(SimpleCParser::ConstantExpressionContext * /*ctx*/) override { }

  virtual void enterDeclaration(SimpleCParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(SimpleCParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifiers(SimpleCParser::DeclarationSpecifiersContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifiers(SimpleCParser::DeclarationSpecifiersContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifiers2(SimpleCParser::DeclarationSpecifiers2Context * /*ctx*/) override { }
  virtual void exitDeclarationSpecifiers2(SimpleCParser::DeclarationSpecifiers2Context * /*ctx*/) override { }

  virtual void enterDeclarationSpecifier(SimpleCParser::DeclarationSpecifierContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifier(SimpleCParser::DeclarationSpecifierContext * /*ctx*/) override { }

  virtual void enterInitDeclaratorList(SimpleCParser::InitDeclaratorListContext * /*ctx*/) override { }
  virtual void exitInitDeclaratorList(SimpleCParser::InitDeclaratorListContext * /*ctx*/) override { }

  virtual void enterInitDeclarator(SimpleCParser::InitDeclaratorContext * /*ctx*/) override { }
  virtual void exitInitDeclarator(SimpleCParser::InitDeclaratorContext * /*ctx*/) override { }

  virtual void enterTypeSpecifier(SimpleCParser::TypeSpecifierContext * /*ctx*/) override { }
  virtual void exitTypeSpecifier(SimpleCParser::TypeSpecifierContext * /*ctx*/) override { }

  virtual void enterStructDeclarationList(SimpleCParser::StructDeclarationListContext * /*ctx*/) override { }
  virtual void exitStructDeclarationList(SimpleCParser::StructDeclarationListContext * /*ctx*/) override { }

  virtual void enterStructDeclaration(SimpleCParser::StructDeclarationContext * /*ctx*/) override { }
  virtual void exitStructDeclaration(SimpleCParser::StructDeclarationContext * /*ctx*/) override { }

  virtual void enterSpecifierQualifierList(SimpleCParser::SpecifierQualifierListContext * /*ctx*/) override { }
  virtual void exitSpecifierQualifierList(SimpleCParser::SpecifierQualifierListContext * /*ctx*/) override { }

  virtual void enterStructDeclaratorList(SimpleCParser::StructDeclaratorListContext * /*ctx*/) override { }
  virtual void exitStructDeclaratorList(SimpleCParser::StructDeclaratorListContext * /*ctx*/) override { }

  virtual void enterStructDeclarator(SimpleCParser::StructDeclaratorContext * /*ctx*/) override { }
  virtual void exitStructDeclarator(SimpleCParser::StructDeclaratorContext * /*ctx*/) override { }

  virtual void enterTypeQualifier(SimpleCParser::TypeQualifierContext * /*ctx*/) override { }
  virtual void exitTypeQualifier(SimpleCParser::TypeQualifierContext * /*ctx*/) override { }

  virtual void enterAlignmentSpecifier(SimpleCParser::AlignmentSpecifierContext * /*ctx*/) override { }
  virtual void exitAlignmentSpecifier(SimpleCParser::AlignmentSpecifierContext * /*ctx*/) override { }

  virtual void enterDeclarator(SimpleCParser::DeclaratorContext * /*ctx*/) override { }
  virtual void exitDeclarator(SimpleCParser::DeclaratorContext * /*ctx*/) override { }

  virtual void enterDirectDeclarator(SimpleCParser::DirectDeclaratorContext * /*ctx*/) override { }
  virtual void exitDirectDeclarator(SimpleCParser::DirectDeclaratorContext * /*ctx*/) override { }

  virtual void enterGccDeclaratorExtension(SimpleCParser::GccDeclaratorExtensionContext * /*ctx*/) override { }
  virtual void exitGccDeclaratorExtension(SimpleCParser::GccDeclaratorExtensionContext * /*ctx*/) override { }

  virtual void enterGccAttributeSpecifier(SimpleCParser::GccAttributeSpecifierContext * /*ctx*/) override { }
  virtual void exitGccAttributeSpecifier(SimpleCParser::GccAttributeSpecifierContext * /*ctx*/) override { }

  virtual void enterGccAttributeList(SimpleCParser::GccAttributeListContext * /*ctx*/) override { }
  virtual void exitGccAttributeList(SimpleCParser::GccAttributeListContext * /*ctx*/) override { }

  virtual void enterGccAttribute(SimpleCParser::GccAttributeContext * /*ctx*/) override { }
  virtual void exitGccAttribute(SimpleCParser::GccAttributeContext * /*ctx*/) override { }

  virtual void enterNestedParenthesesBlock(SimpleCParser::NestedParenthesesBlockContext * /*ctx*/) override { }
  virtual void exitNestedParenthesesBlock(SimpleCParser::NestedParenthesesBlockContext * /*ctx*/) override { }

  virtual void enterTypeQualifierList(SimpleCParser::TypeQualifierListContext * /*ctx*/) override { }
  virtual void exitTypeQualifierList(SimpleCParser::TypeQualifierListContext * /*ctx*/) override { }

  virtual void enterParameterTypeList(SimpleCParser::ParameterTypeListContext * /*ctx*/) override { }
  virtual void exitParameterTypeList(SimpleCParser::ParameterTypeListContext * /*ctx*/) override { }

  virtual void enterParameterList(SimpleCParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(SimpleCParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameterDeclaration(SimpleCParser::ParameterDeclarationContext * /*ctx*/) override { }
  virtual void exitParameterDeclaration(SimpleCParser::ParameterDeclarationContext * /*ctx*/) override { }

  virtual void enterIdentifierList(SimpleCParser::IdentifierListContext * /*ctx*/) override { }
  virtual void exitIdentifierList(SimpleCParser::IdentifierListContext * /*ctx*/) override { }

  virtual void enterTypeName(SimpleCParser::TypeNameContext * /*ctx*/) override { }
  virtual void exitTypeName(SimpleCParser::TypeNameContext * /*ctx*/) override { }

  virtual void enterAbstractDeclarator(SimpleCParser::AbstractDeclaratorContext * /*ctx*/) override { }
  virtual void exitAbstractDeclarator(SimpleCParser::AbstractDeclaratorContext * /*ctx*/) override { }

  virtual void enterDirectAbstractDeclarator(SimpleCParser::DirectAbstractDeclaratorContext * /*ctx*/) override { }
  virtual void exitDirectAbstractDeclarator(SimpleCParser::DirectAbstractDeclaratorContext * /*ctx*/) override { }

  virtual void enterTypedefName(SimpleCParser::TypedefNameContext * /*ctx*/) override { }
  virtual void exitTypedefName(SimpleCParser::TypedefNameContext * /*ctx*/) override { }

  virtual void enterInitializer(SimpleCParser::InitializerContext * /*ctx*/) override { }
  virtual void exitInitializer(SimpleCParser::InitializerContext * /*ctx*/) override { }

  virtual void enterInitializerList(SimpleCParser::InitializerListContext * /*ctx*/) override { }
  virtual void exitInitializerList(SimpleCParser::InitializerListContext * /*ctx*/) override { }

  virtual void enterDesignation(SimpleCParser::DesignationContext * /*ctx*/) override { }
  virtual void exitDesignation(SimpleCParser::DesignationContext * /*ctx*/) override { }

  virtual void enterDesignatorList(SimpleCParser::DesignatorListContext * /*ctx*/) override { }
  virtual void exitDesignatorList(SimpleCParser::DesignatorListContext * /*ctx*/) override { }

  virtual void enterDesignator(SimpleCParser::DesignatorContext * /*ctx*/) override { }
  virtual void exitDesignator(SimpleCParser::DesignatorContext * /*ctx*/) override { }

  virtual void enterStatement(SimpleCParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(SimpleCParser::StatementContext * /*ctx*/) override { }

  virtual void enterLabeledStatement(SimpleCParser::LabeledStatementContext * /*ctx*/) override { }
  virtual void exitLabeledStatement(SimpleCParser::LabeledStatementContext * /*ctx*/) override { }

  virtual void enterCompoundStatement(SimpleCParser::CompoundStatementContext * /*ctx*/) override { }
  virtual void exitCompoundStatement(SimpleCParser::CompoundStatementContext * /*ctx*/) override { }

  virtual void enterBlockItemList(SimpleCParser::BlockItemListContext * /*ctx*/) override { }
  virtual void exitBlockItemList(SimpleCParser::BlockItemListContext * /*ctx*/) override { }

  virtual void enterBlockItem(SimpleCParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(SimpleCParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(SimpleCParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(SimpleCParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterSelectionStatement(SimpleCParser::SelectionStatementContext * /*ctx*/) override { }
  virtual void exitSelectionStatement(SimpleCParser::SelectionStatementContext * /*ctx*/) override { }

  virtual void enterIterationStatement(SimpleCParser::IterationStatementContext * /*ctx*/) override { }
  virtual void exitIterationStatement(SimpleCParser::IterationStatementContext * /*ctx*/) override { }

  virtual void enterForCondition(SimpleCParser::ForConditionContext * /*ctx*/) override { }
  virtual void exitForCondition(SimpleCParser::ForConditionContext * /*ctx*/) override { }

  virtual void enterForDeclaration(SimpleCParser::ForDeclarationContext * /*ctx*/) override { }
  virtual void exitForDeclaration(SimpleCParser::ForDeclarationContext * /*ctx*/) override { }

  virtual void enterForExpression(SimpleCParser::ForExpressionContext * /*ctx*/) override { }
  virtual void exitForExpression(SimpleCParser::ForExpressionContext * /*ctx*/) override { }

  virtual void enterJumpStatement(SimpleCParser::JumpStatementContext * /*ctx*/) override { }
  virtual void exitJumpStatement(SimpleCParser::JumpStatementContext * /*ctx*/) override { }

  virtual void enterCompilationUnit(SimpleCParser::CompilationUnitContext * /*ctx*/) override { }
  virtual void exitCompilationUnit(SimpleCParser::CompilationUnitContext * /*ctx*/) override { }

  virtual void enterTranslationUnit(SimpleCParser::TranslationUnitContext * /*ctx*/) override { }
  virtual void exitTranslationUnit(SimpleCParser::TranslationUnitContext * /*ctx*/) override { }

  virtual void enterExternalDeclaration(SimpleCParser::ExternalDeclarationContext * /*ctx*/) override { }
  virtual void exitExternalDeclaration(SimpleCParser::ExternalDeclarationContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(SimpleCParser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(SimpleCParser::FunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterDeclarationList(SimpleCParser::DeclarationListContext * /*ctx*/) override { }
  virtual void exitDeclarationList(SimpleCParser::DeclarationListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

