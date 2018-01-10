#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool line[4][4] = {0};
int girl[4] = {-1, -1, -1, -1};
bool used[4] = {0};
int all = 0;

bool find(int x)
{
    for(int i = 0; i < 4; i++)
    {
        if(line[x][i] && !used[i])
        {
            used[i] = true;
            if(girl[i] == -1 || find(girl[i]))
            {
                girl[i] = x;
                cout << i << "=" << x << endl;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    line[0][0] = true;
    line[0][1] = true;
    line[1][1] = true;
    line[1][2] = true;
    //line[2][0] = true;
    line[2][1] = true;
    line[3][2] = true;
    for(int i = 0; i < 4; i++)
    {
        memset(used, 0, sizeof(used));
        if(find(i)) all++;
    }
    int c = 0;
    for(int i = 0; i < 4; i++)
        if(girl[i] > -1) c++;
    cout << c << endl;
    return 0;
}

