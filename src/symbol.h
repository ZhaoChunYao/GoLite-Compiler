#ifndef SYMBOL_H
#define SYMBOL_H

#include "tree.h"
#include "type.h"



// Make symbol related functions.
SYMBOL * makeSymbol_var(char * name, Type * type, int lineno);
SYMBOL * makeSymbol_const(char * name, Type * type);
SYMBOL * makeSymbol_function(char * name, TYPELIST * typelist, Type *returnType, int lineno);
SYMBOL * makeSymbol_base(char* name, Type * type);

SYMBOL * makeSymbol_definedType(char * name, Type * type, int lineno);
SYMBOL * makeSymbol_type(char * name, Type * type, int lineno);

SYMBOL * makeSymbol_struct(char * name, SYMBOLLIST * fieldList, Type * structtype);
SYMBOL * makeSymbol_array(char * name, SYMBOL * entrytype, Type * arraytype);

SYMBOL * makeSymbol_slice(char * name, SYMBOL * entrytype, Type * slicetype);

//For structs and functions: makes a list of symbols for each field/parameter respectively
SYMBOLLIST * makeSymbolList(SymbolTable* t, Decl *funcParams);
TYPELIST * makeTypeList(SYMBOLLIST * params);
//Symbol table related functions.
int Hash(char *str);
SymbolTable *initSymbolTable();
SymbolTable* scopeSymbolTable(SymbolTable* parent);
SymbolTable * unscopeSymbolTable(SymbolTable *t);
SYMBOL *putSymbol(SymbolTable *cur, SYMBOL * sym);
bool getSymbolCheck(SymbolTable *cur, char *name);
SYMBOL *getSymbol(SymbolTable *cur, char *name);
void symProg(Prog *n, bool printTable);

void symDecl(Decl *n, SymbolTable* cur);
void checkType(SymbolTable* t, Type* n);
void symStmt(Stmt *n, SymbolTable* cur, SYMBOLLIST *paramList);

void indent(int x);

char *getType(Type* n);
void printType(Type* n);

void printSymTable(SymbolTable* t);
void printTypeList(TYPELIST* head);

void printSymbolList(SYMBOLLIST* head);

#endif 


