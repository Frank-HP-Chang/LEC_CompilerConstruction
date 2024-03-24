/*	Definition section */
%{
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
    bool literal_flag=0;
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
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *id_val;
    char *s_val;
    
    /* ... */
}

/* Token without return */
%token BOOL STRING INT FLOAT ENDL
%token SEMICOLON
%token INC DEC GEQ LEQ EQL NEQ ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN
%token QUO_ASSIGN REM_ASSIGN LAND LOR NEWLINE PRINT PRINTLN 
%token IF ELSE FOR WHILE
%token TRUE FALSE

/*%token DeclarationStmt AssignmentStmt IncDecStmt Block IfStmt WhileStmt ForStmt PrintStmt */

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
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
    : Statement StatementList 
    | Statement 
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
    : LAND 
    | LOR
    | cmp_op
    | add_op 
    | mul_op
;

cmp_op
    : EQL   {cmp_op_STR="EQL";}
    | NEQ   {cmp_op_STR="NEQ";}
    | '<'   {cmp_op_STR="LTR";}
    | LEQ   {cmp_op_STR="LEQ";}
    | '>'   {cmp_op_STR="GTR";}
    | GEQ   {cmp_op_STR="GEQ";}
;

add_op
    : '+'   {add_op_STR="ADD";} 
    | '-'   {add_op_STR="SUB";s_flag=1;} 
;

mul_op
    : '*'   {add_op_STR="MUL";
        if(s_flag)
        {
            printf("SUB\n");
        }
        s_flag=0;
    }
    | '/'   {add_op_STR="QUO";
        if(s_flag)
        {
            printf("SUB\n");
        }
        s_flag=0;
    }
    | '%'   {add_op_STR="REM";
        if(s_flag)
        {
            printf("SUB\n");
        }
        s_flag=0;
    }
;

Operand 
    : Literal {literal_flag=1;}
    | IDENT {calculatePrint($1,scope);type_ADDRESS=lookup_symbol($1,scope);/*printf("-----------\nSCOPE:%d\n--------------\n",scope)*/;}
    | '(' Expression ')'
;

IndexExpr
    : PrimaryExpr '[' Expression ']' 
;

ConversionExpr
    : '(' INT ')' Operand {printf("F to I\n");printf(add_op_STR);printf("\n");} 
    | '(' FLOAT ')' Operand {printf("I to F\n");} 
;

Statement
    :ForStmt 
    |DeclarationStmt
    | AssignmentStmt  
    | CalculateStmt
    | IncDecStmt
    | PrintStmt
    | WhileStmt
    | IfStmt
    | Block
;
Type
    :INT
    |FLOAT
    |STRING
;
DeclarationStmt
    : INT IDENT '=' Expression SEMICOLON  { 
        insert_symbol( scope,$2, "int", yylineno, "-");
    }
    | INT IDENT SEMICOLON { 
        insert_symbol( scope,$2, "int", yylineno, "-"); 
    }
    | INT IDENT '[' Expression ']' SEMICOLON {
        array_flag=1;
         insert_symbol( scope,$2, "array", yylineno, "int"); 
         
         //calculatePrint($2,scope);
    }
    | FLOAT IDENT '=' Expression SEMICOLON  { 
        insert_symbol( scope,$2, "float", yylineno, "-");
    }
    | FLOAT IDENT SEMICOLON { 
        insert_symbol( scope,$2, "float", yylineno, "-"); 
    }
    | FLOAT IDENT '[' Expression ']' SEMICOLON {
        array_flag=1;
         insert_symbol( scope,$2, "array", yylineno, "float"); 
         
    }
    | STRING IDENT '=' '"' Expression '"' SEMICOLON  { 
        insert_symbol( scope,$2, "string", yylineno, "-");
    }
    | STRING IDENT SEMICOLON { 
        insert_symbol( scope,$2, "string", yylineno, "-"); 
    }
    | STRING IDENT '[' Expression ']' SEMICOLON {
         insert_symbol( scope,$2, "array", yylineno, "-"); 
         calculatePrint($2,scope);
    }
    | BOOL IDENT '=' TRUE SEMICOLON  { 
        printf("TRUE\n");
        insert_symbol( scope,$2, "bool", yylineno, "-");
        
    }
    | BOOL IDENT '=' FALSE SEMICOLON  { 
        printf("FALSE\n");
        insert_symbol( scope,$2, "bool", yylineno, "-");
        
    }

;

