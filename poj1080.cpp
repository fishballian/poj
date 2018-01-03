#include<iostream>
#include<cstdio>
#include<climits>
#include<stack>
#include<set>
using namespace std;
#define FOUND -1
#define NOT_FOUND -2

int T, n1, n2;
char s1[101];
char s2[101];
int matrix[5][5] = {{5, -1, -2, -1, -3}, {-1, 5, -3, -2, -4}, {-2, -3, 5, -2, -2}, {-1, -2, -2, 5, -1}, {-3, -4, -2, -1, 0}};

typedef struct
{
    int d1;
    int d2;
} Node;

int index(char a)
{
    switch(a) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        case '-':
            return 4;
    }
}

int get_score(char a, char b)
{
    return matrix[index(a)][index(b)];
}

int cost(const Node& n1, const Node& n2)
{
    int s = 0;
    if(n1.d1 < n2.d1 && n1.d2 < n2.d2)
        return 6 - get_score(s1[n2.d1 - 1], s2[n2.d2 - 1]);
    else if(n1.d1 < n2.d1)
        return 6 - get_score(s1[n2.d1 - 1], '-');
    else
        return 6 - get_score(s2[n2.d2 - 1], '-');
}

bool is_goal(const Node &n)
{
    return n.d1 == n1 && n.d2 == n2;
}

int H(const Node &n)
{
    return 0;
}

int successors(const Node &n, Node a[3])
{
    int c = 0;
    Node new_node;
    if(n.d1 < n1)
    {
        new_node.d1 = n.d1 + 1;
        new_node.d2 = n.d2;
        a[c] = new_node;
        c++;
    }

    if(n.d2 < n2)
    {
        new_node.d1 = n.d1;
        new_node.d2 = n.d2 + 1;
        a[c] = new_node;
        c++;
    }

    if(n.d1 < n1 && n.d2 < n2)
    {
        new_node.d1 = n.d1 + 1;
        new_node.d2 = n.d2 + 1;
        a[c] = new_node;
        c++;
    }
    return c;
}

int search(stack<Node> &path, int g, int bound)
{
    Node n = path.top();
    Node a[3];
    int c, m, t, f;
    f = g + H(n);
    if(f > bound) return f;
    if(is_goal(n)) return FOUND;
    c = successors(n, a);
    m = INT_MAX;
    for(int i = 0; i < c; i++)
    {
        path.push(a[i]);
        t = search(path, g + cost(n, a[i]), bound);
        if(t == FOUND) return FOUND;
        if(t < m) m = t;
        path.pop();
    }
    return m;
}

int ida_star(Node root, stack<Node> &path)
{
    int t, bound = H(root);
    while(!path.empty())
        path.pop();
    path.push(root);
    while(true)
    {
        t = search(path, 0, bound);
        if(t == FOUND) return bound;
        if(t == INT_MAX) return NOT_FOUND;
        bound = t;
    }
}



int main()
{
    int s;
    Node root, pre;
    stack<Node> path;
#ifdef _POJ
    freopen("poj1080.txt", "r", stdin);
#endif
    cin >> T;
    for(int i = 0 ; i < T; i++)
    {
        cin >> n1 >> s1;
        cin >> n2 >> s2;
        root.d1 = 0;
        root.d2 = 0;
        ida_star(root, path);
        pre = path.top();
        path.pop();
        s = 0;
        while(!path.empty())
        {
            root = path.top();
            path.pop();
            //cout << root.d1 << " " << root.d2 << endl;
            if(pre.d1 > root.d1 && pre.d2 > root.d2)
                s += get_score(s1[pre.d1 - 1], s2[pre.d2 - 1]);
            else if(pre.d1 > root.d1)
                s += get_score(s1[pre.d1 - 1], '-');
            else
                s += get_score(s2[pre.d2 - 1], '-');
            pre = root;
        }
        cout << s << endl;
    }
    return 0;
}

