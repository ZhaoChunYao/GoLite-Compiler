#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

extern int yylineno;

Exp *newExp(ExpKind k,int lineno)
{
	Exp *n=malloc(sizeof(Exp));
	n->lineno=lineno;
	n->kind=k;
	return n;
}

Type *newType(TypeKind k, int lineno){
	Type *n = malloc(sizeof(Type));
	n->lineno = lineno;
	n->kind = k;
	return n;
}

Exp *newIdentifiers(Exp* ids, Exp* id, int lineno)
{
	Exp *n=newExp(k_NodeKindIdentifiers, lineno);
	n->val.expressions.expressions = ids;
	n->val.expressions.expression = id;
	return n;
}

Exp *newIdentifier(char* id, int lineno)
{
	Exp *n = newExp(k_NodeKindIdentifier, lineno);
	n->val.identifier = id;
	return n;
}

Prog *newProgram(Decl* package_dec, Decl* top_decs, int lineno)
{
	Prog *n = malloc(sizeof(Prog));
	n->lineno=lineno;
    	n->program.package_dec = package_dec;
    	n->program.top_decs = top_decs;
    	return n;
}

Decl *newDecl(DeclKind k,int lineno)
{
	Decl *n=malloc(sizeof(Decl));
	n->lineno=lineno;
	n->kind=k;
	return n;
}

Decl *newPackage_dec(Exp* identifier, int lineno)
{
	Decl *n = newDecl(k_NodeKindPackageDec, lineno);
    	n->val.package_dec.identifier = identifier;
    	return n;
}

Decl *newTop_decs(Decl* top_decs, Decl* dec, int lineno)
{

    	Decl *n = newDecl(k_NodeKindTopDecs, lineno);
   	n->val.top_decs.top_decs = top_decs;
	n->val.top_decs.dec = dec;
   	return n;
}
Decl *newVarDec(Decl* def, DeclKind kind, int lineno){ //create new variable declaration
	Decl *n = newDecl(kind, lineno);
	n->val.var_dec.def = def;
	return n;
}
Decl *newVarDefs(Decl* defs, Decl* def, int lineno){//create new variable definitions
	Decl *n = newDecl(k_NodeKindVarDefs, lineno);
	n->val.var_defs.var_defs = defs;
	n->val.var_defs.var_def = def;
	return n;
}
Decl *newVarDef(Exp* identifiers, Type* identifier_type, Exp* expressions, int lineno){ //create a new variable deninition
	Decl *n = newDecl(k_NodeKindVarDef, lineno);
	n->val.var_def.identifiers = identifiers;
	n->val.var_def.identifier_type = identifier_type;
	n->val.var_def.expressions = expressions;
	return n;
}
Decl *newTypeDec(Decl* def, DeclKind kind, int lineno){ //create new type declaration
	Decl *n = newDecl(kind, lineno);
	n->val.type_dec.def = def;
	return n;
}
Decl *newTypeDefs(Decl* type_defs, Decl* type_def, int lineno){ //create new type definitions
	Decl *n = newDecl(k_NodeKindTypeDefs, lineno);
	n->val.type_defs.type_defs = type_defs;
	n->val.type_defs.type_def = type_def;
	return n;
}
Decl *newTypeDef(Type* identifier, Type* identifier_type, int lineno){ //create a new type definition
	Decl *n = newDecl(k_NodeKindTypeDef, lineno);
	n->val.type_def.identifier = identifier;
	n->val.type_def.identifier_type = identifier_type;
	return n;
}

/*Decl *newTypeStruct(Type* identifier, Type* struct_type, int lineno){ //create a new struct definition
	Decl *n = newDecl(k_NodeKindTypeDef, lineno);
	n->val.type_struct.identifier = identifier;
	n->val.type_struct.struct_type = struct_type;
	return n;
}*/

Decl *newFuncDec(Exp* id, Decl* params, Decl* func_type, Stmt* block, int lineno){ //create new function declaration
	Decl *n = newDecl(k_NodeKindFuncDec, lineno);
	n->val.func_dec.identifier = id;
	n->val.func_dec.func_params = params;
	n->val.func_dec.func_type = func_type;
	n->val.func_dec.block_body = block;
	return n;
}
Decl *newFuncParams(Decl* func_params, Exp* ids, Type* id_type, int lineno){//create new function parameters
	Decl *n = newDecl(k_NodeKindFuncParams, lineno);
	n->val.func_params.func_params = func_params;
	n->val.func_params.identifiers = ids;
	n->val.func_params.identifier_type = id_type;
	return n;
}

