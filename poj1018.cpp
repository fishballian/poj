#include<iostream>
#include<climits>
#include<cstdlib>
#include<cstdio>
using namespace std;
int a[100][100][2];
int m[100];
int b[10000];
int n, bc;

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

float max_bp()
{
    int i, j, k, _min;
    int r[10000] = {0};
    float re;
    for(i = 0; i < bc; i++)
    {
        if(i > 0 && b[i] == b[i - 1])
        {
            r[i] = r[i - 1];
            continue;
        }
        for(j = 0; j < n; j++)
        {
            _min = INT_MAX;
            for(k = 0; k < m[j]; k++)
            {
                if(a[j][k][0] >= b[i] && a[j][k][1] < _min)
                {
                    _min = a[j][k][1];
                }
            }
            if(_min == INT_MAX)
            {
                r[i] = INT_MAX;
                break;
            }
            else
            {
                r[i] += _min;
            }
        }
    }
    re = 0;
    for(i = 0; i < bc; i++)
    {
        if(r[i] > 0 && r[i] <= INT_MAX)
        {
            re = max(re, float(b[i]) / r[i]);
        }
    }
    return re;
}

int main()
{
    int t, i, j, k;
#ifdef _POJ
    freopen("poj1018.txt", "r", stdin);
#endif
    cin >> t;
    for(i = 0; i < t; i++)
    {
        cin >> n;
        bc = 0;
        for(j = 0; j < n; j++)
        {
            cin >> m[j];
            for(k = 0; k < m[j]; k++)
            {
                cin >> a[j][k][0] >> a[j][k][1];
                b[bc++] = a[j][k][0];
            }
        }
        qsort(b, bc, sizeof(b[0]), &cmp); 
        printf("%.3f\n", max_bp());
    }
    return 0;
}
