#include<iostream>
#include<cstring>
using namespace std;
int n, s;
int c[11];
int d[40];
bool r;

void dfs(int deep)
{
    int i, k, put, p;
    bool f;
    if(deep == n)
    {
        r = true;
        return;
    }
    put = 41;
    for(i = 0; i < s; i++)
    {
		if(d[i] < put)
        {
            put = d[i];
            p = i;
        }
    }
    for(i = 10; i > 0; i--)
    {
        if(c[i] > 0 && d[p] + i <= s && p + i <= s)
        {
            f = true;
            for(k = p + 1; k < p + i; k++)
            {
                if(d[k] != d[p]) 
                {
                    f = false;
                    break;
                }
            }
            if(f)
            {
                for(k = p; k < p + i; k++) d[k] += i;
                c[i]--;
                dfs(deep + 1);
                c[i]++;
                for(k = p; k < p + i; k++) d[k] -= i;
            }
        }
    }
}

bool can_cut()
{
    int i, sum;
    sum = 0;
    for(i = 1; i <= 10; i++)
    {
        sum += i * i * c[i];
    }
    if(sum != s * s)
        return false;
    memset(d, 0, sizeof(d));
    r = false;
    dfs(0);
    return r;
}

int main()
{
    int t, i, j, tmp, sum;
#ifdef _POJ
    freopen("poj1020.txt", "r", stdin);
#endif
    cin >> t;
    for(i = 0; i < t; i++)
    {
        cin >> s >> n;
        memset(c, 0, sizeof(c));
        for(j = 0; j < n; j++)
        {
            cin >> tmp;
            c[tmp] ++;
        }
        if(can_cut())
            cout << "KHOOOOB";
        else
            cout <<"HUTUTU";
        cout << "!" << endl;
    }
    return 0;
}
