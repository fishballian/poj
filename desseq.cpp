#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
#define LEN 5000
#define MAX 10000
int a[LEN];

void find()
{
    int temp[LEN];
    int sum = 0;
    temp[0] = a[0];
    for(int i = 1; i < LEN; i++)
    {
        if(a[i] >= temp[sum])
        {
            sum++;
            temp[sum] = a[i];
        }
        else
        {
            for(int j = sum - 1; j >= 0; j--)
                if(a[i] >= temp[j])
                    temp[j + 1] = min(temp[j + 1], a[i]);
        }
    }
    cout << sum + 1 << endl;
}

void find2()
{
    int **dp = new int*[LEN + 1];
    for(int i = 0; i < LEN + 1; i++)
        dp[i] = new int[LEN];
    for(int i = 0; i < LEN; i++)
        dp[LEN][i] = 0;
    //int dp[LEN + 1][LEN] = {0};
    for(int i = LEN - 1; i >= 0; i--)
        for(int j = 0; j < LEN; j++)
        {
            if(a[j] <= a[i])
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][i] + 1);
            else
                dp[i][j] = dp[i + 1][j];
        }
    cout << dp[0][0] << endl;
    for(int i = 0; i < LEN + 1; i++)
        delete dp[i];
    delete dp;
}

int main()
{
    for(int i = 0; i < LEN; i++)
        a[i] = rand() % MAX;
    //for(int i = 0; i < LEN; i++)
    //    cout << "=" <<  a[i] << endl;
    find();
    //find2();
    return 0;
}

