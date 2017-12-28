#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

#define MAXN 5000

int cmp(const void *a, const void *b)
{
    if(((int *)a)[0] == ((int *)b)[0])
        return ((int *)a)[1] - ((int *)b)[1];
    else
        return ((int *)a)[0] - ((int *)b)[0];
}

int main()
{
    int temp[MAXN];
    int a[MAXN][2];
    int T, n, sum;
    bool bz;
#ifdef _POJ
    freopen("poj1065.txt", "r", stdin);
#endif
    cin >> T;

    for(int i = 0; i < T; i ++)
    {
        cin >> n;
        for(int i = 0; i < n; i ++)
            cin >> a[i][0] >> a[i][1]; 
        qsort(a, n, sizeof(a[0]), &cmp);
        temp[0] = a[0][1];
        sum = 0;
        for(int i = 1; i < n; i ++)
        {
            bz = false;
            if(a[i][1] < temp[sum])
            {
                sum++;
                temp[sum] = a[i][1];
                bz = true;
            }
            else
            {
                for(int j = sum - 1; j >= 0; j --)
                {
                    if(a[i][1] < temp[j])
                    {
                        temp[j + 1] = max(temp[j + 1], a[i][1]);
                        bz = true;
                    }
                }
            }
            if(!bz)
                temp[0] = a[i][1];
        }
        cout << sum + 1 << endl;
    }
    return 0;
}
