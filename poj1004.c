#include<stdio.h>
int main()
{
    float a;
    float s = 0.0;
    int i;
    for(i = 0; i < 12; i++)
    {
        scanf("%f", &a);
        s += a; 
    }
    printf("$%.2f", s / 12);
    return 0;
}
