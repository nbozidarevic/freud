
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
    virtual antlrcpp::Any visitPrimaryExpression(SimpleCParser::PrimaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPostfixExpression(SimpleCParser::PostfixExpressionContext *context) = 0;

    virtual antlrcpp::Any visitArgumentExpressionList(SimpleCParser::ArgumentExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpression(SimpleCParser::UnaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSimpleExpression(SimpleCParser::SimpleExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeExpression(SimpleCParser::MultiplicativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveExpression(SimpleCParser::AdditiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationalExpression(SimpleCParser::RelationalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualityExpression(SimpleCParser::EqualityExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalAndExpression(SimpleCParser::LogicalAndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOrExpression(SimpleCParser::LogicalOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentExpression(SimpleCParser::AssignmentExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentOperator(SimpleCParser::AssignmentOperatorContext *context) = 0;

    virtual antlrcpp::Any visitExpression(SimpleCParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConstantExpression(SimpleCParser::ConstantExpressionContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(SimpleCParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifiers(SimpleCParser::DeclarationSpecifiersContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifiers2(SimpleCParser::DeclarationSpecifiers2Context *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifier(SimpleCParser::DeclarationSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclaratorList(SimpleCParser::InitDeclaratorListContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclarator(SimpleCParser::InitDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitTypeSpecifier(SimpleCParser::TypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclarationList(SimpleCParser::StructDeclarationListContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclaration(SimpleCParser::StructDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitSpecifierQualifierList(SimpleCParser::SpecifierQualifierListContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclaratorList(SimpleCParser::StructDeclaratorListContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclarator(SimpleCParser::StructDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitTypeQualifier(SimpleCParser::TypeQualifierContext *context) = 0;

    virtual antlrcpp::Any visitAlignmentSpecifier(SimpleCParser::AlignmentSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitDeclarator(SimpleCParser::DeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitDirectDeclarator(SimpleCParser::DirectDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitGccDeclaratorExtension(SimpleCParser::GccDeclaratorExtensionContext *context) = 0;

    virtual antlrcpp::Any visitGccAttributeSpecifier(SimpleCParser::GccAttributeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitGccAttributeList(SimpleCParser::GccAttributeListContext *context) = 0;

    virtual antlrcpp::Any visitGccAttribute(SimpleCParser::GccAttributeContext *context) = 0;

    virtual antlrcpp::Any visitNestedParenthesesBlock(SimpleCParser::NestedParenthesesBlockContext *context) = 0;

    virtual antlrcpp::Any visitTypeQualifierList(SimpleCParser::TypeQualifierListContext *context) = 0;

    virtual antlrcpp::Any visitParameterTypeList(SimpleCParser::ParameterTypeListContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(SimpleCParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclaration(SimpleCParser::ParameterDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(SimpleCParser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(SimpleCParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitAbstractDeclarator(SimpleCParser::AbstractDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitDirectAbstractDeclarator(SimpleCParser::DirectAbstractDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitTypedefName(SimpleCParser::TypedefNameContext *context) = 0;

    virtual antlrcpp::Any visitInitializer(SimpleCParser::InitializerContext *context) = 0;

    virtual antlrcpp::Any visitInitializerList(SimpleCParser::InitializerListContext *context) = 0;

    virtual antlrcpp::Any visitDesignation(SimpleCParser::DesignationContext *context) = 0;

    virtual antlrcpp::Any visitDesignatorList(SimpleCParser::DesignatorListContext *context) = 0;

    virtual antlrcpp::Any visitDesignator(SimpleCParser::DesignatorContext *context) = 0;

    virtual antlrcpp::Any visitStatement(SimpleCParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitLabeledStatement(SimpleCParser::LabeledStatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(SimpleCParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockItemList(SimpleCParser::BlockItemListContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(SimpleCParser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(SimpleCParser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitSelectionStatement(SimpleCParser::SelectionStatementContext *context) = 0;

    virtual antlrcpp::Any visitIterationStatement(SimpleCParser::IterationStatementContext *context) = 0;

    virtual antlrcpp::Any visitForCondition(SimpleCParser::ForConditionContext *context) = 0;

    virtual antlrcpp::Any visitForDeclaration(SimpleCParser::ForDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitForExpression(SimpleCParser::ForExpressionContext *context) = 0;

    virtual antlrcpp::Any visitJumpStatement(SimpleCParser::JumpStatementContext *context) = 0;

    virtual antlrcpp::Any visitCompilationUnit(SimpleCParser::CompilationUnitContext *context) = 0;

    virtual antlrcpp::Any visitTranslationUnit(SimpleCParser::TranslationUnitContext *context) = 0;

    virtual antlrcpp::Any visitExternalDeclaration(SimpleCParser::ExternalDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(SimpleCParser::FunctionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationList(SimpleCParser::DeclarationListContext *context) = 0;


};

