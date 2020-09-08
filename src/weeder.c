#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "weeder.h"

int default_case = 0;
void weedDefault(Prog* n);
void weedDefaultDecl(Decl* n);
void weedDefaultStmt(Stmt* n);

void weedContinueBreak(Prog* n);
void weedContinueBreakDecl(Decl* n);
void weedContinueBreakStmt(Stmt* n);


bool returnStmt_is_reached=false;
bool returnComplete=false;

//void weedReturn(Prog *n);

bool hasElseBranch=false;
int branchNum=0;
int returnNum=0;

void further(Stmt *n);

void weedDefault(Prog* n) {
		if(n!=NULL){
			weedDefaultDecl(n->program.top_decs);
		}
}

void weedDefaultDecl(Decl* n){
	if(n!=NULL){
		switch(n->kind){
			case k_NodeKindTopDecs:
		    		weedDefaultDecl(n->val.top_decs.top_decs);
		    		weedDefaultDecl(n->val.top_decs.dec);
		    		break;
			case k_NodeKindFuncDec:
				weedDefaultStmt(n->val.func_dec.block_body);
				break;
		}
	}
}


void weedDefaultStmt(Stmt* n){
	if(n!=NULL){
		switch (n->kind) {
			case k_NodeKindBlockBody:
                        	weedDefaultStmt(n->val.block_body.statements);
                        	break;
			case k_NodeKindStatements:
                        	weedDefaultStmt(n->val.statements.statements);
                        	weedDefaultStmt(n->val.statements.statement);
                        	break;
			case k_NodeKindStatement:
                        	weedDefaultStmt(n->val.statement.stmt);
                        	break;
			case k_NodeKindSwitchDec:
				weedDefaultStmt(n->val.switch_dec.switch_cases);
				default_case=0;
				break;
			case k_NodeKindSwitchCases:
				weedDefaultStmt(n->val.switch_cases.cases);
				break;
			case k_NodeKindDefault:
				default_case ++;
				if (default_case > 1) {
					fprintf(stderr, "Error: (line %d) More than 1 default cases.\n", n->lineno);
					exit(1);
				}
				weedDefaultStmt(n->val.switch_cases.cases);
				break;
		}
	}
}

int continue_flag = 0;
int break_flag = 0;
int res = 0;
void weedContinueBreak(Prog *n)
{
	if(n!=NULL){
		weedContinueBreakDecl(n->program.top_decs);
	}
}

void weedContinueBreakDecl(Decl *n){
	if(n!=NULL){
                switch(n->kind){
                        case k_NodeKindTopDecs:
                                weedContinueBreakDecl(n->val.top_decs.top_decs);
                                weedContinueBreakDecl(n->val.top_decs.dec);
                                break;
                        case k_NodeKindFuncDec:
                                weedContinueBreakStmt(n->val.func_dec.block_body);
                                break;
                }
        }

}

void weedContinueBreakStmt(Stmt *n){
    	if(n==NULL){return;}
	switch (n->kind) {
		case k_NodeKindStatements:
			weedContinueBreakStmt(n->val.statements.statements);
			weedContinueBreakStmt(n->val.statements.statement);
			break;
			
		case k_NodeKindIfStmt:
			if(n->val.if_stmt.simple_statement_dec==NULL){
				weedContinueBreakStmt(n->val.if_stmt.block_body);
				weedContinueBreakStmt(n->val.if_stmt.else_stmt);
				break;
			}else{
				weedContinueBreakStmt(n->val.if_stmt.simple_statement_dec);
				weedContinueBreakStmt(n->val.if_stmt.block_body);
				weedContinueBreakStmt(n->val.if_stmt.else_stmt);
				break;
			}
			
		case k_NodeKindElseStmt:
			if(n->val.else_stmt.if_stmt==NULL){
				weedContinueBreakStmt(n->val.else_stmt.block_body);
				break;
			}else{
				weedContinueBreakStmt(n->val.else_stmt.if_stmt);
				break;
			}
			
		case k_NodeKindForDec:
			break_flag ++;
			continue_flag ++;
			weedContinueBreakStmt(n->val.for_dec.for_condition);
			weedContinueBreakStmt(n->val.for_dec.block_body);
			break_flag --;
			continue_flag --;
			//return res;
			break;
			
		case k_NodeKindForCondition:
			weedContinueBreakStmt(n->val.for_condition.left);
			weedContinueBreakStmt(n->val.for_condition.right);
			break;

		case k_NodeKindSwitchDec:
			break_flag ++;
			weedContinueBreakStmt(n->val.switch_dec.switch_def);
			weedContinueBreakStmt(n->val.switch_dec.switch_cases);
			break_flag --;
			break;
			//return res;
			
		case k_NodeKindSwitchDef:
			weedContinueBreakStmt(n->val.switch_def.simple_statement);
			break;
			
		case k_NodeKindSwitchCases:
			//return 
			weedContinueBreakStmt(n->val.switch_cases.cases);
			weedContinueBreakStmt(n->val.switch_cases.statements);
			break;
			
		case k_NodeKindDefault:
			weedContinueBreakStmt(n->val.switch_cases.cases);
			weedContinueBreakStmt(n->val.switch_cases.statements);
			break;

		case k_NodeKindBlockDec:
			weedContinueBreakStmt(n->val.block_dec.block_body);
			break;
			
		case k_NodeKindBlockBody:
			weedContinueBreakStmt(n->val.block_body.statements);
			break;
		
		case k_NodeKindStatement:
			weedContinueBreakStmt(n->val.statement.stmt);
			break;
			
		case k_NodeKindSimpleStatementDec:
			weedContinueBreakStmt(n->val.simple_statement_dec.statement);
			break;
			
		case k_NodeKindBreak:
			if (break_flag == 0) {
				fprintf(stderr, "Error: (line %d) break statement at invalid location.\n", n->lineno);
				exit(1);
			}
			break;
			
		case k_NodeKindContinue:
			if (continue_flag == 0) {
				fprintf(stderr, "Error: (line %d) continue statement at invalid location.\n", n->lineno);
                                exit(1);

			}
			break;
	}
}

