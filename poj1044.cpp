#include<iostream>
using namespace std;

int find_actual(int a[20][3], int n)
{
    int i, diff, guess;
    bool f;
    diff = a[0][2] - a[0][1];
    guess = a[0][0];
    while(guess < 10000)
    {
        f = true;
        for(i = 1; i < n; i++)
        {
            if(guess < a[i][0] || (guess - a[i][0]) % (a[i][2] - a[i][1]) != 0)
            {
                f = false;
                break;
            }
        }
        if(f)
            return guess;
        guess += diff;
    }
    return -1;
}

int main()
{
    int n, i;
    int a[20][3];
    int c = 0;
    int actual;
#ifdef _POJ
    freopen("poj1044.txt", "r", stdin);
#endif
    while(cin >> n && n > 0)
    {
        for(i = 0; i < n; i++)
            cin >> a[i][0] >> a[i][1] >> a[i][2];

        cout << "Case #" << c + 1 << ":" << endl;
        actual = find_actual(a, n);
        if(actual == -1)
            cout << "Unknown bugs detected." << endl;
        else
            cout << "The actual year is " << actual << "." << endl;
        cout << endl;
        c++;
    }
    return 0;
}

