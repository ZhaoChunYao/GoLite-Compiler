#ifndef TYPECHECK_H
#define TYPECHECK_H
#include "tree.h"
#include "symbol.h"


bool compareType(Type* a, Type* b);
bool compareIdList(Exp *ids1,Exp *ids2);

Type *inferType_Exp(SymbolTable* t, Exp* n);

// Check if struct type contains a field called id.
// Retrun id type if found. Otherwise return NULL.
Type* checkStructId(Type* n, Exp* id);
// Return true if it is not based on funccall
bool checkNotFuncCall(Exp *n);

Type* traceType(SymbolTable* t, Type* type);
// Find and return the underlying type
Type* resolveType(SymbolTable* t, Type* type);

// Check if the type is basic type
bool isBasic(Type* type);

// Check if the type = float64
bool isFloat64(Type* type);

// Check if the type = string
bool isString(Type* type);

// Check if the type = bool
bool isBool(Type* type);

// Check if the type = int
bool isInt(Type* type);

// Check if the type = rune
bool isRune(Type* type);
// Check if the type is numeric
bool isNumeric(Type* type);
// Check if the type is integer
bool isInteger(Type* type);
/*	TODO: not sure what is pointer???
	comparable type: bool, int, float64, string, pointer,
					 struct(if all their fields are comparable),
					 array(if values of array element type are comparable)
*/
bool isComparable(Type* type);
/*  ordered type: int, float64, string  */
bool isOrdered(Type* type);



#endif /* !TYPECHECK_H */

