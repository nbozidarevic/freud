
// Generated from src/grammar/SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SimpleCVisitor.h"


/**
 * This class provides an empty implementation of SimpleCVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SimpleCBaseVisitor : public SimpleCVisitor {
public:

  virtual antlrcpp::Any visitPrimaryExpression(SimpleCParser::PrimaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostfixExpression(SimpleCParser::PostfixExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgumentExpressionList(SimpleCParser::ArgumentExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpression(SimpleCParser::UnaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleExpression(SimpleCParser::SimpleExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativeExpression(SimpleCParser::MultiplicativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveExpression(SimpleCParser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationalExpression(SimpleCParser::RelationalExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityExpression(SimpleCParser::EqualityExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalAndExpression(SimpleCParser::LogicalAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalOrExpression(SimpleCParser::LogicalOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentExpression(SimpleCParser::AssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperator(SimpleCParser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(SimpleCParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantExpression(SimpleCParser::ConstantExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(SimpleCParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationSpecifiers(SimpleCParser::DeclarationSpecifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationSpecifiers2(SimpleCParser::DeclarationSpecifiers2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationSpecifier(SimpleCParser::DeclarationSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitDeclaratorList(SimpleCParser::InitDeclaratorListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitDeclarator(SimpleCParser::InitDeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeSpecifier(SimpleCParser::TypeSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructDeclarationList(SimpleCParser::StructDeclarationListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructDeclaration(SimpleCParser::StructDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecifierQualifierList(SimpleCParser::SpecifierQualifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructDeclaratorList(SimpleCParser::StructDeclaratorListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructDeclarator(SimpleCParser::StructDeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeQualifier(SimpleCParser::TypeQualifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlignmentSpecifier(SimpleCParser::AlignmentSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarator(SimpleCParser::DeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDirectDeclarator(SimpleCParser::DirectDeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGccDeclaratorExtension(SimpleCParser::GccDeclaratorExtensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGccAttributeSpecifier(SimpleCParser::GccAttributeSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGccAttributeList(SimpleCParser::GccAttributeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGccAttribute(SimpleCParser::GccAttributeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNestedParenthesesBlock(SimpleCParser::NestedParenthesesBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeQualifierList(SimpleCParser::TypeQualifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterTypeList(SimpleCParser::ParameterTypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterList(SimpleCParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterDeclaration(SimpleCParser::ParameterDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierList(SimpleCParser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeName(SimpleCParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAbstractDeclarator(SimpleCParser::AbstractDeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDirectAbstractDeclarator(SimpleCParser::DirectAbstractDeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypedefName(SimpleCParser::TypedefNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitializer(SimpleCParser::InitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitializerList(SimpleCParser::InitializerListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDesignation(SimpleCParser::DesignationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDesignatorList(SimpleCParser::DesignatorListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDesignator(SimpleCParser::DesignatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(SimpleCParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabeledStatement(SimpleCParser::LabeledStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompoundStatement(SimpleCParser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockItemList(SimpleCParser::BlockItemListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockItem(SimpleCParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(SimpleCParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectionStatement(SimpleCParser::SelectionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIterationStatement(SimpleCParser::IterationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForCondition(SimpleCParser::ForConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForDeclaration(SimpleCParser::ForDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForExpression(SimpleCParser::ForExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJumpStatement(SimpleCParser::JumpStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompilationUnit(SimpleCParser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTranslationUnit(SimpleCParser::TranslationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternalDeclaration(SimpleCParser::ExternalDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefinition(SimpleCParser::FunctionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationList(SimpleCParser::DeclarationListContext *ctx) override {
    return visitChildren(ctx);
  }


};

