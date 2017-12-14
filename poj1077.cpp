#include<iostream>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<set>
#include<climits>
using namespace std;
#define FOUND -1
#define NOT_FOUND -2
const char ALL_MVS[4] = {'u', 'd', 'l', 'r'};

typedef struct
{
    int state;
    char m;
} Node;


int search(Node path[1000], int &count, set<int> &closeset, int g, int bound);

inline int mabs(int a)
{
    return a < 0 ? -a : a;
}

int h(int State)
{
    int i, t, sum = 0;
    for(i = 1; i <= 9; i++)
    {
        t = State % 10 - 1;
        State /= 10; 
        if(t != 8)
            sum += mabs((9 - i) / 3 - t /3) + mabs((9 - i) % 3 - t % 3);
    }
    return sum;
}

int mv(int State, char dir)
{
    int i, a[9], x;
    for(i = 8; i >= 0; i--)
    {
        a[i] = State % 10;
        if(a[i] == 9)
            x = i;
        State /= 10;
    }
    switch(dir)
    {
        case 'u':
            if(x <= 2)
                return 0;
            a[x] = a[x - 3];
            a[x - 3] = 9;
            break;
        case 'd':
            if(x >= 6)
                return 0;
            a[x] = a[x + 3];
            a[x + 3] = 9;
            break;
        case 'l':
            if(x % 3 == 0)
                return 0;
            a[x] = a[x - 1];
            a[x - 1] = 9;
            break;
        case 'r':
            if(x % 3 == 2)
                return 0;
            a[x] = a[x + 1];
            a[x + 1] = 9;
            break;
    }
    x = 0;
    for(i = 0; i < 9; i++)
        x = 10 * x + a[i];
    return x;
}

inline bool is_goal(int State)
{
    return State == 123456789;
}

int ida_star(int root)
{
    int t, i, count, bound = h(root);
    set<int> closeset;
    Node path[1000];
    Node rn = {root, 's'};
    count = 0;
    path[count++] = rn;
    closeset.insert(root);
    while(true)
    {
        t = search(path, count, closeset, 0, bound);
        if(t == FOUND) 
        {
            for(i = 1; i < count; i++)
                cout << path[i].m;
            cout << endl;
            return bound;
        }
        if(t == INT_MAX) return NOT_FOUND;
        bound = t;
    }
}

int successors(Node success_states[4], int state)
{
    int c = 0;
    int i, NewState;
    Node n;
    for(i = 0; i < 4; i++)
    {
        NewState = mv(state, ALL_MVS[i]);
        if(NewState != 0)
        {
            n.state = NewState;
            n.m = ALL_MVS[i];
            success_states[c++] = n;
        }
    }
    return c;
}

int search(Node path[1000], int &count, set<int> &closeset, int g, int bound)
{
    Node succ, n = path[count - 1];
    int state = n.state;
    int f = g + h(state);
    int min = INT_MAX;
    int i, t, c;
    Node success_states[4];
    char mvs[4];
    if(f > bound) return f;
    if(is_goal(state)) return FOUND;
    c = successors(success_states, state);
    for(i = 0; i < c; i++)
    {
        succ = success_states[i];
        if(closeset.count(succ.state) == 0)
        {
            path[count++] = succ;
            closeset.insert(succ.state);
            t = search(path, count, closeset, g + 1, bound);
            if(t == FOUND) return FOUND;
            if(t < min) min = t;
            count--;
            closeset.erase(succ.state);
        }

    }
    return min;
}

bool solvable(int state)
{
    int i, j, sum = 0;
    int a[9];
    for(i = 8; i >= 0; i--)
    {
        a[i] = state % 10;
        state /= 10;
    }
    for(i = 0; i < 8; i++)
        for(j = i; j < 9; j++)
            if(a[j] < a[i] && a[i] != 9)
                sum++;
    return sum % 2 == 0;
}

int main()
{
    char tmp;
    int root, i;
#ifdef _POJ
    freopen("poj1077.txt", "r", stdin);
    assert(h(123456789) == 0);
    assert(h(123456798) == 1);
    assert(h(129456783) == 2);

    assert(mv(123456789, 'u') == 123459786);
    assert(mv(123456789, 'd') == 0);
    assert(mv(123456789, 'l') == 123456798);
    assert(mv(123456789, 'r') == 0);
#endif
    while(cin >> tmp && !cin.eof() && tmp != '0')
    {
        if(tmp == 'x')
            tmp = '9';
        root = tmp - '0';
        for(i = 1; i < 9; i++)
        {
            cin >> tmp;
            if(tmp == 'x')
                tmp = '9';
            root = 10 * root + tmp - '0';
        }
        if(solvable(root))
            ida_star(root);
        else
            cout << "unsolvable" << endl;
    }
    return 0;
}

