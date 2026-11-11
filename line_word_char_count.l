%{
        #include<stdio.h>
        int ctword=0;
        int ctspace=0;
        int ctline=0;
        int ctchar=0;
%}
WORD [a-zA-Z0-9]+
EOL [\n]
BLANK [ ]
%%
{WORD} {ctword++;ctchar+=yyleng;}
{BLANK} {ctspace++;}
{EOL} {ctline++;}
. { }
%%

void main(int argc,char *argv[])
{
        yyin=fopen(argv[1],"r");
        yylex();
        printf("words:%d",ctword);
        printf("space:%d",ctspace);
        printf("ctline:%d",ctline);
        printf("Char:%d",ctchar);
        fclose(yyin);
}
int yywrap()
{
        return 1;
}
