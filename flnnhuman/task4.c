#include <stdio.h>
int main()
{

    int a,b,c,rev = 0,result = 0,p;

    scanf("%i %i %i", &a,&b,&c);
    for (int i = a; i <= b; i++)
    {
        a = i;
        rev = 0;
        while(a>0)
        {
            rev = rev*10 + a%10;
            a/=10;
        }
        p = (i-rev) > 0 ? i-rev:(i-rev)*(-1);
        if (p<=c)
            result++;
    }

    printf("%i",result);
    return 0;
}