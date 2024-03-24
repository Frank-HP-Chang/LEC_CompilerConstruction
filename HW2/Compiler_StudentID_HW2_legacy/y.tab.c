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
#line 2 "compiler_hw2.y" /* yacc.c:339  */

    #include "common.h" //Extern variables that communicate with lex
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    int scope = 0;
    int indexArr[50], lineno[50], scopeArr[50];
    char* nameArr[50], *typeArr[50], *elementType[50];
    int symNum[5];
    int varNum = 0;
    int printflag = 0;
    bool array_flag=0;
    char *tmp_type;
    char *assign_p_STR;
    char *add_op_STR;
    char *cmp_op_STR;
    int type_ADDRESS;
    int tmp_scope, i;
    bool s_flag=0;
	int type1, type2;
    int add1, add2;
    char ty1[10], ty2[10];

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }


    /* Symbol table function - you can add new function if needed. */
    static void create_symbol();
    static void insert_symbol(int, char*, char*, int, char*);
    static int lookup_symbol(char*,int);
    static void dump_symbol(int);
    void calculatePrint(char *, int);

#line 109 "y.tab.c" /* yacc.c:339  */

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOL = 258,
    STRING = 259,
    INT = 260,
    FLOAT = 261,
    ENDL = 262,
    SEMICOLON = 263,
    INC = 264,
    DEC = 265,
    GEQ = 266,
    LEQ = 267,
    EQL = 268,
    NEQ = 269,
    ADD_ASSIGN = 270,
    SUB_ASSIGN = 271,
    MUL_ASSIGN = 272,
    QUO_ASSIGN = 273,
    REM_ASSIGN = 274,
    LAND = 275,
    LOR = 276,
    NEWLINE = 277,
    PRINT = 278,
    PRINTLN = 279,
    IF = 280,
    ELSE = 281,
    FOR = 282,
    WHILE = 283,
    TRUE = 284,
    FALSE = 285,
    INT_LIT = 286,
    FLOAT_LIT = 287,
    STRING_LIT = 288,
    IDENT = 289
  };
#endif
/* Tokens.  */
#define BOOL 258
#define STRING 259
#define INT 260
#define FLOAT 261
#define ENDL 262
#define SEMICOLON 263
#define INC 264
#define DEC 265
#define GEQ 266
#define LEQ 267
#define EQL 268
#define NEQ 269
#define ADD_ASSIGN 270
#define SUB_ASSIGN 271
#define MUL_ASSIGN 272
#define QUO_ASSIGN 273
#define REM_ASSIGN 274
#define LAND 275
#define LOR 276
#define NEWLINE 277
#define PRINT 278
#define PRINTLN 279
#define IF 280
#define ELSE 281
#define FOR 282
#define WHILE 283
#define TRUE 284
#define FALSE 285
#define INT_LIT 286
#define FLOAT_LIT 287
#define STRING_LIT 288
#define IDENT 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 50 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *id_val;
    char *s_val;
    
    /* ... */

