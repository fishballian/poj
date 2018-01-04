#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int T, n1, n2;
char s1[101];
char s2[101];
int matrix[5][5] = {{5, -1, -2, -1, -3}, {-1, 5, -3, -2, -4}, {-2, -3, 5, -2, -2}, {-1, -2, -2, 5, -1}, {-3, -4, -2, -1, 0}};
int dp[2][101];

int index(char a)
{
    switch(a) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        case '-':
            return 4;
    }
}

int get_score(char a, char b)
{
    return matrix[index(a)][index(b)];
}

int mmax(int a, int b, int c)
{
    if(a >= b && a >= c)
        return a;
    else if(b >= a && b >= c)
        return b;
    else
        return c;
}

int main()
{
#ifdef _POJ
    freopen("poj1080.txt", "r", stdin);
#endif
    cin >> T;
    for(int i = 0 ; i < T; i++)
    {
        cin >> n1 >> s1;
        cin >> n2 >> s2;
        for(int j = n1; j >= 0; j --)
        {
            for(int k = n2; k >= 0; k--)
            {
                if(j == n1 && k == n2)
                    dp[j % 2][k] = 0;
                else if(j == n1)
                    dp[j % 2][k] = dp[j % 2][k + 1] + get_score(s2[k], '-');
                else if(k == n2)
                    dp[j % 2][k] = dp[(j + 1) % 2][k] + get_score(s1[j], '-');
                else
                    dp[j % 2][k] = mmax(
                            dp[(j + 1) % 2][k + 1] + get_score(s1[j], s2[k]),
                            dp[(j + 1) % 2][k] + get_score(s1[j], '-'),
                            dp[j % 2][k + 1] + get_score(s2[k], '-'));
            }
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}

