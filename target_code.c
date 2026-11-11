#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
        char left[100],right[100],result[100],op,op1[100],op2[100],relop[100],label[100];
        char tac[100][100];
        char line[100];
        int i,n;
        printf("Enter the number of lines");
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
                fgets(line,sizeof(line),stdin);
                line[strcspn(line,"\n")]='\0';
                strcpy(tac[i],line);
        }
        for(i=0;i<n;i++)
        {
                strcpy(line,tac[i]);
                if(sscanf(line,"if %s %s %s goto %s",left,relop,right,label)==4)
                {
                         printf("MOV AX, %s\n", left);
                         printf("CMP AX, %s\n", right);

                         if (strcmp(relop, "<") == 0)
                                 printf("JL %s\n", label);

                         else if (strcmp(relop, "<=") == 0)
                                printf("JLE %s\n", label);

                        else if (strcmp(relop, ">") == 0)
                                printf("JG %s\n", label);

                        else if (strcmp(relop, ">=") == 0)
                                printf("JGE %s\n", label);

                        else if (strcmp(relop, "==") == 0)
                                printf("JE %s\n", label);

                        else if (strcmp(relop, "!=") == 0)
                                printf("JNE %s\n", label);

                        continue;
                }
                if(sscanf(line,"goto %s",label)==1)
                {
                        printf("JMP %s\n",label);
                        continue;
                }
                if(sscanf(line,"%s = %s %c %s",result,op1,&op,op2)==4)
                {
                        printf("MOV AX,%s",op1);
                        switch(op)
                        {
                                case '+':
                                        printf("ADD AX,%s\n",op2);break;
                                case '-':
                                        printf("SUB AX,%s\n",op2);break;
                                case '*':
                                        printf("MOV BX,%s\n",op2);
                                        printf("MUL BX\n");break;
                                case '/':
                                        printf("MOV dx,0\n");
                                        printf("MOV BX,%s\n",op2);
                                        printf("DIV BX\n");break;


                        }
                        printf("MOV %s,AX\n",result);
                        continue;
                }
                if(sscanf(line,"%s = %s",result,op1)==2)
                {
                        printf("MOV AX,%s\n",op1);
                        printf("MOV %s,AX\n",result);
                        continue;
                }
        }
}
