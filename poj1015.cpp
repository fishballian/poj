#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int a[200][3];
int diff[200][3];
int n, m;
int r[20];
int r2[20];
int D, P, D_P;
int cut[200][20][2][2];

int cmp1(const void *a, const void *b)
{
    return ((int *)a)[0] - ((int *)b)[0];
}

int cmp2(const void *a, const void *b)
{
    int *ap = (int *)a;
    int *bp = (int *)b;
    return (bp[0] + bp[1]) - (ap[0] + ap[1]);
}

int cmp3(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void gen_cut()
{
    int i, j, k, c, s, t;
    qsort(diff, n, sizeof(diff[0]), &cmp1);
    for(i = 0; i < n; i++)
    {
        for(j = 1; j <= m && j + i <= n; j++)
        {
            s = c = t = 0;
            k = 0;
            while(c < j)
            {
                if(diff[k][2] >= i)
                {
                    s+=diff[k][0];
                    t+=diff[k][1];
                    c++;
                }
                k++;
            }
            cut[i][j][0][0] = s;
            cut[i][j][0][1] = t;

            s = c = t = 0;
            k = n - 1;
            while(c < j)
            {
                if(diff[k][2] >= i)
                {
                    s+=diff[k][0];
                    t+=diff[k][1];
                    c++;
                }
                k--;
            }
            cut[i][j][1][0] = s;
            cut[i][j][1][1] = t;
        }
    }

    //for(i = 0; i < n; i++)
    //{
    //    for(j = 1; j <= m && j + i <= n; j++)
    //        printf("%d,%d,%d,%d ", cut[i][j][0][0], cut[i][j][0][1], cut[i][j][1][0], cut[i][j][1][1]);
    //    printf("\n");
    //}
}

void dfs(int d, int u, int td, int tp)
{
    //if(D_P == 0)
    //    return;
    int i, delta, t1, t2;
    t1 = td - tp + cut[u][m - d][0][0];
    t2 = td - tp + cut[u][m - d][1][0];
    if(t1 >= 0 && t2 >= 0 && (t1 > D_P || (t1 == D_P && td + tp + cut[u][m - d][0][1] <= D + P)))
        return;
    if(t1 <= 0 && t2 <= 0 && (abs(t2) > D_P || (abs(t2) == D_P && td + tp + cut[u][m - d][1][1] <= D + P)))
        return;
    if(d >= m)
    {
        delta = abs(td - tp) - abs(D - P);
        if(delta < 0 || (delta == 0 && td + tp > D + P))
        {
            for(i = 0; i < m; i++)
                r2[i] = r[i];
            D = td;
            P = tp;
            D_P = abs(D - P);
        }
        return;
    }
    if(u >= n)
        return;
    r[d] = a[u][2];
    dfs(d + 1, u + 1, td + a[u][0], tp + a[u][1]);
    dfs(d, u + 1, td, tp);
}

int main()
{
    int i, c = 0;
#ifdef _POJ
    freopen("poj1015.txt","r",stdin);
#endif
    while(cin >> n && n > 0)
    {
        cin >> m;
        for(i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1];
            a[i][2] = i;
        }
        //qsort(a, n, sizeof(a[0]), &cmp2);
        for(i = 0; i < n; i++)
        {
            diff[i][0] = a[i][0] - a[i][1];
            diff[i][1] = a[i][0] + a[i][1];
            diff[i][2] = i;
        }
        D = 20 * 20;
        P = 0;
        D_P = abs(D - P);
        gen_cut();
        dfs(0, 0, 0, 0);
        cout << "Jury #" << ++c << endl;
        cout << "Best jury has value " << D << " for prosecution and value " << P <<" for defence:"<< endl;
        qsort(r2, m, sizeof(r2[0]), &cmp3);
        for(i = 0; i < m; i++)
            cout << " " << r2[i] + 1;
        cout << endl << endl;
    }
    return 0;
}
