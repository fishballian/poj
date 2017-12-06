#include<stdio.h>
#include<limits.h>
#include<math.h>
char matrix[100][100];
int b[100][100][100];

#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int N, Max, s;
#ifdef _POJ
    freopen("poj1050.txt", "r", stdin);
#endif
    while(scanf("%d", &N) != EOF && N != 0)
    {
        Max = INT_MIN;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &matrix[i][j]);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
            {
                s = 0;
                for(int k = i; k < N; k++)
                {
                    s += matrix[k][j];
                    b[i][j][k - i] = s;
                    //printf("%d %d %d %d\n", i, j, k - i, s);
                }
            }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                for(int k = 0; k + i < N; k++)
                {
                    s = 0;
                    for(int m = 0; m <= j; m++)
                        s += b[k][m][i];
                    Max = max(s, Max);
                    for(int l = 1; l + j < N; l++)
                    {
                        s -= b[k][l - 1][i];
                        s += b[k][l + j][i];
                        Max = max(s, Max);
                    }
                }
        printf("%d\n", Max);
    }
    return 0;
}

