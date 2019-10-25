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
#line 3 "compiler.y" /* yacc.c:339  */


// other includes
#include "heading.h"

// extern to remove compiler error
extern FILE* yyin;
extern int yylex(void);

// extern from lex file
extern int curline;
extern int curpos;

// User Subroutines
int yyerror(char* s);
int yyerror(string s);
void print_funs();
void print_symtabs();
void semantic_error(string s);  // has been disabled ...

// Data Structures
string fname;             // error check if function has same name as file
bool is_main = false;     // error check was main function declared
int loop_deep = 0;        // error check counter for continue out of a loop
bool continue_loop = false;
string continue_lbl_name;

int vectorSize;           // holds the size of vectors being declared
int reductionCt;          // used to generate the label numbers

bool pdec_flag = true;  // if inside of parameter declarations, output $0, $1, etc...
int pnum_cnt = 0;       // count the # of params to a function

map<string,int>::iterator iter; // general iterator for map<string,int>

// string streams
ostringstream rules;   // holds grammar rules printed out by actions
ostringstream decs;    // holds gen()-emitted target-code declarations
ostringstream code;    // holds gen()-emitted target-code all instructions
ostringstream bcode;   // holds gen()-emitted target-code boolean instructions
stack<string> bstack;  // stack for holding code strings of boolean code

// functions
string funs;                  // used to write out a whole function to a string from milvec
vector<string> funslst;       // hold all the compiled function strings
map<string,int> decfunctions; // names of declared functions

// symbol tables
map<string,int> symtab;              // symbol table for current function
vector< map<string,int> > symtablst; // all symbol tables for every function


#line 119 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
    LO = 258,
    FUNCTION = 259,
    BEGINPARAMS = 260,
    ENDPARAMS = 261,
    BEGINLOCALS = 262,
    ENDLOCALS = 263,
    BEGINBODY = 264,
    ENDBODY = 265,
    ARRAY = 266,
    OF = 267,
    IF = 268,
    THEN = 269,
    ENDIF = 270,
    ELSE = 271,
    WHILE = 272,
    BEGINLOOP = 273,
    ENDLOOP = 274,
    DO = 275,
    READ = 276,
    WRITE = 277,
    CONTINUE = 278,
    RETURN = 279,
    INTEGER = 280,
    NUMBER = 281,
    ID = 282,
    TRUE = 283,
    FALSE = 284,
    ASSIGN = 285,
    OR = 286,
    AND = 287,
    NOT = 288,
    NE = 289,
    EQ = 290,
    LE = 291,
    GE = 292,
    HI = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 59 "compiler.y" /* yacc.c:355  */


// TERMINALS
// declarations of union members for lexical values of tokens
int        junk;         // for one-of-a-kind lexical values
int	     int_val;      // values of integer literals, i.e., NUMBER
string*    ident;        // points to identifers' actual lexemes

// NONTERMINALS
// declarations of union members lexical values of non-terminals,
// which are pointers to translation records
string*    code;         // for all nonterminals.


