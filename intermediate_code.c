#include <stdio.h>
#include <string.h>

int main()
{
    char exp[50], temp = '1';
    int i, j;

    printf("Enter an expression: ");
    scanf("%49s", exp);

    printf("\nIntermediate Code:\n");

    /* Handle * and / first */
    i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '*' || exp[i] == '/')
        {
            printf("t%c = %c %c %c\n",
                   temp, exp[i-1], exp[i], exp[i+1]);

            exp[i-1] = temp;

            /* Remove operator and right operand */
            j = i;
            while (exp[j+2] != '\0')
            {
                exp[j] = exp[j+2];
                j++;
            }
            exp[j] = '\0';

            temp++;
            i = 0;
        }
        else
        {
            i++;
        }
    }

    /* Handle + and - */
    i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '+' || exp[i] == '-')
        {
            printf("t%c = %c %c %c\n",
                   temp, exp[i-1], exp[i], exp[i+1]);

            exp[i-1] = temp;

            /* Remove operator and right operand */
            j = i;
            while (exp[j+2] != '\0')
            {
                exp[j] = exp[j+2];
                j++;
            }
            exp[j] = '\0';

            temp++;
            i = 0;
        }
        else
        {
            i++;
        }
    }

    printf("Result = t%c\n", exp[0]);

    return 0;
}