#line 226 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,    48,     2,     2,    42,     2,     2,
      43,    44,    40,    35,     2,    36,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    47,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    98,    99,   105,   106,   111,   112,   116,
     117,   118,   121,   122,   123,   128,   129,   130,   131,   132,
     136,   137,   138,   139,   140,   141,   145,   146,   150,   157,
     164,   174,   175,   176,   180,   184,   185,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   205,   208,   211,   217,
     220,   223,   228,   231,   234,   238,   243,   252,   257,   262,
     267,   272,   279,   285,   286,   287,   291,   294,   295,   296,
     297,   298,   299,   303,   307,   311,   318,   319,   320,   324,
     327,   331,   331,   335,   352,   355,   358,   365
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "STRING", "INT", "FLOAT", "ENDL",
  "SEMICOLON", "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "LAND", "LOR",
  "NEWLINE", "PRINT", "PRINTLN", "IF", "ELSE", "FOR", "WHILE", "TRUE",
  "FALSE", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "IDENT", "'+'", "'-'",
  "'!'", "'<'", "'>'", "'*'", "'/'", "'%'", "'('", "')'", "'['", "']'",
  "'='", "'\"'", "'{'", "'}'", "$accept", "Program", "StatementList",
  "Expression", "UnaryExpr", "PrimaryExpr", "unary_op", "binary_op",
  "cmp_op", "add_op", "mul_op", "Operand", "IndexExpr", "ConversionExpr",
  "Statement", "DeclarationStmt", "CalculateStmt", "AssignmentExpr",
  "AssignmentStmt", "assign_p", "IncDecStmt", "IncDecExpr", "IfStmt",
  "WhileStmt", "Condition", "Block", "$@1", "ForStmt", "Literal",
  "PrintStmt", YY_NULLPTR
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
     285,   286,   287,   288,   289,    43,    45,    33,    60,    62,
      42,    47,    37,    40,    41,    91,    93,    61,    34,   123,
     125
};
# endif

#define YYPACT_NINF -125

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-125)))

