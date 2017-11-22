#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i, j, n, r;
    int a[100][100];
    int dp[100] = {0};
    cin >> n;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
        for(j = i; j >= 1; j--)
            dp[j] = max(dp[j], dp[j - 1]) + a[i][j];
        dp[0] = dp[0] + a[i][0];
    }
    r = 0;
    for(i = 0; i < n; i++)
        if(dp[i] > r)
            r = dp[i];
    cout << r << endl;
    return 0;
}
