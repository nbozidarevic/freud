
// Generated from src/grammar/SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SimpleCParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SimpleCParser.
 */
class  SimpleCListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterPrimaryExpression(SimpleCParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(SimpleCParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterPostfixExpression(SimpleCParser::PostfixExpressionContext *ctx) = 0;
  virtual void exitPostfixExpression(SimpleCParser::PostfixExpressionContext *ctx) = 0;

  virtual void enterArgumentExpressionList(SimpleCParser::ArgumentExpressionListContext *ctx) = 0;
  virtual void exitArgumentExpressionList(SimpleCParser::ArgumentExpressionListContext *ctx) = 0;

  virtual void enterUnaryExpression(SimpleCParser::UnaryExpressionContext *ctx) = 0;
  virtual void exitUnaryExpression(SimpleCParser::UnaryExpressionContext *ctx) = 0;

  virtual void enterSimpleExpression(SimpleCParser::SimpleExpressionContext *ctx) = 0;
  virtual void exitSimpleExpression(SimpleCParser::SimpleExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(SimpleCParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(SimpleCParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(SimpleCParser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(SimpleCParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterRelationalExpression(SimpleCParser::RelationalExpressionContext *ctx) = 0;
  virtual void exitRelationalExpression(SimpleCParser::RelationalExpressionContext *ctx) = 0;

  virtual void enterEqualityExpression(SimpleCParser::EqualityExpressionContext *ctx) = 0;
  virtual void exitEqualityExpression(SimpleCParser::EqualityExpressionContext *ctx) = 0;

  virtual void enterLogicalAndExpression(SimpleCParser::LogicalAndExpressionContext *ctx) = 0;
  virtual void exitLogicalAndExpression(SimpleCParser::LogicalAndExpressionContext *ctx) = 0;

  virtual void enterLogicalOrExpression(SimpleCParser::LogicalOrExpressionContext *ctx) = 0;
  virtual void exitLogicalOrExpression(SimpleCParser::LogicalOrExpressionContext *ctx) = 0;

  virtual void enterAssignmentExpression(SimpleCParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(SimpleCParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterAssignmentOperator(SimpleCParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(SimpleCParser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterExpression(SimpleCParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SimpleCParser::ExpressionContext *ctx) = 0;

  virtual void enterConstantExpression(SimpleCParser::ConstantExpressionContext *ctx) = 0;
  virtual void exitConstantExpression(SimpleCParser::ConstantExpressionContext *ctx) = 0;

  virtual void enterDeclaration(SimpleCParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(SimpleCParser::DeclarationContext *ctx) = 0;

  virtual void enterDeclarationSpecifiers(SimpleCParser::DeclarationSpecifiersContext *ctx) = 0;
  virtual void exitDeclarationSpecifiers(SimpleCParser::DeclarationSpecifiersContext *ctx) = 0;

  virtual void enterDeclarationSpecifiers2(SimpleCParser::DeclarationSpecifiers2Context *ctx) = 0;
  virtual void exitDeclarationSpecifiers2(SimpleCParser::DeclarationSpecifiers2Context *ctx) = 0;

  virtual void enterDeclarationSpecifier(SimpleCParser::DeclarationSpecifierContext *ctx) = 0;
  virtual void exitDeclarationSpecifier(SimpleCParser::DeclarationSpecifierContext *ctx) = 0;

  virtual void enterInitDeclaratorList(SimpleCParser::InitDeclaratorListContext *ctx) = 0;
  virtual void exitInitDeclaratorList(SimpleCParser::InitDeclaratorListContext *ctx) = 0;

  virtual void enterInitDeclarator(SimpleCParser::InitDeclaratorContext *ctx) = 0;
  virtual void exitInitDeclarator(SimpleCParser::InitDeclaratorContext *ctx) = 0;

  virtual void enterTypeSpecifier(SimpleCParser::TypeSpecifierContext *ctx) = 0;
  virtual void exitTypeSpecifier(SimpleCParser::TypeSpecifierContext *ctx) = 0;

  virtual void enterStructDeclarationList(SimpleCParser::StructDeclarationListContext *ctx) = 0;
  virtual void exitStructDeclarationList(SimpleCParser::StructDeclarationListContext *ctx) = 0;

  virtual void enterStructDeclaration(SimpleCParser::StructDeclarationContext *ctx) = 0;
  virtual void exitStructDeclaration(SimpleCParser::StructDeclarationContext *ctx) = 0;

  virtual void enterSpecifierQualifierList(SimpleCParser::SpecifierQualifierListContext *ctx) = 0;
  virtual void exitSpecifierQualifierList(SimpleCParser::SpecifierQualifierListContext *ctx) = 0;

  virtual void enterStructDeclaratorList(SimpleCParser::StructDeclaratorListContext *ctx) = 0;
  virtual void exitStructDeclaratorList(SimpleCParser::StructDeclaratorListContext *ctx) = 0;

  virtual void enterStructDeclarator(SimpleCParser::StructDeclaratorContext *ctx) = 0;
  virtual void exitStructDeclarator(SimpleCParser::StructDeclaratorContext *ctx) = 0;

  virtual void enterTypeQualifier(SimpleCParser::TypeQualifierContext *ctx) = 0;
  virtual void exitTypeQualifier(SimpleCParser::TypeQualifierContext *ctx) = 0;

  virtual void enterAlignmentSpecifier(SimpleCParser::AlignmentSpecifierContext *ctx) = 0;
  virtual void exitAlignmentSpecifier(SimpleCParser::AlignmentSpecifierContext *ctx) = 0;

  virtual void enterDeclarator(SimpleCParser::DeclaratorContext *ctx) = 0;
  virtual void exitDeclarator(SimpleCParser::DeclaratorContext *ctx) = 0;

  virtual void enterDirectDeclarator(SimpleCParser::DirectDeclaratorContext *ctx) = 0;
  virtual void exitDirectDeclarator(SimpleCParser::DirectDeclaratorContext *ctx) = 0;

  virtual void enterGccDeclaratorExtension(SimpleCParser::GccDeclaratorExtensionContext *ctx) = 0;
  virtual void exitGccDeclaratorExtension(SimpleCParser::GccDeclaratorExtensionContext *ctx) = 0;

  virtual void enterGccAttributeSpecifier(SimpleCParser::GccAttributeSpecifierContext *ctx) = 0;
  virtual void exitGccAttributeSpecifier(SimpleCParser::GccAttributeSpecifierContext *ctx) = 0;

  virtual void enterGccAttributeList(SimpleCParser::GccAttributeListContext *ctx) = 0;
  virtual void exitGccAttributeList(SimpleCParser::GccAttributeListContext *ctx) = 0;

  virtual void enterGccAttribute(SimpleCParser::GccAttributeContext *ctx) = 0;
  virtual void exitGccAttribute(SimpleCParser::GccAttributeContext *ctx) = 0;

  virtual void enterNestedParenthesesBlock(SimpleCParser::NestedParenthesesBlockContext *ctx) = 0;
  virtual void exitNestedParenthesesBlock(SimpleCParser::NestedParenthesesBlockContext *ctx) = 0;

  virtual void enterTypeQualifierList(SimpleCParser::TypeQualifierListContext *ctx) = 0;
  virtual void exitTypeQualifierList(SimpleCParser::TypeQualifierListContext *ctx) = 0;

  virtual void enterParameterTypeList(SimpleCParser::ParameterTypeListContext *ctx) = 0;
  virtual void exitParameterTypeList(SimpleCParser::ParameterTypeListContext *ctx) = 0;

  virtual void enterParameterList(SimpleCParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(SimpleCParser::ParameterListContext *ctx) = 0;

  virtual void enterParameterDeclaration(SimpleCParser::ParameterDeclarationContext *ctx) = 0;
  virtual void exitParameterDeclaration(SimpleCParser::ParameterDeclarationContext *ctx) = 0;

  virtual void enterIdentifierList(SimpleCParser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(SimpleCParser::IdentifierListContext *ctx) = 0;

  virtual void enterTypeName(SimpleCParser::TypeNameContext *ctx) = 0;
  virtual void exitTypeName(SimpleCParser::TypeNameContext *ctx) = 0;

  virtual void enterAbstractDeclarator(SimpleCParser::AbstractDeclaratorContext *ctx) = 0;
  virtual void exitAbstractDeclarator(SimpleCParser::AbstractDeclaratorContext *ctx) = 0;

  virtual void enterDirectAbstractDeclarator(SimpleCParser::DirectAbstractDeclaratorContext *ctx) = 0;
  virtual void exitDirectAbstractDeclarator(SimpleCParser::DirectAbstractDeclaratorContext *ctx) = 0;

  virtual void enterTypedefName(SimpleCParser::TypedefNameContext *ctx) = 0;
  virtual void exitTypedefName(SimpleCParser::TypedefNameContext *ctx) = 0;

  virtual void enterInitializer(SimpleCParser::InitializerContext *ctx) = 0;
  virtual void exitInitializer(SimpleCParser::InitializerContext *ctx) = 0;

  virtual void enterInitializerList(SimpleCParser::InitializerListContext *ctx) = 0;
  virtual void exitInitializerList(SimpleCParser::InitializerListContext *ctx) = 0;

  virtual void enterDesignation(SimpleCParser::DesignationContext *ctx) = 0;
  virtual void exitDesignation(SimpleCParser::DesignationContext *ctx) = 0;

  virtual void enterDesignatorList(SimpleCParser::DesignatorListContext *ctx) = 0;
  virtual void exitDesignatorList(SimpleCParser::DesignatorListContext *ctx) = 0;

  virtual void enterDesignator(SimpleCParser::DesignatorContext *ctx) = 0;
  virtual void exitDesignator(SimpleCParser::DesignatorContext *ctx) = 0;

  virtual void enterStatement(SimpleCParser::StatementContext *ctx) = 0;
  virtual void exitStatement(SimpleCParser::StatementContext *ctx) = 0;

  virtual void enterLabeledStatement(SimpleCParser::LabeledStatementContext *ctx) = 0;
  virtual void exitLabeledStatement(SimpleCParser::LabeledStatementContext *ctx) = 0;

  virtual void enterCompoundStatement(SimpleCParser::CompoundStatementContext *ctx) = 0;
  virtual void exitCompoundStatement(SimpleCParser::CompoundStatementContext *ctx) = 0;

  virtual void enterBlockItemList(SimpleCParser::BlockItemListContext *ctx) = 0;
  virtual void exitBlockItemList(SimpleCParser::BlockItemListContext *ctx) = 0;

  virtual void enterBlockItem(SimpleCParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(SimpleCParser::BlockItemContext *ctx) = 0;

  virtual void enterExpressionStatement(SimpleCParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(SimpleCParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterSelectionStatement(SimpleCParser::SelectionStatementContext *ctx) = 0;
  virtual void exitSelectionStatement(SimpleCParser::SelectionStatementContext *ctx) = 0;

  virtual void enterIterationStatement(SimpleCParser::IterationStatementContext *ctx) = 0;
  virtual void exitIterationStatement(SimpleCParser::IterationStatementContext *ctx) = 0;

  virtual void enterForCondition(SimpleCParser::ForConditionContext *ctx) = 0;
  virtual void exitForCondition(SimpleCParser::ForConditionContext *ctx) = 0;

  virtual void enterForDeclaration(SimpleCParser::ForDeclarationContext *ctx) = 0;
  virtual void exitForDeclaration(SimpleCParser::ForDeclarationContext *ctx) = 0;

  virtual void enterForExpression(SimpleCParser::ForExpressionContext *ctx) = 0;
  virtual void exitForExpression(SimpleCParser::ForExpressionContext *ctx) = 0;

  virtual void enterJumpStatement(SimpleCParser::JumpStatementContext *ctx) = 0;
  virtual void exitJumpStatement(SimpleCParser::JumpStatementContext *ctx) = 0;

  virtual void enterCompilationUnit(SimpleCParser::CompilationUnitContext *ctx) = 0;
  virtual void exitCompilationUnit(SimpleCParser::CompilationUnitContext *ctx) = 0;

  virtual void enterTranslationUnit(SimpleCParser::TranslationUnitContext *ctx) = 0;
  virtual void exitTranslationUnit(SimpleCParser::TranslationUnitContext *ctx) = 0;

  virtual void enterExternalDeclaration(SimpleCParser::ExternalDeclarationContext *ctx) = 0;
  virtual void exitExternalDeclaration(SimpleCParser::ExternalDeclarationContext *ctx) = 0;

  virtual void enterFunctionDefinition(SimpleCParser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(SimpleCParser::FunctionDefinitionContext *ctx) = 0;

  virtual void enterDeclarationList(SimpleCParser::DeclarationListContext *ctx) = 0;
  virtual void exitDeclarationList(SimpleCParser::DeclarationListContext *ctx) = 0;


};

