#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int a[20];
    for(int i = 0; i < 20; i ++)
        a[i] = rand() % 10000;
    sort(a, a + 20, cmp);
    for(int i = 0; i < 20; i ++)
        cout << a[i] << endl;
    return 0;
}