#line 213 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      49,    48,    42,    40,    47,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    45,
      39,     2,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    50,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   146,   146,   149,   162,   170,   182,   185,   193,   203,
     210,   217,   266,   294,   324,   357,   364,   376,   389,   403,
     416,   429,   442,   455,   468,   481,   494,   507,   520,   536,
     557,   578,   587,   596,   605,   614,   623,   632,   641,   650,
     669,   675,   681,   687,   696,   702,   710,   717,   724,   730,
     736,   757,   774,   774,   801,   801,   822,   840
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LO", "FUNCTION", "BEGINPARAMS",
  "ENDPARAMS", "BEGINLOCALS", "ENDLOCALS", "BEGINBODY", "ENDBODY", "ARRAY",
  "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "BEGINLOOP", "ENDLOOP",
  "DO", "READ", "WRITE", "CONTINUE", "RETURN", "INTEGER", "NUMBER", "ID",
  "TRUE", "FALSE", "ASSIGN", "OR", "AND", "NOT", "NE", "EQ", "LE", "GE",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "':'", "','",
  "')'", "'('", "']'", "'['", "HI", "$accept", "Program", "StmtList",
  "ExpList", "beginparams", "endparams", "FunctionDecl", "Decl",
  "DeclList", "BoolExp", "Exp", "ReadStmt", "WriteStmt", "Stmt", "$@1",
  "$@2", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    62,    60,
      43,    45,    42,    47,    37,    59,    58,    44,    41,    40,
      93,    91,   293
};
# endif

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -46,    36,   -46,   -15,   -46,   -17,    28,   -46,   -46,     0,
     -46,    38,    34,    17,    66,    31,   -46,   -46,    14,   -46,
     -46,     5,    62,    64,    42,    59,   116,   -18,   -18,   112,
     105,   -24,   -46,   -24,   -16,    47,    93,    95,    99,   130,
     -46,    48,   -46,   -46,   -18,   -24,   -18,   -10,   133,    82,
     -46,   100,   -24,   179,   179,   -24,   -24,   -46,   113,   137,
     -24,   -46,   -46,   -24,   -24,   -46,   -46,    13,    68,    59,
     -18,   -18,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -46,    59,   -24,   170,   179,   138,   -46,
     106,   179,    73,   179,   143,   -46,   -46,   102,   160,   -46,
     179,   179,   179,   179,   179,   179,    52,    52,   -46,   -46,
     -46,    59,   114,   154,   135,   -24,   -24,   -46,   -46,   -46,
      59,   126,   174,   -46,   -24,   159,   179,   139,   -46,   -18,
     179,   -46,   -46,   158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     3,     0,     0,     9,    15,     0,
      10,     0,     0,     0,     0,     0,    15,    16,     0,    12,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,     0,     0,    48,    49,     0,     0,
      37,    29,    17,    18,     0,     0,     0,     0,     0,     0,
      54,    40,     0,    44,    57,     0,     0,    11,     0,     0,
       0,     4,    13,     6,     0,    20,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,    46,     0,     5,
      42,    45,     0,     7,     0,    19,    38,     0,    22,    21,
      24,    23,    26,    25,    27,    28,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,    39,    30,    51,
       0,     0,     0,    41,     0,     0,     8,     0,    53,     0,
      47,    43,    50,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   -45,   -46,   -46,   -46,   -46,   190,   191,   -28,
     -26,   -46,   -46,   -34,   -46,   -46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    35,    92,     8,    12,     4,    13,     9,    47,
      48,    36,    37,    38,   111,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    58,    40,    41,    69,    53,    10,    54,    40,    41,
      42,    43,     5,    23,    55,    44,    65,    45,    67,    66,
      68,    70,    71,    45,    97,    52,    86,    11,     6,    87,
      88,    46,    11,     7,    91,    56,     2,    93,    94,   112,
       3,    16,    98,    99,    70,    71,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    57,    11,   113,
      27,    95,    17,    58,    28,    22,   121,    29,    30,    31,
      32,    33,    27,    25,    34,   127,    28,    18,    58,    29,
      30,    31,    32,    33,    14,    15,    34,    58,    24,   125,
     126,    19,    26,    58,    80,    81,    82,    63,   130,    64,
      83,   133,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    70,    71,    27,    96,   119,   120,    28,
     116,   117,    29,    30,    31,    32,    33,    27,    39,    34,
      50,    28,    51,   122,    29,    30,    31,    32,    33,    27,
      59,    34,    60,    28,    61,   128,    29,    30,    31,    32,
      33,    85,    27,    34,   132,    62,    28,   115,    89,    29,
      30,    31,    32,    33,    90,   124,    34,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    78,    79,
      80,    81,    82,    78,    79,    80,    81,    82,   114,    70,
      71,   129,    71,   118,    78,    79,    80,    81,    82,    78,
      79,    80,    81,    82,   123,    20,     0,    21,     0,   131,
      78,    79,    80,    81,    82,     0,     0,     0,    96,    78,
      79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      28,    35,    26,    27,    14,    31,     6,    33,    26,    27,
      28,    29,    27,     8,    30,    33,    44,    41,    46,    45,
      46,    31,    32,    41,    69,    49,    52,    27,    45,    55,
      56,    49,    27,     5,    60,    51,     0,    63,    64,    84,
       4,     7,    70,    71,    31,    32,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    10,    27,    85,
      13,    48,    45,    97,    17,    51,   111,    20,    21,    22,
      23,    24,    13,     9,    27,   120,    17,    11,   112,    20,
      21,    22,    23,    24,    46,    47,    27,   121,    26,   115,
     116,    25,    50,   127,    42,    43,    44,    49,   124,    51,
      18,   129,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    31,    32,    13,    48,    15,    16,    17,
      47,    48,    20,    21,    22,    23,    24,    13,    12,    27,
      18,    17,    27,    19,    20,    21,    22,    23,    24,    13,
      47,    27,    47,    17,    45,    19,    20,    21,    22,    23,
      24,    51,    13,    27,    15,    25,    17,    51,    45,    20,
      21,    22,    23,    24,    27,    30,    27,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    40,    41,
      42,    43,    44,    40,    41,    42,    43,    44,    50,    31,
      32,    17,    32,    50,    40,    41,    42,    43,    44,    40,
      41,    42,    43,    44,    50,    15,    -1,    16,    -1,    50,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    40,
      41,    42,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,     4,    59,    27,    45,     5,    57,    61,
       6,    27,    58,    60,    46,    47,     7,    45,    11,    25,
      60,    61,    51,     8,    26,     9,    50,    13,    17,    20,
      21,    22,    23,    24,    27,    55,    64,    65,    66,    12,
      26,    27,    28,    29,    33,    41,    49,    62,    63,    62,
      18,    27,    49,    63,    63,    30,    51,    10,    66,    47,
      47,    45,    25,    49,    51,    62,    63,    62,    63,    14,
      31,    32,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    18,    68,    51,    63,    63,    63,    45,
      27,    63,    56,    63,    63,    48,    48,    55,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    67,    55,    63,    50,    51,    47,    48,    50,    15,
      16,    55,    19,    50,    30,    63,    63,    55,    19,    17,
      63,    50,    15,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      58,    59,    60,    60,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    66,    68,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     3,     0,     1,     3,     1,
       1,    12,     3,     8,     3,     0,     3,     1,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       4,     3,     3,     3,     3,     3,     2,     1,     3,     4,
       2,     5,     3,     6,     2,     3,     3,     6,     1,     1,
       7,     5,     0,     6,     0,     7,     1,     2
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
        case 2:
