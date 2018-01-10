#include<iostream>
#include<cstdio>
using namespace std;

int N, K;
int P[100];
char a[100][1001];

bool valid2(int g, bool heavier)
{
    int s1, s2, t;
    if(heavier)
        t = 3;
    else
        t = 1;
    for(int i = 0; i < K; i++)
    {
        s1 = s2 = 0;
        for(int j = 0; j < P[i]; j++)
        {
            if(a[i][j] - '0' == g)
                s1 += t;
            else
                s1 += 2;
        }
        for(int j = P[i]; j < 2 * P[i]; j++)
        {
            if(a[i][j] - '0' == g)
                s2 += t;
            else
                s2 += 2;
        }
        if(s1 < s2 && a[i][2 * P[i]] == '<')
            continue;
        if(s1 == s2 && a[i][2 * P[i]] == '=')
            continue;
        if(s1 > s2 && a[i][2 * P[i]] == '>')
            continue;
        return false;
    }
    return true;
}

bool valid(int g)
{
    return (valid2(g, true) || valid2(g, false));
}

int main()
{
    int i, j, r, c;
#ifdef _POJ
    freopen("poj1029.txt", "r", stdin);
#endif
    while(cin >> N >> K && !cin.eof())
    {
        for(i = 0; i < K; i++)
        {
            cin >> P[i];
            for(j = 0; j < 2 * P[i]; j++)
                cin >> a[i][j];
            cin >> a[i][j];
        }
        c = 0;
        for(i = 1; i <= N; i++)
        {
            if(valid(i))
            {
                r = i;
                c++;
            }
        }
        if(c == 1)
            cout << r << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}

