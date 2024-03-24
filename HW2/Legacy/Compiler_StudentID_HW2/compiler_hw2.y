/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }


    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(/* ... */);
    static void insert_symbol(/* ... */);
    static void lookup_symbol(/* ... */);
    static void dump_symbol(/* ... */);
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    bool b_val;
    char id_val;
    /* ... */
}

/* Token without return */
%token INT FLOAT BOOL STRING
%token SEMICOLON





/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <id_val> IDENT


/* Nonterminal with return, which need to sepcify type */

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */

/* BE NOTICED
1.
StatementList
    : Statement
    | StatementList Statement
*/
%%

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




Statement
    : DeclarationStmt{
        printf("DeclarationStmt");
    }
;

DeclarationStmt
    : Type IDENT SEMICOLON {;}
    
;





%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

/*


%type <IDENT> DeclarationStmt AssignmentStmt IncDecStmt Block IfStmt WhileStmt ForStmt PrintStmt 
%type <i_val> Expression UnaryExpr PrimaryExpr
----------------------------------------------------------

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