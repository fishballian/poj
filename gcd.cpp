#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    return b?gcd(b, a % b):a;
}

int exgcd(int a, int b, int &x, int &y)
{
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    int q = exgcd(b, a % b, y, x);
    y -= a/b * x;
    return q;
}

int main()
{
    cout << "gcd(6, -2)=" << gcd(6, -2) << endl;
    cout << "gcd(5, -1)=" << gcd(5, -1) << endl;
    cout << "gcd(12, 8)=" << gcd(12, 8) << endl;
    cout << "gcd(8, 12)=" << gcd(8, 12) << endl;
    int x, y;
    cout <<  exgcd(8, 12, x, y) << " = " << x << " * 8" << " + " << y  << " * 12" << endl;
    cout <<  exgcd(-1, 5, x, y) << " = " << x << " * -1" << " + " << y  << " * 5" << endl;
    cout << -1 % -5 << endl;
    return 0;
}

