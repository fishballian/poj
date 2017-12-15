#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int N, mv[200][2];
bool vis[200];
int Min;

void dfs(int deep, int last, int round)
{
    int j, round2;
    if(deep == N)
    {
        Min = min(Min, round);
        return;
    }
    for(j = 0; j < N; j++)
    {
        if(vis[j])
            continue;
        if(mv[j][0] <= last)
        {
            round2 = round + 1;
            if(round2 >= Min)
                continue;
        }
        else
        {
            round2 = round;
        }
        vis[j] = true;
        dfs(deep + 1, mv[j][1], round2);
        vis[j] = false;
    }
}

int cmp(const void *a, const void *b)
{
    return ((int *)a)[0] - ((int *)b)[0];
}

int main()
{
    int T;
#ifdef _POJ
    freopen("poj1083.txt", "r", stdin);
#endif
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N;
        for(int j = 0; j < N; j++)
        {
            cin >> mv[j][0] >> mv[j][1];
            mv[j][0] = (mv[j][0] - 1) / 2;
            mv[j][1] = (mv[j][1] - 1) / 2;
            if(mv[j][0] > mv[j][1])
                swap(mv[j][0], mv[j][1]);
        }
        //qsort(mv, N, sizeof(mv[0]), &cmp);
        Min = 200;
        memset(vis, 0, sizeof(vis));
        dfs(0, 200, 0);
        cout << Min * 10 << endl;
    }
    return 0;
}

