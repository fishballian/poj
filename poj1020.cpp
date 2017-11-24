#include<iostream>
using namespace std;
int n;
int s;
int a[16];
int p[16][2];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

bool in_range(float x, float y, int i)
{
    int a1, a2, a3, a4;
    a1 = p[i][0];
    a2 = a1 + a[i];
    a3 = p[i][1];
    a4 = a3 + a[i];
    return a1 < x && a2 > x && a3 < y && a4 > y;
}

bool is_overlap(int x, int y, int t)
{
    int i, l;
    for(i = 0; i < t; i++)
    {
        if(in_range(x, y, i)
                || in_range(x + a[t], y, i)
                || in_range(x, y + a[t], i)
                || in_range(x + a[t], y + a[t], i)
                || in_range((x + a[t]) / 2.0, (y + a[t]) / 2.0, i))
            return true;
    }
    return false;
}

bool can_cut()
{
    int i, j, k, u;
    bool f, t;
    j = 0;
    for(i = 0; i < n; i++)
        j += a[i] * a[i];
    if(s * s != j)
        return false;
    qsort(a, n, sizeof(a[0]), &cmp);
    for(i = 0; i < n; i++)
    {
        f = false;
        for(j = 0; j < s; j++)
        {
            if(f) break;
            for(k = 0; k < s; k++)
            {
                if(!is_overlap(j, k, i))
                {
                    f = true;
                    p[i][0] = j;
                    p[i][1] = k;
                    break;
                }
            }
        }
        if(!f)
            return false;
    }
    return true;
}


int main()
{
    int t, i, j;
#ifdef _POJ
    freopen("poj1020.txt", "r", stdin);
#endif
    cin >> t;
    for(i = 0; i < t; i++)
    {
        cin >> s >> n;
        for(j = 0; j < n; j++)
            cin >> a[j];
        if(can_cut())
            cout << "KHOOOOB";
        else
            cout <<"HUTUTU";
        cout << "!" << endl;
    }
    return 0;
}
