#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
#include<cmath>
using namespace std;
int M, N;
int a[100][3];
int s[100][100][2];

typedef struct
{
    int money;
    int max_level;
    int min_level;
    int goods;
} node;

bool operator< (const node& a, const node& b)
{
    return a.money < b.money;
}


int main()
{
    int i, j, g, Min;
    node n, n2;
    priority_queue<node, vector<node>, less<node> > minHeap;
#ifdef _POJ
    freopen("poj1062.txt", "r", stdin);
#endif
    while(scanf("%d%d", &M, &N) != EOF)
    {
        for(i = 0; i < N; i++)
        {
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
            for(j = 0; j < a[i][2]; j++)
            {
                scanf("%d%d", &s[i][j][0], &s[i][j][1]);
            }
        }
        Min = a[0][0];
        n.money = 0;
        n.max_level = a[0][1];
        n.min_level = a[0][1];
        n.goods = 0;
        minHeap.push(n);
        while(!minHeap.empty())
        {
            n = minHeap.top();
            minHeap.pop();
            Min = min(Min, n.money + a[n.goods][0]);
            g = n.goods;
            if(n.money < Min)
            {
                for(i = 0; i < a[g][2]; i++)
                {
                    n2.goods = s[g][i][0] - 1;
                    n2.money = s[g][i][1] + n.money;
                    n2.max_level = max(n.max_level, a[s[g][i][0] - 1][1]);
                    n2.min_level = min(n.min_level, a[s[g][i][0] - 1][1]);
                    if(n2.max_level - n2.min_level <= M)
                        minHeap.push(n2);
                }
            }
            
        }
        cout << Min << endl;
    }
    return 0;
}

