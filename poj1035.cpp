#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<cstdlib>
using namespace std;


int cmp(const void * a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n, count, len, t;
    string tmp, tmp2;
    char s[30];
    int a[26 * 31];
    map<string, int> dict;
    string sa[10001];
#ifdef _POJ
    freopen("poj1035.txt", "r", stdin);
#endif
    dict.clear();
    n = 0;
    while(cin >> sa[n] && !cin.eof())
    {
        dict[sa[n]] = n;
        n++;
        while(cin >> sa[n] && sa[n][0] != '#')
        {
            dict[sa[n]] = n;
            n++;
        }
        while(cin >> tmp && tmp[0] != '#')
        {
            cout << tmp;
            if(dict.count(tmp) > 0)
            {
                cout << " is correct";
            }
            else
            {
                count = 0;
                for(int i = 0; i < tmp.size(); i++)
                {
                    tmp2 = tmp;
                    tmp2.erase(i, 1);
                    if(dict.count(tmp2) > 0)
                        a[count++] = dict[tmp2];
                }

                for(int i = 0; i < tmp.size(); i++)
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        tmp2 = tmp;
                        tmp2.replace(i, 1, 1, c);
                        if(dict.count(tmp2) > 0)
                            a[count++] = dict[tmp2];
                    }
                for(int i = 0; i <= tmp.size(); i++)
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        tmp2 = tmp;
                        tmp2.insert(i, 1, c);
                        if(dict.count(tmp2) > 0)
                            a[count++] = dict[tmp2];
                    }
                qsort(a, count, sizeof(a[0]), &cmp);
                cout << ":";
                t = -1;
                for(int i = 0; i < count; i++)
                    if(t != a[i])
                    {
                        cout << " " << sa[a[i]];
                        t = a[i];
                    }
            }
            cout << endl;
        }
        n = 0;
    }
    return 0;
}

