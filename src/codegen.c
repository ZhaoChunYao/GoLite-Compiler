#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "codegen.h"

SymbolTable* sym_root;   // Root of symbol table.
bool newScope = true;
bool printElse = false;
bool toPrint = false;
bool toPrintln = false;
int init_count = 0;
char* tag = "tag_";
bool isFirstExp = true;
int ff = 0;

SymbolTable* traverseDown(SymbolTable* parent){
	SymbolTable* t = parent;
	for(int i = 0; i<1000; i++){
		if(parent->visited[i] == false && parent->child[i] != NULL){
			parent->visited[i] = true;
			t = parent->child[i];
			//printf("visit");
			return t;
		}
	}
}

SymbolTable* traverseUp(SymbolTable* t){
	return t->parent;
}

void codegenProg(Prog *n, char* name) {
    if (n != NULL) {
        //char* file_name = n->program.package_dec->val.package_dec.identifier->val.identifier;
        char file_name [100];
        for (int i = 0; i < strlen(name); i ++) {
            if (name[i] == '.') {
                file_name[i] = '\0';
                break;
            } else {
                file_name[i] = name[i];
            }
        }
        strcat(file_name, ".cpp\0");
        FILE * file = fopen(file_name, "w");    // The file pointer.
        //printf(file_name);
        /*
        if (file != NULL) {
                printf("The file is now opened.\n") ;
        }*/
        codegenHeader(file);
        //fputs("{\n", file);
        SymbolTable* child = traverseDown(sym_root);
        codegenDecl(n->program.package_dec, child, file);
        codegenDecl(n->program.top_decs, child, file);
        codegenExitMain(file);
        //fputs("}\n", file);
    }
}

void codegenExitMain(FILE* file) {
    fputs("int main() {\n", file);
    for (int i = 1; i <= init_count; i ++) {
        char name [10];
        sprintf(name, "init%d();\n", i);
        fputs(name, file);
    }
    fputs("main1();\n", file);
    fputs("}", file);
}

// Generate basic header and helper functions of a c++ file.
void codegenHeader(FILE* file) {
	fputs("#include <stdio.h> \n", file);
    fputs("#include <iostream>\n", file);
    fputs("#include <string>\n", file);
    fputs("#include <array>\n", file);
	fputs("#include <vector>\n", file);
	fputs("#include <iostream> \n", file);
	fputs("#include <ios> \n", file);
	fputs("#include <string> \n", file);
    fputs("using namespace std;\n", file);

    //fputs("namespace {\n", file);
    fputs("std::ios_base::fmtflags f( cout.flags() );\n", file);
    //fputs("bool tag_true = true;\n", file);
    //fputs("bool tag_false = false;\n", file);
    char* helper1 = "bool operator<(string& l, string& r)\n{\nstring c1 = l;\nstring c2 = r;\nreturn c1.compare(c2) < 0; // keep the same order\n}\n";
    char* helper2 = "bool operator>(string& l, string& r)\n{\nstring c1 = l;\nstring c2 = r;\nreturn c1.compare(c2) > 0; // keep the same order\n}\n";
    fputs(helper1, file);
    fputs(helper2, file);
    //fputs("}\n", file);
}

