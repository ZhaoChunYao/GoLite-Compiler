/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 27 "parser.y" /* yacc.c:1909  */

	#include "tree.h"

#line 48 "y.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tINT = 258,
    tFLOAT = 259,
    tIDENTIFIER = 260,
    tSTRING = 261,
    tHEX = 262,
    tOCTAL = 263,
    tRUNE = 264,
    tNEWLINE = 265,
    tBREAK = 266,
    tCASE = 267,
    tCHAN = 268,
    tCONST = 269,
    tCONTINUE = 270,
    tDEFAULT = 271,
    tDEFER = 272,
    tELSE = 273,
    tFALLTHROUGH = 274,
    tFOR = 275,
    tFUNC = 276,
    tGO = 277,
    tGOTO = 278,
    tIF = 279,
    tIMPORT = 280,
    tINTERFACE = 281,
    tMAP = 282,
    tPACKAGE = 283,
    tRANGE = 284,
    tRETURN = 285,
    tSELECT = 286,
    tSTRUCT = 287,
    tSWITCH = 288,
    tTYPE = 289,
    tVAR = 290,
    tPRINT = 291,
    tPRINTLN = 292,
    tAPPEND = 293,
    tLEN = 294,
    tCAP = 295,
    tPLUS = 296,
    tMINUS = 297,
    tMULTIPLY = 298,
    tDIVIDE = 299,
    tMODULO = 300,
    tBIT_AND = 301,
    tBIT_OR = 302,
    tBIT_XOR = 303,
    tLEFT_SHIFT = 304,
    tRIGHT_SHIFT = 305,
    tBIT_CLEAR = 306,
    tPLUS_EQUAL = 307,
    tMINUS_EQUAL = 308,
    tMULTIPLY_EQUAL = 309,
    tDIVIDE_EQUAL = 310,
    tMODULO_EQUAL = 311,
    tBIT_AND_EQUAL = 312,
    tBIT_OR_EQUAL = 313,
    tBIT_XOR_EQUAL = 314,
    tLEFT_SHIFT_EQUAL = 315,
    tRIGHT_SHIFT_EQUAL = 316,
    tBIT_CLEAR_EQUAL = 317,
    tAND = 318,
    tOR = 319,
    tCHANNEL = 320,
    tINC = 321,
    tDEC = 322,
    tIS_EQUAL = 323,
    tIS_NOT_EQUAL = 324,
    tLESS_THAN = 325,
    tGREATER_THAN = 326,
    tEQUAL = 327,
    tNOT = 328,
    tLESS_THAN_EQUAL = 329,
    tGREATER_THAN_EQUAL = 330,
    tDECLARATION = 331,
    tELLIPSIS = 332,
    tLEFT_PAR = 333,
    tLEFT_SQUARE = 334,
    tLEFT_CURL = 335,
    tCOMMA = 336,
    tDOT = 337,
    tRIGHT_PAR = 338,
    tRIGHT_SQUARE = 339,
    tRIGHT_CURL = 340,
    tSEMICOLON = 341,
    tCOLON = 342,
    pNEG = 343,
    pPOS = 344,
    pNOT = 345,
    pXOR = 346
  };
#endif
/* Tokens.  */
#define tINT 258
#define tFLOAT 259
#define tIDENTIFIER 260
#define tSTRING 261
#define tHEX 262
#define tOCTAL 263
#define tRUNE 264
#define tNEWLINE 265
#define tBREAK 266
#define tCASE 267
#define tCHAN 268
#define tCONST 269
#define tCONTINUE 270
#define tDEFAULT 271
#define tDEFER 272
#define tELSE 273
#define tFALLTHROUGH 274
#define tFOR 275
#define tFUNC 276
#define tGO 277
#define tGOTO 278
#define tIF 279
#define tIMPORT 280
#define tINTERFACE 281
#define tMAP 282
#define tPACKAGE 283
#define tRANGE 284
#define tRETURN 285
#define tSELECT 286
#define tSTRUCT 287
#define tSWITCH 288
#define tTYPE 289
#define tVAR 290
#define tPRINT 291
#define tPRINTLN 292
#define tAPPEND 293
#define tLEN 294
#define tCAP 295
#define tPLUS 296
#define tMINUS 297
#define tMULTIPLY 298
#define tDIVIDE 299
#define tMODULO 300
#define tBIT_AND 301
#define tBIT_OR 302
#define tBIT_XOR 303
#define tLEFT_SHIFT 304
#define tRIGHT_SHIFT 305
#define tBIT_CLEAR 306
#define tPLUS_EQUAL 307
#define tMINUS_EQUAL 308
#define tMULTIPLY_EQUAL 309
#define tDIVIDE_EQUAL 310
#define tMODULO_EQUAL 311
#define tBIT_AND_EQUAL 312
#define tBIT_OR_EQUAL 313
#define tBIT_XOR_EQUAL 314
#define tLEFT_SHIFT_EQUAL 315
#define tRIGHT_SHIFT_EQUAL 316
#define tBIT_CLEAR_EQUAL 317
#define tAND 318
#define tOR 319
#define tCHANNEL 320
#define tINC 321
#define tDEC 322
#define tIS_EQUAL 323
#define tIS_NOT_EQUAL 324
#define tLESS_THAN 325
#define tGREATER_THAN 326
#define tEQUAL 327
#define tNOT 328
#define tLESS_THAN_EQUAL 329
#define tGREATER_THAN_EQUAL 330
#define tDECLARATION 331
#define tELLIPSIS 332
#define tLEFT_PAR 333
#define tLEFT_SQUARE 334
#define tLEFT_CURL 335
#define tCOMMA 336
#define tDOT 337
#define tRIGHT_PAR 338
#define tRIGHT_SQUARE 339
#define tRIGHT_CURL 340
#define tSEMICOLON 341
#define tCOLON 342
#define pNEG 343
#define pPOS 344
#define pNOT 345
#define pXOR 346

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:1909  */

	int int_val;
	int octal_val;
	int hex_val;
	double float_val;
	char* string_val;
	char* rune_val;
	Prog* prog;
	Decl* decl;
	Stmt* stmt;
	Type* type;
	Exp* exp;

#line 256 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
