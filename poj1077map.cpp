#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<map>
#include<stack>
using namespace std;

map<string, char> m;
stack<string> sta;

bool move(string &s, char d)
{
    int i, x;
    for(i = 0; i < 9; i++)
        if(s[i] == 'x')
        {
            x = i;
            break;
        }

    switch(d)
    {
        case 'u':
            if(x <= 2)
                return false;
            s[x] = s[x - 3];
            s[x - 3] = 'x';
            break;
        case 'd':
            if(x >= 6)
                return false;
            s[x] = s[x + 3];
            s[x + 3] = 'x';
            break;
        case 'l':
            if(x % 3 <= 0)
                return false;
            s[x] = s[x - 1];
            s[x - 1] = 'x';
            break;
        case 'r':
            if(x % 3 >= 2)
                return false;
            s[x] = s[x + 1];
            s[x + 1] = 'x';
            break;
    }
    return true;
}

void constuct_map()
{
    string s = "12345678x";
    string top;
    m[s] = 's';
    sta.push(s);
    while(!sta.empty())
    {
        top = sta.top();
        sta.pop();
        s = top;
        if(move(s, 'u') && m.find(s) == m.end())
        {
            m[s] = 'd';
            sta.push(s);
        }

        s = top;
        if(move(s, 'd') && m.find(s) == m.end())
        {
            m[s] = 'u';
            sta.push(s);
        }

        s = top;
        if(move(s, 'l') && m.find(s) == m.end())
        {
            m[s] = 'r';
            sta.push(s);
        }
        
        s = top;
        if(move(s, 'r') && m.find(s) == m.end())
        {
            m[s] = 'l';
            sta.push(s);
        }
    }
}

int main()
{
    char s[2];
    string ori = "12345678x";
    int i;
    char dir;
#ifdef _POJ
    freopen("poj1077.txt", "r", stdin);
    string str = "12345678x";
    assert(true == move(str, 'u'));
    assert("12345x786" == str);
    assert(true == move(str, 'u'));
    assert("12x453786" == str);
    assert(false == move(str, 'u'));
    assert(true == move(str, 'l'));
    assert("1x2453786" == str);
    assert(true == move(str, 'l'));
    assert("x12453786" == str);
    assert(false == move(str, 'l'));
    assert(true == move(str, 'r'));
    assert("1x2453786" == str);
    assert(true == move(str, 'r'));
    assert("12x453786" == str);
    assert(false == move(str, 'r'));
    assert(true == move(str, 'd'));
    assert("12345x786" == str);
    assert(true == move(str, 'd'));
    assert("12345678x" == str);
    assert(false == move(str, 'd'));

#endif
    constuct_map();
    cout << m.size() << endl;
    while(scanf("%s", s) != EOF)
    {
        ori[0] = s[0];
        for(i = 1; i < 9; i++)
        {
            scanf("%s", s);
            ori[i] = s[0];
        }
        if(m.find(ori) == m.end())
            printf("unsolvable\n");
        else
        {
            while(ori != "12345678x")
            {
                dir = m.find(ori)->second;
                cout << dir;
                move(ori, dir);
            }
            cout << endl;
        }
    }
    return 0;
}

