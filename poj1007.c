#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int l;

int count_unsort(char *s)
{
    int i, j, c = 0;
    for(i = 0; i < l; i++)
        for(j = i + 1; j < l; j++)
            if(s[i] > s[j])
                c++;
    return c;
}

int cmp(const void *a, const void *b)
{
    char* as = *(char(*)[])a;
    char* bs = *(char(*)[])b;
    int r = count_unsort(as) - count_unsort(bs);
    if(r == 0)
        return as - bs;
    else
        return r;
}


int main()
{
    int i, n;
    char a[100][51];
    scanf("%d%d", &l, &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    qsort(a, n, sizeof(a[0]), &cmp);
    for(i = 0; i < n; i++)
        printf("%s\n", a[i]);
    return 0;
}

