#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<queue>
#include<map>
#include<stack>
using namespace std;
char res[10000];
int count;

int calc(const string &s);
bool do_move(string &s, char d);

char revert(char dir)
{
    char mv = 'l';
    switch(dir)
    {
        case 'u':
            mv = 'd';
            break;
        case 'd':
            mv = 'u';
            break;
        case 'l':
            mv = 'r';
            break;
    }
    return mv;
}

class node
{
    public:
        node(){}
        node(string s, char mv, int len) : s(s), mv(mv), len(len){
            f = len + calc(s);
        }
        
        bool move(char dir)
        {
            if(do_move(s, dir))
            {
                len++;
                mv = dir;
                f = len + calc(s);
            }
            else
                return false;
        }
        string s;
        char mv;
        int len;
        int f;
};

bool operator< (const node &a, const node &b)
{
    return a.f > b.f;
}

bool astar_search(string str)
{
    priority_queue<node> openset;
    map<string, char> closeset;
    openset.push(node(str, 's', 0));
    node n, n2;
    string s2;
    int i, j, sum, count = 0;
    stack<int> st;
    char t;
    bool finish = false;
    while(!openset.empty())
    {
        n = openset.top();
        openset.pop();
        closeset[n.s] = n.mv;
        if(n.s == "12345678x")
        {
            finish = true;
            s2 = n.s;
            while(true)
            {
                if(closeset.find(s2) != closeset.end())
                {
                    t = closeset.find(s2)->second;
                    if(t == 's')
                        break;
                    st.push(t);
                    do_move(s2, revert(t));
                }
                else
                {
                    exit(-1);
                }
            }
            count = 0;
            while(!st.empty())
            {
                res[count++] = st.top();
                st.pop();
            }
            res[count++] = '\0';
            break;
        }
        n2 = n;
        if(n2.move('u') && closeset.find(n2.s) == closeset.end())
            openset.push(n2);
        n2 = n;
        if(n2.move('d') && closeset.find(n2.s) == closeset.end())
            openset.push(n2);
        n2 = n;
        if(n2.move('l') && closeset.find(n2.s) == closeset.end())
            openset.push(n2);
        n2 = n;
        if(n2.move('r') && closeset.find(n2.s) == closeset.end())
            openset.push(n2);
    }
    return finish;
}

int calc(const string &s)
{
    int i, n, sum;
    sum = 0;
    for(i = 0; i < 9; i++)
    {
        if(s[i] == 'x')
            n = 8;
        else
            n = s[i] - '1';
        sum += i != n;
    }
    return sum;
}

bool do_move(string &s, char d)
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

int main()
{
    char s[2];
    string ori = "12345678x";
    int i, j, sum;
    char dir;
#ifdef _POJ
    freopen("poj1077.txt", "r", stdin);
    assert(calc("12345678x") == 0);
    assert(calc("1234567x8") == 2);
    assert(calc("12345x786") == 2);
    char xx[40] = "dlurullddrurdllurdr";
    ori = "23415x768";
    for(i = 0; xx[i] != '\0'; i++)
    {
        assert(do_move(ori, xx[i]));
    }
    assert(ori == "12345678x");
#endif

    while(scanf("%s", s) != EOF && s[0] != '0')
    {
        ori[0] = s[0];
        for(i = 1; i < 9; i++)
        {
            scanf("%s", s);
            ori[i] = s[0];
        }
        //cout << ori << "==";
        sum = 0;
        for(i = 0; i < 8; i++)
            for(j = i + 1; j < 9; j++)
                if(ori[j] != 'x' && ori[i] != 'x' && ori[j] < ori[i])
                    sum++;
        if(sum % 2 == 1)
        {
            //assert(astar_search(ori) == false);
            cout << "unsolvable" << endl;
        }
        else if(ori == "12345678x")
        {
            printf("lr\n");
        }
        else if(astar_search(ori))
        {
            for(i = 0; res[i] != '\0'; i++)
            {
                assert(do_move(ori, res[i]));
            }
            assert(ori == "12345678x");
            cout << res << endl;
        }
        else
        {
            cout << "unsolvable" << endl;
        }
    }
    return 0;
}

