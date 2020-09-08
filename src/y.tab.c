/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "tree.h"
#include "weeder.h"

extern Prog* root;
extern int yylineno;
extern char* yytext;
int yylex();

void yyerror(const char *s) {
	if (mode == parse){
		fprintf(stderr, "Error: (line %d) %s\n", yylineno, s);
		fprintf(stderr,  "%s\n", yytext);
		exit(1);
	}
	else{
		while(yylex()){}
	}
}

#line 91 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 27 "parser.y" /* yacc.c:355  */

	#include "tree.h"

#line 125 "y.tab.c" /* yacc.c:355  */

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
#line 31 "parser.y" /* yacc.c:355  */

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

#line 333 "y.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 364 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   757

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  281

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   346

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   206,   206,   219,   223,   234,   238,   242,   246,   261,
     265,   275,   279,   289,   293,   297,   315,   319,   329,   333,
     343,   362,   366,   371,   375,   379,   390,   398,   412,   421,
     436,   440,   450,   454,   464,   468,   479,   483,   497,   501,
     511,   515,   519,   533,   543,   547,   551,   565,   580,   584,
     594,   598,   602,   626,   640,   644,   648,   652,   656,   660,
     664,   668,   672,   676,   680,   684,   694,   704,   714,   724,
     735,   746,   750,   754,   758,   762,   767,   771,   775,   779,
     783,   787,   791,   795,   799,   803,   807,   811,   815,   825,
     838,   842,   852,   856,   866,   870,   881,   885,   889,   893,
     897,   905,   915,   919,   923,   927,   931,   935,   939,   943,
     947,   951,   955,   959,   963,   967,   971,   975,   979,   983,
     987,   997,  1001,  1005,  1009,  1020,  1024,  1028,  1032,  1042,
    1046,  1050,  1060,  1071,  1075,  1087,  1091,  1095,  1099,  1103,
    1118,  1128
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINT", "tFLOAT", "tIDENTIFIER",
  "tSTRING", "tHEX", "tOCTAL", "tRUNE", "tNEWLINE", "tBREAK", "tCASE",
  "tCHAN", "tCONST", "tCONTINUE", "tDEFAULT", "tDEFER", "tELSE",
  "tFALLTHROUGH", "tFOR", "tFUNC", "tGO", "tGOTO", "tIF", "tIMPORT",
  "tINTERFACE", "tMAP", "tPACKAGE", "tRANGE", "tRETURN", "tSELECT",
  "tSTRUCT", "tSWITCH", "tTYPE", "tVAR", "tPRINT", "tPRINTLN", "tAPPEND",
  "tLEN", "tCAP", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\"&\"",
  "\"|\"", "\"^\"", "\"<<\"", "\">>\"", "\"&^\"", "\"+=\"", "\"-=\"",
  "\"*=\"", "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"", "\"^=\"", "\"<<=\"",
  "\">>=\"", "\"&^=\"", "\"&&\"", "\"||\"", "\"<-\"", "\"++\"", "\"--\"",
  "\"==\"", "\"!=\"", "\"<\"", "\">\"", "\"=\"", "\"!\"", "\"<=\"",
  "\">=\"", "\":=\"", "\"...\"", "\"(\"", "\"[\"", "\"{\"", "\",\"",
  "\".\"", "\")\"", "\"]\"", "\"}\"", "\";\"", "\":\"", "pNEG", "pPOS",
  "pNOT", "pXOR", "$accept", "program", "package_dec", "top_decs",
  "var_dec", "var_defs", "var_def", "type_dec", "type_defs", "type_def",
  "identifier_type", "struct_body", "func_dec", "func_params",
  "identifiers", "func_type", "statements", "if_stmt", "else_stmt",
  "for_dec", "for_condition", "switch_dec", "switch_def", "switch_cases",
  "block_body", "statement", "simple_statement_dec", "print_dec",
  "println_dec", "break_dec", "continue_dec", "simple_statement",
  "return_dec", "expressions", "expression_opt", "expressions_opt",
  "expression", "binary_expression", "unary_expression", "literals",
  "builtins", "func_call", "primary_expressions", "primary_expression",
  "selector", "index", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346
};
# endif

#define YYPACT_NINF -264

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-264)))

