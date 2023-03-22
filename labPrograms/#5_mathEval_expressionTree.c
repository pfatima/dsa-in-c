//evaluating mathematical expression
//using expression trees

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char a[100], ch;
    int t1, t2, res, i, count = 0;
    printf("enter expression: \n");
    scanf("%s", a);
    for(i = 0; i < strlen(a); i++)
    {
        ch = a[i];
        if (isdigit(ch))
            break;
        else
            count++;
    }
    count -= 1;
    while(count >= 0)
    {
        t1 = a[2 * count + 1] - 48;
        t2 = a[2 * count + 2] - 48;
        if(a[count] == '/')
            res = t1 / t2;
        else if(a[count] == '*')
            res = t1 * t2;
        else if(a[count] == '+')
            res = t1 + t2;
        else if(a[count] == '-')
            res = t1 - t2;
        else
            printf("invalid expression :(\n");
        a[count] = res + 48;
        count -= 1;
    }
    printf("evaluated result from expression tree is %d\n", res);
}
