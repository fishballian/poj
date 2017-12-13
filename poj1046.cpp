#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int main()
{
    int set[16][3];
    int t[3];
    int i, j, D, p, Min;
#ifdef _POJ
    freopen("poj1046.txt", "r", stdin);
#endif
    for(i = 0; i < 16; i++)
        scanf("%d%d%d", &set[i][0], &set[i][1], &set[i][2]);
    while(scanf("%d%d%d", &t[0], &t[1], &t[2]) && t[0] >= 0)
    {
        Min = INT_MAX;
        for(i = 0; i < 16; i++)
        {
            D = 0;
            for(j = 0; j < 3; j++)
                D += (set[i][j] - t[j]) * (set[i][j] - t[j]);
            if(D < Min)
            {
                p = i;
                Min = D;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", t[0], t[1], t[2], set[p][0], set[p][1], set[p][2]);
    }
    return 0;
}

