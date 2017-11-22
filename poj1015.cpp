#include<iostream>
#include<cmath>
using namespace std;
int a[200][2];
int n, m;
int r[20];
int r2[20];
int D, P;
int cut[200][20];
int diff[200];

void gen_cut()
{
    int i, j, arr;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j + i < n && j < m; j++)
        {
        }
    }
}

void dfs(int d, int u)
{
    int i, td, tp, delta;
    if(d >= m)
    {
        td = tp = 0;
        for(i = 0; i < m; i++)
        {
            td += a[r[i]][0];
            tp += a[r[i]][1];
        }
        delta = abs(td - tp) - abs(D - P);
        if(delta < 0 || (delta == 0 && D + P < td + tp))
        {
            for(i = 0; i < m; i++)
                r2[i] = r[i];
            D = td;
            P = tp;
        }
        return;
    }
    if(u >= n)
        return;
    r[d] = u;
    dfs(d + 1, u + 1);
    dfs(d, u + 1);
}

int main()
{
    int i, c = 0;
    while(cin >> n && n > 0)
    {
        cin >> m;
        for(i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1];
            diff[i] = a[i][0] - a[i][1];
        }
        D = 20 * 20;
        P = 0;
        dfs(0, 0);
        cout << "Jury #" << ++c << endl;
        cout << "Best jury has value " << D << " for prosecution and value " << P <<" for defence:"<< endl;
        for(i = 0; i < m; i++)
            cout << " " << r2[i] + 1;
        cout << endl << endl;
    }
    return 0;
}

