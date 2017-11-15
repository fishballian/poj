#include<stdio.h>
#include<stdlib.h>
int stamps[100] = {0};
int count_diff(int a[4])
{
    int i, c = 0;
    for(i = 0; i < 4 && a[3 - i] != 0; i++)
        if(i == 0 || a[4 - i] != a[3 - i])
            c++;
    return c;
}

int count(int a[4])
{
    int i, c;
    for(i = 0; i < 4 && a[3 - i] != 0; i++)
        continue;
    return i;
}

int find_max(int a[4])
{
    int i, m = 0;
    for(i = 0; i < 4 && a[3 - i] != 0; i++)
        if(stamps[a[3 - i]] > m)
            m = a[3 - i];
    return m;
}

int cmp2(int a[4], int b[4])
{
    int i, j, r = 0;
    i = count_diff(a);
    j = count_diff(b);
    if(i != j)
        r = i - j;
    else
    {
        i = count(a);
        j = count(b);
        if(i != j)
            r = j - i;
        else
        {
            i = find_max(a);
            j = find_max(b);
            if(i != j)
                r = i - j;
        }
    }
    return r;
}

void resolve(const int r, const int l)
{
    int a1[4] = {0};
    int a2[4] = {0};
    int i, x1, x2, x3, x4;
    int tmp, tie = 0;
    for(x1 = 0; x1 < l; x1++)
        for(x2 = x1; x2 < l; x2++)
            for(x3 = x2; x3 < l; x3++)
                for(x4 = x3; x4 < l; x4++)
                {
                    if(stamps[x1] + stamps[x2] + stamps[x3] + stamps[x4] == r)
                    {

                        a2[0] = x1;
                        a2[1] = x2;
                        a2[2] = x3;
                        a2[3] = x4;
                        tmp = cmp2(a1, a2);
                        if(tmp < 0)
                        {
                            a1[0] = x1;
                            a1[1] = x2;
                            a1[2] = x3;
                            a1[3] = x4;
                            tie = 0;
                        }
                        else if(tmp == 0)
                        {
                            tie = 1;
                        }
                    }
                }
    printf("%d ", r);
    tmp = count_diff(a1);
    if(tmp == 0)
        printf("---- none");
    else
    {
        printf("(%d):", tmp);
        if(tie == 1)
            printf(" tie");
        else
            for(i = 0; i < 4; i++)
                if(a1[i] > 0)
                    printf(" %d", stamps[a1[i]]);
    }
    printf("\n");
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}


int main()
{
    int i, j, r;
    char c;
    while(1)
    {
        if(scanf("%d", &stamps[1]) == EOF)
            break;
        i = 2;
        while(scanf("%d", &stamps[i]) && stamps[i] > 0)
        {
            i++;
        }
        qsort(stamps, i, sizeof(stamps[0]), &cmp);
        while(scanf("%d", &r) && r > 0)
        {
            resolve(r, i);
        }
    }

    return 0;
}
