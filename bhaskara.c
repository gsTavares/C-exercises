#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    char equation[50];
    int i = 0, j = 0;

    int a = 0, b = 0, c = 0, delta = 0;
    float x, x1, x2;

    printf("\nType the equation: ");
    gets(equation);
    printf("-------------------------------------\n");

    while (i < strlen(equation))
    {
        if (*(equation + i) == ' ')
        {
            for (j = i; j < strlen(equation); j++)
            {
                *(equation + j) = *(equation + j + 1);
            }
        }

        if (*(equation + i) == '=')
        {
            int final = strlen(equation) - i;
            for (int t = 0; t < final; t++)
            {
                *(equation + i + t) = 0;
            }
        }
        i++;
    }

    if (*(equation + 0) == 'x')
    {
        a = 1;
    }
    else
    {
        // (char ascII - the real number) = 48
        a = (int)*(equation + 0) - 48;
        printf("%d", a);
    }

    i = 0;
    j = 0;

    while (i < strlen(equation))
    {
        if (*(equation+i) == '+' || *(equation+i) == '-')
        {
            b = *(equation+i+1) - 48;
            break;
        }
        i++;
    }

    c = (int) *(equation+(strlen(equation)-1)) - 48;

    delta = (b*b) - (4*a*c);
    printf("\ndelta = %d", delta);

    if(delta < 0){
        printf("unreal solution only");
    } else if(delta == 0){
        x = (-b)/(2*a);
        printf("\nx = %.1lf", (float) x);
    } else {
        x1 = (-b + sqrt((double) delta))/(2*a);
        x2 = (-b - sqrt((double) delta))/(2*a);
        printf("\nx1 = %.1lf, x2 = %.1lf", x1, x2);
    }

    return 0;
}
