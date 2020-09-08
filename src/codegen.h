#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "symbol.h"
#include "tree.h"
#include "type.h"

void codegenProg(Prog *n, char* name);
// Generate basic header and helper functions of a c++ file.
void codegenHeader(FILE* file);
void codegenDecl(Decl *n, SymbolTable* cur, FILE* file);
int codegenType(Type *n, SymbolTable* cur, FILE* file);
void codegenSTMT(Stmt *n, SymbolTable* cur, FILE* file);
void codegenExp(Exp* n, SymbolTable* t, FILE* file);
// File print binary and unary operators.
void printOperator(ExpKind kind, FILE* file);
void helpSimpleStatementEqual(Exp* ids, Exp* values, SymbolTable* cur, FILE* file);
void codegenExitMain(FILE* file);
void printIdList(Exp* temp, Type* t, SymbolTable* cur, FILE* file);



