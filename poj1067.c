#include<stdio.h>
#include<math.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int a, b, Min, Max;
#ifdef _POJ
    freopen("poj1067.txt", "r", stdin);
#endif
    while(scanf("%d%d", &a, &b) != EOF)
    {
        if(a == 0 || b == 0 || a == b)
            printf("1\n");
        else
        {
            Min = min(a, b);
            Max = max(a, b);
        }
                
    }
    return 0;
}