#define YYTABLE_NINF -135

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,    26,    43,  -264,   -26,  -264,   -15,  -264,    91,    27,
      33,  -264,  -264,  -264,    23,   121,  -264,    16,  -264,  -264,
      22,    25,    10,  -264,    29,   121,     1,  -264,    11,  -264,
      12,  -264,   232,   110,    44,   121,   -37,   102,  -264,    36,
      51,   121,    31,    32,    55,    57,  -264,  -264,    42,  -264,
    -264,    69,    72,    74,   232,   232,   232,   232,   256,    76,
     605,  -264,  -264,  -264,  -264,  -264,   -70,  -264,   232,  -264,
      78,   154,   121,  -264,     5,  -264,   121,  -264,  -264,  -264,
    -264,  -264,   232,   232,   232,   232,  -264,  -264,  -264,  -264,
     -36,   352,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   160,  -264,  -264,    76,  -264,    80,   102,
      78,  -264,   102,  -264,    76,    84,   524,   395,   438,  -264,
    -264,   605,   317,   317,  -264,  -264,  -264,  -264,   317,   317,
    -264,  -264,  -264,   651,   640,   363,   363,   363,   363,   363,
     363,   308,  -264,   197,  -264,  -264,    82,    86,  -264,   232,
    -264,  -264,  -264,   -20,    98,    99,    83,   297,   232,   210,
     120,   126,   202,  -264,  -264,  -264,    68,  -264,  -264,  -264,
     129,  -264,  -264,  -264,  -264,  -264,  -264,  -264,   124,  -264,
     -31,   675,  -264,  -264,   481,  -264,  -264,    78,   125,   605,
     261,   232,   565,   136,   605,   137,  -264,   232,   232,   141,
     232,   232,  -264,  -264,   232,    34,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,  -264,  -264,  -264,
     139,   232,   565,   142,  -264,   232,   156,   157,    76,    76,
       6,    76,   -70,   605,   605,   605,   605,   605,   605,   605,
     605,   605,   605,   605,  -264,   158,   159,   224,  -264,   161,
     167,   232,   168,   170,    35,   224,   -21,  -264,  -264,  -264,
     -74,  -264,  -264,  -264,  -264,  -264,   171,  -264,   140,  -264,
     140
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     4,     1,     2,     3,     0,     0,
       0,     6,     5,     7,     0,     0,    19,     0,    33,    12,
       0,     0,     0,    23,     0,     0,     0,    20,     0,    16,
       0,     9,     0,     0,    14,    35,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,   125,   126,   138,   127,
     128,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      91,    96,    97,    99,   100,   137,    98,    32,     0,    34,
       0,     0,    35,    31,     0,    24,     0,    22,    17,    18,
      10,    11,    95,     0,     0,     0,   122,   121,   124,   123,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,    13,    37,     0,     0,
       0,    25,     0,    21,    94,     0,     0,     0,     0,   139,
     101,    90,   102,   103,   104,   105,   106,   107,   108,   109,
     111,   112,   110,   119,   120,   113,   114,   115,   116,   117,
     118,     0,   140,    88,    29,    30,     0,     0,   132,     0,
     130,   131,   141,   138,     0,     0,    46,    88,    93,    88,
       0,     0,     0,    53,    54,    55,     0,    61,    62,    65,
       0,    60,    36,    56,    63,    64,    58,    59,     0,    57,
       0,    71,    28,    26,     0,    69,    70,     0,     0,    44,
      98,     0,     0,     0,    92,     0,    49,    95,    95,     0,
       0,     0,    52,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,   129,
       0,    93,     0,     0,    89,    93,     0,     0,    75,    87,
       0,    74,   133,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    43,     0,     0,    42,    48,     0,
       0,     0,     0,     0,    88,    42,     0,    38,    67,    68,
       0,    37,    47,    45,    39,    40,     0,    37,    51,    41,
      50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -264,  -264,  -264,  -264,   237,  -264,   216,   248,  -264,   235,
       8,  -264,  -264,  -264,   132,   192,  -263,     0,     2,  -264,
    -264,  -264,  -264,  -264,   -69,  -264,   101,  -264,  -264,  -264,
    -264,  -164,  -264,   -32,  -121,  -109,   -30,  -264,  -264,  -264,
    -264,  -264,  -264,  -132,  -264,  -264
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   174,    30,    20,   175,    28,    17,
      69,    74,    13,    36,   176,    70,   153,   177,   267,   178,
     197,   179,   180,   240,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   124,   203,   125,    60,    61,    62,    63,
      64,    65,   190,    66,   114,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,   118,   198,   167,    40,   205,     8,    92,   278,   112,
      18,     1,   113,   277,   280,    18,    15,    18,   261,     9,
      10,   191,   262,    27,    86,    87,    88,    89,    91,    34,
      23,     4,    15,    39,   200,   200,   116,   200,    18,    48,
     163,   214,    82,     5,    71,    73,    72,   129,   206,    77,
     215,   156,   -33,   126,   127,   128,   -33,    24,    82,   117,
       7,   -33,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   242,   123,    41,    46,    47,   163,    49,
     121,   263,    50,    35,    42,    44,    14,    32,   236,   237,
     273,    22,    29,    25,    26,    16,    33,    23,    31,    38,
     255,    19,   172,   172,   258,    67,    68,    78,    79,    75,
      82,    51,    52,    53,    54,    55,    23,   155,   230,   194,
     157,    56,   191,   233,    24,    76,   199,   202,   204,   204,
     210,    80,    21,    81,   211,   163,   191,    83,   191,    33,
      84,   164,    85,    24,    37,   165,    57,    92,   117,    18,
     166,    58,    21,   256,   167,   152,   154,   158,   192,   -88,
     168,   232,   193,   169,     9,    10,   170,   171,   238,   239,
      25,    26,   241,    33,   195,   196,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   276,   207,    25,
      26,   204,   163,   119,   208,   204,   122,   209,   164,   212,
     213,   231,   165,    46,    47,   163,    49,   166,   172,    50,
     117,   167,   234,   235,   129,   254,   -88,   168,   257,   270,
     169,     9,    10,   170,   171,    46,    47,    48,    49,   259,
     260,    50,   266,    11,   264,   265,    45,   268,    51,    52,
      53,    54,    55,   269,    12,   271,   272,   279,    56,    46,
      47,    90,    49,    43,   120,    50,   275,   274,   201,     0,
      51,    52,    53,    54,    55,   172,     0,   117,     0,     0,
      56,     0,   173,    57,     0,     0,     0,     0,    58,     0,
     -93,     0,     0,     0,    51,    52,    53,    54,    55,     0,
      46,    47,   163,    49,    56,    57,    50,     0,     0,     0,
      58,     0,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,     0,     0,   227,   228,    57,
       0,     0,     0,  -134,    58,    51,    52,    53,    54,    55,
     112,     0,  -134,   113,     0,    56,     0,   -71,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      95,    96,    97,    98,     0,     0,   101,   102,   103,     0,
      57,   104,   105,     0,     0,    58,   106,   107,   108,   109,
       0,     0,   110,   111,     0,     0,     0,     0,     0,     0,
       0,     0,   162,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
     106,   107,   108,   109,     0,     0,   110,   111,     0,     0,
       0,     0,     0,     0,     0,   130,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
       0,     0,     0,   106,   107,   108,   109,     0,     0,   110,
     111,     0,     0,     0,     0,     0,     0,     0,   160,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,     0,     0,     0,   106,   107,   108,   109,
       0,     0,   110,   111,     0,     0,     0,     0,     0,     0,
       0,   161,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,     0,     0,     0,   106,
     107,   108,   109,     0,     0,   110,   111,     0,     0,     0,
       0,     0,     0,     0,   229,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,     0,
       0,     0,   106,   107,   108,   109,     0,     0,   110,   111,
       0,     0,     0,     0,     0,   159,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
       0,     0,     0,   106,   107,   108,   109,     0,     0,   110,
     111,     0,     0,     0,     0,   117,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
       0,     0,     0,   106,   107,   108,   109,     0,     0,   110,
     111,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,   106,   107,
     108,   109,     0,     0,   110,   111,     0,     0,     0,   106,
     107,   108,   109,     0,     0,   110,   111,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,     0,     0,
       0,   227,   228,     0,     0,     0,     0,  -134,     0,     0,
       0,     0,     0,     0,   112,     0,  -134,   113
};