void codegenDecl(Decl *n, SymbolTable* cur, FILE* file){
	if(n != NULL){
		switch (n->kind){
			case k_NodeKindPackageDec:
				//printf("package ");
				//char* name = n->val.package_dec.identifier->val.identifier;
				//fputs(name, file);
				//fputs(";\n", file);
				break;
			case k_NodeKindTopDecs:
				codegenDecl(n->val.top_decs.top_decs, cur, file);
		    	codegenDecl(n->val.top_decs.dec, cur, file);
		    	break;
			case k_NodeKindVarDecLine:
		    case k_NodeKindVarDecPar:
				codegenDecl(n->val.var_dec.def, cur, file);
				break;
			case k_NodeKindVarDefs:
				codegenDecl(n->val.var_defs.var_defs, cur, file);
				codegenDecl(n->val.var_defs.var_def, cur, file);
				break;
			case k_NodeKindVarDef:
				;
				Exp* ids = n->val.var_def.identifiers;
				Exp* values = n->val.var_def.expressions;
				if(values == NULL){
					while (ids != NULL){
						Exp* id = ids->val.identifiers.identifier;

						if (strcmp("_", id->val.identifier) != 0) {
						    SYMBOL* s = getSymbol(cur, id->val.identifier);
                            Type* t = s->typelit.type;
                            //print type
                            int type = codegenType(t, cur, file);
                            fputs(" ", file);
                            codegenExp(id, cur, file);//tag
                            if (type == 1) {
                                fputs("{}", file);
                            } else if (type == 2) {
                                fputs("= 0", file);
                            }  else if (type == 3) {
                                fputs("= \"\"", file);
                            }
                            fputs(";\n", file);
						}

						ids = ids->val.identifiers.identifiers;
					}
				}else{
					while (ids != NULL && values != NULL){
						Exp* id = ids->val.identifiers.identifier;
						Exp* value = values->val.expressions.expression;
						if (strcmp("_", id->val.identifier) != 0) {
                        	SYMBOL* s = getSymbol(cur, id->val.identifier);
                            Type* t = s->typelit.type;
                            //print type
                            codegenType(t, cur, file);
                            fputs(" ", file);
                            codegenExp(id, cur, file); //tag
                            fputs(" = ", file);
                            codegenExp(value, cur, file);
                            fputs(";\n", file);
                        } else {
                            codegenExp(value, cur, file);
                            fputs(";\n", file);
                        }
						ids = ids->val.identifiers.identifiers;
						values = values->val.expressions.expressions;
					}
				}
				break;
			case k_NodeKindTypeDecPar:
		    case k_NodeKindTypeDecLine:
				codegenDecl(n->val.type_dec.def, cur, file);
				break;
			case k_NodeKindTypeDefs:
				codegenDecl(n->val.type_defs.type_def, cur, file);
				codegenDecl(n->val.type_defs.type_defs, cur, file);
				break;
			case k_NodeKindTypeDef:
			    if (strcmp("_", n->val.type_def.identifier->val.identifier) != 0) {
			        fputs("typedef ", file);
                    //print id_type
                    codegenType(n->val.type_def.identifier_type, cur, file);
                    fputs(" ", file);
                    //print id
                    codegenType(n->val.type_def.identifier, cur, file);
                    fputs(";\n", file);
			    }
				break;
			case k_NodeKindFuncDec:
				;
				char* name2 = n->val.func_dec.identifier->val.identifier;
				if (strcmp("_", name2) == 0) {
				    break;
				}
				//printf(name2);
				//printf("\n");
				char name_init [10];
				if (strcmp("init", name2) == 0) {
				    init_count ++;
				    sprintf(name_init, "init%d", init_count);
				    //printf(name_init);
				}
				if(n->val.func_dec.func_type != NULL){
					codegenDecl(n->val.func_dec.func_type, cur, file);
				} else{
					fputs("void ", file);
				}
				if (strcmp("init", name2) == 0) {
				    fputs(name_init, file);
				} else if (strcmp("main", name2) == 0) {
				    fputs("main1", file);
				} else {
				    fputs(name2, file);
				}
				fputs("(", file);
				codegenDecl(n->val.func_dec.func_params, cur, file);
				fputs(")", file);
				//SymbolTable* next = traverseDown(cur);
				codegenSTMT(n->val.func_dec.block_body, cur, file);
				break;
			case k_NodeKindFuncParams:
				;
				codegenDecl(n->val.func_params.func_params, cur, file);

				if (n->val.func_params.func_params != NULL) {
                    fputs(", ", file);
                }
				Exp* temp = n->val.func_params.identifiers;
				/*
				while (temp != NULL) {
					Exp* current = temp->val.identifiers.identifier;
					codegenType(n->val.func_params.identifier_type, cur, file);
					fputs(" ", file);
					codegenExp(current, cur, file);
					temp = temp->val.identifiers.identifiers;
					if(temp != NULL){
						fputs(", ", file);
					}
				}*/
				printIdList(temp, n->val.func_params.identifier_type, cur, file);
				break;
		    case k_NodeKindFuncType:
				;
				Type* type = n->val.func_type.identifier_type;
				if(type == NULL){
					//print type
					fputs("void ", file);
				}else{
					codegenType(type, cur, file);
					fputs(" ", file);
				}
				break;
		}
	}
}

