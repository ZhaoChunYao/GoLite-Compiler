/* Code section */
%{
#include <stdio.h>
#include <string.h>
#include "main.h"

#include "y.tab.h" /* Token types */
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

// Function header.
int fToken(int token);
%}

/* Helper definitions */
DIGIT [0-9]
ESC_CHARSTR  (\\)[abfnrtv"\\]

/* Scanner options, line number generation */
%option yylineno

%x C_COMMENT

%%

[\r]+
[ \t]+


break { /* keywords */
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tBREAK);
}
case {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tCASE);
}
chan {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tCHAN);
}
const {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tCONST);
}
continue {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tCONTINUE);
}
default {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tDEFAULT);
}
defer {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tDEFER);
}
else {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tELSE);
}
fallthrough {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tFALLTHROUGH);
}
for {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tFOR);
}
func {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tFUNC);
}
go {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tGO);
}
goto {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tGOTO);
}
if {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tIF);
}
import {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tIMPORT);
}
interface {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tINTERFACE);
}
map {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tMAP);
}
package {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tPACKAGE);
}
range {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tRANGE);
}
return {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tRETURN);
}
select {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tSELECT);
}
struct {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tSTRUCT);
}
switch {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tSWITCH);
}
type {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tTYPE);
}
var {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tVAR);
}
print {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tPRINT);
}
println {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tPRINTLN);
}
append {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tAPPEND);
}
len {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tLEN);
}
cap {
	if (mode == tokens) {
		printf("Reserved keyword: %s\n", yytext);
	}
	return fToken(tCAP);
}

"+"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tPLUS); }
"-"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tMINUS); }
"*"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tMULTIPLY); }
"/"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tDIVIDE); }
"%"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tMODULO); }
"&"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tBIT_AND); }
"|"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tBIT_OR); }
"^"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tBIT_XOR); }
"<<"            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tLEFT_SHIFT); }
">>"            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tRIGHT_SHIFT); }
"&^"            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tBIT_CLEAR); }
"+="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tPLUS_EQUAL); }
"-="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tMINUS_EQUAL); }
"*="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tMULTIPLY_EQUAL); }
"/="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tDIVIDE_EQUAL); }
"%="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tMODULO_EQUAL); }
"&="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tBIT_AND_EQUAL); }
"|="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tBIT_OR_EQUAL); }
"^="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tBIT_XOR_EQUAL); }
"<<="           { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tLEFT_SHIFT_EQUAL); }
">>="           { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tRIGHT_SHIFT_EQUAL); }
"&^="           { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tBIT_CLEAR_EQUAL); }
"&&"            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tAND); }
"||"            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tOR); }
"<-"		{ if (mode == tokens) {printf("%s\n", yytext);} return fToken(tCHANNEL); }
"++"            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tINC); }
"--"            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tDEC); }
"=="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tIS_EQUAL); }
"<"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tLESS_THAN); }
">"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tGREATER_THAN); }
"="             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tEQUAL); }
"!"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tNOT); }
"!="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tIS_NOT_EQUAL); }
"<="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tLESS_THAN_EQUAL); }
">="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tGREATER_THAN_EQUAL); }
":="            { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tDECLARATION); }
"..."		{ if (mode == tokens) {printf("%s\n", yytext);} return fToken(tELLIPSIS); }
"("             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tLEFT_PAR); }
"["             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tLEFT_SQUARE); }
"{"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tLEFT_CURL); }
","             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tCOMMA); }
"."             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tDOT); }
")"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tRIGHT_PAR); }
"]"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tRIGHT_SQUARE); }
"}"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tRIGHT_CURL); }
";"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tSEMICOLON); }
":"             { if (mode == tokens) {printf("%s\n", yytext);} return fToken(tCOLON); }

\n {	/* New line */
    int token = fToken(tNEWLINE);
    if(token == tSEMICOLON) {
        if (mode == tokens) {
			printf (";\n");
		}
        return token;
    }
}

0+|([1-9]{DIGIT}*) {/* Integer */
	if (mode == tokens) {
		printf ("Integer constant: %s\n", yytext);
	}
	yylval.int_val = atoi(yytext);
	return fToken(tINT);
}
0[1-7][0-7]* {/* Octal */
    // Octal
    if (mode == tokens) {
		printf ("Octal constant: %s\n", yytext);
	}
	yylval.octal_val = strtol(yytext, NULL, 8);
    return fToken(tINT);
}
0[x|X][0-9a-fA-F]+ {/* Hex */
    if (mode == tokens) {
		printf ("Hexdecimal constant: %s\n", yytext);
	}
	yylval.hex_val = strtol(yytext, NULL, 16);
    return fToken(tINT);
}
([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*) {/* Float */
    if (mode == tokens) {
		printf ("Float constant: %s\n", yytext);
	}
	yylval.float_val = atof(yytext);
	return fToken(tFLOAT);
}
'((\\[abfnrtv\\\'])|[^\\'])' {
    // Rune/Character
    if (mode == tokens) {
		printf ("Rune: %s\n", yytext);
	}
    yylval.rune_val = strdup(yytext);
    return fToken(tRUNE);
}

[a-zA-Z_][a-zA-Z0-9_]* {/* Identifiers */
	if (mode == tokens) {
		printf ("Identifier: %s\n", yytext);
	}
	yylval.string_val = strdup(yytext);
	return fToken(tIDENTIFIER);
}

"`"([\x00-\x5F\x61-\x7F]|{ESC_CHARSTR})*"`" {
	/* Raw strings */
	if (mode == tokens) {
		printf("String: %s\n", yytext);
	}
	yylval.string_val = strdup(yytext);
	return fToken(tSTRING);
}


(\")([\x00-\x09\x0B-\x21\x23-\x5B\x5D-\x7F]|{ESC_CHARSTR})*(\") {
	/* Interpreted strings */
	if (mode == tokens) {
		printf("String: %s\n", yytext);
	}
	yylval.string_val = strdup(yytext);
	return fToken(tSTRING);
}

"//"[^\n]*	{}
"/*"[^*]*"*"+([^/*][^*]*"*"+)*"/" {}


. {
	// Everything else
	fprintf (stderr, "Error: (line %d) unexpected character '%s'\n", yylineno, yytext);
	exit(1);
}
%%
// Auto-inject semicolon tokens
int last_token = 0;
int fToken(int token) {
    if(token == tNEWLINE) {
        switch(last_token) {
            case tIDENTIFIER:
            case tINT:
            case tFLOAT:
			//case imaginary:
            case tRUNE:
            case tSTRING:
            case tBREAK:
            case tCONTINUE:
            case tFALLTHROUGH:
            case tRETURN:
            case tINC:
            case tDEC:
            case tRIGHT_PAR:
            case tRIGHT_SQUARE:
            case tRIGHT_CURL:
                // Put another new line
                //unput('\n');

                // Update last token
                last_token = tSEMICOLON;
                return tSEMICOLON;
            default:
                last_token = token;
                return tNEWLINE;
        }
    } else {
		if (token == tRIGHT_CURL) {
					unput('\n');
		}
        last_token = token;
        return token;
    }
}



