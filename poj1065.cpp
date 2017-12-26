#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
class Stick
{
    public:
        int length;
        int weight;
};

bool compare_length(Stick a, Stick b)
{
    return a.length < b.length;
}

bool compare_wight(Stick a, Stick b)
{
    return a.weight < b.weight;
}

int main()
{
    int T, n, c, t, r;
    Stick a[5000];
    bool vis[5000];
    vector<Stick> v;
    vector<Stick>::iterator it;
#ifdef _POJ
    freopen("poj1065.txt", "r", stdin);
#endif
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        v.clear();
        memset(vis, 0, sizeof(vis));
        r = c = 0;
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> a[j].length >> a[j].weight; 
        v.assign(a, a + n - 1);
        stable_sort(v.begin(), v.end(), compare_wight);
        stable_sort(v.begin(), v.end(), compare_length);
        while(c < n)
        {
            t = 0;
            while(vis[t]) t++;
            r++;
            vis[t] = true;
            c++;
            for(int j = t + 1; j < n; j++)
                if(a[j].length >= a[t].length && a[j].weight >= a[t].weight)
                {
                    vis[j] = true;
                    c++;
                }
        }
        cout << r << endl;
    }
    return 0;
}