#define YYTABLE_NINF -82

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      88,   -32,   -18,   -12,   -10,   -20,   -17,  -125,    -9,  -125,
    -125,  -125,    67,  -125,  -125,  -125,    53,    25,  -125,   164,
    -125,    -8,    37,  -125,  -125,  -125,     8,  -125,  -125,    19,
    -125,  -125,    30,  -125,  -125,  -125,     4,  -125,  -125,  -125,
       3,     1,     2,     7,    37,    37,    37,  -125,  -125,    21,
      22,    26,    27,    31,    20,    39,  -125,   340,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,    37,  -125,
    -125,  -125,   399,    37,  -125,  -125,  -125,  -125,    88,   -11,
    -125,    37,    47,  -125,    37,    37,  -125,    37,    37,   351,
     385,    55,    56,    89,    93,    96,    98,   102,   -26,   -26,
    -125,   385,  -125,  -125,    37,   385,   177,    62,   106,   109,
     213,    37,   225,   297,   261,   308,   122,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,    37,  -125,  -125,   115,  -125,  -125,
    -125,  -125,   124,   126,   125,  -125,   133,  -125,  -125,   108,
    -125,  -125,  -125,   134,  -125,  -125,   118,  -125,  -125,  -125
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      81,     0,     0,     0,     0,     0,     0,    83,     0,    84,
      85,    86,    32,    12,    13,    14,     0,     0,     2,     0,
       5,     7,     0,     9,    10,    11,     4,    38,    40,     0,
      39,    41,     0,    44,    43,    45,     0,    37,    31,    42,
       0,     0,     0,     0,     0,     0,     0,    74,    75,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     1,    25,
      23,    20,    21,    68,    69,    70,    71,    72,    15,    16,
      26,    27,    22,    24,    28,    29,    30,    67,     0,    17,
      18,    19,     0,     0,     8,     3,    66,    73,    81,     0,
      53,     0,     0,    47,     0,     0,    50,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     6,    64,    65,     0,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    81,    57,
      58,    59,    60,    61,     0,    35,    36,     0,    34,    82,
      55,    56,     0,     0,     0,    46,     0,    49,    87,    76,
      79,    63,    54,     0,    48,    51,    81,    52,    77,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -125,  -125,   -25,   -16,   123,  -125,  -125,  -125,  -125,  -125,
    -125,   -88,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,    -7,  -125,   112,  -124,  -125,  -125,  -125,  -125
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    78,    79,    80,
      81,    23,    24,    25,    26,    27,    28,    29,    30,    82,
      31,    32,    33,    34,   101,    35,    36,    37,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    85,    40,   149,   150,     9,    10,    11,    56,    90,
      93,     1,     2,     3,     4,    96,    41,   134,   118,   119,
     135,   136,    42,    44,    43,    58,    45,    86,    99,   100,
     100,     5,   159,     6,    46,     7,     8,    83,    87,     9,
      10,    11,    12,    13,    14,    15,    91,    94,    92,    95,
      89,    16,    97,    88,    98,   103,   104,   -81,    54,    55,
     105,   106,   111,   117,   108,   107,   115,   116,     9,    10,
      11,    56,    13,    14,    15,   120,    47,    48,   122,   123,
      16,   124,   125,   109,     9,    10,    11,    56,    13,    14,
      15,     1,     2,     3,     4,   121,    16,   129,   137,   127,
     128,   130,    49,    50,   131,   143,   132,    51,    52,    53,
     133,     5,   139,     6,   140,     7,     8,   141,    57,     9,
      10,    11,    12,    13,    14,    15,    59,    60,    61,    62,
     148,    16,   152,   154,   156,    68,    69,    59,    60,    61,
      62,   155,   157,     6,     0,    84,    68,    69,     0,   158,
      70,    71,     0,    72,    73,    74,    75,    76,   102,     0,
       0,    70,    71,   151,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,   153,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    59,    60,
      61,    62,     0,     0,     0,     0,     0,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,     0,     0,
       0,    77,    70,    71,     0,    72,    73,    74,    75,    76,
       0,     0,     0,   138,    59,    60,    61,    62,     0,     0,
       0,     0,     0,    68,    69,     0,    59,    60,    61,    62,
       0,     0,     0,     0,     0,    68,    69,     0,    70,    71,
       0,    72,    73,    74,    75,    76,     0,     0,     0,   142,
      70,    71,     0,    72,    73,    74,    75,    76,     0,     0,
       0,   144,    59,    60,    61,    62,     0,     0,     0,     0,
       0,    68,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,     0,    72,
      73,    74,    75,    76,     0,   145,     0,   146,    59,    60,
      61,    62,     0,     0,     0,     0,   147,    68,    69,    59,
      60,    61,    62,     0,     0,     0,     0,     0,    68,    69,
       0,     0,    70,    71,     0,    72,    73,    74,    75,    76,
       0,     0,     0,    70,    71,     0,    72,    73,    74,    75,
      76,    59,    60,    61,    62,     0,     0,     0,     0,     0,
      68,    69,    59,    60,    61,    62,     0,     0,     0,     0,
       0,    68,    69,     0,     0,    70,    71,     0,    72,    73,
      74,    75,    76,     0,   110,     0,    70,    71,     0,    72,
      73,    74,    75,    76,     0,   126,    59,    60,    61,    62,
       0,     0,     0,     0,     0,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,     0,    72,    73,    74,    75,    76,   112,   113,
       9,    10,    11,    56,    13,    14,    15,     0,     0,     0,
       0,     0,    16,     0,     0,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
      16,    26,    34,   127,   128,    31,    32,    33,    34,     8,
       8,     3,     4,     5,     6,     8,    34,    43,    29,    30,
     108,   109,    34,    43,    34,     0,    43,     8,    44,    45,
      46,    23,   156,    25,    43,    27,    28,    45,     8,    31,
      32,    33,    34,    35,    36,    37,    45,    45,    47,    47,
      47,    43,    45,    49,    47,    34,    34,    49,     5,     6,
      34,    34,    78,    88,    44,    34,    82,    83,    31,    32,
      33,    34,    35,    36,    37,    91,     9,    10,    94,    95,
      43,    97,    98,    44,    31,    32,    33,    34,    35,    36,
      37,     3,     4,     5,     6,    48,    43,     8,   114,    44,
      44,     8,    35,    36,     8,   121,     8,    40,    41,    42,
       8,    23,    50,    25,     8,    27,    28,     8,   134,    31,
      32,    33,    34,    35,    36,    37,    11,    12,    13,    14,
       8,    43,     8,     8,    26,    20,    21,    11,    12,    13,
      14,     8,     8,    25,    -1,    22,    20,    21,    -1,   156,
      35,    36,    -1,    38,    39,    40,    41,    42,    46,    -1,
      -1,    35,    36,    48,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    20,    21,    35,
      36,    -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    47,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    46,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    20,    21,    -1,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    46,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    46,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    38,
      39,    40,    41,    42,    -1,     8,    -1,    46,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,     8,    20,    21,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,    21,
      -1,    -1,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    35,    36,    -1,    38,    39,    40,    41,
      42,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      20,    21,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    20,    21,    -1,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    -1,    44,    -1,    35,    36,    -1,    38,
      39,    40,    41,    42,    -1,    44,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,    38,    39,    40,    41,    42,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    23,    25,    27,    28,    31,
      32,    33,    34,    35,    36,    37,    43,    52,    53,    54,
      55,    56,    57,    62,    63,    64,    65,    66,    67,    68,
      69,    71,    72,    73,    74,    76,    77,    78,    79,    80,
      34,    34,    34,    34,    43,    43,    43,     9,    10,    35,
      36,    40,    41,    42,     5,     6,    34,    54,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      35,    36,    38,    39,    40,    41,    42,    47,    58,    59,
      60,    61,    70,    45,    55,    53,     8,     8,    49,    47,
       8,    45,    47,     8,    45,    47,     8,    45,    47,    54,
      54,    75,    75,    34,    34,    34,    34,    34,    44,    44,
      44,    54,    29,    30,    48,    54,    54,    53,    29,    30,
      54,    48,    54,    54,    54,    54,    44,    44,    44,     8,
       8,     8,     8,     8,    43,    62,    62,    54,    46,    50,
       8,     8,    46,    54,    46,     8,    46,     8,     8,    76,
      76,    48,     8,    48,     8,     8,    26,     8,    73,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    62,    62,    62,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    67,
      67,    67,    68,    68,    68,    68,    69,    70,    70,    70,
      70,    70,    70,    71,    72,    72,    73,    73,    73,    74,
      75,    77,    76,    78,    79,    79,    79,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     3,     6,     5,
       3,     6,     7,     3,     6,     5,     5,     4,     4,     4,
       4,     4,     3,     5,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     5,     7,     7,     5,
       1,     0,     4,     1,     1,     1,     1,     5
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 20:
#line 136 "compiler_hw2.y" /* yacc.c:1646  */
    {cmp_op_STR="EQL";}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 137 "compiler_hw2.y" /* yacc.c:1646  */
    {cmp_op_STR="NEQ";}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 138 "compiler_hw2.y" /* yacc.c:1646  */
    {cmp_op_STR="LTR";}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 139 "compiler_hw2.y" /* yacc.c:1646  */
    {cmp_op_STR="LEQ";}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 140 "compiler_hw2.y" /* yacc.c:1646  */
    {cmp_op_STR="GTR";}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 141 "compiler_hw2.y" /* yacc.c:1646  */
    {cmp_op_STR="GEQ";}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 145 "compiler_hw2.y" /* yacc.c:1646  */
    {add_op_STR="ADD";}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 146 "compiler_hw2.y" /* yacc.c:1646  */
    {add_op_STR="SUB";s_flag=1;}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 150 "compiler_hw2.y" /* yacc.c:1646  */
    {add_op_STR="MUL";
        if(s_flag)
        {
            printf("SUB\n");
        }
        s_flag=0;
    }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 157 "compiler_hw2.y" /* yacc.c:1646  */
    {add_op_STR="QUO";
        if(s_flag)
        {
            printf("SUB\n");
        }
        s_flag=0;
    }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 164 "compiler_hw2.y" /* yacc.c:1646  */
    {add_op_STR="REM";
        if(s_flag)
        {
            printf("SUB\n");
        }
        s_flag=0;
    }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 175 "compiler_hw2.y" /* yacc.c:1646  */
    {calculatePrint((yyvsp[0].id_val),scope);type_ADDRESS=lookup_symbol((yyvsp[0].id_val),scope);/*printf("-----------\nSCOPE:%d\n--------------\n",scope)*/;}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 184 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("F to I\n");printf(add_op_STR);printf("\n");}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 185 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("I to F\n");}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 205 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        insert_symbol( scope,(yyvsp[-3].id_val), "int", yylineno, "-");
    }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 208 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        insert_symbol( scope,(yyvsp[-1].id_val), "int", yylineno, "-"); 
    }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 211 "compiler_hw2.y" /* yacc.c:1646  */
    {
        array_flag=1;
         insert_symbol( scope,(yyvsp[-4].id_val), "array", yylineno, "int"); 
         
         //calculatePrint($2,scope);
    }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 217 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        insert_symbol( scope,(yyvsp[-3].id_val), "float", yylineno, "-");
    }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 220 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        insert_symbol( scope,(yyvsp[-1].id_val), "float", yylineno, "-"); 
    }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 223 "compiler_hw2.y" /* yacc.c:1646  */
    {
        array_flag=1;
         insert_symbol( scope,(yyvsp[-4].id_val), "array", yylineno, "float"); 
         
    }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 228 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        insert_symbol( scope,(yyvsp[-5].id_val), "string", yylineno, "-");
    }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 231 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        insert_symbol( scope,(yyvsp[-1].id_val), "string", yylineno, "-"); 
    }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 234 "compiler_hw2.y" /* yacc.c:1646  */
    {
         insert_symbol( scope,(yyvsp[-4].id_val), "array", yylineno, "-"); 
         calculatePrint((yyvsp[-4].id_val),scope);
    }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 238 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        printf("TRUE\n");
        insert_symbol( scope,(yyvsp[-3].id_val), "bool", yylineno, "-");
        
    }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 243 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        printf("FALSE\n");
        insert_symbol( scope,(yyvsp[-3].id_val), "bool", yylineno, "-");
        
    }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 252 "compiler_hw2.y" /* yacc.c:1646  */
    {
        calculatePrint((yyvsp[-3].id_val),scope);
        calculatePrint((yyvsp[-1].id_val),scope);
        printf("ADD\n");
    }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 257 "compiler_hw2.y" /* yacc.c:1646  */
    {
        calculatePrint((yyvsp[-3].id_val),scope);
        calculatePrint((yyvsp[-1].id_val),scope);
        printf("SUB\n");
    }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 262 "compiler_hw2.y" /* yacc.c:1646  */
    {
        calculatePrint((yyvsp[-3].id_val),scope);
        calculatePrint((yyvsp[-1].id_val),scope);
        printf("MUL\n");
    }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 267 "compiler_hw2.y" /* yacc.c:1646  */
    {
        calculatePrint((yyvsp[-3].id_val),scope);
        calculatePrint((yyvsp[-1].id_val),scope);
        printf("QUO\n");
    }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 272 "compiler_hw2.y" /* yacc.c:1646  */
    {
        calculatePrint((yyvsp[-3].id_val),scope);
        calculatePrint((yyvsp[-1].id_val),scope);
        printf("REM\n");
    }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 279 "compiler_hw2.y" /* yacc.c:1646  */
    {
        if(array_flag)
        {
            printf(add_op_STR);printf("\n");
        }
    }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 286 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("TRUE\n");}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 287 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("FALSE\n");}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 291 "compiler_hw2.y" /* yacc.c:1646  */
    {printf(assign_p_STR);printf("\n");}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 294 "compiler_hw2.y" /* yacc.c:1646  */
    {assign_p_STR="ASSIGN";}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 295 "compiler_hw2.y" /* yacc.c:1646  */
    {assign_p_STR="ADD_ASSIGN";}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 296 "compiler_hw2.y" /* yacc.c:1646  */
    {assign_p_STR="SUB_ASSIGN";}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 297 "compiler_hw2.y" /* yacc.c:1646  */
    {assign_p_STR="MUL_ASSIGN";}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 298 "compiler_hw2.y" /* yacc.c:1646  */
    {assign_p_STR="QUO_ASSIGN";}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 299 "compiler_hw2.y" /* yacc.c:1646  */
    {assign_p_STR="REM_ASSIGN";}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 307 "compiler_hw2.y" /* yacc.c:1646  */
    {
        calculatePrint((yyvsp[-1].id_val),scope);
        printf("INC\n");
    }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 311 "compiler_hw2.y" /* yacc.c:1646  */
    {
        calculatePrint((yyvsp[-1].id_val),scope);
        printf("DEC\n");
    }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 327 "compiler_hw2.y" /* yacc.c:1646  */
    {printf(cmp_op_STR);printf("\n");}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 331 "compiler_hw2.y" /* yacc.c:1646  */
    {scope++;}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 331 "compiler_hw2.y" /* yacc.c:1646  */
    {dump_symbol(scope);--scope;}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 352 "compiler_hw2.y" /* yacc.c:1646  */
    {
        printf("INT_LIT %d\n", (yyval.i_val));
    }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 355 "compiler_hw2.y" /* yacc.c:1646  */
    {
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
    }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 358 "compiler_hw2.y" /* yacc.c:1646  */
    {
        printf("STRING_LIT %s\n",(yyval.s_val));
    }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 365 "compiler_hw2.y" /* yacc.c:1646  */
    {
        if(array_flag)
        {
            printf("PRINT %s",elementType[type_ADDRESS]);printf("\n");
        }
        else
        {
            printf("PRINT %s",typeArr[type_ADDRESS]);printf("\n");
        }
        
    }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1877 "y.tab.c" /* yacc.c:1646  */
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 381 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    create_symbol();
    yyparse();
    dump_symbol(scope);
    array_flag=0;
    yylineno--;
    //printf("HELLo THERE");
	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol() {
    for(int i=50; i>=0; i--) {
            indexArr[i] = 0;
            lineno[i] = 0;
            scopeArr[i] = -1;
            nameArr[i] = NULL;
            typeArr[i] = NULL;
            elementType[i] = NULL;
        }
    for(int i=4; i>=0; i--) {
        symNum[i] = 0;
        }
    //printf("WE ARE CREATE!!!\n");
}