Decl *newFuncType(Type* id_type, int lineno){
	Decl *n = newDecl(k_NodeKindFuncType, lineno);
	n->val.func_type.identifier_type = id_type;
	return n;
}

Type *newIdType(char* identifier, int lineno){
	Type *n = newType(k_NodeKindIdType, lineno);
	n->val.identifier = identifier;
	return n;
}

Type *newStructBody(Type *struct_body, Exp* ids, Type *type, int lineno){ //create a new struct body definition
	Type *n = newType(k_NodeKindStructBody, lineno);
	n->val.struct_body.struct_body = struct_body;
	n->val.struct_body.identifiers = ids;
	n->val.struct_body.type = type;
	return n;
}

Type *newIdentifierType(int size, Type *identifier_type, TypeKind kind, int lineno){
	Type *n = newType(kind, lineno);
	n->val.identifier_type.size = size;
	n->val.identifier_type.identifier_type = identifier_type;
	return n;
}

Stmt *newStmt(StmtKind k, int lineno){
	Stmt *n=malloc(sizeof(Stmt));
	n->kind=k;
	n->lineno=lineno;
}
Stmt *newStatements(Stmt *statements, Stmt *statement, int lineno){
	Stmt *n = newStmt(k_NodeKindStatements, lineno);
	n->val.statements.statements = statements;
	n->val.statements.statement = statement;
	return n;
}
Stmt *newStatement(Stmt *stmt, int lineno){
	Stmt *n = newStmt(k_NodeKindStatement, lineno);
	n->val.statement.stmt = stmt;
	return n;
}
Stmt *newStatementDec(Decl *decl, int lineno){
	Stmt *n = newStmt(k_NodeKindStatementDec, lineno);
	n->val.statement_dec.decl = decl;
	return n;
}
Stmt *newBlockBody(Stmt *statements, int lineno){
	Stmt *n = newStmt(k_NodeKindBlockBody, lineno);
	n->val.block_body.statements = statements;
	return n;
}
Stmt *newSimpleStatementDec(Stmt *statement, int lineno){
	Stmt *n = newStmt(k_NodeKindSimpleStatementDec, lineno);
	n->val.simple_statement_dec.statement = statement;
	return n;
}

Stmt *newSimpleStatement(Exp *lhs, Exp *rhs, StmtKind kind, int lineno){
	Stmt *n = newStmt(kind, lineno);
	n->val.simple_statement.lhs = lhs;
	n->val.simple_statement.rhs = rhs;
	return n;
}
Stmt *newPrintStatement(Exp *expression_opt, StmtKind kind, int lineno){
	Stmt *n = newStmt(kind, lineno);
	n->val.print_dec.expressions_opt = expression_opt;
	return n;
}
Stmt *newReturnStatement(Exp *expression_opt, int lineno){
	Stmt *n = newStmt(k_NodeKindReturn, lineno);
	n->val.return_dec.expression_opt = expression_opt;
	return n;
}

Stmt *newIfStmt(Stmt* simple_statement_dec, Exp *expression, Stmt* block_body, Stmt* else_stmt, int lineno){
	Stmt *n = newStmt(k_NodeKindIfStmt, lineno);
	n->val.if_stmt.simple_statement_dec = simple_statement_dec;
	n->val.if_stmt.expression = expression;
	n->val.if_stmt.block_body = block_body;
	n->val.if_stmt.else_stmt = else_stmt;
	return n;
}
Stmt *newElseStmt(Stmt *if_stmt, Stmt* block_body, int lineno){
	Stmt *n = newStmt(k_NodeKindElseStmt, lineno);
	n->val.else_stmt.if_stmt = if_stmt;
	n->val.else_stmt.block_body = block_body;
	return n;
}
Stmt *newForDec(Stmt *for_condition, Stmt* block_body, int lineno){
	Stmt *n = newStmt(k_NodeKindForDec, lineno);
	n->val.for_dec.for_condition = for_condition;
	n->val.for_dec.block_body = block_body;
	return n;
}
Stmt *newForCondition(Stmt *left, Exp *expression, Stmt *right, int lineno){
	Stmt *n = newStmt(k_NodeKindForCondition, lineno);
	n->val.for_condition.left = left;
	n->val.for_condition.expression = expression;
	n->val.for_condition.right = right;
	return n;
}
Stmt *newSwitchDec(Stmt *switch_def, Stmt *switch_cases, int lineno){
	Stmt *n = newStmt(k_NodeKindSwitchDec, lineno);
	n->val.switch_dec.switch_def = switch_def;
	n->val.switch_dec.switch_cases = switch_cases;
	return n;
}

