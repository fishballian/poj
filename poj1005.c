#include<stdio.h>
#include<math.h>
int main()
{
    int i, n;
    float l, x, y;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%f%f", &x, &y);
        l = 0.5 * 3.14 * (x * x + y * y) / 50;
        printf("Property %d: This property will begin eroding in year %d.\n", i+1, (int)ceil(l));
    }
    printf("END OF OUTPUT.");
    return 0;
}
