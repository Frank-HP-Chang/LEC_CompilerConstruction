/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    #define codegen(...) \
        do { \
            for (int i = 0; i < INDENT; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

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

    //hw3
    int series_num=30;
    char *char_i_binary_op;
    int var_num=0;
    char *var_series[30];
    float var_type[30];
    int var_type_status=-1; // overall variable status
    char *binary_op_status; // bin_op e.g add sub
    int normal_print=1;
    char *conver_status;
    int conver_flag=0;
    
    int load_store=0;
    char *get_assign_IDENT;

    int get_IDENT_idx;


    /* Other global variables */
    FILE *fout = NULL;
    bool HAS_ERROR = false;
    int INDENT = 0;
    
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed.*/
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

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <id_val> IDENT

/* Nonterminal with return, which need to sepcify type */

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
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
    | Expression binary_op Expression {
        if(conver_flag==0)
        {
            binary_op_judge(var_type_status,binary_op_status);
        }
        
    }
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
    : '+'   
    {
        binary_op_status="add";
        add_op_STR="ADD";} 
    | '-'   
    {   binary_op_status="sub";
        add_op_STR="SUB";s_flag=1;} 
;

mul_op
    : '*'   {add_op_STR="MUL";
        binary_op_status="mul";
        if(s_flag)
        {
            printf("SUB\n");
        }
        s_flag=0;
    }
    | '/'   {add_op_STR="QUO";
        binary_op_status="div";
        if(s_flag)
        {
            printf("SUB\n");
        }
        s_flag=0;
    }
    | '%'   {add_op_STR="REM";
        binary_op_status="rem";
        if(s_flag)
        {
            printf("SUB\n");
        }
        s_flag=0;
    }
;

Operand 
    : Literal {literal_flag=1;}
    | IDENT {
        get_IDENT_idx=searchInt($1);
        
        //if(load_store==1)
        //{
        //    get_assign_IDENT=$1;
        //    load_store=0;
        //}
        //else if(load_store==2)
        //{
        //    if(var_type[get_IDENT_idx]==1)
        //    {
        //        var_type_status=1;
        //        codegen("iload %d\n",get_IDENT_idx);
        //    }
        //    if(var_type[get_IDENT_idx]==2)
        //    {
        //        var_type_status=2;
        //        codegen("fload %d\n",get_IDENT_idx);
        //    }
        //    calculatePrint($1,scope);type_ADDRESS=lookup_symbol($1,scope);/*printf("-----------\nSCOPE:%d\n--------------\n",scope)*/;
//
        //}
    }
    | '(' Expression ')'
;

IndexExpr
    : PrimaryExpr '[' Expression ']' 
;

ConversionExpr
    : '(' INT ')' Operand 
    {
        conver_status="f2i";   
        conver_flag=1;
        printf("F to I\n");printf(add_op_STR);printf("\n");} 
    | '(' FLOAT ')' Operand 
    {
        conver_status="i2f";
        conver_flag=2;
        printf("I to F\n");} 
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
    : INT IDENT
    {   codegen("ldc");
        var_series[var_num]=$2;
        var_type[var_num]=1;
    } '=' Expression SEMICOLON  { 
        insert_symbol( scope,$2, "int", yylineno, "-");
    }
    | INT IDENT SEMICOLON { 
        codegen("ldc 0\n");
        codegen("istore");
        codegen("%d\n",var_num);
        var_series[var_num]=$2;
        var_type[var_num]=1;
        var_num++;
        insert_symbol( scope,$2, "int", yylineno, "-"); 
    }
    | INT IDENT '[' Expression ']' SEMICOLON {
        array_flag=1;
         insert_symbol( scope,$2, "array", yylineno, "int"); 
         
         //calculatePrint($2,scope);
    }
    | FLOAT IDENT
    {   codegen("ldc");
        var_series[var_num]=$2;
        var_type[var_num]=2;

    } '=' Expression SEMICOLON  { 
        insert_symbol( scope,$2, "float", yylineno, "-");
    }
    | FLOAT IDENT SEMICOLON { 
        codegen("ldc 0.0\n");
        codegen("fstore");
        codegen("%d\n",var_num);
        var_series[var_num]=$2;
        var_type[var_num]=2;
        var_num++;
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
    : Expression assign_p Expression
    | Expression assign_p '"' Expression '"' 
    | Expression assign_p TRUE {printf("TRUE\n");}
    | Expression assign_p FALSE {printf("FALSE\n");}
;

AssignmentStmt
    : AssignmentExpr SEMICOLON {
        codegen(conver_status);
        codegen("\n");
        int ass_IDENTnum_temp=searchInt("z1");
        binary_op_judge(conver_flag,binary_op_status);
        if(var_type[ass_IDENTnum_temp]==1)
        {
            codegen("istore %d\n",ass_IDENTnum_temp);
        }
        if(var_type[ass_IDENTnum_temp]==2)
        {
            codegen("fstore %d\n",ass_IDENTnum_temp);
        }
        load_store=0;}
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
        if(var_type_status==1)
        {
            codegen("ldc 1\n");
            int Inc_temp=searchInt($1);
            codegen("iload %d\n",Inc_temp);
            codegen("iadd\n");
            codegen("istore %d\n",Inc_temp);
            normal_print=0;
        }
        if(var_type_status==2)
        {
            codegen("fconst_1\n");
            int Inc_temp=searchInt($1);
            codegen("fload %d\n",Inc_temp);
            codegen("fadd\n");
            codegen("fstore %d\n",Inc_temp);
            normal_print=0;
        }

       
        calculatePrint($1,scope);
        printf("INC\n");
    }
    | IDENT DEC{
        if(var_type_status==1)
        {
            int Dec_temp=searchInt($1);
            codegen("iload %d\n",Dec_temp);
            codegen("ldc 1\n");
            codegen("isub\n");
            codegen("istore %d\n",Dec_temp);
            normal_print=0;
        }
        if(var_type_status==2)
        {
            int Dec_temp=searchInt($1);
            codegen("fload %d\n",Dec_temp);
            codegen("fconst_1\n");
            codegen("fsub\n");
            codegen("fstore %d\n",Dec_temp);
            normal_print=0;
        }
        

     
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
    : WHILE '(' Condition ')' Block 

Condition
    :Expression {printf(cmp_op_STR);printf("\n");}
;

Block
    : {scope++;}  '{' StatementList '}' {dump_symbol(scope);--scope;}
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
        codegen("%d\n",$<i_val>$);
        codegen("istore");
        codegen("%d\n",var_num);
        var_num++;
        //printf("INT_LIT %d\n", $<i_val>$);
    }
    | FLOAT_LIT {
        codegen("%f\n",$1);
        codegen("fstore");
        codegen("%d\n",var_num);
        var_num++;
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
            
            codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            codegen("swap\n");
            if(var_type_status==1){
                codegen("invokevirtual java/io/PrintStream/print(I)V\n");
            }
            if(var_type_status==2){
                codegen("invokevirtual java/io/PrintStream/print(F)V\n");
            }
            codegen("\n");
            
            binary_op_status="QWER";
            literal_flag=0;
        }
        else
        {
            printf("PRINT %s",typeArr[type_ADDRESS]);printf("\n");
        }


    }
    | PRINT '(' '"' Expression '"' ')' SEMICOLON 
    {
        codegen("ldc \"\\n\"\n");
        codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        codegen("swap\n");
        codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");

    }
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
        
    for(int i=0;i<series_num;i++)
    {
        var_type[i]=-1;
        var_series[i]="EMPTY";
    }
        
    
    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    codegen(".source hw3.j\n");
    codegen(".class public Main\n");
    codegen(".super java/lang/Object\n");
    codegen(".method public static main([Ljava/lang/String;)V\n");
    codegen(".limit stack 100\n");
    codegen(".limit locals 100\n");
    INDENT++;

    yyparse();

	printf("Total lines: %d\n", yylineno);

    /* Codegen end */
    codegen("return\n");
    INDENT--;
    codegen(".end method\n");
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    }
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
    int returnValue=2;
    for(int i=1; i<=varNum; i++) {
        //printf("------------------\n");
        //printf("level:%d scopeArr: %d\n",level,scopeArr[i-1]);
        //printf("id: %s nameArr:%s\n",id,nameArr[i-1]);
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

int searchInt(char *tempCHAR)
{

    for(int i=0;i<series_num;i++)
    {
        if(strcmp(tempCHAR,var_series[i])==0)
        {

            return i;
            break;
        }
    }
    return -100;

}

void binary_op_judge(int var_type_status,char* binary_op_status)
{
    char gen_op[6]="i";
    if(var_type_status==1)
    {   
        strcat(gen_op,binary_op_status);
        codegen(gen_op);
        codegen("\n");
    }
    if(var_type_status==2)
    {   
        char gen_op[6]="f";
        strcat(gen_op,binary_op_status);
        codegen(gen_op);
        codegen("\n");
    }
}