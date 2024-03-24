/* Definition section */
%{
    #include "common.h"
    #include "y.tab.h"	/* header file generated by bison */
    extern YYSTYPE yylval;

    #define YY_NO_UNPUT
    #define YY_NO_INPUT
%}


/* Define regular expression label */
letter  [a-zA-Z_]
digit [0-9]
id {letter}+({letter}|{digit})*
inumber {digit}+
fnumber ({digit}*\.{digit}+)
newline		[\n]
bnumber "true"|"false"

%x CMT
%x STR
%option yylineno

/* Rules section */
%%

"/*"        { BEGIN(CMT); }
<CMT>"*/"   { BEGIN(INITIAL); }
<CMT>\n     {;}
<CMT>.      {;}
"//".*      {;}
"\""        { BEGIN(STR);
                return '"';
            }
<STR>"\""   { BEGIN(INITIAL);
                return '"';
            }
<STR>[^\"]* { yylval.s_val = strdup(yytext);
                return STRING_LIT;
            }
"int"       {return INT;}
"float"     {return FLOAT;}
"bool"      {return BOOL;}
"string"    {return STRING;}
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         {return '/';}
"%"         {return '%';}
"++"        {return INC;}
"--"        {return DEC;}

">"         {return '>';}
"<"         {return '<';}
">="        {return GEQ;}
"<="        {return LEQ;}
"=="        {return EQL;}
"!="        {return NEQ;}

"="         {return '=';}
"+="        {return ADD_ASSIGN;}
"-="        {return SUB_ASSIGN;}
"*="        {return MUL_ASSIGN;}
"/="        {return QUO_ASSIGN;}
"%="        {return REM_ASSIGN;}

"&&"        {return LAND;}
"||"        {return LOR;}
"!"         {return '!';}

"("         {return '(';}
")"         {return ')';}
"["         {return '[';}
"]"         {return ']';}
"{"         {return '{';}
"}"         {return '}';}

";"         {return SEMICOLON;}
","         {return ',';}
"\n"        {;}

"print"     { return PRINT; }


{inumber}   { yylval.i_val = atoi(yytext);
                return INT_LIT;
            }


{fnumber}   { yylval.f_val = atof(yytext);
                return FLOAT_LIT;
            }

{id}        { yylval.id_val = strdup(yytext);
                return IDENT;
            }

{bnumber}   { yylval.s_val = strdup(yytext);
                return BOOL_LIT;
            }

<<EOF>>     { static int once = 0;
                if (once++) {
                    yyterminate();
                }
                yylineno++;
                
            }
[ \t]+      {;}
.           {;}
%%
/*  C Code section */
int yywrap(void)
{
    return 1;
}