static int lookup_symbol(char *id, int level) {
    int returnValue=2;
    for(int i=0; i<varNum; i++) {
        //printf("------------------\n");
        //printf("level:%d scopeArr: %d\n",level,scopeArr[i]);
        //printf("id: %s nameArr:%s\n",id,nameArr[i]);
        //printf("------------------\n");
        //printf("IN THE LOOKUP LOOP\n");
        if( strcmp(id,nameArr[i])==0 && (level == scopeArr[i]) ) {
            returnValue=i;
        }
    }
    //printf("LOOKUPLV %s %d",id,level);
    return returnValue;
}


static void insert_symbol(int level, char *ident, char *type,int line_num, char *element)
{

    printf("> Insert {%s} into symbol table (scope level: %d)\n", ident, level);    
    int i = varNum;
    indexArr[i] = symNum[level];
    nameArr[i] = ident;
    typeArr[i] = type;
    lineno[i] = line_num;
    elementType[i] = element;
    scopeArr[i] = level;

    symNum[level]++;
    varNum++;
    //printf("LEVEL %d\n",level);
    /*printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int in=0; in<varNum; in++) {
        if(scopeArr[in] == level) {
            printf("%-10d%-10s%-10s%-10d%-10d%s\n",
            indexArr[in], nameArr[in], typeArr[in], in, lineno[in], elementType[in]);

            //strcpy(nameArr[i], "");
        }
    }*/
    //printf("varNum:%d\n",varNum);
}
static void dump_symbol(int level){
    printf("> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
     for(int i=0; i<varNum; i++) {
        if(scopeArr[i] == level) {
            printf("%-10d%-10s%-10s%-10d%-10d%s\n",
            indexArr[i], nameArr[i], typeArr[i], i, lineno[i], elementType[i]);

            scopeArr[i] = -1;
            strcpy(nameArr[i], "");
        }
    }

    symNum[level] = 0;
}
void calculatePrint(char *VARname, int scope)
{
    printf("IDENT (name=%s, address=%d)\n", VARname, lookup_symbol(VARname, scope));
}
/*



{printf("---------\n HERE \n------\n");}
%type <IDENT> DeclarationStmt AssignmentStmt IncDecStmt Block IfStmt WhileStmt ForStmt PrintStmt 
%type <i_val> Expression UnaryExpr PrimaryExpr
----------------------------------------------------------
DeclarationStmt
    : Type IDENT Literal    { insert_symbol( scope,$2, "int", yylineno, "-"); }
    | Type IDENT STR_init    { insert_symbol( scope, $2, "string", yylineno, "-"); }
    | FLOAT IDENT FLOAT_init    { insert_symbol( scope, $2, "float", yylineno, "-"); }
    | BOOL IDENT BOOL_init       { insert_symbol( scope, $2, "bool", yylineno, "-"); }
;

INT_init
    : '=' INT_LIT SEMICOLON {printf("INT_LIT %d\n", $2);}
    | SEMICOLON
;

FLOAT_init
    : '=' FLOAT_LIT SEMICOLON {printf("FLOAT_LIT %f\n",$2);}
    | SEMICOLON
;

STR_init
    : '=' '"' STRING_LIT '"' SEMICOLON {printf("STRING_LIT %d\n", $3);}
    | SEMICOLON
;

BOOL_init 
    : '=' BOOL_LIT SEMICOLON {printf("FLOAT_LIT %f\n",$2);}
    | SEMICOLON
;
Program
    : StatementList
;

StatementList
    : Statement
    | StatementList Statement
;

Type
    : TypeName { $$ = $1; }
;

TypeName
    : INT 
    | FLOAT
    | STRING
    | BOOL

;

Literal
    : INT_LIT {
        printf("INT_LIT %d\n", $<i_val>$);
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $<f_val>$);
    }
;

Expression
    : UnaryExpr 
    | Expression binary_op Expression
;

UnaryExpr
    : PrimaryExpr 
    | unary_op UnaryExpr
;

PrimaryExpr
    : Operand 
    | IndexExpr 
    | ConversionExpr
;
unary_op
	: '+'
	| '-'
	| '!'
;

binary_op
    : '||' 
    | '&&'
    | cmp_op
    | add_op 
    | mul_op
;

cmp_op
    : '==' 
    | '!=' 
    | '<' 
    | '<='
    | '>' 
    | '>='
;

add_op
    : '+' 
    | '-'
;

mul_op
    : '*' 
    | '/' 
    | '%'
;

Operand 
    : Literal 
    | identifier 
    | '(' Expression ')'
;

IndexExpr
    : PrimaryExpr '[' Expression ']'
;

ConversionExpr
    : Type '(' Expression ')'
;

Statement
    : DeclarationStmt{
        printf("DeclarationStmt");
    }
    | AssignmentStmt{

    }
    | IncDecStmt{

    }
    | Block{
        printf("Block");
    }
    | IfStmt{
        printf("IfStmt");
    }
    | WhileStmt{

    }
    | ForStmt{

    }
    | PrintStmt{
        printf("PrintStmt");
    }
;

DeclarationStmt
    : Type IDENT SEMICOLON
    | Type IDENT '=' Expression SEMICOLON
    | Type IDENT '[' Expression ']' SEMICOLON
;

AssignmentExpr
    : Expression assign_p Expression
;

AssignmentStmt
    : AssignmentExpr SEMICOLON
;

assign_p
    : '='
    | '+='
    | '-='
    | '*='
    | '/='
    | '%='
;

IncDecExpr
    : Expression '++'
    | Expression '--'
;

IncDecStmt
    : IncDecExpr SEMICOLON
;

Block
    : '{' Statement '}'
;

IfStmt 
    :

*/
