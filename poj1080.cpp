#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int T, n1, n2;
char s1[101];
char s2[101];
int m;
int matrix[5][5] = {{5, -1, -2, -1, -3}, {-1, 5, -3, -2, -4}, {-2, -3, 5, -2, -2}, {-1, -2, -2, 5, -1}, {-3, -4, -2, -1, 0}};
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

void dfs(int d1, int d2, int score)
{
    int t;
    if(d1 == n1 && d2 == n2)
    {
        if(score > m)
            m = score;
        return;
    }
    //pick 1
    if(d1 < n1)
    {
        t = get_score(s1[d1], '-');
        dfs(d1 + 1, d2, score + t);
    }
    //pick 2
    if(d2 < n2)
    {
        t = get_score(s2[d2], '-');
        dfs(d1, d2 + 1, score + t);
    }
    //pick 1,2
    if(d1 < n1 && d2 < n2)
    {
        t = get_score(s1[d1], s2[d2]);
        dfs(d1 + 1, d2 + 1, score + t);
    }
}

int main()
{
#ifdef _POJ
    freopen("poj1080.txt", "r", stdin);
#endif
    cin >> T;
    for(int i = 0 ; i < T; i++)
    {
        m = INT_MIN;
        cin >> n1 >> s1;
        cin >> n2 >> s2;
        dfs(0, 0, 0);
        cout << m << endl;
    }
    return 0;
}

