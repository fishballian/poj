#include<iostream>
#include<vector>
using namespace std;
class A
{
    public:
        A(int a)
        {
            data = a;
            cout << "A init " << data << endl;
        }
        ~A()
        {
            cout << "A delete " << data << endl;
        }
    private:
        int data;
};

void foo()
{
    A a(1);
}

int main()
{
    int i;
    A b(2);
    A *p = new A(3);
    foo();
    cout << "Program Terminate" << endl;
    delete p;
    vector<int> v;
    for(i = 0; i < 10000; i++)
        v.push_back(i);
    cout << v.size() << endl;
    return 0;
}

