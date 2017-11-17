#include<stdio.h>
#include<stdlib.h>
#define bool int
#define false 0
#define true 1
#define MAX 64
int n, sum, max;
int a[MAX];
int visit[MAX];
int origin;
bool f;

int cmp(const void *a, const void *b)
{
    return -(*(int *)a - *(int *)b);
}

void def(int d, int len, int u)
{

}

bool valid(i)
{
    origin = i;
    f = false;
    def(0, 0, 0);
    return f;
}

int main()
{
    int i;
    while(scanf("%d", &n) && n != 0)
    {
        max = sum = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
            max = a[i] > max?a[i]:max;
        }
        qsort(a, n, sizeof(a[0]), &cmp);
        for(i = max; i <= sum; i++)
        {
            if(sum % i == 0)
            {
                if(valid(i))
                {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
