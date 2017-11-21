#include<iostream>
#include<cstring>
using namespace std;

int coin[12];
char lc[3][13];
char rc[3][13];
char re[3][5];

int count_wight(const char *, const int);


int is_solution(int r, int is_light)
{
    int i, w1, w2;
    memset(coin, 0, sizeof(coin));
    coin[r] = 1;
    for(i = 0; i < 3; i++)
    {
        w1 = count_wight(lc[i], is_light);
        w2 = count_wight(rc[i], is_light);
        if(w1 > w2 && strcmp(re[i], "up") == 0)
            continue;
        else if(w1 == w2 && strcmp(re[i], "even") == 0)
            continue;
        else if(w1 < w2 && strcmp(re[i], "down") == 0)
            continue;
        else
            return 0;
    }
    return 1;
}

int count_wight(const char *s, const int is_light)
{
    int i, len = strlen(s);
    int sum = 0;
    for(i = 0; i < len; i++)
    {
        if(coin[s[i] - 'A'] == 0)
            sum+=2;
        else
            if(is_light == 0)
                sum+=3;
            else
                sum+=1;
    }
    return sum;
}

int main()
{
    int i, n, j, k, f, r, is_light;
    char s[6];
    cin >> n;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cin>>lc[j]>>rc[j]>>re[j];
        }
        f = 0;
        for(j = 0; j < 12; j++)
        {
            if(f == 1) break;
            for(k = 0; k < 2; k++)
            {
                if(is_solution(j, k))
                {
                    f = 1;
                    r = j;
                    is_light = k;
                    break;
                }
            }
        }
        if(is_light)
            strcpy(s, "light");
        else
            strcpy(s, "heavy");
        cout << (char)(r + 'A') << " is the counterfeit coin and it is " << s << "." << endl;

    }
    return 0;
}
