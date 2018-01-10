#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int N, n, t;
    int a[1000];
#ifdef _POJ
    freopen("poj1032.txt", "r", stdin);
#endif
    while(cin >> N && !cin.eof())
    {
        for(int i = 0; i < 1000; i ++)
        {
            N -= i + 2;
            if(N < 0)
            {
                N += i + 2;
                n = i;
                break;
            }
            a[i] = i + 2;
        }
        for(int i = n - 1; i >= 0; i --) 
        {
            t = ceil((double)N / (i + 1));
            a[i] += t;
            N -= t;
        }
        for(int i = 0; i < n; i ++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}