//Must have a return statement at the last line of the function scope. In other word, no code can exist after the return statement. Unless if else statements terminates the funciton in advance.
/*
void weedReturn(Prog *n){
        if(n!=NULL){
                weedReturnDecl(n->program.top_decs);
        }
}
*/

void weedReturnDecl(Decl* n){   // n is func_dec
        if(n!=NULL){
                switch(n->kind){
                        /*
                        case k_NodeKindTopDecs:
                                weedReturnDecl(n->val.top_decs.top_decs);
                                weedReturnDecl(n->val.top_decs.dec);
                                break;
                        */
                        case k_NodeKindFuncDec:
                            if (n->val.func_dec.func_type==NULL) {
                                return;
                            }
                            if(n->val.func_dec.func_type!=NULL){
                                int r = weedReturnStmt(n->val.func_dec.block_body);//check whether there is return statement at the last line of the code
                                if (r > 0) {
                                    return;
                                } else {
                                    fprintf(stderr, "Error: (line %d) missing return statement.\n", n->lineno);
                                    exit(1);
                                }

                            }
                }
        }

}

int weedReturnStmt(Stmt* n){   // block body
	if(n!=NULL){
		switch(n->kind){//In the function scope, check whether there is code after the return statement
			case k_NodeKindBlockBody:
                return weedReturnStmt(n->val.block_body.statements);
            case k_NodeKindStatements:
            {
                /*
				if(returnStmt_is_reached==true)//return statement should be the last line of code, i.e. the first node in the subtree. Thus, there shouldn't be an statements node calling weedReturnStmt on the statements node that contains the return statement.
                                {
					fprintf(stderr, "Error: (line %d) missing return at end of function.\n", n->lineno);
	       				exit(1);

				}*/
                int a = weedReturnStmt(n->val.statements.statements) ;
				int b = weedReturnStmt(n->val.statements.statement);//this method should end after the return statement is reached, since it is the last line of the function
                if (a > 0) {
                    fprintf(stderr, "Error: (line %d) Having statements after return statement.\n", n->lineno);
                    exit(1);
                }
                if (a > 0 || b > 0) {
                    return 1;
                }
             }
            case k_NodeKindStatement:
                return weedReturnStmt(n->val.statement.stmt);
			case k_NodeKindReturn:
				return 1;
			case k_NodeKindIfStmt:
			    ;
			    int isReturned = weedReturnStmt(n->val.if_stmt.block_body);
			    if (isReturned <= 0) {
			        fprintf(stderr, "Error: (line %d) missing return statement.\n", n->lineno);
                    exit(1);
			    }
                Stmt* elseBranch = n->val.if_stmt.else_stmt;
                if (elseBranch == NULL) {
                     fprintf(stderr, "Error: (line %d) missing return statement.\n", n->lineno);
                     exit(1);
                }

                if (elseBranch->val.else_stmt.if_stmt != NULL) {
                   return weedReturnStmt(elseBranch->val.else_stmt.if_stmt);  //else if
                } else if (n->val.else_stmt.block_body != NULL) {
                    int r = weedReturnStmt(n->val.else_stmt.block_body); //else
                    if (r <= 0) {
                        fprintf(stderr, "Error: (line %d) missing return statement.\n", n->lineno);
                        exit(1);
                    }
                    return r;
                }

             case k_NodeKindForDec:
                return 0;

             case k_NodeKindSwitchDec:
                return 0;
			default:
			    return 0;
		}

	}
    return 0;
}



void further(Stmt *n){
			if(n!=NULL){
                        switch(n->kind){
                        case k_NodeKindBlockBody:
                                further(n->val.block_body.statements);
                                break;
                        case k_NodeKindStatements:
                                further(n->val.statements.statements);
                                further(n->val.statements.statement);
                                break;
                        case k_NodeKindStatement:
                                further(n->val.statement.stmt);
                                break;
                        case k_NodeKindReturn:
                                returnNum++;
                                break;
                        case k_NodeKindIfStmt:
                                branchNum++;
                                further(n->val.if_stmt.block_body);
                                further(n->val.if_stmt.else_stmt);
                                break;
                        case k_NodeKindElseStmt:
                                if(n->val.else_stmt.if_stmt==NULL){hasElseBranch=true;branchNum++;}
                                further(n->val.else_stmt.if_stmt);
                                further(n->val.else_stmt.block_body);
                                break;
                        }
			}

			//printf("branch%i return%i",branchNum,returnNum);

}

