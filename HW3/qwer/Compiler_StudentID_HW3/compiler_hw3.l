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
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }

"print"     { return PRINT; }

{inumber}   { yylval.i_val = atoi(yytext);
                return INT_LIT;
            }

{id}        { yylval.ctr.id_name = strdup(yytext);
                return IDENT;
            }
[;]         { return SEMICOLON; }
[\n]        {;}
<<EOF>>     { static int once = 0;
                if (once++) {
                    yyterminate();
                }
            }
[ \t]+      {;}
.           {;}
%%
/*  C Code section */
int yywrap(void)
{
    return 1;
}