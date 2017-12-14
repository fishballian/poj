#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int T, N, mv[200][2];
#ifdef _POJ
    freopen("poj1083.txt", "r", stdin);
#endif
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N;
        for(int j = 0; j < N; j++)
        {
            cin >> mv[j][0] >> mv[j][1];
            if(mv[j][0] > mv[j][1])
                swap(mv[j][0], mv[j][1]);
        }
        cout << 10 * i + 10 << endl;
    }
    return 0;
}

