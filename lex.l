%{
        #include<stdio.h>
        #include<stdlib.h>
        #include<string.h>
        #include<ctype.h>
%}
LETTER [a-zA-Z_]+
DIGIT [0-9]+
ID {LETTER}({LETTER}|{DIGIT})*
FLOAT_NUM {DIGIT}+"."{DIGIT}+
INTEGER {DIGIT}+
WS [ \t\n]
%%
{WS} { }
"//".* { printf("comment\n"); }
"int"|"float"|"double"|"char"|"return"|"main" {printf("Keyword:%s\n",yytext);}
{ID} {printf("identifier:%s\n",yytext);}
{FLOAT_NUM} {printf("Float:%s\n",yytext);}
{INTEGER} {printf("INT:%s\n",yytext);}
"+"|"-"|"*"|"/"|">"|"<"|"=" {printf("Operator:%s\n",yytext);}
"{"|"/"|")"|"("|";"|","|"}" {printf("Delimeter:%s\n",yytext);}
%%
int main(int argc,char *argv[])
{
        yyin=fopen(argv[1],"r");
        yylex();
        fclose(yyin);
        return 0;

}
int yywrap()
{
        return 1;
}
