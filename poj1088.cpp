#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[100][100];
int p[100][100];
int R, C;

int find_max_len(int x, int y)
{
    int r, m;
    if(p[x][y] != 0)
        return p[x][y];
    m = 0;
    if(x - 1 >= 0 && a[x - 1][y] < a[x][y])
    {
        r = find_max_len(x - 1, y);
        if(r > m)
            m = r;
    }
    if(x + 1 < R && a[x + 1][y] < a[x][y])
    {
        r = find_max_len(x + 1, y);
        if(r > m)
            m = r;
    }
    if(y - 1 >= 0 && a[x][y - 1] < a[x][y])
    {
        r = find_max_len(x, y - 1);
        if(r > m)
            m = r;
    }
    if(y + 1 < C && a[x][y + 1] < a[x][y])
    {
        r = find_max_len(x, y + 1);
        if(r > m)
            m = r;
    }
    p[x][y] = m + 1;
    return m + 1;
}

int find_max_path_len()
{
    int i, j, m = 1;
    memset(p, 0, sizeof(p));
    for(i = 0; i < R; i++)
        for(j = 0; j < C; j++)
            m = max(m, find_max_len(i, j));
    return m;
}

int main()
{
    int i, j;
#ifdef _POJ
    freopen("poj1088.txt", "r", stdin);
#endif
    while(cin >> R >> C && !cin.eof())
    {
        for(i = 0; i < R; i++)
            for(j = 0; j < C; j++)
            {
                cin >> a[i][j];
            }
        cout << find_max_path_len() << endl;
    }
    return 0;
}