static const yytype_int16 yycheck[] =
{
      32,    70,   166,    24,     3,   169,    21,    81,   271,    79,
       5,    28,    82,    87,   277,     5,     5,     5,    12,    34,
      35,   153,    16,    15,    54,    55,    56,    57,    58,    21,
       5,     5,     5,    25,   166,   167,    68,   169,     5,     5,
       5,    72,    78,     0,    81,    37,    83,    83,   169,    41,
      81,   120,    72,    83,    84,    85,    76,    32,    78,    80,
      86,    81,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   215,    76,    84,     3,     4,     5,     6,
      85,    85,     9,    83,    83,    83,     5,    72,   207,   208,
     264,    78,    86,    78,    79,    78,    81,     5,    86,    80,
     231,    78,    78,    78,   235,     5,    72,    86,    86,    83,
      78,    38,    39,    40,    41,    42,     5,   119,   197,   159,
     122,    48,   264,   202,    32,    84,   166,   167,   168,   169,
      72,    86,    10,    86,    76,     5,   278,    78,   280,    81,
      78,    11,    78,    32,    22,    15,    73,    81,    80,     5,
      20,    78,    30,   232,    24,     5,    86,    83,    86,    86,
      30,   201,    86,    33,    34,    35,    36,    37,   210,   211,
      78,    79,   214,    81,    86,    86,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   266,    78,    78,
      79,   231,     5,    71,    78,   235,    74,     5,    11,    80,
      86,    86,    15,     3,     4,     5,     6,    20,    78,     9,
      80,    24,    86,    86,    83,    86,    86,    30,    86,   261,
      33,    34,    35,    36,    37,     3,     4,     5,     6,    83,
      83,     9,    18,     6,    86,    86,    30,    86,    38,    39,
      40,    41,    42,    86,     6,    87,    86,    86,    48,     3,
       4,     5,     6,    28,    72,     9,   266,   265,   167,    -1,
      38,    39,    40,    41,    42,    78,    -1,    80,    -1,    -1,
      48,    -1,    85,    73,    -1,    -1,    -1,    -1,    78,    -1,
      80,    -1,    -1,    -1,    38,    39,    40,    41,    42,    -1,
       3,     4,     5,     6,    48,    73,     9,    -1,    -1,    -1,
      78,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    66,    67,    73,
      -1,    -1,    -1,    72,    78,    38,    39,    40,    41,    42,
      79,    -1,    81,    82,    -1,    48,    -1,    86,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      43,    44,    45,    46,    -1,    -1,    49,    50,    51,    -1,
      73,    63,    64,    -1,    -1,    78,    68,    69,    70,    71,
      -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    63,    64,    -1,    -1,    -1,
      68,    69,    70,    71,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    68,    69,    70,    71,    -1,    -1,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    68,    69,    70,    71,
      -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    68,
      69,    70,    71,    -1,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    68,    69,    70,    71,    -1,    -1,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    68,    69,    70,    71,    -1,    -1,    74,
      75,    -1,    -1,    -1,    -1,    80,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    68,    69,    70,    71,    -1,    -1,    74,
      75,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    63,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    -1,    -1,    74,    75,    -1,    -1,    -1,    68,
      69,    70,    71,    -1,    -1,    74,    75,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    93,    94,     5,     0,    95,    86,    21,    34,
      35,    96,    99,   104,     5,     5,    78,   101,     5,    78,
      98,   106,    78,     5,    32,    78,    79,   102,   100,    86,
      97,    86,    72,    81,   102,    83,   105,   106,    80,   102,
       3,    84,    83,   101,    83,    98,     3,     4,     5,     6,
       9,    38,    39,    40,    41,    42,    48,    73,    78,   125,
     128,   129,   130,   131,   132,   133,   135,     5,    72,   102,
     107,    81,    83,   102,   103,    83,    84,   102,    86,    86,
      86,    86,    78,    78,    78,    78,   128,   128,   128,   128,
       5,   128,    81,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    63,    64,    68,    69,    70,    71,
      74,    75,    79,    82,   136,   137,   125,    80,   116,   106,
     107,    85,   106,   102,   125,   127,   128,   128,   128,    83,
      83,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,     5,   108,    86,   102,   116,   102,    83,    81,
      83,    83,    84,     5,    11,    15,    20,    24,    30,    33,
      36,    37,    78,    85,    96,    99,   106,   109,   111,   113,
     114,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     134,   135,    86,    86,   128,    86,    86,   112,   123,   128,
     135,   118,   128,   126,   128,   123,   126,    78,    78,     5,
      72,    76,    80,    86,    72,    81,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    66,    67,    83,
     116,    86,   128,   116,    86,    86,   127,   127,   125,   125,
     115,   125,   135,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,    86,   126,   116,    86,   126,    83,
      83,    12,    16,    85,    86,    86,    18,   110,    86,    86,
     125,    87,    86,   123,   110,   109,   116,    87,   108,    86,
     108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    94,    95,    95,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    99,    99,   100,   100,
     101,   102,   102,   102,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   110,   111,   112,   112,   112,   113,   114,   114,
     115,   115,   115,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   119,   120,   121,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   130,   130,   130,   130,   131,   131,   131,   131,   132,
     132,   132,   133,   134,   134,   135,   135,   135,   135,   135,
     136,   137
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     2,     2,     0,     3,
       5,     3,     0,     4,     2,     3,     3,     5,     3,     0,
       2,     4,     3,     1,     3,     4,     4,     0,     8,     7,
       4,     2,     3,     1,     1,     0,     2,     0,     5,     6,
       2,     3,     0,     4,     1,     5,     0,     5,     4,     2,
       5,     4,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     5,     2,
       2,     1,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     0,     3,
       3,     1,     1,     0,     1,     0,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     1,     1,     1,     1,     6,
       4,     4,     4,     3,     1,     2,     2,     1,     1,     3,
       2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 207 "parser.y" /* yacc.c:1646  */
    {	
		root = newProgram((yyvsp[-1].decl), (yyvsp[0].decl), (yylsp[-1]).first_line);
		weedDefault(root);
		weedContinueBreak(root);
		//weedReturn(root);	    
        }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 220 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newPackage_dec(newIdentifier((yyvsp[-1].string_val), (yylsp[-1]).first_line), (yylsp[-2]).first_line);
        }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 224 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newPackage_dec(newIdentifier((yyvsp[0].string_val), (yylsp[0]).first_line), (yylsp[-1]).first_line);
        }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 235 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newTop_decs((yyvsp[-1].decl), (yyvsp[0].decl), (yylsp[-1]).first_line);
        }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 239 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newTop_decs((yyvsp[-1].decl), (yyvsp[0].decl), (yylsp[-1]).first_line);
        }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 243 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newTop_decs((yyvsp[-1].decl), (yyvsp[0].decl), (yylsp[-1]).first_line);
        }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 247 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = NULL;
        }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 262 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newVarDec((yyvsp[-1].decl), k_NodeKindVarDecLine, (yylsp[-2]).first_line);
        }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 266 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newVarDec((yyvsp[-2].decl), k_NodeKindVarDecPar, (yylsp[-4]).first_line);
        }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 276 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newVarDefs((yyvsp[-2].decl), (yyvsp[-1].decl), (yylsp[-2]).first_line);
        }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 280 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = NULL;
        }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 290 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newVarDef((yyvsp[-3].exp), (yyvsp[-2].type), (yyvsp[0].exp), (yylsp[-3]).first_line);
        }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 294 "parser.y" /* yacc.c:1646  */
    {
			(yyval.decl) = newVarDef((yyvsp[-1].exp), (yyvsp[0].type), NULL, (yylsp[-1]).first_line);
		}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 298 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newVarDef((yyvsp[-2].exp), NULL, (yyvsp[0].exp), (yylsp[-2]).first_line);
        }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 316 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newTypeDec((yyvsp[-1].decl), k_NodeKindTypeDecLine, (yylsp[-2]).first_line);
        }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 320 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newTypeDec((yyvsp[-2].decl), k_NodeKindTypeDecPar, (yylsp[-4]).first_line);
        }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 330 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newTypeDefs((yyvsp[-2].decl), (yyvsp[-1].decl), (yylsp[-2]).first_line);
        }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 334 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = NULL;
        }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 344 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newTypeDef(newIdType((yyvsp[-1].string_val), (yylsp[-1]).first_line), (yyvsp[0].type), (yylsp[-1]).first_line);
        }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 363 "parser.y" /* yacc.c:1646  */
    {
            (yyval.type) = newIdentifierType((yyvsp[-2].int_val), (yyvsp[0].type), k_NodeKindArrayType, (yylsp[-3]).first_line);
        }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 367 "parser.y" /* yacc.c:1646  */
    {
            (yyval.type) = newIdentifierType(-1, (yyvsp[0].type), k_NodeKindSliceType, (yylsp[-2]).first_line);
        }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 372 "parser.y" /* yacc.c:1646  */
    {
            (yyval.type) = newIdType((yyvsp[0].string_val), (yylsp[0]).first_line);	//k_NodeKindIdType
        }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 376 "parser.y" /* yacc.c:1646  */
    {
			(yyval.type) = newIdentifierType(-1, (yyvsp[-1].type), k_NodeKindParType, (yylsp[-2]).first_line);
		}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 380 "parser.y" /* yacc.c:1646  */
    {
			(yyval.type) = newIdentifierType(-1, (yyvsp[-1].type), k_NodeKindStructType, (yylsp[-3]).first_line);
		}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 391 "parser.y" /* yacc.c:1646  */
    {
            (yyval.type) = newStructBody((yyvsp[-3].type), (yyvsp[-2].exp), (yyvsp[-1].type), (yylsp[-3]).first_line);
        }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 399 "parser.y" /* yacc.c:1646  */
    {
            (yyval.type) = NULL;
        }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 413 "parser.y" /* yacc.c:1646  */
    {
        	Decl* n = newFuncDec(newIdentifier((yyvsp[-6].string_val), (yylsp[-6]).first_line), (yyvsp[-4].decl), (yyvsp[-2].decl), (yyvsp[-1].stmt), (yylsp[-7]).first_line);
            (yyval.decl) = n;
            /*if (weedContinueBreak(n) >0) {
				exit(1);
			}*/
		weedReturnDecl(n);
        }
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 422 "parser.y" /* yacc.c:1646  */
    {
            Decl* n = newFuncDec(newIdentifier((yyvsp[-5].string_val), (yylsp[-5]).first_line), NULL, (yyvsp[-2].decl), (yyvsp[-1].stmt), (yylsp[-6]).first_line);
            (yyval.decl) = n;
		weedReturnDecl(n);
            /*if (weedContinueBreak(n) >0) {
				exit(1);
			}*/
        }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 437 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newFuncParams((yyvsp[-3].decl), (yyvsp[-1].exp), (yyvsp[0].type), (yylsp[-3]).first_line);
        }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 441 "parser.y" /* yacc.c:1646  */
    {
            (yyval.decl) = newFuncParams(NULL, (yyvsp[-1].exp), (yyvsp[0].type), (yylsp[-1]).first_line);
        }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 451 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) = newIdentifiers((yyvsp[-2].exp), newIdentifier((yyvsp[0].string_val), (yylsp[0]).first_line), (yylsp[-2]).first_line);
        }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 455 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp) = newIdentifiers(NULL, newIdentifier((yyvsp[0].string_val), (yylsp[0]).first_line), (yylsp[0]).first_line);
        }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 465 "parser.y" /* yacc.c:1646  */
    {
			(yyval.decl) = newFuncType((yyvsp[0].type), (yylsp[0]).first_line);
        }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 469 "parser.y" /* yacc.c:1646  */
    {
			(yyval.decl) = NULL;
        }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 480 "parser.y" /* yacc.c:1646  */
    {
			(yyval.stmt) = newStatements((yyvsp[-1].stmt), (yyvsp[0].stmt), (yylsp[-1]).first_line);
        }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 484 "parser.y" /* yacc.c:1646  */
    {
			(yyval.stmt) = NULL;
        }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 498 "parser.y" /* yacc.c:1646  */
    {
    	(yyval.stmt)=newIfStmt(NULL,(yyvsp[-3].exp),(yyvsp[-2].stmt),(yyvsp[0].stmt),(yylsp[-4]).first_line);
    }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 502 "parser.y" /* yacc.c:1646  */
    {
    	(yyval.stmt)=newIfStmt((yyvsp[-4].stmt),(yyvsp[-3].exp),(yyvsp[-2].stmt),(yyvsp[0].stmt),(yylsp[-5]).first_line);
    }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 512 "parser.y" /* yacc.c:1646  */
    {
			(yyval.stmt)=newElseStmt((yyvsp[0].stmt),NULL,(yylsp[-1]).first_line);
        }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 516 "parser.y" /* yacc.c:1646  */
    {
    	(yyval.stmt)=newElseStmt(NULL,(yyvsp[-1].stmt),(yylsp[-2]).first_line);
    }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 520 "parser.y" /* yacc.c:1646  */
    {
			(yyval.stmt)=NULL;
        }
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 534 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt)=newForDec((yyvsp[-2].stmt),(yyvsp[-1].stmt),(yylsp[-3]).first_line);
        }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 544 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt)=newForCondition(NULL,(yyvsp[0].exp),NULL,(yylsp[0]).first_line);
        }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 548 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt)=newForCondition((yyvsp[-4].stmt),(yyvsp[-2].exp),(yyvsp[0].stmt),(yylsp[-4]).first_line);
        }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 552 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt)=NULL;
        }
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 566 "parser.y" /* yacc.c:1646  */
    {
            Stmt* n = newSwitchDec((yyvsp[-4].stmt), (yyvsp[-2].stmt), (yylsp[-4]).first_line);
			/*if (weedDefault(n) == 1) {
				printf("Syntex error: Cotaining more than one default case in switch cases.\n");
				exit(1);
			}*/
            (yyval.stmt) = n;
        }
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 581 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt)=newSwitchDef((yyvsp[-2].stmt),(yyvsp[0].exp),(yylsp[-3]).first_line);
        }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 585 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt)=newSwitchDef(NULL,(yyvsp[0].exp),(yylsp[-1]).first_line);
        }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 595 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt)=newSwitchCases((yyvsp[-4].stmt),(yyvsp[-2].exp),(yyvsp[0].stmt),k_NodeKindSwitchCases,(yylsp[-3]).first_line);
        }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 599 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt)=newSwitchCases((yyvsp[-3].stmt),NULL,(yyvsp[0].stmt),k_NodeKindDefault,(yylsp[-2]).first_line);
        }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 603 "parser.y" /* yacc.c:1646  */
    {
			(yyval.stmt)=NULL;
        }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 627 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt)=newBlockBody((yyvsp[-1].stmt),(yylsp[-2]).first_line);
        }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 641 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatementDec((yyvsp[0].decl), (yylsp[0]).first_line);
        }
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 645 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatementDec((yyvsp[0].decl), (yylsp[0]).first_line);
        }
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 649 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatement((yyvsp[0].stmt), (yylsp[0]).first_line);
        }
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 653 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatement((yyvsp[0].stmt), (yylsp[0]).first_line);
        }
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 657 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatement((yyvsp[0].stmt), (yylsp[0]).first_line);
        }
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 661 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatement((yyvsp[0].stmt), (yylsp[0]).first_line);
        }
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 665 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatement((yyvsp[0].stmt), (yylsp[0]).first_line);
        }
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 669 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatement((yyvsp[0].stmt), (yylsp[0]).first_line);
        }
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 673 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatement((yyvsp[0].stmt), (yylsp[0]).first_line);
        }
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 677 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatement((yyvsp[0].stmt), (yylsp[0]).first_line);
        }
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 681 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatement((yyvsp[0].stmt), (yylsp[0]).first_line);
        }
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 685 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newStatement((yyvsp[0].stmt), (yylsp[0]).first_line);
        }
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 695 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newSimpleStatementDec((yyvsp[-1].stmt), (yylsp[-1]).first_line);
        }
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 705 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newPrintStatement((yyvsp[-2].exp), k_NodeKindPrintDec, (yylsp[-3]).first_line);
        }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 715 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newPrintStatement((yyvsp[-2].exp), k_NodeKindPrintlnDec, (yylsp[-3]).first_line);
        }
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 725 "parser.y" /* yacc.c:1646  */
    {
        	Stmt* n = newBreak((yylsp[-1]).first_line);
            (yyval.stmt) = n;
        }
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 736 "parser.y" /* yacc.c:1646  */
    {
        	Stmt* n = newContinue((yylsp[-1]).first_line);
            (yyval.stmt) = n; 
        }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 747 "parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = newSimpleStatement((yyvsp[0].exp), NULL, k_NodeKindSimpleStatementExp, (yylsp[0]).first_line);
        }
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 751 "parser.y" /* yacc.c:1646  */
    {
			(yyval.stmt) = newSimpleStatement((yyvsp[-1].exp), NULL, k_NodeKindSimpleStatementInc, (yylsp[-1]).first_line);
        }
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 755 "parser.y" /* yacc.c:1646  */
    {
			(yyval.stmt) = newSimpleStatement((yyvsp[-1].exp), NULL, k_NodeKindSimpleStatementDecrease, (yylsp[-1]).first_line);
        }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 759 "parser.y" /* yacc.c:1646  */
    {
			(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementEqual, (yylsp[-2]).first_line);
        }
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 763 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementEqual, (yylsp[-2]).first_line);
        }
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 768 "parser.y" /* yacc.c:1646  */
    {
			(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementPlusEqual, (yylsp[-2]).first_line);
        }
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 772 "parser.y" /* yacc.c:1646  */
    {
(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementMinEqual, (yylsp[-2]).first_line);
        }
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 776 "parser.y" /* yacc.c:1646  */
    {
(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementMulEqual, (yylsp[-2]).first_line);
        }
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 780 "parser.y" /* yacc.c:1646  */
    {
(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementDivEqual, (yylsp[-2]).first_line);
        }
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 784 "parser.y" /* yacc.c:1646  */
    {
(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementModEqual, (yylsp[-2]).first_line);
        }
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 788 "parser.y" /* yacc.c:1646  */
    {
(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementBitAndEqual, (yylsp[-2]).first_line);
        }
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 792 "parser.y" /* yacc.c:1646  */
    {
(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementBitOrEqual, (yylsp[-2]).first_line);
        }
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 796 "parser.y" /* yacc.c:1646  */
    {
(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementBitXorEqual, (yylsp[-2]).first_line);
        }
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 800 "parser.y" /* yacc.c:1646  */
    {
(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementLeftShiftEqual, (yylsp[-2]).first_line);
        }
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 804 "parser.y" /* yacc.c:1646  */
    {
(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementRightShiftEqual, (yylsp[-2]).first_line);
        }
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 808 "parser.y" /* yacc.c:1646  */
    {
(yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementBitClearEqual, (yylsp[-2]).first_line);
        }
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 812 "parser.y" /* yacc.c:1646  */
    {
       (yyval.stmt) = newSimpleStatement((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindSimpleStatementDeclEqual, (yylsp[-2]).first_line);     
        }
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 816 "parser.y" /* yacc.c:1646  */
    {
			(yyval.stmt)=NULL;
        }
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 826 "parser.y" /* yacc.c:1646  */
    {
           (yyval.stmt)=newReturnStatement((yyvsp[-1].exp), (yylsp[-2]).first_line);
        }
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 839 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) = newExpressions((yyvsp[-2].exp), (yyvsp[0].exp), (yylsp[0]).first_line);
        }
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 843 "parser.y" /* yacc.c:1646  */
    {
        	(yyval.exp) = newExpressions(NULL, (yyvsp[0].exp), (yylsp[0]).first_line);
        }
