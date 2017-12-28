#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
#define LEN 20000
#define MAX 10000
int a[LEN];

void find()
{
    int temp[LEN];
    int sum = 0;
    bool bz;
    temp[0] = a[0];
    for(int i = 1; i < LEN; i++)
    {
        bz = false;
        if(a[i] >= temp[sum])
        {
            sum++;
            temp[sum] = a[i];
            bz = true;
        }
        else
        {
            for(int j = sum - 1; j >= 0; j--)
                if(a[i] >= temp[j])
                {
                    temp[j + 1] = min(temp[j + 1], a[i]);
                    bz = true;
                    break;
                }
        }
        if(!bz)
            temp[0] = a[i]; 
    }
    cout << sum + 1 << endl;
}

void find2()
{
    int m = 0;
    int dp[LEN] = {0};
    for(int i = LEN - 1; i >= 0; i--)
        for(int j = 0; j < LEN; j++)
            if(a[j] <= a[i] && i != j)
                dp[j] = max(dp[j], dp[i] + 1);
    for(int i = 0; i < LEN; i ++)
        m = max(dp[i], m);
    cout << m << endl;
}

int main()
{
    for(int i = 0; i < LEN; i++)
        a[i] = rand() % MAX;
    find();
    cout << "====" << endl;
    find2();
    return 0;
}

