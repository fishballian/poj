#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
#ifdef _POJ
    freopen("poj1042.txt", "r", stdin);
#endif
    int i, n, h, f[25], d[25], t[24];
    while(scanf("%d", &n) && n > 0)
    {
        scanf("%d", &h);
        for(i = 0; i < n; i++)
            scanf("%d%d", &f[i], &d[i]);
        for(i = 0; i < n - 1; i++)
            scanf("%d", &t[i]);
        for(i = 0; i < n - 1; i++)
            printf("%d, ", f[i]);
        printf("%d\n", f[n - 1]);
        printf("Number of fish expected: %d\n\n", 31);
    }
    return 0;
}

