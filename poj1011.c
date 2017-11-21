#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
#define false 0
#define true 1
#define MAX 64
int n, sum, max;
int a[MAX];
int v[MAX];
int origin;
bool f;

int cmp(const void *a, const void *b)
{
    return -(*(int *)a - *(int *)b);
}

void def(int d, int len, int u)
{
    int i;
    if(f) return;
    if(len == 0)
    {
        i = 0;
        while(v[i]) i++;
        v[i] = true;
        def(d + 1, a[i], i+1);
        v[i] = false;
    } 
    else if(len == origin)
    {
        if(d == n)
            f = true;
        else
            def(d, 0, 0);
    }
    else
    {
        for(i = u; i < n; i++)
            if(!v[i] && len + a[i] <= origin)
            {
                if(!v[i - 1] && a[i] == a[i - 1]) continue;
                v[i] = true;
                def(d + 1, len + a[i], i + 1);
                v[i] = false;
            }
    }
}

bool valid(int i)
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
        memset(v, false, sizeof(v));
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