#line 2582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 853 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) = newExpressionOpt((yyvsp[0].exp), (yylsp[0]).first_line);
        }
#line 2590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 857 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) = NULL;
        }
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 867 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) = newExpressionsOpt((yyvsp[0].exp), (yylsp[0]).first_line);
        }
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 871 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) = NULL;
        }
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 882 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpression((yyvsp[0].exp),(yylsp[0]).first_line);
        }
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 886 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpression((yyvsp[0].exp),(yylsp[0]).first_line);
        }
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 890 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpression((yyvsp[0].exp),(yylsp[0]).first_line);
        }
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 894 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp)=newExpression((yyvsp[0].exp),(yylsp[0]).first_line);
        }
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 898 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp)=newExpression((yyvsp[0].exp),(yylsp[0]).first_line);
        }
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 906 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp)=newExpression((yyvsp[-1].exp),(yylsp[-1]).first_line);
        }
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 916 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) = newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryPlus, (yylsp[-2]).first_line);
        }
#line 2670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 920 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)= newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryMinus, (yylsp[-2]).first_line);
        }
#line 2678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 924 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) =newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryMultiply, (yylsp[-2]).first_line);
        }
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 928 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) =newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryDivide, (yylsp[-2]).first_line);
        }
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 932 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) =newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryModulo, (yylsp[-2]).first_line);
        }
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 936 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) =newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryBitAnd, (yylsp[-2]).first_line);
        }
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 940 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) =newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryBitOr, (yylsp[-2]).first_line);
        }
