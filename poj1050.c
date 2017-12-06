#include<stdio.h>
#include<limits.h>
#include<math.h>
char matrix[100][100];

#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int N, Max, s;
#ifdef _POJ
    freopen("poj1050.txt", "r", stdin);
#endif
    while(scanf("%d", &N) != EOF)
    {
        Max = INT_MIN;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &matrix[i][j]);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                for(int k = 0; k + i < N; k++)
                    for(int l = 0; l + j < N; l++)
                    {
                        s = 0;
                        for(int m = k; m <= k + i; m++)
                            for(int n = l; n <= l + j; n++)
                                s += matrix[m][n];
                        Max = max(s, Max);
                    }
        printf("%d\n", Max);
    }
    return 0;
}

