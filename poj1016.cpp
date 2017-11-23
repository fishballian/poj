#include<iostream>
#include<cstring>
using namespace std;
void transform(char *n)
{
    int c[10] = {0};
    int i, j, len;
    len = strlen(n);
    for(i = 0; i < len; i++)
        c[n[i] - '0']++;
    j = 0;
    for(i = 0; i < 10; i++)
    {
        if(c[i] > 0)
        {
            if(c[i] >= 10)
            {
                n[j++] = c[i] / 10 + '0';
                n[j++] = c[i] % 10 + '0';
            }
            else
            {
                n[j++] = c[i] + '0';
            }
            n[j++] = i + '0';
        }
    }
    n[j] = '\0';
}

int main()
{
    int i, j;
    bool f;
    char n[81];
    char t[16][81];
#ifdef _POJ
    freopen("poj1016.txt", "r", stdin);
#endif
    while(cin >> n && strcmp(n, "-1") != 0)
    {
        cout << n;
        strcpy(t[0], n);
        i = 0;
        f = false;
        while(i < 15)
        {
            strcpy(t[i + 1], t[i]);
            transform(t[i + 1]);
        //    cout << t << endl;
            for(j = 0; j < i + 1; j++)
            {
                if(strcmp(t[j], t[i + 1]) == 0)
                {
                    if(j == 0 && i == 0)
                    {
                        f = true;
                        cout << " is self-inventorying";
                    }
                    else if(j == i)
                    {
                        f = true;
                        cout << " is self-inventorying after " << i << " steps";
                    }
                    else
                    {
                        f = true;
                        cout << " enters an inventory loop of length " << i + 1 - j;
                    }
                    break;
                }
            }
            if(f)
                break;
            i++;
        }
        if(i == 15)
            cout << " can not be classified after 15 iterations";
        cout << endl;
    }
    return 0;
}