void printIdList(Exp* temp, Type* t, SymbolTable* cur, FILE* file) {
    if (temp != NULL) {
        printIdList(temp->val.identifiers.identifiers, t, cur, file);
        if (temp->val.identifiers.identifiers != NULL) {
            fputs(", ", file);
        }
        Exp* current = temp->val.identifiers.identifier;
        codegenType(t, cur, file);
        fputs(" ", file);
        if (strcmp(current->val.identifier, "_") == 0) {
            char name [10];
            char findex [2];
            sprintf(findex, "%d", ff);
            strcpy(name, "tag_");
            strcat(name, findex);
            fputs(name, file);
            ff ++;
        } else {
            codegenExp(current, cur, file);
        }
    }
}

int codegenType(Type *n, SymbolTable* cur, FILE* file){ // return 1 array, 2 integer valued, 3 string
	if(n != NULL){
		switch (n->kind){
			case k_NodeKindIdType:
			    ;
			    int res = 0;
				if(strcmp(n->val.identifier, "int")==0){
					fputs("int", file);
					res = 2;
				}else if(strcmp(n->val.identifier, "float64")==0){
					fputs("float", file);
					res = 2;
				}else if(strcmp(n->val.identifier, "rune")==0){
					fputs("int", file);
					res = 2;
				}else if(strcmp(n->val.identifier, "string")==0){
					fputs("string", file);
					res = 3;
				}else{
					fputs(n->val.identifier, file);
				}
				return res;
			case k_NodeKindArrayType:
				;
				int size = n->val.identifier_type.size;
				fputs("array<", file);
				codegenType(n->val.identifier_type.identifier_type, cur, file);
				fputs(", ", file);
				char str[20];
                sprintf(str, " %d \0", size);
                fputs(str, file);
				fputs(">", file);
				return 1;
			case k_NodeKindSliceType:
				fputs("vector<", file);
				codegenType(n->val.identifier_type.identifier_type, cur, file);
				fputs(">", file);
				return 0;
			case k_NodeKindStructType:
				fputs("struct {\n", file);
				codegenType(n->val.identifier_type.identifier_type, cur, file);
				fputs("}\n", file);
				return 0;
			case k_NodeKindParType:
				codegenType(n->val.identifier_type.identifier_type, cur, file);
				return 0;
			case k_NodeKindStructBody:
				;
				Exp* temp = n->val.struct_body.identifiers;
				while (temp != NULL) {
					Exp* current = temp->val.identifiers.identifier;
					if (strcmp("_", current->val.identifier) != 0) {
					    int type = codegenType(n->val.struct_body.type, cur, file);
                        fputs(" ", file);
                        codegenExp(current, cur, file);
                        if (type == 1) {
                            fputs("{}", file);
                        } else if (type == 2) {
                            fputs("= 0", file);
                        }  else if (type == 3) {
                            fputs("= \"\"", file);
                        }
                        fputs(";\n", file);
					}

					temp = temp->val.identifiers.identifiers;
				}
				codegenType(n->val.struct_body.struct_body, cur, file);
				return 0;
		}
	}
}


