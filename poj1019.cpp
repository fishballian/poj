#include<iostream>
#include<cassert>
#include<climits>
#include<cmath>
using namespace std;
int a_len;
unsigned long a[100000];

void gen_array()
{
    int i, d;
    a[0] = 1;
    a_len = 1;
    i = 9;
    d = 1;
    for(a_len = 1; a_len < 100000; a_len++)
    {
        if(a_len >= i)
        {
            d++;
            i = i * 10 + 9;
        }
        a[a_len] = a[a_len - 1] + d;
    }
}

char get_index(int i, int p)
{
    int j;
    for(j = 0; j < p; j++)
        i /= 10;
    return '0' + i % 10;
}

char get_pos(int p)
{
    int d, u, i = 0;
    while(p > a[i])
    {
        p-=a[i];
        i++;
    }
    i = 0;
    while(p > a[i])
    {
        i++;
    }
    u = i + 1;
    return get_index(u, a[i] - p);
}

int main()
{
    int n, i;
    int p;
#ifdef _POJ
    freopen("poj1019.txt", "r", stdin);
#endif
    gen_array();
    //assert(get_pos(1) == '1');
    //assert(get_pos(9) == '3');
    //assert(get_pos(10) == '4');
    //assert(get_pos(11) == '1');
    //assert(get_pos(55) == '1');
    //assert(get_pos(3045) == '9');
    //assert(get_pos(2147483647) == '2');
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> p;
        cout << get_pos(p) << endl;
    }
    return 0;
}
