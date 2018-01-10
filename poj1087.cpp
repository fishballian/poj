#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n, m, k;
    char r[100][25];
    char d[100][2][25];
    char a[100][2][25];
#ifdef _POJ
    freopen("poj1087.txt", "r", stdin);
#endif
    while(cin >> n && !cin.eof())
    {
        for(int i = 0; i < n; i ++)
            cin >> r[i];
        cin >> m;
        for(int i = 0; i < m; i++)
            cin >> d[i][0] >> d[i][1];
        cin >> k;
        for(int i = 0; i < k; i++)
            cin >> a[i][0] >> a[i][1];
        cout << m - n << endl;
    }
    return 0;
}

