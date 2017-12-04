#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long LL;
int N, K;
LL a[10001];

int main()
{
    int i;
    LL s, m, b, e, r;
    float t;
#ifdef _POJ
    freopen("poj1064.txt", "r", stdin);
#endif
    while(scanf("%d %d", &N, &K) != EOF)
    {
        s = 0;
        m = 1;
        for(i = 0; i < N; i++)
        {
            scanf("%f", &t);
            a[i] = round(100 * t);
            s += a[i];
            m = max(m, a[i]);
        }
        b = 1;
        e = min(s / K + 1, m);
        r = 0;
        while(b <= e)
        {
            m = (b + e) / 2;
            s = 0;
            for(i = 0; i < N; i++)
            {
                s += a[i] / m;
            }
            if(s >= K)
            {
                r = max(r, m);
                b = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        printf("%.2f\n", r / 100.0);
    }
    return 0;
}

