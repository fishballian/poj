#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[28];

int is_solution(const int k, const int i)
{
    int j, n, d, u, r;
    n = 2 * k;
    d = -1;
    for(j = 0; j < 2 * k; j++)
    {
        a[j] = j;
    }
    for(j = 0; j < k; j++)
    {
        d = (d + i) % n;
        if(a[d] < k)
            return 0;
        n--;
        for(u = d; u < n; u++)
            a[u] = a[u + 1];
        d--;
    }
    return 1;
}

int find_solution(const int k)
{
    int i;
    for(i = 1; i < 100000000; i++)
    {
        if(is_solution(k, i))
            return i;
    }
    return -1;
}

int main()
{
    int i, k;
    int b[14] = {0};
    for(i = 1; i < 14; i++)
        b[i] = find_solution(i);
    while(scanf("%d", &k) && k > 0)
    {
        //printf("%d\n", find_solution(k));
        printf("%d\n", b[k]);
    }
    return 0;
}
