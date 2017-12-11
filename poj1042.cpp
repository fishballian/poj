#include<iostream>
#include<cstdio>
#include<cassert>
#include<cmath>
#include<cstring>
#include<climits>
using namespace std;
int n, h, f[25], d[25], t[24];
int dp[26][193][2];

int calc_fish_num(int fi, int di, int times)
{
    int u;
    if(di > 0)
        u = fi / di;
    else
        u = INT_MAX;

    if(times <= u)
        return (fi + fi - di * (times - 1)) * times / 2;
    else
        return (fi + fi - di * (u - 1)) * u / 2 + fi - di * u;
}

void construct_dp()
{
    int m, u, spend;
    memset(dp, 0, sizeof(dp));
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 1; j <= h * 12; j++) 
        {
            m = calc_fish_num(f[i], d[i], j);
            spend = j;
            for(int k = j - t[i]; k >= 1; k--)
            {
                u = calc_fish_num(f[i], d[i], k) + dp[i + 1][j - t[i] - k][0];
                if(u > m)
                {
                    m = u;
                    spend = k;
                }
            }
            dp[i][j][0] = m;
            dp[i][j][1] = spend;
        }
    }
}

int main()
{
    int i, u;
#ifdef _POJ
    freopen("poj1042.txt", "r", stdin);
#endif
    while(scanf("%d", &n) && n > 0)
    {
        scanf("%d", &h);
        for(i = 0; i < n; i++)
            scanf("%d", &f[i]);
        for(i = 0; i < n; i++)
            scanf("%d", &d[i]);
        for(i = 0; i < n - 1; i++)
            scanf("%d", &t[i]);
#ifdef _TEST
        assert(calc_fish_num(10, 3, 1) == 10);
        assert(calc_fish_num(10, 3, 3) == 21);
        assert(calc_fish_num(10, 3, 4) == 22);
        assert(calc_fish_num(10, 3, 5) == 22);
        assert(calc_fish_num(10, 5, 2) == 15);
        assert(calc_fish_num(10, 5, 3) == 15);
#endif
        construct_dp();
        //for(i = 0; i < n; i++)
        //{
        //    for(int j = 0; j <= h * 12; j++)
        //        printf("%2d ", dp[i][j][1]);
        //    cout << endl;
        //}
        u = h * 12;
        i = 0;
        while(i < n)
        {
            printf("%d", dp[i][u][1] * 5);
            u -= dp[i][u][1];
            if(i < n - 1)
            {
                if(u > 0)
                    u -= t[i];
                printf(", ");
            }
            i++;
        }
        printf("\n");
        printf("Number of fish expected: %d\n\n", dp[0][h * 12][0]);
    }
    return 0;
}