Stmt *newSwitchDef(Stmt *simple_statement, Exp *expression_opt, int lineno){
	Stmt *n = newStmt(k_NodeKindSwitchDef, lineno);
	n->val.switch_def.simple_statement = simple_statement;
	n->val.switch_def.expression_opt=expression_opt;
	return n;
}
Stmt *newSwitchCases(Stmt *cases, Exp *expressions, Stmt *statements, StmtKind kind, int lineno){
	Stmt *n = newStmt(kind, lineno);
	n->val.switch_cases.cases = cases;
	n->val.switch_cases.expression = expressions;
	n->val.switch_cases.statements = statements;
	return n;
}
Stmt *newBreak(int lineno){
	Stmt *n = newStmt(k_NodeKindBreak, lineno);
	return n;
}
Stmt *newContinue(int lineno){
	Stmt *n = newStmt(k_NodeKindContinue, lineno);
	return n;
}

Exp *newExpressions(Exp *expressions, Exp *expression, int lineno){
	Exp *n = newExp(k_NodeKindExpressions, lineno);
	n->val.expressions.expressions = expressions;
	n->val.expressions.expression = expression;
	return n;
}
Exp *newExpressionOpt(Exp *expression, int lineno){
	Exp *n = newExp(k_NodeKindExpressionOpt, lineno);
	n->val.expression.expression = expression;
	return n;
}
Exp *newExpressionsOpt(Exp *expressions, int lineno){
	Exp *n = newExp(k_NodeKindExpressionsOpt, lineno);
	n->val.expressions.expressions = expressions;
	return n;
}
Exp *newExpression(Exp *expression, int lineno){
	Exp *n = newExp(k_NodeKindExpression, lineno);
	n->val.expression.expression = expression;
	return n;
}
Exp *newExpressionBinary(Exp *lhs, Exp *rhs, ExpKind kind, int lineno){
	Exp *n = newExp(kind, lineno); 
	n->val.binary.lhs = lhs;
	n->val.binary.rhs = rhs;
	return n;
}
Exp *newExpressionUnary(Exp *operand, ExpKind kind, int lineno){
	Exp *n = newExp(kind, lineno); 
	n->val.unary.operand = operand;
	return n;
}
Exp *newIntLiteral(int literal, int lineno){
	Exp *n = newExp(k_NodeKindIntLiteral, lineno);
	n->val.intLiteral = literal;
	return n;
}
Exp *newRuneLiteral(char* literal, int lineno){
	Exp *n = newExp(k_NodeKindRuneLiteral, lineno);
	n->val.runeLiteral = literal;
	return n;
}
Exp *newFloatLiteral(double literal, int lineno){
	Exp *n = newExp(k_NodeKindFloatLiteral, lineno);
	n->val.floatLiteral = literal;
	return n;
}

Exp *newStringLiteral(char* literal, int lineno){
	Exp *n = newExp(k_NodeKindStringLiteral, lineno);
	n->val.stringLiteral = literal;
	return n;
}

Exp *newExpressionPrimary(Exp *primary_expression, Exp *selector, Exp *index, Type* identifier_type, Exp *expression, int lineno){
	Exp *n = newExp(k_NodeKindExpressionPrimary, lineno); 
	n->val.primary_expression.primary_expression = primary_expression;
	n->val.primary_expression.selector = selector;
	n->val.primary_expression.index = index;
	n->val.primary_expression.identifier_type = identifier_type;
	n->val.primary_expression.expression = expression;
	return n;
}

Exp *newExpressionsPrimary(Exp *primary_expressions, Exp *primary_expression, int lineno){
	Exp *n = newExp(k_NodeKindExpressionsPrimary, lineno);
	n->val.primary_expressions.primary_expressions = primary_expressions;
	n->val.primary_expressions.primary_expression = primary_expression;
	return n;
}

Exp *newSelector(Exp *identifier, int lineno){
	Exp *n = newExp(k_NodeKindSelector, lineno); 
	n->val.selector.identifier = identifier;
	return n;
}
Exp *newIndex(Exp *expression, int lineno){
	Exp *n = newExp(k_NodeKindIndex, lineno); 
	n->val.index.expression = expression;
	return n;
}

Exp *newBuiltin(Exp *expression1, Exp *expression2, ExpKind kind, int lineno){
	Exp *n = newExp(kind, lineno);
	n->val.builtins.expression1 = expression1;
	n->val.builtins.expression2 = expression2;
	return n;
}

Exp *newFuncCall(Exp *identifier, Exp *expressions_opt, int lineno){
	Exp *n = newExp(k_NodeKindFuncCall, lineno);
	n->val.func_call.identifier = identifier;
	n->val.func_call.expressions_opt = expressions_opt;
	return n;
}