void codegenSTMT(Stmt *n, SymbolTable* cur, FILE* file){
	if(n != NULL){
		switch (n->kind){
			case k_NodeKindStatements:
			{
				codegenSTMT(n->val.statements.statements,cur,file);
				codegenSTMT(n->val.statements.statement,cur,file);
				break;
			}
			case k_NodeKindStatement:
			{
				codegenSTMT(n->val.statement.stmt,cur,file);
				break;
			}
			case k_NodeKindStatementDec:
			{
				codegenDecl(n->val.statement_dec.decl,cur,file);
				break;
			}
			case k_NodeKindBlockDec:
			{
				codegenSTMT(n->val.block_dec.block_body,cur,file);
				break;
			}
			case k_NodeKindBlockBody:
			{
			    if (newScope) {
			        SymbolTable* child = traverseDown(cur);
			        fputs("\n{\n",file);
                    codegenSTMT(n->val.block_body.statements,child,file);
                    fputs("\n}\n",file);
                    //cur = traverseUp(child);
			    } else {
			        fputs("\n{\n",file);
                	codegenSTMT(n->val.block_body.statements,cur,file);
                	fputs("\n}\n",file);
                	//cur = traverseUp(child);
			    }

				break;
			}
			case k_NodeKindSimpleStatementDec:
			{
				codegenSTMT(n->val.simple_statement_dec.statement,cur,file);
				fputs(";\n", file);
				break;
			}
			case k_NodeKindSimpleStatementExp:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementInc:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("++",file);
				break;
			}
			case k_NodeKindSimpleStatementDecrease:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("--",file);
				break;
			}
			case k_NodeKindSimpleStatementEqual:
			{
				//printf("visit");
				Exp* ids = n->val.simple_statement.lhs;
				Exp* values = n->val.simple_statement.rhs;
				helpSimpleStatementEqual(ids, values, cur, file);
				break;
			}
			case k_NodeKindSimpleStatementPlusEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("+=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementMinEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("-=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementMulEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("*=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementDivEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("/=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementModEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("%=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementBitAndEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("&=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementBitOrEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("|=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementBitXorEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("^=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementLeftShiftEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("<<=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementRightShiftEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs(">>=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementBitClearEqual:
			{
				codegenExp(n->val.simple_statement.lhs,cur,file);
				fputs("&^=",file);
				codegenExp(n->val.simple_statement.rhs,cur,file);
				break;
			}
			case k_NodeKindSimpleStatementDeclEqual:
			{
				/*int undeclaredIdSize=0;
				int declaredIdSize=0;*/
				int idSize=0;
				Exp *ids=n->val.simple_statement.lhs;
				while(ids!=NULL){
					char *name=ids->val.expressions.expression->val.identifier;
					/*SYMBOL *idSym=getSymbol(cur,name);
					if(idSym->lineno!=n->lineno){//the variable is not declared in the same line as the short declaration statement
						undeclaredIdSize++;
					}else{
						declaredIdSize++;
					}*/
					idSize++;
					ids=ids->val.expressions.expressions;
				}
				/*char *undeclaredIdList[undeclaredIdSize];
				char *declaredIdList[declaredIdSize];
				int j=0;//counts the index of undeclared id list
				int k=0;//counts the index of declared id list
				ids=n->val.simple_statement.lhs;
				for(int i=0;i<idSize;i++){
					char *name=ids->val.expressions.expression->val.identifier;
					SYMBOL *idSym=getSymbol(cur,name);
					if(idSym->lineno!=n->lineno){
						undeclaredIdList[j]=name;
						j++;
					}else{
						declaredIdList[k]=name;
						k++;
					}
					ids=ids->val.expressions.expressions;
				}*/
				Exp *expList[idSize];
				Exp *exps=n->val.simple_statement.rhs;
				for(int i=0;i<idSize;i++){
					expList[i]=exps->val.expressions.expression;
					exps=exps->val.expressions.expressions;
				}
				ids=n->val.simple_statement.lhs;
				for(int i=0;i<idSize;i++)
				{
					char *name=ids->val.expressions.expression->val.identifier;
					SYMBOL *idSym=getSymbol(cur,name);
					if(idSym->lineno!=n->lineno){
					    fputs(tag, file);
						fputs(name,file);
						fputs("=",file);
						codegenExp(expList[i],cur,file);
						//fputs(";\n",file);
					}else{
						Type *type=getSymbol(cur,name)->typelit.type;
                                                codegenType(type,cur,file);
                                                fputs(" ",file);
						fputs(tag, file);
						fputs(name,file);
						fputs("=",file);
						codegenExp(expList[i],cur,file);
						//fputs(";\n",file);
					}
				}
				break;
			}

			case k_NodeKindPrintDec:
			{
				toPrint = true;
				codegenExp(n->val.print_dec.expressions_opt,cur,file);
				toPrint = false;
				break;
			}
			case k_NodeKindPrintlnDec:
			{
				toPrintln = true;
				codegenExp(n->val.print_dec.expressions_opt,cur,file);
				fputs("cout << \"\\n\";\n", file);
				toPrintln = false;
				break;
			}
			case k_NodeKindReturn:
			{
				fputs("return ",file);
				if(n->val.return_dec.expression_opt!=NULL){
					codegenExp(n->val.return_dec.expression_opt,cur,file);
				}
				fputs(";\n",file);
				break;
			}
			case k_NodeKindIfStmt:
			{
				//print the real if statement
				SymbolTable* child = traverseDown(cur);
				codegenSTMT(n->val.if_stmt.simple_statement_dec,child,file);//the init statement
				if (printElse) {
				    fputs("else ",file);
				}
				fputs("if(",file);//beginning of the real if statement
				codegenExp(n->val.if_stmt.expression,child,file);
				fputs(")",file);
				newScope = false;
				codegenSTMT(n->val.if_stmt.block_body,child,file);
				newScope = true;
				//fputs("\n}\n",file);//end of the real if statement
				if(n->val.if_stmt.else_stmt!=NULL){
					codegenSTMT(n->val.if_stmt.else_stmt,cur,file);
				}
				break;
			}
			case k_NodeKindElseStmt:
			{
				//fputs("else",file);
				//SymbolTable* block = traverseDown(cur);
				if(n->val.else_stmt.if_stmt!=NULL){
				    printElse = true;
					codegenSTMT(n->val.else_stmt.if_stmt,cur,file);
					printElse = false;
				}else{
				    fputs("else",file);
					codegenSTMT(n->val.else_stmt.block_body,cur,file);
				}
				break;
			}
			case k_NodeKindForDec:
			{
			    SymbolTable* block = traverseDown(cur);
				Stmt *condition=n->val.for_dec.for_condition;
				if(condition->val.for_condition.left!=NULL){
					fputs("for(",file);

					codegenSTMT(condition->val.for_condition.left,block,file);
					fputs(";",file);
					codegenExp(condition->val.for_condition.expression,block,file);
					fputs(";",file);
					codegenSTMT(condition->val.for_condition.right,block,file);
					fputs(")",file);
					newScope = false;
					codegenSTMT(n->val.for_dec.block_body,block,file);
					newScope = true;
				}else if(condition->val.for_condition.expression!=NULL){
					fputs("while(",file);
					//SymbolTable* block = traverseDown(cur);
					codegenExp(condition->val.for_condition.expression,block,file);
					fputs(")",file);
					newScope = false;
					codegenSTMT(n->val.for_dec.block_body,block,file);
					newScope = true;
				}else{
					fputs("while(true)",file);
					newScope = false;
					codegenSTMT(n->val.for_dec.block_body,block,file);
					newScope = true;
				}
				break;
			}
			case k_NodeKindForCondition:
				break;
			case k_NodeKindSwitchDec:
			{
				//fputs("if(true)",file);
				//fputs("{\n",file);
				Stmt *def=n->val.switch_dec.switch_def;
				//SymbolTable* init = traverseDown(cur);
				SymbolTable* block = traverseDown(cur);
				codegenSTMT(def->val.switch_def.simple_statement,block,file);
				fputs(";\n",file);
				if(def->val.switch_def.expression_opt!=NULL){
					fputs("switch(",file);
					codegenExp(def->val.switch_def.expression_opt,block,file);
					fputs(") {\n",file);
					codegenSTMT(n->val.switch_dec.switch_cases,block,file);
					fputs("}\n",file);
				}
				else{
					fputs("switch",file);
					codegenSTMT(n->val.switch_dec.switch_cases,block,file);
				}
				//fputs("\n}\n",file);
				break;
			}
			case k_NodeKindSwitchDef:
				break;
			case k_NodeKindSwitchCases:
			{
				codegenSTMT(n->val.switch_cases.cases,cur,file);
				fputs("case ",file);
				codegenExp(n->val.switch_cases.expression,cur,file);
				fputs(":\n",file);
				fputs("{\n",file);
				codegenSTMT(n->val.switch_cases.statements,cur,file);
				fputs("}\n",file);
				break;
			}
			case k_NodeKindDefault:
			{
				codegenSTMT(n->val.switch_cases.cases,cur,file);
				fputs("default:\n",file);
				fputs("{\n",file);
				codegenSTMT(n->val.switch_cases.statements,cur,file);
				fputs("}\n",file);
				break;
			}

			case k_NodeKindBreak:
			{
				fputs("break;\n",file);
				break;
			}
			case k_NodeKindContinue:
			{
				fputs("continue;\n",file);
				break;
			}
		}
	}
}



void codegenExp(Exp* n, SymbolTable* t, FILE* file) {
    if (n != NULL) {
        switch (n->kind) {
            case k_NodeKindIdentifiers: // won't come here
            {
                break;
            }
            case k_NodeKindIdentifier:
            {
                //SYMBOL* s = checkSymbolExists(t, n->val.identifier);
                if (strcmp("true", n->val.identifier) == 0 || strcmp("false", n->val.identifier) == 0) {
                    fputs(n->val.identifier, file);
                } else {
                    fputs(tag, file);
                    fputs(n->val.identifier, file);
                }

                break;
            }
            case k_NodeKindExpressions:
            {
                codegenExp(n->val.expressions.expressions, t, file);
                if (n->val.expressions.expressions != NULL && !toPrint && !toPrintln) {
                    fputs(", ", file);
                }
                if (toPrintln) {
                    if (n->val.expressions.expressions != NULL) {
                        fputs("cout << \" \" << ", file);
                    } else {
                        fputs("cout << ", file);
                    }
                    Type* type = inferType_Exp(t, n->val.expressions.expression);
                    //printType(type);    //debug
                    if (isFloat64(type)) {
                        fputs("std::showpos << std::scientific << ", file);
                    } else if (isBool(type)) {
                        fputs("std::boolalpha << ", file);
                    } /*else if (isRune(type)) {
                        fputs("(int) ", file);
                    }*/
                    codegenExp(n->val.expressions.expression,t,file);
                    fputs(";\n", file);
                    fputs("cout.flags(f);\n", file);
                } else if (toPrint) {
                    fputs("cout << ", file);
                    Type* type = inferType_Exp(t, n->val.expressions.expression);
                    if (isFloat64(type)) {
                        fputs("std::showpos << std::scientific << ", file);
                    } else if (isBool(type)) {
                        fputs("std::boolalpha << ", file);
                    } /*else if (isRune(type)) {
                        fputs("(int) ", file);
                    }*/
                    codegenExp(n->val.expressions.expression,t,file);
                    fputs(";\n", file);
                    fputs("cout.flags(f);\n", file);
                } else {
                    codegenExp(n->val.expressions.expression,t,file);
                }
                break;
            }
            case k_NodeKindExpressionOpt:
            {
                codegenExp(n->val.expression.expression, t, file);
                break;
            }
            case k_NodeKindExpressionsOpt:
            {
                codegenExp(n->val.expressions.expressions, t, file);
                break;
            }
            case k_NodeKindExpression:
            {
                codegenExp(n->val.expression.expression, t, file);
                break;
            }
            /*--------------------binary expressions----------------------*/
            case k_NodeKindExpressionBinarybitClear:
            {
                fputs(" ( ", file);
                codegenExp(n->val.binary.lhs, t, file);
                fputs(" &", file);
                fputs("(~", file);
                fputs(" ( ", file);
                codegenExp(n->val.binary.rhs, t, file);
                fputs(" ))", file);
                fputs(" ) ", file);
                break;
            }
            case k_NodeKindExpressionBinaryPlus:
            case k_NodeKindExpressionBinaryMinus:
            case k_NodeKindExpressionBinaryMultiply:
            case k_NodeKindExpressionBinaryDivide:
            case k_NodeKindExpressionBinaryModulo:
            case k_NodeKindExpressionBinaryBitAnd:
            case k_NodeKindExpressionBinaryBitOr:
            case k_NodeKindExpressionBinaryBitXor:
            case k_NodeKindExpressionBinaryLeftShift:
            case k_NodeKindExpressionBinaryRightShift:
            case k_NodeKindExpressionBinaryIsEqual:
            case k_NodeKindExpressionBinaryIsNotEqual:
            case k_NodeKindExpressionBinaryLessThan:
            case k_NodeKindExpressionBinaryGreaterThan:
            case k_NodeKindExpressionBinaryLessThanEqual:
            case k_NodeKindExpressionBinaryGreaterThanEqual:
            case k_NodeKindExpressionBinaryAnd:
            case k_NodeKindExpressionBinaryOr:
            {
                fputs("(", file);
                fputs("(", file);
                codegenExp(n->val.binary.lhs, t, file);
                fputs(")", file);
                printOperator(n->kind, file);
                fputs("(", file);
                codegenExp(n->val.binary.rhs, t, file);
                fputs(")", file);
                fputs(")", file);
                break;
            }
            /*--------------------unary expressions----------------------*/
            case k_NodeKindUMinus:
            case k_NodeKindUPlus:
            case k_NodeKindUNot:
            case k_NodeKindUXor:
            {
                fputs("(", file);
                printOperator(n->kind, file);
                codegenExp(n->val.unary.operand, t, file);
                fputs(")", file);
                break;
            }
            /*--------------------literals----------------------*/
            case k_NodeKindIntLiteral:
            {
                 char str[20];
                sprintf(str, " %d \0", n->val.intLiteral);
                fputs(str, file);
                break;
            }
            case k_NodeKindRuneLiteral:
            {
                char str[20];
                fputs(" ", file);
                /*
                if (strlen(n->val.runeLiteral) == 1) {
                    fputs("(int)", file);
                }*/
                fputs("(int)", file);
                fputs(n->val.runeLiteral, file);
                fputs(" ", file);

                break;
            }
            case k_NodeKindFloatLiteral:
            {
                char str[20];
                sprintf(str, " %f \0", n->val.floatLiteral);
                fputs(str, file);
                break;
            }
            case k_NodeKindStringLiteral:
            {
                fputs(" ", file);
                fputs("(string)", file);
                if (n->val.rawLiteral != NULL) {
                    fputs(n->val.rawLiteral, file);
                } else {
                    fputs(n->val.stringLiteral, file);
                }

                fputs(" ", file);
                break;
            }

            case k_NodeKindExpressionsPrimary:  // Won't come here.
            {
                break;
            }
            case k_NodeKindExpressionPrimary:
            {
                if (n->val.primary_expression.primary_expression != NULL && n->val.primary_expression.selector != NULL) {   //selector
                    codegenExp(n->val.primary_expression.primary_expression, t, file);
                    codegenExp(n->val.primary_expression.selector, t, file);
                } else if (n->val.primary_expression.primary_expression != NULL && n->val.primary_expression.index != NULL) {   //index
                    codegenExp(n->val.primary_expression.primary_expression, t, file);
                    codegenExp(n->val.primary_expression.index, t, file);
                } else if (n->val.primary_expression.expression != NULL) {  // identifier or function call
                    codegenExp(n->val.primary_expression.expression, t, file);
                }
                break;
            }

            case k_NodeKindSelector:
            {
                fputs(".", file);
                codegenExp(n->val.selector.identifier, t, file);
                break;
            }

            case k_NodeKindIndex:
            {
                fputs(".at(", file);
                codegenExp(n->val.index.expression, t, file);
                fputs(")", file);
                break;
            }

            case k_NodeKindAppend:  //expression1.push_back(expression2)
            {
                fputs("(", file);
                codegenExp(n->val.builtins.expression1, t, file);
                fputs(".push_back(", file);
                codegenExp(n->val.builtins.expression2, t, file);
                fputs("))", file);
                break;
            }
            case k_NodeKindLen:
            {
                fputs("(", file);
                codegenExp(n->val.builtins.expression1, t, file);
                fputs(".length())", file);
                break;
            }
            case k_NodeKindCap:
            {
                Type* type = inferType_Exp(t, n->val.builtins.expression1);
                Type* resolved_type = resolveType(t, type);
                if (resolved_type->kind == k_NodeKindArrayType) {   //.max_size()
                    fputs("(", file);
                    codegenExp(n->val.builtins.expression1, t, file);
                    fputs(".max_size())", file);
                } else if (resolved_type->kind != k_NodeKindSliceType) {    //.size()
                    fputs("(", file);
                    codegenExp(n->val.builtins.expression1, t, file);
                    fputs(".size())", file);
                }
                break;
            }
            case k_NodeKindFuncCall:
            {
                // Check for type cast
                if (!getSymbolCheck(t, n->val.func_call.identifier->val.identifier)) {	// type cast
                    fputs("((", file);
                    if (strcmp("float64", n->val.func_call.identifier->val.identifier) == 0) {
                        fputs("float", file);
                    } else {
                        fputs(n->val.func_call.identifier->val.identifier, file);
                    }
                    fputs(")", file);
                    fputs("(", file);
                    codegenExp(n->val.func_call.expressions_opt, t, file);
                    fputs("))", file);

                } else {    // function call
                    fputs("(", file);
                    fputs(n->val.func_call.identifier->val.identifier, file);
                    fputs("(", file);
                    codegenExp(n->val.func_call.expressions_opt, t, file);
                    fputs("))", file);
                }
                break;
            }
        }
    }
}

// File print binary and unary operators.
void printOperator(ExpKind kind, FILE* file) {
    switch (kind) {
        /*------------------------binary operators------------------------*/
        case k_NodeKindExpressionBinaryPlus:
            fputs(" + ", file);
            break;
        case k_NodeKindExpressionBinaryMinus:
            fputs(" - ", file);
            break;
        case k_NodeKindExpressionBinaryMultiply:
            fputs(" * ", file);
            break;
        case k_NodeKindExpressionBinaryDivide:
            fputs(" / ", file);
             break;
        case k_NodeKindExpressionBinaryModulo:
            fputs(" % ", file);
            break;
        case k_NodeKindExpressionBinaryBitAnd:
            fputs(" & ", file);
            break;
        case k_NodeKindExpressionBinaryBitOr:
            fputs(" | ", file);
            break;
        case k_NodeKindExpressionBinaryBitXor:
            fputs(" ^ ", file);
            break;
        case k_NodeKindExpressionBinaryLeftShift:
            fputs(" << ", file);
            break;
        case k_NodeKindExpressionBinaryRightShift:
            fputs(" >> ", file);
            break;
        case k_NodeKindExpressionBinaryIsEqual:
            fputs(" == ", file);
            break;
        case k_NodeKindExpressionBinaryIsNotEqual:
            fputs(" != ", file);
            break;
        case k_NodeKindExpressionBinaryLessThan:
            fputs(" < ", file);
            break;
        case k_NodeKindExpressionBinaryGreaterThan:
            fputs(" > ", file);
            break;
        case k_NodeKindExpressionBinaryLessThanEqual:
            fputs(" <= ", file);
            break;
        case k_NodeKindExpressionBinaryGreaterThanEqual:
            fputs(" >= ", file);
            break;
        case k_NodeKindExpressionBinaryAnd:
            fputs(" && ", file);
            break;
        case k_NodeKindExpressionBinaryOr:
            fputs(" || ", file);
            break;

        /*------------------------unary operators------------------------*/
         case k_NodeKindUMinus:
            fputs(" - ", file);
            break;
         case k_NodeKindUPlus:
            fputs(" + ", file);
            break;
         case k_NodeKindUNot:
            fputs(" ! ", file);
            break;
         case k_NodeKindUXor:
            fputs(" ~ ", file);
            break;

    }
}

void helpSimpleStatementEqual(Exp* ids, Exp* values, SymbolTable* cur, FILE* file) {
    if (ids != NULL && values != NULL) {
        Exp* newIds = ids->val.primary_expressions.primary_expressions;
        Exp* newValues = values->val.expressions.expressions;
        helpSimpleStatementEqual(newIds, newValues, cur, file);

        Exp* id = ids->val.primary_expressions.primary_expression;
        Exp* value = values->val.expressions.expression;
        codegenExp(id, cur, file);
        fputs(" = ", file);
        codegenExp(value, cur, file);
        fputs(";\n", file);
    }
}







