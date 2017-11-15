#include<stdio.h>
#include<stdlib.h>
int w, l, p2l, len;
int p[1001][2];
int p2[1000 * 9][3];

int is_valid(int x, int y)
{
    return (x * w + y) < len && x >= 0 && y < w && y >= 0;
}

int findv(int x, int y)
{
    int s = x * w + y;
    int i;
    if(is_valid(x, y))
    {
        for(int i = 0; i < l; i++)
        {
            if((s -= p[i][1]) < 0)
                return p[i][0];
        }
    }
    else
    {
        printf("invalid xy:%d %d\n", x, y);
    }
    return -1;
}

int get_diff(int i, int j)
{
    int x, y, k;
    int s = findv(i, j);
    int m = 0;
    for(x = i - 1; x <= i + 1; x++)
        for(y = j - 1; y <= j + 1; y++)
        {
            if(is_valid(x, y))
            {
                k = abs(s - findv(x, y));
                if(k > m)
                    m = k;
            }

        }
    return m;
}

void process(int x, int y)
{
    int i, j, s;
    for(i = x - 1; i <= x + 1; i++)
        for(j = y - 1; j <= y + 1; j++)
        {
            if(is_valid(i, j % w))
            {
               p2[p2l][0] = i;
               p2[p2l][1] = j % w;
               p2l++;
            }
        }
}

int cmp(const void *a, const void *b)
{
    int *al = (int *)a;
    int *bl = (int *)b;
    if(al[0] == bl[0])
        return al[1] - bl[1];
    else
        return al[0] - bl[0];
}

void rm_duplicate()
{
    int i, j, x, y, d, old;
    j = 0;
    old = -1;
    for(i = 0; i < p2l; i++)
    {
        x = p2[i][0];
        y = p2[i][1];
        while(i < p2l && p2[i + 1][0] == x && p2[i + 1][1] == y)
            i++;
        d = get_diff(x, y);
        if(d != old)
        {
            p2[j][0] = x;
            p2[j][1] = y;
            p2[j][2] = d;
            j++;
        }
        old = d;
    }
    p2l = j;
}

int main()
{
    int i, s, t;
    while(scanf("%d", &w) && w > 0)
    {
        s = len = l = p2l  = 0;
        while(scanf("%d %d", &p[l][0], &p[l][1]) && (p[l][0] != 0 || p[l][1] != 0))
        {
            len += p[l][1];
            l++;
        }
        for(i = 0; i < l; i++)
        {
            process(s / w, s % w);
            s+=p[i][1];
        }
        process((len - 1) / w, (len - 1) % w);
        qsort(p2, p2l, sizeof(p2[0]), &cmp);
        rm_duplicate();
        printf("%d\n", w);
        for(i = 0; i < p2l; i++)
        {

            //printf("====%d %d %d\n", p2[i][0], p2[i][1], p2[i][2]);
            if(i + 1 < p2l)
                t = p2[i + 1][0] * w + p2[i + 1][1] - p2[i][0] * w - p2[i][1];
            else
                t = len - p2[i][0] * w - p2[i][1];
            printf("%d %d\n", p2[i][2], t);
        }
        printf("0 0\n");
    }
    printf("0\n");
    return 0;
}
