#include <stdio.h>
#include "pretty.h"
#include "tree.h"

void prettyProg(Prog* e){
	if (e == NULL) return;
	prettyDecl(e->program.package_dec);
	prettyDecl(e->program.top_decs);
}

void prettyDecl(Decl* e){
	if (e == NULL) return;
	switch (e->kind) {
		case k_NodeKindPackageDec:
			printf("package ");
			prettyExp(e->val.package_dec.identifier);
			printf("\n");
			break;
			
		case k_NodeKindTopDecs:
			prettyDecl(e->val.top_decs.top_decs);
			prettyDecl(e->val.top_decs.dec);
			break;
			
		case k_NodeKindVarDecLine:
			printf("var ");
			prettyDecl(e->val.var_dec.def);
			break;
		case k_NodeKindVarDecPar:
			printf("var (\n");
			prettyDecl(e->val.var_dec.def);
			printf(")\n");
			break;
		case k_NodeKindVarDefs:
			prettyDecl(e->val.var_defs.var_defs);
			prettyDecl(e->val.var_defs.var_def);
			break;
		case k_NodeKindVarDef:
			if (e->val.var_def.expressions == NULL) {
				prettyExp(e->val.var_def.identifiers);
				printf(" ");
				prettyType(e->val.var_def.identifier_type);
				printf(" ");
			} else if (e->val.var_def.identifier_type == NULL) {
				prettyExp(e->val.var_def.identifiers);
				printf("=");
				prettyExp(e->val.var_def.expressions);
			} else {
				prettyExp(e->val.var_def.identifiers);
				prettyType(e->val.var_def.identifier_type);
				printf("=");
				prettyExp(e->val.var_def.expressions);
			}
			break;
		case k_NodeKindTypeDecLine:
			printf("type ");
			prettyDecl(e->val.type_dec.def);
			printf("\n");
			break;
		case k_NodeKindTypeDecPar:
			printf("type (");
			prettyDecl(e->val.type_dec.def);
			printf(")\n");
			break;
		case k_NodeKindTypeDefs:
			prettyDecl(e->val.type_defs.type_defs);
			prettyDecl(e->val.type_defs.type_def);
			break;
		case k_NodeKindTypeDef:
			prettyType(e->val.type_def.identifier);
			prettyType(e->val.type_def.identifier_type);
			break;
		case k_NodeKindFuncDec:
			if (e->val.func_dec.func_params == NULL) {
				printf("func");
				printf(" ");
				prettyExp(e->val.func_dec.identifier);
				printf("()");
				prettyDecl(e->val.func_dec.func_type);
				prettyStmt(e->val.func_dec.block_body);
			} else {
				printf("func");
				printf(" ");
				prettyExp(e->val.func_dec.identifier);
				printf("(");
				prettyDecl(e->val.func_dec.func_params);
				printf(")");
				prettyDecl(e->val.func_dec.func_type);
				prettyStmt(e->val.func_dec.block_body);
			}
			break;
		case k_NodeKindFuncParams:
			if(e->val.func_params.func_params==NULL)
			{
				prettyExp(e->val.func_params.identifiers);
				prettyType(e->val.func_params.identifier_type);
			}
			else
			{
				prettyDecl(e->val.func_params.func_params);
				printf(", ");
				prettyExp(e->val.func_params.identifiers);
				prettyType(e->val.func_params.identifier_type);
			}
			break;
		case k_NodeKindFuncType:
			prettyType(e->val.func_type.identifier_type);
			break;
	}
}

void prettyType(Type* e){
	if (e == NULL) return;
	switch (e->kind) {
		case k_NodeKindArrayType:
			printf("[");
			printf("%d", e->val.identifier_type.size);
			printf("]");
			prettyType(e->val.identifier_type.identifier_type);
			break;
		case k_NodeKindSliceType:
			printf("[");
			printf("]");
			prettyType(e->val.identifier_type.identifier_type);
			break;
		case k_NodeKindStructType:
			printf("struct {");
			prettyType(e->val.identifier_type.identifier_type);
			printf("}");
			break;
		case k_NodeKindIdType:
			printf("%s", e->val.identifier);
			printf(" ");
			break;
		case k_NodeKindParType:
			printf("(");
			prettyType(e->val.identifier_type.identifier_type);
			printf(")");
			break;
		case k_NodeKindStructBody:
			prettyType(e->val.struct_body.struct_body);
			prettyExp(e->val.struct_body.identifiers);
			printf(" ");
			prettyType(e->val.struct_body.type);
			printf("\n");
			break;
	}
}

