#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int a[200][3];
int n, m;
int r[20];
int r2[20];
int D, P;
int cut[200][20];
int diff[200];

int cmp1(const void *a, const void *b)
{
    return (*(int(*)[3])b)[0] - (*(int(*)[3])a)[0];
}

int cmp2(const void *a, const void *b)
{
    return (*(int(*)[3])b)[1] - (*(int(*)[3])a)[1];
}

void gen_cut()
{
    int i, j, k, s;
    qsort(a, n, sizeof(a[0]), &cmp1);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j + i < n && j < m; j++)
        {
            s = 0;
            for(k = 0; k < j;)
            {
                if(a[k][2] >= i)
                {
                    s+=a[k][0];
                    k++;
                }
            }
        }
    }

    //qsort(a, n, sizeof(a[0]), &cmp2);
    //for(i = 0; i < n; i++)
    //    cout << a[i][1] << " ";
    //cout << endl;
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
    r[d] = a[u][2];
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
            a[i][2] = i;
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

