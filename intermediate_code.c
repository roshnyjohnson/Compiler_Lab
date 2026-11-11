#include <stdio.h>
#include <string.h>

char s[100];
int pos = 0, t = 1;

void expr(char *res);

void factor(char *res)
{
    if (s[pos] == '(')
    {
        pos++;
        expr(res);
        pos++;
    }
    else
    {
        sprintf(res, "%c", s[pos++]);
    }
}

void term(char *res)
{
    char l[10], r[10], op;

    factor(l);

    while (s[pos] == '*' || s[pos] == '/')
    {
        op = s[pos++];
        factor(r);

        printf("t%d = %s %c %s\n", t, l, op, r);
        sprintf(l, "t%d", t++);
    }

    strcpy(res, l);
}

void expr(char *res)
{
    char l[10], r[10], op;

    term(l);

    while (s[pos] == '+' || s[pos] == '-')
    {
        op = s[pos++];
        term(r);

        printf("t%d = %s %c %s\n", t, l, op, r);
        sprintf(l, "t%d", t++);
    }

    strcpy(res, l);
}

int main()
{
    char result[10], variable;

    printf("Enter expression: ");
    scanf("%99s", s);

    printf("\nThree-address code:\n");

    variable = s[pos++];  // Read variable
    pos++;                // Skip '='

    expr(result);         // Generate code for RHS

    printf("%c = %s\n", variable, result);

    return 0;
}