#line 2718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 944 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) =newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryBitXor, (yylsp[-2]).first_line);
        }
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 948 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinarybitClear, (yylsp[-2]).first_line);
        }
#line 2734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 952 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryLeftShift, (yylsp[-2]).first_line);
        }
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 956 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryRightShift, (yylsp[-2]).first_line);
        }
#line 2750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 960 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryIsEqual, (yylsp[-2]).first_line);
        }
#line 2758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 964 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryIsNotEqual, (yylsp[-2]).first_line);
        }
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 968 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryLessThan, (yylsp[-2]).first_line);
        }
#line 2774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 972 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryGreaterThan, (yylsp[-2]).first_line);
        }
#line 2782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 976 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryLessThanEqual, (yylsp[-2]).first_line);
        }
#line 2790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 980 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryGreaterThanEqual, (yylsp[-2]).first_line);
        }
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 984 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryAnd, (yylsp[-2]).first_line);
        }
#line 2806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 988 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionBinary((yyvsp[-2].exp), (yyvsp[0].exp), k_NodeKindExpressionBinaryOr, (yylsp[-2]).first_line);
        }
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 998 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionUnary((yyvsp[0].exp),k_NodeKindUMinus,(yylsp[0]).first_line);
        }
#line 2822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1002 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionUnary((yyvsp[0].exp),k_NodeKindUPlus,(yylsp[0]).first_line);
        }
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1006 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionUnary((yyvsp[0].exp),k_NodeKindUNot,(yylsp[0]).first_line);
        }
