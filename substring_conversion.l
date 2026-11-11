%{
        #include<stdio.h>
        #include<stdlib.h>
        #include<string.h>
        #include<ctype.h>
%}

%%
[a-z] {printf("%c",toupper(yytext[0]));}
[A-Z] {printf("%c",tolower(yytext[0]));}
. {printf("%s",yytext);}
%%

int main()
{
        printf("Enter string");
        yylex();
        return 0;
}
int yywrap()
{
        return 1;
}
