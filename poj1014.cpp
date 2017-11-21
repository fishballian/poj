#include<iostream>
using namespace std;
int a[6];
bool f;
int sum;

void dfs(int, int);

bool can_divide()
{
    int i, l, r, n;
    sum = 0;
    for(i = 0; i < 6; i++)
    {
        n = 6;
        if(a[i] > n)
        {
            a[i] = a[i] - n;
            a[i] = a[i] % 2 + n;
        }
        sum += a[i] * (i + 1);
    }
    if(sum % 2 != 0)
        return false;
    sum = sum / 2;
    f = false;
    dfs(0, 5);
    return f;
}

void dfs(int acc, int u)
{
    int i;
    if(f == true)
        return;
    if(acc == sum)
    {
        f = true;
        return;
    }
    for(i = u; i >= 0; i--)
    {
        if(a[i] > 0 && acc + i + 1 <= sum)
        {
            a[i]--;
            dfs(acc + i + 1, i);
            a[i]++;
        }
    }
}

int main()
{
    int n = 0;
    int i;
    int end;
    while(true)
    {
        n++;
        end = true;
        for(i = 0; i < 6; i++)
        {
            cin >> a[i];
            if(a[i] != 0) end = false;
        }
        if(end) break;

        cout << "Collection #" << n << ":" << endl;
        cout << "Can";
        if(!can_divide())
            cout << "'t";
        cout << " be divided."<< endl << endl;
    }
    return 0;
}
