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
#define u (sqrt(5.0)+1)/2

int main()
{
    int a, b, Min, Max;
    //double golden = (sqrt(5) - 1) / 2;
#ifdef _POJ
    freopen("poj1067.txt", "r", stdin);
#endif
    while(scanf("%d%d", &a, &b) != EOF)
    {
        Min = min(a, b);
        Max = max(a, b);
        if(floor((Max - Min) * u) == Min)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}

