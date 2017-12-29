#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n, k, a[200];
    char s[200];
#ifdef _POJ
    freopen("poj1026.txt", "r", stdin);
#endif
    while(cin >> n && n > 0)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        while(cin >> k && k > 0)
        {
            scanf("%[^\n]", s);
            cout << s << endl;
        }
    }
    return 0;
}

