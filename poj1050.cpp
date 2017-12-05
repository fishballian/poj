#include<stdio.h>
char matrix[100][100];

int main()
{
    int N;
#ifdef _POJ
    freopen("poj1050.txt", "r", stdin);
#endif
    while(scanf("%d", &N) != EOF)
    {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &matrix[i][j]);

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                printf("%d\n", matrix[i][j]);
    }
    return 0;
}

