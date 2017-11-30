#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    float vr, w, vs, r, c;
    int n, i;
#ifdef _POJ
    freopen("poj1045.txt", "r", stdin);
#endif
    cin >> vs >> r >> c >> n;
    for(i = 0; i < n; i++)
    {
        cin >> w;
        vr = c*r*w*vs/sqrt(1 + pow(c * r * w, 2));
        printf("%.3f\n", vr);
    }
    return 0;
}
