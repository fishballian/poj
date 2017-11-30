#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int w, h, n;
bool grid1[100][100];
bool grid2[100][100];
int c;
int p1;
int p2;

typedef struct
{
    int x;
    int y;
    int val;
} cluster;

cluster c1[10000];
cluster c2[10000];

int calc_val(int a[10000][2], int n, int len)
{
    int i, sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += a[i][0] * len + a[i][1] + 1;
    }
    return sum;
}

void x_reflect(int a[10000][2], int n, int xlen)
{
    int i;
    for(i = 0; i < n; i++)
    {
        a[i][0] = xlen - a[i][0] - 1;
    }
}

void y_reflect(int a[10000][2], int n, int ylen)
{
    int i;
    for(i = 0; i < n; i++)
    {
        a[i][1] = ylen - a[i][1] - 1;
    }
}

cluster normalform(int a[10000][2], int n)
{
    int i, t, minx, miny, maxx, maxy, xlen, ylen;
    int value;
    cluster clu;
    maxx = maxy = 0;
    minx = miny = 100;
    for(i = 0; i < n; i++)
    {
        if(a[i][0] < minx)
            minx = a[i][0];
        if(a[i][0] > maxx)
            maxx = a[i][0];
        if(a[i][1] < miny)
            miny = a[i][1];
        if(a[i][1] > maxy)
            maxy = a[i][1];
    }
    for(i = 0; i < n; i++)
    {
        a[i][0] -= minx;
        a[i][1] -= miny;
    }
    xlen = maxx - minx + 1;
    ylen = maxy - miny + 1;
    if(maxx - minx > maxy - miny)
    {
        for(i = 0; i <n; i++)
        {
            t = a[i][0];
            a[i][0] = a[i][1];
            a[i][1] = t;
        }
        t = xlen;
        xlen = ylen;
        ylen = t;
    }
    value = calc_val(a, n, xlen);

    x_reflect(a, n, xlen);
    value = min(value, calc_val(a, n, xlen));

    y_reflect(a, n, ylen);
    value = min(value, calc_val(a, n, xlen));

    x_reflect(a, n, xlen);
    value = min(value, calc_val(a, n, xlen));
    
    clu.x = xlen;
    clu.y = ylen;
    clu.val = value;
    return clu;

}

void print(bool grid[100][100])
{
    int i, j;
    for(i = 0; i < w; i++)
    {
        for(j = 0; j < h; j++)
        {
            if(grid[i][j])
                cout << "@";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void dfs(int a[10000][2], bool visit[100][100], bool grid[100][100], int i, int j)
{
    if(i >= 0 && i <= w && j >=0 && j <= h && !visit[i][j] && grid[i][j])
    {
        a[c][0] = i;
        a[c++][1] = j;
        visit[i][j] = true;
        dfs(a, visit, grid, i - 1, j);
        dfs(a, visit, grid, i, j - 1);
        dfs(a, visit, grid, i + 1, j);
        dfs(a, visit, grid, i, j + 1);
    }
}

void divide(bool grid[100][100], cluster clu[10000], int &p)
{
    int i, j, x, y;
    int a[10000][2];
    bool visit[100][100] = {0};
    for(i = 0; i < w; i++)
    {
        for(j = 0; j < h; j++)
        {
            c = 0;
            if(!visit[i][j] && grid[i][j])
            {
                dfs(a, visit, grid, i, j);
                clu[p++] = normalform(a, c);
                //cout << clu[p - 1].x << "," << clu[p - 1].y << "," << clu[p - 1].val << endl;
            }
        }
    }
}

void readin(bool grid[100][100])
{
    int j, x, y;
    for(j = 0; j < n; j++)
    {
        cin >> x >> y;
        grid[x][y] = true;
    }
}

int cmp(const void *a, const void *b)
{
    cluster* pa = (cluster *)a;
    cluster* pb = (cluster *)b;
    if(pa->x != pb->x)
        return pa->x - pb->x;
    if(pa->y != pb->y)
        return pa->y - pb->y;
    return pa->val - pb->val;
}

bool is_equal()
{
    int i;
    divide(grid1, c1, p1);
    divide(grid2, c2, p2);
    if(p1 != p2)
        return false;
    qsort(c1, p1, sizeof(c1[0]), &cmp);
    qsort(c2, p2, sizeof(c1[0]), &cmp);
    for(i = 0; i < p1; i++)
    {
        if(c1[i].x != c2[i].x)
            return false;
        if(c1[i].y != c2[i].y)
            return false;
        if(c1[i].val != c2[i].val)
            return false;
    }
    return true;
}

int main()
{
    int t, i;
#ifdef _POJ
    freopen("poj1021.txt", "r", stdin);
#endif
    cin >> t;
    for(i = 0; i < t; i++)
    {
        memset(grid1, 0, sizeof(grid1));
        memset(grid2, 0, sizeof(grid2));
        p1 = p2 = 0;
        cin >> w >> h >> n;
        readin(grid1);
        readin(grid2);
        //print(grid1);
        //cout << "================" << endl;
        //print(grid2);
        if(is_equal())
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
