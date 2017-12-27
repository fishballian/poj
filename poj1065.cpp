#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
using namespace std;
int T, n, r;
int a[5000][2];
bool vis[5000];

int cmp(const void *a, const void *b)
{
    int *ap = (int *)a;
    int *bp = (int *)b;
    if(ap[0] == bp[0])
        return ap[1] - bp[1];
    else
        return ap[0] - bp[0];
}

void dfs(int d, int t, int lastl, int lastw)
{
    int t2;
    bool f;
    if(d >= n)
    {
        if(t < r)
            r = t;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(vis[i])
            continue;
        if(a[i][0] >= lastl && a[i][1] >= lastw)
            t2 = t;
        else
            t2 = t + 1;
        f = false;
        for(int j = 0; j < i; j++)
            if(!vis[j] && a[j][0] < a[i][0] && a[j][1] < a[i][1])
            {
                f = true;
                break;
            }
        if(f)
            continue;
        if(t2 >= r)
            continue;
        vis[i] = true;
        dfs(d + 1, t2, a[i][0], a[i][1]);
        vis[i] = false;

    }
}

int main()
{
#ifdef _POJ
    freopen("poj1065.txt", "r", stdin);
#endif
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> a[j][0] >> a[j][1];
        qsort(a, n, sizeof(a[0]), &cmp);
        //for(int j = 0; j < n; j++)
        //    cout << a[j][0] << "," << a[j][1] << endl;
        memset(vis, 0, sizeof(vis));
        r = INT_MAX;
        dfs(0, 0, INT_MAX, INT_MAX);
        cout << r << endl;
    }
    return 0;
}

