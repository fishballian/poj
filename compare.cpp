#include<iostream>
#include<cstdio>
using namespace std;

class A
{
    public:
        A(int a, int b) : a(a), b(b){}
        friend int compare(const A& a, const A& b);
    private:
        int a, b;
};

int compare(const A& a, const A& b)
{
    return a.a + a.b - (b.a + b.b);
}

int main()
{
    A a(1, 2);
    A b(2, 1);
    cout << compare(a, b) << endl;
    //cout << a==b << endl;
    return 0;
}

