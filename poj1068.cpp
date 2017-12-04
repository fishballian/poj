#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int i, j, k, t, n, a, b, c, u;
    char s[40];
    stack<char> st;
#ifdef _POJ
    freopen("poj1068.txt", "r", stdin);
#endif
    cin >> t;
    for(i = 0; i < t; i++)
    {
        cin >> n;
        a = c = 0;
        for(j = 0; j < n; j++)
        {
            cin >> b;
            for(k = 0; k < b - a; k++)
            {
                s[c++] = '(';
            }
            st.push(')');
            u = 0;
            for(k = c - 1; k >= 0; k--)
            {
                if(s[k] == '(' && st.top() == ')')
                {
                    st.pop();
                    u++;
                    if(st.empty())
                    {
                        cout << u;
                        cout << " ";
                        break;
                    }
                }
                else
                {
                    st.push(s[k]);
                }

            }
            s[c++] = ')';
            a = b;
        }
        s[c] = '\0';
        //cout << s << endl;

        //cout << a[0];
        //for(j = 1; j < n; j++)
        //    cout << " " << a[j];
        cout << endl;
    }
    return 0;
}