#line 2838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1010 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionUnary((yyvsp[0].exp),k_NodeKindUXor,(yylsp[0]).first_line);
        }
#line 2846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1021 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp)=newIntLiteral((yyvsp[0].int_val),(yylsp[0]).first_line);
        }
#line 2854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1025 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp)=newFloatLiteral((yyvsp[0].float_val),(yylsp[0]).first_line);
        }
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1029 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp)=newStringLiteral((yyvsp[0].string_val),(yylsp[0]).first_line);
        }
#line 2870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1033 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp)=newRuneLiteral((yyvsp[0].rune_val),(yylsp[0]).first_line);
        }
#line 2878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1043 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp)=newBuiltin((yyvsp[-3].exp),(yyvsp[-1].exp),k_NodeKindAppend,(yylsp[-5]).first_line);
        }
#line 2886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1047 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newBuiltin((yyvsp[-1].exp),NULL,k_NodeKindLen,(yylsp[-3]).first_line);
		}
#line 2894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1051 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newBuiltin((yyvsp[-1].exp),NULL,k_NodeKindCap,(yylsp[-3]).first_line);
		}
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1061 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newFuncCall(newIdentifier((yyvsp[-3].string_val),(yylsp[-3]).first_line),(yyvsp[-1].exp),(yylsp[-3]).first_line);
        }
