#include<stdlib.h>
#include<stdio.h>
int cmp(const void *a, const void *b)
{
    return *((int (*)[2])a)[0] - *((int (*)[2])b)[0];
}
int main()
{
    int a[5][2] = {{5, 1}, {3, 2}, {6, 3}, {2, 4}, {1, 5}};
    qsort(a, 5, sizeof(a[0]), &cmp);
    for(int i = 0; i < 5; i++)
        printf("%d,%d\n", a[i][0], a[i][1]);
    return 0;
}
