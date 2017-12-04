#include<iostream>
#include<vector>
using namespace std;
class A
{
    public:
        A(int a) : data(a)
        {
            cout << "A init " << data << endl;
        }
        A(const A& b)
        {
            data = b.data;
            cout << "A copy " << data << endl;
        }
        ~A()
        {
            cout << "A delete " << data << endl;
        }
        int data;
};

vector<A> foo()
{
    vector<A> v;
    A a(1);
    v.push_back(a);
    return v;
}

int main()
{
    vector<A> vv;
    vv = foo();
    cout << "Program Terminate" << endl;
    return 0;
}

