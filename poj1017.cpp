#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a[6];
    int i, n, left, left2, use2;
    bool end;
#ifdef _POJ
    freopen("poj1017.txt", "r", stdin);
#endif
    while(true)
    {
        end = true;
        for(i = 0; i < 6; i++)
        {
            cin >> a[i];
            if(a[i] != 0)
                end = false;
        }
        if(end)
            break;
        n = a[5] + a[4] + a[3];
        a[0] = max(0, a[0] - 11 * a[4]);
        a[1] = max(0, a[1] - 5 * a[3]);
        n += ceil(a[2] / 4.0);
        left = a[2] % 4;
        switch(left){
            case 0:
                break;
            case 1:
                use2 = min(5, a[1]);
                a[1] -= use2;
                a[0] = max(0, a[0] - (36 - 4 *use2));
                break;
            case 2:
                use2 = min(3, a[1]);
                a[1] -= use2;
                a[0] = max(0, a[0] - (36 - 4 *use2));
                break;
            case 3:
                use2 = min(1, a[1]);
                a[1] -= use2;
                a[0] = max(0, a[0] - (36 - 4 *use2));
                break;
        }
        n += ceil((a[0] + 4 * a[1]) / 6.0);
        cout << n << endl;
    }
    return 0;
}
