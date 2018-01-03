#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n, k, a[200];
    int tran[200][201];
    char s[201];
    char s2[201];
    int t, c;
#ifdef _POJ
    freopen("poj1026.txt", "r", stdin);
#endif
    while(cin >> n && n > 0)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
        {
            t = a[i] - 1;
            c = 1;
            while(t != i)
            {
                tran[i][c] = t;
                c++;
                t = a[t] - 1;
            }
            tran[i][0] = c;
        }
        while(cin >> k && k > 0)
        {
            getchar();
            scanf("%[^\n]", s);
            for(int i = strlen(s); i < n; i++)
                s[i] = ' ';
            s[n] = '\0';
            for(int i = 0; i < n; i++)
            {
                t = k % tran[i][0];
                if(t == 0)
                    t = i;
                else
                   t =  tran[i][t];
                s2[t] = s[i];
            }
            s2[n] = '\0';
            cout << s2 << endl;
        }
        cout << endl;
    }
    return 0;
}

