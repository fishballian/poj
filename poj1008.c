#include<stdio.h>
#include<string.h>
char mnames[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char dnames[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int month_to_num(char m[])
{
    for(int i = 0; i < 19; i++)
        if(strcmp(mnames[i], m) == 0)
            return i;
    return -1;
}

void transform(int d, char m[], int y)
{
    int days;
    int ny, nd1;
    char *nd2;
    days = y * 365 + d + 20 * month_to_num(m);
    ny = days / 260; 
    nd1 = (days % 13) + 1;
    nd2 = dnames[days % 20];
    printf("%d %s %d\n", nd1, nd2, ny);
}

int main()
{
    int i, n, y, d;
    char m[10];
    scanf("%d", &n);
    printf("%d\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d. %s %d", &d, m, &y);
        transform(d, m, y);
    }
    return 0;
}
