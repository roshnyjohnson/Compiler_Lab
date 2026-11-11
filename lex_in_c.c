#include<stdio.h>
#include<string.h>
#include<ctype.h>

char keyword[][20]={ "int", "float", "char", "if", "else", "while", "for",
    "return", "void", "break", "continue", "double", "long",
    "short", "switch", "case", "default", "do"};

int Is_keyword(char str[])
{
        int n=sizeof(keyword)/sizeof(keyword[0]);
        for(int i=0;i<n;i++)
        {
                if(strcmp(str,keyword[i])==0)
                {
                        return 1;
                }

        }
        return 0;
}

int main()
{
        char buffer[20];
        int i,j;
        int ch;
        FILE *fp;
        fp=fopen("input.c","r");
        while((ch=fgetc(fp))!=EOF)
        {
                if(isspace(ch))
                {
                        continue;
                }

                if(isalpha(ch)||ch=='_')
                {
                        i=0;
                        buffer[i++]=ch;
                        while((ch=fgetc(fp))!=EOF &&(isalpha(ch)||ch=='_'))
                        {
                                buffer[i++]=ch;
                        }
                        buffer[i]='\0';
                        if(Is_keyword(buffer))
                        {
                                printf("Keyword-%s\n",buffer);

                        }
                        else{
                                printf("Identifier-%s\n",buffer);
                        }
                }
                else if(isdigit(ch))
                {
                        i=0;
                        int dot_count=0;
                        buffer[i++]=ch;
                        while((ch=fgetc(fp))!=EOF&&(isdigit(ch)||ch=='.'))
                        {
                                if(ch=='.') dot_count++;
                                if(dot_count>1) break;

                                 buffer[i++]=ch;
                        }
                        buffer[i]='\0';
                        printf("Digit-%s\n",buffer);
                }
                else if(ch=='"')
                {
                        i=0;
                        while((ch=fgetc(fp))!=EOF&&ch!='"')


                        {
                                        buffer[i++]=ch;
                        }
                        buffer[i]='\0';
                        printf("String-%s\n",buffer);
                }
                else if(strchr("+-*/=<>!&|",ch)){
                        char next=fgetc(fp);
                        if((ch=='+'&&next=='+')||
                        (ch=='+'&&next=='=')||
                        (ch=='-'&&next=='-')||
                        (ch=='-'&&next=='-')||
                        (ch=='>'&&next=='=')||
                        (ch=='<'&&next=='='))
                        {
                                printf("Operator:%c%c\n",ch,next);
                        }
                        else{
                                printf("Operator:%c\n",ch);
                        }

                }
                else if (strchr("(){}[];,.", ch)) {
                        printf("Special Symbol : %c\n", ch);
                }

                /* Invalid Character */
                else {
                        printf("Invalid Token : %c\n", ch);
                }


        }
        fclose(fp);
}
