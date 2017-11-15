#include<stdio.h>
int main()
{
    int p, e, i, d, k, c = 1;
    while(scanf("%d%d%d%d", &p, &e, &i, &d) && p != -1)
    {
        for(k = 1; k <= 21252; k++)
        {
            if((d + k - p) % 23 == 0 && (d + k - e) % 28 == 0 && (d + k - i) % 33 == 0)
                break;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n", c, k);
        c++;
    }
    return 0;
}