#line 2910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1072 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp) = newExpressionsPrimary((yyvsp[-2].exp), (yyvsp[0].exp), (yylsp[-2]).first_line);
        }
#line 2918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1076 "parser.y" /* yacc.c:1646  */
    {
            (yyval.exp) = newExpressionsPrimary(NULL, (yyvsp[0].exp), (yylsp[0]).first_line);
        }
#line 2926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1088 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionPrimary((yyvsp[-1].exp),(yyvsp[0].exp),NULL,NULL,NULL,(yylsp[0]).first_line);
        }
#line 2934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1092 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newExpressionPrimary((yyvsp[-1].exp),NULL,(yyvsp[0].exp),NULL,NULL,(yylsp[0]).first_line);
        }
#line 2942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1096 "parser.y" /* yacc.c:1646  */
    {
    (yyval.exp)=newExpressionPrimary(NULL,NULL,NULL,NULL,(yyvsp[0].exp),(yylsp[0]).first_line);
        }
#line 2950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1100 "parser.y" /* yacc.c:1646  */
    {
    (yyval.exp)=newExpressionPrimary(NULL,NULL,NULL,NULL,newIdentifier((yyvsp[0].string_val),(yylsp[0]).first_line),(yylsp[0]).first_line);
        }
#line 2958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1104 "parser.y" /* yacc.c:1646  */
    {
    (yyval.exp)=newExpressionPrimary(NULL,NULL,NULL,NULL,newIdentifier((yyvsp[-1].string_val),(yylsp[-1]).first_line),(yylsp[-1]).first_line);
        }
#line 2966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1119 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newSelector(newIdentifier((yyvsp[0].string_val),(yylsp[0]).first_line),(yylsp[0]).first_line);
        }
#line 2974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1129 "parser.y" /* yacc.c:1646  */
    {
			(yyval.exp)=newIndex((yyvsp[-1].exp),(yylsp[-2]).first_line);
        }
#line 2982 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2986 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
