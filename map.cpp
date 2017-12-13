#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
    map<string, int> m;
    string *s = new string("dddd");
    m["ssss"] = 111;
    m[*s] = 2222;
    cout << m.find("ssss")->second << endl;
    cout << m.find("dddd")->second << endl;
    delete s;
    cout << m.find("dddd")->second << endl;
    cout << (m.find("ssss2") == m.end()) << endl;
    cout << (m.find("ssss") == m.end()) << endl;
    return 0;
}

