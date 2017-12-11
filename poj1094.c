#include<stdio.h>
#include<string.h>

int main()
{
    int m, n, sum;
    int aj[26][26];
    int c[26][26];
    char sorted[27];
    int count;
    char s[4];
    int finish;
    int x, y;
    int i, j, k;
#ifdef _POJ
    freopen("poj1094.txt", "r", stdin);
#endif
    while(scanf("%d%d", &n, &m) && n > 0)
    {
        memset(aj, 0, sizeof(aj));
        finish = 0;
        for(i = 0; i < m; i++)
        {
            scanf("%s", s);
            if(finish)
                continue;
            x = s[0] - 'A';
            y = s[2] - 'A';
            if(aj[x][y] == -1 || x == y)
            {
                finish = 1;
                printf("Inconsistency found after %d relations.", i + 1);
                continue;
            }
            aj[x][y] = 1;
            aj[y][x] = -1;

            for(j = 0; j < n; j++)
            {
                if(aj[j][x] == 1)
                {
                    if(aj[j][y] == -1)
                    {
                        finish = 1;
                        printf("Inconsistency found after %d relations.", i + 1);
                        break;
                    }
                    aj[j][y] = 1;
                    aj[y][j] = -1;
                }

                if(aj[j][y] == -1)
                {
                    if(aj[j][x] == 1)
                    {
                        finish = 1;
                        printf("Inconsistency found after %d relations.", i + 1);
                        break;
                    }
                    aj[j][x] = -1;
                    aj[x][j] = 1;
                }
            }
            if(!finish)
            {
                memset(sorted, 0, sizeof(sorted));
                for(j = 0; j < n; j++)
                {
                    sum = 0;
                    for(k = 0; k < n; k++)
                        if(aj[j][k] == -1)
                            sum++;
                    sorted[sum] = j + 'A';
                }
                sum = 0;
                for(j = 0; j < n; j++)
                    if(sorted[j] > 0)
                        sum++;
                if(sum == n)
                {
                    finish = 1;
                    printf("Sorted sequence determined after %d relations: %s.", i + 1, sorted);
                }
            }
        }
        if(!finish)
            printf("Sorted sequence cannot be determined.");
        printf("\n");
    }
    return 0;
}

