She is a \"girl\"STRING_LIT				      |	She is a \"girl\" 	 STRING_LIT
"QUOTA							      |	"        	 QUOTA
She is a \"girl\"STRING_LIT				      |	She is a \"girl\" 	 STRING_LIT
"QUOTA							      |	"        	 QUOTA
I have  	 STRING_LIT				      |	I have   	 STRING_LIT
I have 	STRING_LIT					      |	I have   	 STRING_LIT
 apple(s)\n   	 STRING_LIT				      |	 apple(s)\n 	 STRING_LIT
 apple(s)\n   	 STRING_LIT				      |	 apple(s)\n 	 STRING_LIT
apple(s)\n   	 STRING_LIT				      |	 apple(s)\n 	 STRING_LIT
 apple(s)\n  	 STRING_LIT				      |	 apple(s)\n 	 STRING_LIT
apple(s)\n  	 STRING_LIT				      |	 apple(s)\n 	 STRING_LIT
I have  	 STRING_LIT				      |	I have   	 STRING_LIT
apple(s)\n 	 STRING_LIT					 apple(s)\n 	 STRING_LIT
 apple(s)\n	 STRING_LIT				      |	 apple(s)\n 	 STRING_LIT
 I have 	 STRING_LIT					      |	I have   	 STRING_LIT
"        	 QUOTA						"        	 QUOTA

I have 	 STRING_LIT					      |	I have   	 STRING_LIT
"        	 QUOTA						"        	 QUOTA
)        	 RPAREN						)        	 RPAREN
print    	 PRINT						print    	 PRINT
(        	 LPAREN						(        	 LPAREN
x        	 IDENT						x        	 IDENT
)        	 RPAREN						)        	 RPAREN
print    	 PRINT						print    	 PRINT
(        	 LPAREN						(        	 LPAREN
"        	 QUOTA						"        	 QUOTA
 apple(s)\n	 STRING_LIT				      |	 apple(s)\n 	 STRING_LIT

 I have STRING_LIT					      |	I have   	 STRING_LIT
"        	 QUOTA						"        	 QUOTA
)        	 RPAREN						)        	 RPAREN
print    	 PRINT						print    	 PRINT
(        	 LPAREN						(        	 LPAREN
x        	 IDENT						x        	 IDENT
)        	 RPAREN						)        	 RPAREN
print    	 PRINT						print    	 PRINT
(        	 LPAREN						(        	 LPAREN
"        	 QUOTA						"        	 QUOTA
 apple(s)\nSTRING_LIT					      |	 apple(s)\n 	 STRING_LIT
"        	 QUOTA						"        	 QUOTA
)        	 RPAREN						)        	 RPAREN
;        	 SEMICOLON					;        	 SEMICOLON

I have         	 STRING_LIT				      |	I have   	 STRING_LIT
"        	 QUOTA						"        	 QUOTA
)        	 RPAREN						)        	 RPAREN
print    	 PRINT						print    	 PRINT
(        	 LPAREN						(        	 LPAREN
x        	 IDENT						x        	 IDENT
)        	 RPAREN						)        	 RPAREN
print    	 PRINT						print    	 PRINT
(        	 LPAREN						(        	 LPAREN
"        	 QUOTA						"        	 QUOTA
 apple(s)\n        	 STRING_LIT			      |	 apple(s)\n 	 STRING_LIT

(        	 LPAREN						(        	 LPAREN
"        	 QUOTA						"        	 QUOTA
I have   	 STRING_LIT					I have   	 STRING_LIT
"        	 QUOTA						"        	 QUOTA
)        	 RPAREN						)        	 RPAREN
print    	 PRINT						print    	 PRINT
(        	 LPAREN						(        	 LPAREN
x        	 IDENT						x        	 IDENT
)        	 RPAREN						)        	 RPAREN
print    	 PRINT						print    	 PRINT
(        	 LPAREN						(        	 LPAREN


I have  	 STRING_LIT				      |	I have   	 STRING_LIT
"        	 QUOTA						"        	 QUOTA
)        	 RPAREN						)        	 RPAREN
print    	 PRINT						print    	 PRINT
(        	 LPAREN						(        	 LPAREN
x        	 IDENT						x        	 IDENT
)        	 RPAREN						)        	 RPAREN
print    	 PRINT						print    	 PRINT
(        	 LPAREN						(        	 LPAREN
"        	 QUOTA						"        	 QUOTA
 apple(s)\n 	 STRING_LIT					 apple(s)\n 	 STRING_LIT
"        	 QUOTA						"        	 QUOTA
)        	 RPAREN						)        	 RPAREN
;        	 SEMICOLON					;        	 SEMICOLON

\"              { BEGIN STRING; printf("%-8s \t %s\n", yytext, "QUOTA"); }
<STRING>\\\"    { printf("%s", yytext); }
<STRING>\"      { printf("%s\t %s\n%-8s \t %s\n"," ","STRING_LIT", yytext, "QUOTA");
                  BEGIN INITIAL;               
                }
<STRING>.       { printf("%s", yytext); }