void prettyStmt(Stmt* e){
	if (e == NULL) return;
	switch (e->kind) {
		case k_NodeKindStatements:
			prettyStmt(e->val.statements.statements);
			prettyStmt(e->val.statements.statement);
			printf("\n");
			break;
			
		case k_NodeKindStatement:
			prettyStmt(e->val.statement.stmt);
			printf("\n");
			break;
			
		case k_NodeKindStatementDec:
			prettyDecl(e->val.statement_dec.decl);
			break;
		
		case k_NodeKindBlockDec:
			prettyStmt(e->val.block_dec.block_body);
			break;
			
		case k_NodeKindBlockBody:
			printf("{\n");
			prettyStmt(e->val.block_body.statements);
			printf("\n}\n");
			break;
		
		case k_NodeKindSimpleStatementDec:
			prettyStmt(e->val.simple_statement_dec.statement);
			break;
			
		case k_NodeKindSimpleStatementExp:
			prettyExp(e->val.simple_statement.lhs);
			break;
		
		case k_NodeKindSimpleStatementInc:
			prettyExp(e->val.simple_statement.lhs);
			printf("++");
			break;
			
		case k_NodeKindSimpleStatementDecrease:
			prettyExp(e->val.simple_statement.lhs);
			printf("--");
			break;
			
		case k_NodeKindSimpleStatementEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("=");
			prettyExp(e->val.simple_statement.rhs);
			break;
			
		case k_NodeKindSimpleStatementPlusEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("+=");
			prettyExp(e->val.simple_statement.rhs);
			break;
			
		case k_NodeKindSimpleStatementMinEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("-=");
			prettyExp(e->val.simple_statement.rhs);
			break;
			
		case k_NodeKindSimpleStatementMulEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("*=");
			prettyExp(e->val.simple_statement.rhs);
			break;
			
		case k_NodeKindSimpleStatementDivEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("/=");
			prettyExp(e->val.simple_statement.rhs);
			break;
			
		case k_NodeKindSimpleStatementModEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("%%");
			printf("=");
			prettyExp(e->val.simple_statement.rhs);
			break;
			
		case k_NodeKindSimpleStatementBitAndEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("&=");
			prettyExp(e->val.simple_statement.rhs);
			break;
			
		case k_NodeKindSimpleStatementBitOrEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("|=");
			prettyExp(e->val.simple_statement.rhs);
			break;
		
		case k_NodeKindSimpleStatementBitXorEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("^=");
			prettyExp(e->val.simple_statement.rhs);
			break;
		
		case k_NodeKindSimpleStatementLeftShiftEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("<<=");
			prettyExp(e->val.simple_statement.rhs);
			break;
			
		case k_NodeKindSimpleStatementRightShiftEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf(">>=");
			prettyExp(e->val.simple_statement.rhs);
			break;
			
		case k_NodeKindSimpleStatementBitClearEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf("&^=");
			prettyExp(e->val.simple_statement.rhs);
			break;
			
		case k_NodeKindSimpleStatementDeclEqual:
			prettyExp(e->val.simple_statement.lhs);
			printf(":=");
			prettyExp(e->val.simple_statement.rhs);
			break;
		
		case k_NodeKindPrintDec:
			printf("print(");
			prettyExp(e->val.print_dec.expressions_opt);
			printf(")");
			break;
			
		case k_NodeKindPrintlnDec:
			printf("println(");
			prettyExp(e->val.print_dec.expressions_opt);
			printf(")");
			break;
			
		case k_NodeKindReturn:
			printf("return ");
			prettyExp(e->val.return_dec.expression_opt);
			printf("\n");
			break;
			
		case k_NodeKindIfStmt:
			if(e->val.if_stmt.simple_statement_dec==NULL)
			{
				printf("if ");
				prettyExp(e->val.if_stmt.expression);
				prettyStmt(e->val.if_stmt.block_body);
				prettyStmt(e->val.if_stmt.else_stmt);
			}
			else
			{
				printf("if ");
				prettyStmt(e->val.if_stmt.simple_statement_dec);
				printf(";");
				prettyExp(e->val.if_stmt.expression);
				prettyStmt(e->val.if_stmt.block_body);
				prettyStmt(e->val.if_stmt.else_stmt);
			}
			break;
			
		case k_NodeKindElseStmt:
			printf("else ");
			if(e->val.else_stmt.if_stmt==NULL)
			{
				prettyStmt(e->val.else_stmt.block_body);
			}
			else
			{
				prettyStmt(e->val.else_stmt.if_stmt);
			}
			break;
			
		case k_NodeKindForDec:
			printf("for ");
			prettyStmt(e->val.for_dec.for_condition);
			prettyStmt(e->val.for_dec.block_body);
			break;
			
		case k_NodeKindForCondition:
			if(e->val.for_condition.left!=NULL){
				prettyStmt(e->val.for_condition.left);
				printf(";");
				prettyExp(e->val.for_condition.expression);
				printf(";");
				prettyStmt(e->val.for_condition.right);
			}else if(e->val.for_condition.expression!=NULL){
				prettyExp(e->val.for_condition.expression);
			}
			break;
			
		case k_NodeKindSwitchDec:
			printf("switch ");
			prettyStmt(e->val.switch_dec.switch_def);
			printf("{");
			prettyStmt(e->val.switch_dec.switch_cases);
			printf("}");
			break;
			
		case k_NodeKindSwitchDef:
			if(e->val.switch_def.simple_statement==NULL)
			{
				prettyExp(e->val.switch_def.expression_opt);
			}
			else
			{
				prettyStmt(e->val.switch_def.simple_statement);
				printf(";");
				prettyExp(e->val.switch_def.expression_opt);
			}
			break;
			
		case k_NodeKindSwitchCases:
			prettyStmt(e->val.switch_cases.cases);
			printf("case ");
			prettyExp(e->val.switch_cases.expression);
			printf(":\n");
			prettyStmt(e->val.switch_cases.statements);
			break;
			
		case k_NodeKindDefault:
			prettyStmt(e->val.switch_cases.cases);
			printf("case ");
			printf("default:\n");
			prettyStmt(e->val.switch_cases.statements);
			break;
			
		case k_NodeKindBreak:
			printf("break;\n");
			break;
			
		case k_NodeKindContinue:
			printf("continue;\n");
			break;
	}
}

