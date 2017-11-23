#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int a[200][2];
int dd[200];
int dp[20][801][200][3];
int n, m;

int cmp3(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void gen_dp()
{
    int i, j, k, u, diff, add, mdiff, mdiff2, madd, s, t, near = 0;

    for(i = 0; i < m; i++)
        for(j = -400; j <= 400; j++)
            for(k = 0; k < n; k++)
                dp[i][j + 400][k][0] = 400;
    int min_max[20][2] = {0};
    qsort(dd, n, sizeof(dd[0]), &cmp3);
    for(i = 1; i < m; i++)
    {
        min_max[i][0] = min_max[i - 1][0] + dd[i - 1];
        min_max[i][1] = min_max[i - 1][1] + dd[n - i];
    }
    for(i = m - 1; i >= 0; i--)
    {
        mdiff2 = 400;
        for(j = min_max[i][0]; j <= min_max[i][1]; j++)
        {
            if(abs(j) > mdiff2 + 20)
            {
                continue;
            }
            for(k = i; k <= n - (m - i); k++)
            {
                mdiff = 400;
                madd = 0;
                s = i;
                for(u = k; u <= n - (m - i); u++)
                {
                    if(i < m - 1)
                    {
                        t = j + a[u][0] - a[u][1];
                        diff = dp[i + 1][t + 400][u + 1][0];
                        add = dp[i + 1][t + 400][u + 1][1] + a[u][0] + a[u][1];
                    }
                    else
                    {
                        diff = j + a[u][0] - a[u][1];
                        add = a[u][0] + a[u][1];
                    }
                    if(abs(diff) < abs(mdiff) || (abs(diff) == abs(mdiff) && add > madd))
                    {
                        mdiff = diff;
                        madd = add;
                        s = u;
                    }
                }
                dp[i][j + 400][k][0] = mdiff;
                dp[i][j + 400][k][1] = madd;
                dp[i][j + 400][k][2] = s;
                mdiff2 = min(abs(mdiff), mdiff2);
            }
        }
    }
}

int main()
{
    int i, s, c = 0;
    int mdiff, madd, D, P;
    int r[20];
#ifdef _POJ
    freopen("poj1015.txt","r",stdin);
#endif

    while(cin >> n && n > 0)
    {
        cin >> m;
        for(i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1];
            dd[i] = a[i][0] - a[i][1];
        }
        gen_dp();
        mdiff = 400;
        madd = 0;
        for(i = 0; i < n - m + 1; i++)
        {
            if(abs(dp[0][400][i][0]) < mdiff || (abs(dp[0][400][i][0]) == mdiff && dp[0][400][i][1] > madd))
            {
                s = dp[0][400][i][2];
                mdiff = abs(dp[0][400][i][0]);
                madd = dp[0][400][i][1];
            }
        }
        r[0] = s;
        D = P = mdiff = 0;
        for(i = 1; i < m; i++)
        {
            mdiff += a[r[i - 1]][0] - a[r[i - 1]][1];
            r[i] = dp[i][mdiff + 400][r[i - 1] + 1][2];
        }
        for(i = 0; i < m; i++)
        {
            D += a[r[i]][0];
            P += a[r[i]][1];
        }
        cout << "Jury #" << ++c << endl;
        cout << "Best jury has value " << D << " for prosecution and value " << P <<" for defence:"<< endl;
        //qsort(r, m, sizeof(r[0]), &cmp3);
        for(i = 0; i < m; i++)
            cout << " " << r[i] + 1;
        cout << endl << endl;
    }
    return 0;
}