#line 146 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Program -> /* EMPTY */ \n";
        }
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 150 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Program -> ProgramFunctionDecl \n";

            if(is_main == false)
            {
                string s = "No main function declared";
                /* semantic_error(s); */
            }
        }
#line 1428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 163 "compiler.y" /* yacc.c:1646  */
    {
            rules << "StmtList -> Stmt \n";

            (yyval.code) = new string(*(yyvsp[-1].code));
            code.str("");
            code.clear();
        }
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 171 "compiler.y" /* yacc.c:1646  */
    {
            rules << "StmtList -> StmtList Stmt ';' \n";

            (yyval.code) = new string(*(yyvsp[-2].code) + *(yyvsp[-1].code));
            code.str("");
            code.clear();
        }
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 182 "compiler.y" /* yacc.c:1646  */
    {
            rules << "ExpList -> /* EMPTY */ \n";
        }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 186 "compiler.y" /* yacc.c:1646  */
    {
            rules << "ExpList -> Exp \n";

            (yyval.code) = new string(*(yyvsp[0].ident));
            code << "param " << *(yyval.code) << "\n";

        }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 194 "compiler.y" /* yacc.c:1646  */
    {
            rules << "ExpList -> Explist ',' Exp \n";

            (yyval.code) = new string(*(yyvsp[0].ident));
            code << "param " << *(yyval.code) << "\n";
        }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 204 "compiler.y" /* yacc.c:1646  */
    {
            pdec_flag = true;
        }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 211 "compiler.y" /* yacc.c:1646  */
    {
            pdec_flag = false; // set flag to done with params
        }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 221 "compiler.y" /* yacc.c:1646  */
    {
            rules << "FunctionDecl -> FUNCTION ID ';' \n";
            rules << "   BEGINPARAMS DeclList  ENDPARAMS \n"; // scalars
            rules << "   BEGINLOCALS DeclList  ENDLOCALS \n";
            rules << "   BEGINBODY   StmtList  ENDBODY \n";

            if(*(yyvsp[-10].ident) == "main")
            {
                is_main = true;
            }

            decfunctions[*(yyvsp[-10].ident)] = 0;

            stringstream func_dec;
            func_dec << "func " << *(yyvsp[-10].ident) << "\n";
            func_dec << *(yyvsp[-7].code);
            func_dec << *(yyvsp[-4].code);
            func_dec << *(yyvsp[-1].code);
            func_dec << "endfunc" << "\n";

            funs = func_dec.str();
            func_dec.str("");

            // save function
            funslst.push_back(funs);

            // save symtab
            symtablst.push_back(symtab);

            // reset variables
            code.str("");
            code.clear();
            decs.str("");
            decs.clear();
            bcode.str("");
            bcode.clear();
            symtab.clear();
            funs = "";
            continue_loop = false;
            pdec_flag = true;
            pnum_cnt = 0;
        }
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 267 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Decl -> ID ':' INTEGER \n";

            iter = symtab.find(*(yyvsp[-2].ident));
            if(iter != symtab.end())
            {
                string s = "Identifier " + *(yyvsp[-2].ident) + " multiple declares";
                /* semantic_error(s); */
            }
            else if(iter->first == fname)
            {
                string s = "Identifier " + *(yyvsp[-2].ident) + " same name as file";
                /* semantic_error(s); */
            }

            symtab[*(yyvsp[-2].ident)] = 0; // add to symbol table

            decs << ". " << *((yyvsp[-2].ident)) << "\n";
            if(pdec_flag == true)
            {
                decs << "= " << *(yyvsp[-2].ident) << ", $" << pnum_cnt << "\n";
                pnum_cnt++;
            }
            (yyval.code) = new string(decs.str());
            decs.str("");
            decs.clear();
        }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 295 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Decl -> ID ':' ARRAY '[' NUMBER ']' OF INTEGER \n";

            iter = symtab.find(*(yyvsp[-7].ident));
            if(iter != symtab.end())
            {
                string s = "Identifier " + *(yyvsp[-7].ident) + " multiple declares";
                /* semantic_error(s); */
            }
            else if(iter->first == fname)
            {
                string s = "Identifier " + *(yyvsp[-7].ident) + " same name as file";
                /* semantic_error(s); */
            }

            if((yyvsp[-3].int_val) <= 0)
            {
                string s = "Zero/Negative array size";
                /* semantic_error(s); */
            }

            symtab[*(yyvsp[-7].ident)] = (yyvsp[-3].int_val); // add to symbol table

            vectorSize = (yyvsp[-3].int_val);
            decs  << ".[] " << *((yyvsp[-7].ident)) << ", " << vectorSize << "\n";
            (yyval.code) = new string(decs.str());
            decs.str("");
            decs.clear();
        }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 325 "compiler.y" /* yacc.c:1646  */
    {
            rules << "VectorDec. ->  ID ',' VectorDecl \n";

            iter = symtab.find(*(yyvsp[-2].ident));
            if(iter != symtab.end())
            {
                string s = "Identifier " + *(yyvsp[-2].ident) + " multiple declares";
                /* semantic_error(s); */
            }
            else if(iter->first == fname)
            {
                string s = "Identifier " + *(yyvsp[-2].ident) + " same name as file";
                /* semantic_error(s); */
            }

            symtab[*(yyvsp[-2].ident)] = 0; // add to symbol table

            decs << ". " << *(yyvsp[-2].ident) << "\n";
            if(pdec_flag == true)
            {
                decs << "= " << *(yyvsp[-2].ident) << ", $" << pnum_cnt << "\n";
                pnum_cnt++;
            }
            decs << *(yyvsp[0].code);
            (yyval.code) = new string(decs.str());
            decs.str("");
            decs.clear();
        }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 357 "compiler.y" /* yacc.c:1646  */
    {
            rules << "DeclList -> EMPTY\n";

            (yyval.code) = new string(decs.str());
            decs.str("");
            decs.clear();
        }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 365 "compiler.y" /* yacc.c:1646  */
    {
            rules << "DeclList -> DeclList Decl ';' \n";

            decs << *(yyvsp[-2].code) << *(yyvsp[-1].code);
            (yyval.code) = new string(decs.str());
            decs.str("");
            decs.clear();
        }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 377 "compiler.y" /* yacc.c:1646  */
    {
            rules << " TRUE \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "= " << *(yyval.code) << ", " << 1 << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 390 "compiler.y" /* yacc.c:1646  */
    {
            rules << " FALSE \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "= " << *(yyval.code) << ", " << 0 << "\n";

            bstack.push(bcode.str());
            code.str("");

        }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 404 "compiler.y" /* yacc.c:1646  */
    {
            rules << " '(' BoolExp ')' \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "= " << *(yyval.code) << ", " << *(yyvsp[-1].code) << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 417 "compiler.y" /* yacc.c:1646  */
    {
            rules << " NOT BoolExp \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "! " << *(yyval.code) << ", " << *(yyvsp[0].code) << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 430 "compiler.y" /* yacc.c:1646  */
    {
            rules << " BoolExp AND BoolExp \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "&& " << *(yyval.code) << ", " << *(yyvsp[-2].code) << ", " << *(yyvsp[0].code) << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 443 "compiler.y" /* yacc.c:1646  */
    {
            rules << " BoolExp OR BoolExp \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "|| " << *(yyval.code) << ", " << *(yyvsp[-2].code) << ", " << *(yyvsp[0].code) << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 456 "compiler.y" /* yacc.c:1646  */
    {
            rules << " Exp EQ Exp \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "== " << *(yyval.code) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 469 "compiler.y" /* yacc.c:1646  */
    {
            rules << " Exp NE Exp \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "!= " << *(yyval.code) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 482 "compiler.y" /* yacc.c:1646  */
    {
            rules << " Exp GE Exp \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << ">= " << *(yyval.code) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 495 "compiler.y" /* yacc.c:1646  */
    {
            rules << " Exp LE Exp \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "<= " << *(yyval.code) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 508 "compiler.y" /* yacc.c:1646  */
    {
            rules << " Exp '>' Exp \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "> " << *(yyval.code) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 521 "compiler.y" /* yacc.c:1646  */
    {
            rules << " Exp '<' Exp \n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));

            bcode << code.str();
            bcode << ". " << *(yyval.code) << "\n";                        // declare temp
            bcode << "< " << *(yyval.code) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";

            bstack.push(bcode.str());
            code.str("");
        }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 537 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> ID\n";

            iter = symtab.find(*(yyvsp[0].ident));
            if(iter == symtab.end())
            {
                string s = "Identifier " + *(yyvsp[0].ident) + " used, but not declared";
                /* semantic_error(s); */
            }
            else if(iter->second > 0)
            {
                string s = "Using an array " + *(yyvsp[0].ident) + " as an integer";
                /* semantic_error(s); */
            }

            (yyval.ident) = new string("_T" + to_string(reductionCt++));

            code << ". " << *(yyval.ident) << "\n";                        // declare temp
            code << "= " << *(yyval.ident) << ", " << *(yyvsp[0].ident) << "\n";
        }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 558 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> ID '[' Exp ']' \n";

            iter = symtab.find(*(yyvsp[-3].ident));
            if(iter == symtab.end())
            {
                string s = "Identifier " + *(yyvsp[-3].ident) + " used, but not declared";
                /* semantic_error(s); */
            }
            else if(iter->second > 0)
            {
                string s = "Using an integer " + *(yyvsp[-3].ident) + " as an array";
                /* semantic_error(s); */
            }

            (yyval.ident) = new string("_T" + to_string(reductionCt++));

            code << ". " << *(yyval.ident) << "\n";                        // declare temp
            code << "=[] " << *(yyval.ident) << ", " << *(yyvsp[-3].ident) << ", " << *(yyvsp[-1].ident) << "\n";
        }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 579 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> Exp '+' Exp\n";

            (yyval.ident) = new string("_T" + to_string(reductionCt++));

            code << ". " << *(yyval.ident) << "\n";                        // declare temp
            code << "+ " << *(yyval.ident) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";
        }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 588 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> Exp '-' Exp\n";

            (yyval.ident) = new string("_T" + to_string(reductionCt++));

            code << ". " << *(yyval.ident) << "\n";                        // declare temp
            code << "- " << *(yyval.ident) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";
        }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 597 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> Exp '*' Exp\n";

            (yyval.ident) = new string("_T" + to_string(reductionCt++));

            code << ". " << *(yyval.ident) << "\n";                        // declare temp
            code << "* " << *(yyval.ident) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";
        }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 606 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> Exp '/' Exp\n";

            (yyval.ident) = new string("_T" + to_string(reductionCt++));

            code << ". " << *(yyval.ident) << "\n";                        // declare temp
            code << "/ " << *(yyval.ident) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";
        }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 615 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> Exp '%' Exp\n";

            (yyval.ident) = new string("_T" + to_string(reductionCt++));

            code << ". " << *(yyval.ident) << "\n";                        // declare temp
            code << "% " << *(yyval.ident) << ", " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";
    }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 624 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> '-' Exp\n";

            (yyval.ident) = new string("_T" + to_string(reductionCt++));

            code << ". " << *(yyval.ident) << "\n";                        // declare temp
            code << "- " << *(yyval.ident) << ", " << 0 << ", " << *(yyvsp[0].ident) << "\n";
        }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 633 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> NUMBER\n";

            (yyval.ident) = new string("_T" + to_string(reductionCt++));

            code << ". " << *(yyval.ident) << "\n";                        // declare temp
            code << "= " << *(yyval.ident) << ", " << (yyvsp[0].int_val) << "\n";
        }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 642 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> '(' Exp ')' \n";

            (yyval.ident) = new string("_T" + to_string(reductionCt++));

            code << ". " << *(yyval.ident) << "\n";                        // declare temp
            code << "= " << *(yyval.ident) << ", " << *(yyvsp[-1].ident) << "\n";
        }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 651 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Exp -> ID '(' Exp ')' \n";

            iter = decfunctions.find(*(yyvsp[-3].ident));
            if(iter == decfunctions.end())
            {
                string s = "Using undeclared function " + *(yyvsp[-3].ident);
                /* semantic_error(s); */
            }

            (yyval.ident) = new string("_T" + to_string(reductionCt++));   // dest

            code << ". " << *(yyval.ident) << "\n";                        // declare temp dest
            code << "call " << *(yyvsp[-3].ident) << ", " << *(yyval.ident) << "\n";      // call func with dest
        }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 670 "compiler.y" /* yacc.c:1646  */
    {
            rules << "ReadStmt -> Read ID \n";

            code  << ".< " << *(yyvsp[0].ident) << "\n";
        }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 676 "compiler.y" /* yacc.c:1646  */
    {
            rules << "ReadStmt -> READ ID '[' Exp ']' \n";

            code  << ".[]< " << *(yyvsp[-3].ident) << ", " << *(yyvsp[-1].ident) << "\n";
        }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 682 "compiler.y" /* yacc.c:1646  */
    {
            rules << "ReadStmt -> ReadStmt ',' ID \n";

            code  << ".< " << *(yyvsp[0].ident) << "\n";
        }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 688 "compiler.y" /* yacc.c:1646  */
    {
            rules << "ReadStmt -> ReadStmt ',' ID '[' Exp ']'\n";

            code  << ".[]< " << *(yyvsp[-3].ident) << ", " << (yyvsp[-1].ident) << "\n";
        }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 697 "compiler.y" /* yacc.c:1646  */
    {
            rules << "WriteStmt -> WRITE Exp \n";

            code << ".> " << *(yyvsp[0].ident) << "\n";
        }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 703 "compiler.y" /* yacc.c:1646  */
    {
            rules << "WriteStmt -> WriteStmt ',' Exp \n";

            code << ".> " << *(yyvsp[0].ident) << "\n";
        }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 711 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Stmt -> ID ASSIGN Exp\n";

            code << "= " << *(yyvsp[-2].ident) << ", " << *(yyvsp[0].ident) << "\n";
            (yyval.code) = new string(code.str());
        }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 718 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Stmt -> ID '[' Exp ']' ASSIGN Exp\n";

            code << "[]= " << *(yyvsp[-5].ident) << ", " << *(yyvsp[-3].ident) << ", " << *(yyvsp[0].ident) << "\n";
            (yyval.code) = new string(code.str());
        }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 725 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Stmt -> ReadStmt" ;

            (yyval.code) = new string(code.str());
        }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 731 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Stmt -> WriteStmt" ;

            (yyval.code) = new string(code.str());
        }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 737 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Stmt -> IF BoolExp THEN StmtList ELSE StmtList ENDIF\n";

            string* then_lbl = new string("_L" + to_string(reductionCt++));
            string* else_lbl = new string("_L" + to_string(reductionCt++));
            string* endif_lbl = new string("_L" + to_string(reductionCt++));

            string bool_string = bstack.top(); bstack.pop();

            code << bool_string;
            code << "?:= " << *then_lbl << ", " << *(yyvsp[-5].code) << "\n";    // if BoolExp goto THEN
            code << ":= " << *else_lbl << "\n";                    // goto ELSE
            code << ": " << *then_lbl << "\n";                     // THEN:
            code << *(yyvsp[-3].code);                                           // StmtList
            code << ":= " << *endif_lbl << "\n";                   // goto ENDIF
            code << ": " << *else_lbl << "\n";                     // ELSE:
            code << *(yyvsp[-1].code);                                           // StmtList
            code << ": " << *endif_lbl << "\n";                    // ENDIF:
            (yyval.code) = new string(code.str());
        }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 758 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Stmt -> IF BoolExp THEN StmtList ENDIF\n";

            string* then_lbl = new string("_L" + to_string(reductionCt++));
            string* else_lbl = new string("_L" + to_string(reductionCt++));

            string bool_string = bstack.top(); bstack.pop();

            code << bool_string;
            code << "?:= " << *then_lbl << ", " << *(yyvsp[-3].code) << "\n";   // if BoolExp goto THEN
            code << ":= " << *else_lbl << "\n";                   // goto ELSE
            code << ": " << *then_lbl << "\n";                    // THEN:
            code << *(yyvsp[-1].code);                                          // StmtList
            code << ": " << *else_lbl << "\n";                    // ELSE:
            (yyval.code) = new string(code.str());
        }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 774 "compiler.y" /* yacc.c:1646  */
    {++loop_deep;}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 775 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Stmt -> WHILE BoolExp BEGINLOOP StmtList ENDLOOP\n";

            loop_deep--;

            string* while_lbl = new string("_L" + to_string(reductionCt++));
            string* begin_lbl = new string("_L" + to_string(reductionCt++));
            string* exit_lbl = new string("_L" + to_string(reductionCt++));

            string bool_string = bstack.top(); bstack.pop();

            if(continue_loop == true)
            {
                code << ": " << continue_lbl_name << "\n";
                continue_loop = false;
            }
            code << ": " << *while_lbl << "\n";                   // WHILE:
            code << bool_string;
            code << "?:= " << *begin_lbl << ", " << *(yyvsp[-4].code) << "\n"; // if boolExp goto BEGINLOOP
            code << ":= " << *exit_lbl << "\n";                  // otherwise, goto EXIT
            code << ": " << *begin_lbl <<  "\n";                 // BEGINLOOP:
            code << *(yyvsp[-1].code);                                         // StmtList
            code << ":= " << *while_lbl <<  "\n";                // goto WHILE
            code << ": " << *exit_lbl << "\n";                   // EXIT:
            (yyval.code) = new string(code.str());
        }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 801 "compiler.y" /* yacc.c:1646  */
    {++loop_deep;}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 802 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Stmt -> DO BEGINLOOP StmtList ENDLOOP WHILE BoolExp\n";

            --loop_deep;

            string* begin_lbl = new string("_L" + to_string(reductionCt++));

            string bool_string = bstack.top(); bstack.pop();

            code  << ": " << *begin_lbl << "\n" ;         // BEGINLOOP:
            code << *(yyvsp[-3].code);                                  // StmtList
            if(continue_loop == true)
            {
                code << ": " << continue_lbl_name << "\n";
                continue_loop = false;
            }
            code << bool_string;
            code << "?:= " << *begin_lbl << ", " << *(yyvsp[0].code) << "\n"; // if BoolExp goto BEGINLOOP
            (yyval.code) = new string(code.str());
        }
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 823 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Stmt -> CONTINUE\n";

            if(loop_deep == 0)
            {
                string s = "Continue not in a loop";
                /* semantic_error(s); */
            }

            string* cont_lbl = new string("_L" + to_string(reductionCt++));

            continue_loop = true;
            continue_lbl_name = *cont_lbl;

            code  << ":= " << *cont_lbl << "\n";
            (yyval.code) = new string(code.str());
        }
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 841 "compiler.y" /* yacc.c:1646  */
    {
            rules << "Stmt -> RETURN Exp\n";

            (yyval.code) = new string("_T" + to_string(reductionCt++));
            code << ". " << *(yyval.code) << "\n";                        // declare temp
            code << "= " << *(yyval.code) << ", " << *(yyvsp[0].ident) << "\n";
            code << "ret " << *(yyval.code) << "\n";
            (yyval.code) = new string(code.str());
        }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2305 "y.tab.c" /* yacc.c:1646  */
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
#line 852 "compiler.y" /* yacc.c:1906  */



