#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int i,error;
char input[100];
void E();
void EPRIME();
void T();
void TPRIME();
void F();

void E()
{
        T();
        EPRIME();

}
void EPRIME()
{
        if(input[i]=='+'||input[i]=='-')
        {
                i++;
                T();
                EPRIME();
        }
}

void T()
{
        F();
        TPRIME();

}
void TPRIME()
{
        if(input[i]=='*'||input[i]=='/')
        {
                i++;
                F();
                TPRIME();
        }
}

void F()
{
        if(isalnum(input[i]))
        {
                i++;
        }
        else if(input[i]=='(')
        {
                i++;
                E();
                if(input[i]==')')
                {
                        i++;
                }
                else{
                        error=1;
                }
        }
        else{
                error=1;
        }
}
int main()
{
        printf("Enter the expression\n");
        scanf("%s",input);
        if(input[0]=='+'||input[0]=='-'||input[0]=='*'||input[0]=='/')
        {
                printf("Rejected\n");
                return 0;
        }
        if(input[strlen(input)-1]=='+'||input[strlen(input)-1]=='-'||input[strlen(input)-1]=='*'||input[strlen(input)-1]=='/')
        {
                printf("Rejected\n");
                return 0;
        }

        E();
        if(error==0&&i==strlen(input))
        {
                printf("Accepted");
        }
        else{
                printf("Rejected");
        }
}
