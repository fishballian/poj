#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1; y=0;
        return a;
    }
    LL t=exgcd(b,a%b,x,y);

    LL xx=x;
    x=y;
    y=xx-a/b*y;

    return t;
}

int main()
{
    LL x,y,m,n,mod;
#ifdef _POJ
    freopen("poj1061.txt", "r", stdin);
#endif
    while(~scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&mod))
    {
        if(m==n) puts("Impossible");
        else
        {
            if(m<n) swap(m,n),swap(x,y);
            LL a,k;
            LL c=y-x;
            LL d=exgcd(m-n,mod,a,k);

            if(c%d) printf("Impossible\n");
            else printf("%lld\n",((a*c/d)%(mod/d)+(mod/d))%(mod/d));
        }
    }
    return 0;
}
