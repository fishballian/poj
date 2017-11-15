#include<stdio.h>
#include<stdlib.h>
int parse(const char *s){
    int i = 0, j = 0, r = 0;
    while(j < 7)
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            r = r * 10 + s[i] - '0';
            j++;
        }
        else if('A' <= s[i] && s[i] <= 'P')
        {
            r = r * 10 + (s[i] - 'A') / 3 + 2;
            j++;
        }
        else if('R' <= s[i] && s[i] <= 'Y')
        {
            r = r * 10 + (s[i] - 'Q') / 3 + 7;
            j++;
        }
        i++;
    }
    return r;
}

void pr(int a)
{
    printf("%03d-%04d", a / 10000, a % 10000);
}

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n, i, j, p, c;
    int a[100000];
    char s[10000];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", s);
        a[i] = parse(s);
    }
    qsort(a, n, sizeof(a[0]), &cmp);
    for(i = 0; i < n; i++)
    {
        j = i;
        c = 1;
        while(i + 1 < n && a[j] == a[i + 1])
        {
            c++;
            i++;
        }
        if(c > 1)
        {
            pr(a[j]);
            printf(" %d\n", c);
            p++;
        }
    }
    if(p == 0)
        printf("No duplicates.\n");
    return 0;
}