CalculateStmt
    :IDENT '+' IDENT SEMICOLON {
        calculatePrint($1,scope);
        calculatePrint($3,scope);
        printf("ADD\n");
    }
    |IDENT '-' IDENT SEMICOLON {
        calculatePrint($1,scope);
        calculatePrint($3,scope);
        printf("SUB\n");
    }
    |IDENT '*' IDENT SEMICOLON {
        calculatePrint($1,scope);
        calculatePrint($3,scope);
        printf("MUL\n");
    }
    |IDENT '/' IDENT SEMICOLON {
        calculatePrint($1,scope);
        calculatePrint($3,scope);
        printf("QUO\n");
    }
    |IDENT '%' IDENT SEMICOLON {
        calculatePrint($1,scope);
        calculatePrint($3,scope);
        printf("REM\n");
    }
;
AssignmentExpr
    : Expression assign_p Expression {
        if(array_flag)
        {
            printf(add_op_STR);printf("\n");
        }
    }
    | Expression assign_p '"' Expression '"' 
    | Expression assign_p TRUE {printf("TRUE\n");}
    | Expression assign_p FALSE {printf("FALSE\n");}
;

AssignmentStmt
    : AssignmentExpr SEMICOLON {printf(assign_p_STR);printf("\n");}
;
assign_p
    : '=' {assign_p_STR="ASSIGN";}
    | ADD_ASSIGN    {assign_p_STR="ADD_ASSIGN";}
    | SUB_ASSIGN    {assign_p_STR="SUB_ASSIGN";}
    | MUL_ASSIGN    {assign_p_STR="MUL_ASSIGN";}
    | QUO_ASSIGN    {assign_p_STR="QUO_ASSIGN";}
    | REM_ASSIGN    {assign_p_STR="REM_ASSIGN";}
;

IncDecStmt
    : IncDecExpr SEMICOLON
;

IncDecExpr
    : IDENT INC{
        calculatePrint($1,scope);
        printf("INC\n");
    }
    | IDENT DEC{
        calculatePrint($1,scope);
        printf("DEC\n");
    }
;

IfStmt
    : IF '(' Condition ')' Block 
    | IF '(' Condition ')' Block ELSE IfStmt
    | IF '(' Condition ')' Block ELSE Block
;

WhileStmt
    : WHILE '(' Condition ')' {scope++;} Block 

Condition
    :Expression {printf(cmp_op_STR);printf("\n");}
;

Block
    :  '{'  StatementList  '}' {dump_symbol(scope);} {scope--;}
;

ForStmt
    : FOR
    | FOR '(' ForClause ')' Block
;

ForClause
    : InitStmt SEMICOLON Condition SEMICOLON Poststmt
;

InitStmt
    : SimpleExpr
;

Poststmt
    : SimpleExpr
;

SimpleExpr
    : AssignmentExpr
    | Expression
    | IncDecExpr
;

Literal
    : INT_LIT {
        printf("INT_LIT %d\n", $<i_val>$);
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $1);
    }
    | STRING_LIT {
        printf("STRING_LIT %s\n",$<s_val>$);
    }

;

PrintStmt
    : PRINT INT_LIT  {printf("INT");}
    | PRINT '(' Expression ')' SEMICOLON {
        if(array_flag)
        {
            printf("PRINT %s",elementType[type_ADDRESS]);printf("\n");
        }
        else if(literal_flag)
        {
            printf("PRINT int");printf("\n");
            literal_flag=0;
        }
        else
        {
            printf("PRINT %s",typeArr[type_ADDRESS]);printf("\n");
        }
        
    }
    | PRINT '(' '"' Expression '"' ')' SEMICOLON {printf("PRINT string\n");}
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
            scopeArr[i] = 0;
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
    int returnValue=-1;
    for(int i=1; i<=varNum; i++) {
        printf("------------------\n");
        printf("level:%d scopeArr: %d\n",level,scopeArr[i-1]);
        printf("id: %s nameArr:%s\n",id,nameArr[i-1]);
        //printf("------------------\n");
        //printf("IN THE LOOKUP LOOP\n");
        if( strcmp(id,nameArr[i-1])==0 && (level == scopeArr[i-1]) ) {
            returnValue=(i-1);
        }
    }
    //printf("LOOKUPLV %s %d",id,level);
    return returnValue;
}


static void insert_symbol(int level, char *ident, char *type,int line_num, char *element)
{


    printf("> Insert {%s} into symbol table (scope level: %d)\n", ident, level);    
    //int i = varNum;
    indexArr[varNum] = symNum[level];
    nameArr[varNum] = ident;
    typeArr[varNum] = type;
    lineno[varNum] = line_num;
    elementType[varNum] = element;
    scopeArr[varNum] = level;

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
     for(int i=1; i<=varNum; i++) {
        if(scopeArr[i-1] == level) {
            printf("%-10d%-10s%-10s%-10d%-10d%s\n",
            indexArr[i-1], nameArr[i-1], typeArr[i-1], i-1, lineno[i-1], elementType[i-1]);

            scopeArr[i-1] = -1;
            strcpy(nameArr[i-1], "");
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