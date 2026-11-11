%{
        #include<stdio.h>
        #include<stdlib.h>
        #include<ctype.h>
        int v_count=0;
        int c_count=0;
%}
%%
[aeiouAEIOU] {v_count++;}
[a-zA-Z] {c_count++;}
[\n] {printf("the vowels:%d\nconsonants:%d",v_count,c_count);}
%%

int main()
{
        printf("Enter string:");
        yylex();
        return 0;

}
int yywrap()
{
        return 1;
}