int main(int argc, char** argv)
{
    // try to read from a input file
    if(argc >= 2)
    {
        yyin = fopen(argv[1], "r");
        if(yyin == NULL)
        {
           yyin = stdin;
        }
    }
    else // error if no input file
    {
        // yyin = stdin;
        cout << "Error: needs input file" << endl;
        exit(1);
    }

    fname = string(argv[1]);
    fname.pop_back(); fname.pop_back(); fname.pop_back(); fname.pop_back(); // remove ".min"

    yyparse(); // calls yylex()

    print_funs();
    //print_symtabs();
}

// print out mil code for functions
void print_funs()
{
    for(auto i : funslst)
    {
        output(i);
    }
}

// print out symbol tables
void print_symtabs()
{
    for(auto i : symtablst)
    {
        for( auto j : i )
        {
            string t = j.first;
            t+=" ";
            t+=to_string(j.second);
            t+=" ";
            output(t);
        }
        output("");
    }
}

void semantic_error(string s)
{
    string err = "Semantic error: ";
    err += s;
    output(err);
}

// Here is the function that reports lexical and parse errors.
// It is overloaded for char* && string
int yyerror( char* s ) { return yyerror(string(s)); }

int yyerror( string s )
{
  extern int  yylineno;    // defined and maintained in lex.c
  extern char* yytext;     // defined and maintained in lex.c
  cerr << "ERROR: " << s << " at symbol " << yytext;
  cerr << " on line " << curline << " position " << curpos << endl;
  exit( 1 );
}
