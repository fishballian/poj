#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string s;
    string current("http://www.acm.org/");
    stack<string> f;
    stack<string> b;
#ifdef _POJ
    freopen("poj1028.txt", "r", stdin);
#endif
    while(cin >> s && s != "QUIT")
    {
        //cout << s << endl;
        if(s == "VISIT")
        {
            cin >> s;
            while(!f.empty())
                f.pop();
            b.push(current);
            current = s;
            cout << current << endl;
        }
        else if(s == "BACK")
        {
            if(!b.empty())
            {
                f.push(current);
                current = b.top();
                b.pop();
                cout << current << endl;
            }
            else
            {
                cout << "Ignored" << endl;
            }

        }
        else if(s == "FORWARD")
        {
            if(!f.empty())
            {
                b.push(current);
                current = f.top();
                f.pop();
                cout << current << endl;
            }
            else
            {
                cout << "Ignored" << endl;
            }
        }
        else
        {
            cout << "Unknown command" << endl;
        }
    }
    return 0;
}

