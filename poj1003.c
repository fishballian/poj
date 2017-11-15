#include<stdio.h>
int main()
{
    float f, a[10000];
    int i, j;
    a[0] = 0.0;
    for(i = 1; i < 10000; i++)
    {
        a[i] = a[i - 1] + 1.0 / (i + 1);
        if(a[i] > 5.20)
        {
            j = i;
        }

    }
    while(scanf("%f", &f) && !(f - 0 > -0.00001 && f - 0 < 0.00001))
    {
        for(i = 1; i <= j; i++)
            if(a[i] > f)
            {
                printf("%d card(s)\n", i);
                break;
            }
    }
    return 0;
}