void prettyExp(Exp* e){
	if (e == NULL) return;
	switch (e->kind) {
		case k_NodeKindIdentifiers: 
            {
				if(e->val.identifiers.identifiers != NULL){
					prettyExp(e->val.identifiers.identifiers);
					printf(", ");
				}
				prettyExp(e->val.identifiers.identifier);
				break;
            }
            case k_NodeKindIdentifier:
            {
                printf("%s", e->val.identifier);
				printf(" ");
				break;
            }
            case k_NodeKindExpressions:
            {
                if(e->val.expressions.expressions!=NULL){
					prettyExp(e->val.expressions.expressions);
					printf(",");
					prettyExp(e->val.expressions.expression);
				}else{
					prettyExp(e->val.expressions.expression);
				}
                break;
            }
            case k_NodeKindExpressionOpt:
            {
                prettyExp(e->val.expression.expression);
                break;
            }
            case k_NodeKindExpressionsOpt:
            {
                prettyExp(e->val.expressions.expressions);
                break;
            }
            case k_NodeKindExpression:
            {
                prettyExp(e->val.expression.expression);
                break;
            }
            
            case k_NodeKindExpressionBinaryPlus:
				prettyExp(e->val.binary.lhs);
				printf("+");
				prettyExp(e->val.binary.rhs);
				break;
			
			case k_NodeKindExpressionBinaryMinus:
				prettyExp(e->val.binary.lhs);
				printf("-");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryMultiply:
				prettyExp(e->val.binary.lhs);
				printf("*");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryDivide:
				prettyExp(e->val.binary.lhs);
				printf("/");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryModulo:
				prettyExp(e->val.binary.lhs);
				printf("%%");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryBitAnd:
				prettyExp(e->val.binary.lhs);
				printf("&");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryBitOr:
				prettyExp(e->val.binary.lhs);
				printf("|");
				prettyExp(e->val.binary.rhs);
				break;
			
			case k_NodeKindExpressionBinaryBitXor:
				prettyExp(e->val.binary.lhs);
				printf("^");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinarybitClear:
				prettyExp(e->val.binary.lhs);
				printf("&^");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryLeftShift:
				prettyExp(e->val.binary.lhs);
				printf("<<");
				prettyExp(e->val.binary.rhs);
				break;
			
			case k_NodeKindExpressionBinaryRightShift:
				prettyExp(e->val.binary.lhs);
				printf(">>");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryIsEqual:
				prettyExp(e->val.binary.lhs);
				printf("==");
				prettyExp(e->val.binary.rhs);
				break;
			
			case k_NodeKindExpressionBinaryIsNotEqual:
				prettyExp(e->val.binary.lhs);
				printf("!=");
				prettyExp(e->val.binary.rhs);
				break;
			
			case k_NodeKindExpressionBinaryLessThan:
				prettyExp(e->val.binary.lhs);
				printf("<");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryGreaterThan:
				prettyExp(e->val.binary.lhs);
				printf(">");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryLessThanEqual:
				prettyExp(e->val.binary.lhs);
				printf("<=");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryGreaterThanEqual:
				prettyExp(e->val.binary.lhs);
				printf(">=");
				prettyExp(e->val.binary.rhs);
				break;
			
			case k_NodeKindExpressionBinaryAnd:
				prettyExp(e->val.binary.lhs);
				printf("&&");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindExpressionBinaryOr:
				prettyExp(e->val.binary.lhs);
				printf("||");
				prettyExp(e->val.binary.rhs);
				break;
				
			case k_NodeKindUMinus:
				printf("-");
				prettyExp(e->val.unary.operand);
				break;
				
			case k_NodeKindUPlus:
				printf("+");
				prettyExp(e->val.unary.operand);
				break;
			
			case k_NodeKindUNot:
				printf("!");
				prettyExp(e->val.unary.operand);
				break;
			
			case k_NodeKindUXor:
				printf("^");
				prettyExp(e->val.unary.operand);
				break;
            /*--------------------literals----------------------*/
            case k_NodeKindIntLiteral:
				printf("%i", e->val.intLiteral);
				break;
				
			case k_NodeKindFloatLiteral:
				printf("%f", e->val.floatLiteral);
				break;
				
			case k_NodeKindStringLiteral:
				printf("%s", e->val.stringLiteral);
				break;
				
			case k_NodeKindRuneLiteral:
				printf("%s", e->val.runeLiteral);
				break;
			

            case k_NodeKindExpressionsPrimary: 
            {
				if(e->val.primary_expressions.primary_expressions!=NULL){
					prettyExp(e->val.primary_expressions.primary_expressions);
					printf("'");
					prettyExp(e->val.primary_expressions.primary_expression);
				}else{
					prettyExp(e->val.primary_expressions.primary_expression);
				}
                break;
            }
            case k_NodeKindExpressionPrimary:
            {
                if (e->val.primary_expression.primary_expression != NULL && e->val.primary_expression.selector != NULL) {   //selector
                    prettyExp(e->val.primary_expression.primary_expression);
                    prettyExp(e->val.primary_expression.selector);
                } else if (e->val.primary_expression.primary_expression != NULL && e->val.primary_expression.index != NULL) {   //index
                    prettyExp(e->val.primary_expression.primary_expression);
                    prettyExp(e->val.primary_expression.index);
                } else if (e->val.primary_expression.expression != NULL) {  // identifier or function call
                    prettyExp(e->val.primary_expression.expression);
                }
                break;
            }

            case k_NodeKindSelector:
            {
                printf(".");
				prettyExp(e->val.selector.identifier);
				break;
            }

            case k_NodeKindIndex:
            {
                printf("[");
				prettyExp(e->val.index.expression);
				printf("]");
				break;
            }

            case k_NodeKindAppend:  //expression1.push_back(expression2)
            {
                printf("append(");
				prettyExp(e->val.builtins.expression1);
				printf(", ");
				prettyExp(e->val.builtins.expression2);
				printf(")");
				break;
            }
            case k_NodeKindLen:
            {
                printf("len(");
				prettyExp(e->val.builtins.expression1);
				printf(")");
				break;
            }
            case k_NodeKindCap:
            {
                printf("cap(");
				prettyExp(e->val.builtins.expression1);
				printf(")");
				break;
            }
            case k_NodeKindFuncCall:
            {
                prettyExp(e->val.func_call.identifier);
				printf("(");
				prettyExp(e->val.func_call.expressions_opt);
				printf(")");
                break;
            }
	}
}

