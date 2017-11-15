#include<stdio.h>
#include<string.h>
#define MAX 151

int max(const int a, const int b){
    if(a > b)
        return a;
    else
        return b;
}

void add(char r[], const char a[], const char b[])
{
    int la = strlen(a);
    int lb = strlen(b);
    int len = max(la, lb);
    int carry = 0;
    int ai, bi, s;
    char t[MAX];
    t[len] = '\0';
    for(int i = 0; i < len; i++){
        ai = la - i - 1;
        bi = lb - i - 1;
        if(ai >= 0 && bi >= 0)
            s = a[ai] - '0' + b[bi] - '0' + carry;
        else if(ai >= 0)
            s = a[ai] - '0' + carry;
        else
            s = b[bi] - '0' + carry;
        t[len - i - 1] = s % 10 + '0';
        carry = s / 10;
    }
    if(carry > 0){
        strcpy(r, "1");
        strcat(r, t);
    }else
        strcpy(r, t);
}

void remove_heading_zero(char r[])
{
    int i,s,len;
    len = strlen(r);
    s = 0;
    for(i = 0; i < len; i++)
        if(r[i] == '0' && s == 0)
            continue;
        else
            r[s++] = r[i];
    r[s] = '\0';
}

void remove_tailing_zero(char r[])
{
    int i,s,len;
    len = strlen(r);
    s = 0;
    if(strchr(r, '.') != NULL){
        for(i = 0; i < len; i++)
            if(r[len - i - 1] == '0')
                r[len - i - 1] = '\0';
            else if(r[len - i -1] == '.'){
                r[len - i - 1] = '\0';
                break;
            }else
                break;
    }
    if(strcmp(r, "") == 0)
        strcpy(r, "0");
}

void multi_n(char r[], const char a[], const int n)
{
    int len = strlen(a);
    int i,s;
    int carry = 0;
    char t[MAX];
    t[len] = '\0';
    for(i = len - 1; i >= 0; i--){
        s = (a[i] - '0') * n + carry;
        t[i] = s % 10 + '0';
        carry = s / 10;
    }
    r[0] = '0' + carry;
    r[1] = '\0';
    strcat(r, t);
    remove_heading_zero(r);
}


void multi(char r[], const char a[], const char b[])
{
    int len = strlen(b);
    int n;
    char t[MAX];
    strcpy(r, "");
    for(int i = 0; i < len; i++){
        strcat(r, "0");
        n = b[i] - '0';
        multi_n(t, a, n);
        add(r, r, t);
    }
}

int remove_decimal(char a[])
{
    int len = strlen(a);
    int n = 0;
    int d = 100;
    for(int i = 0; i < len; i++)
        if(a[i] == '.')
            d = i;
        else
            a[n++] = a[i];
    a[n] = '\0';
    if(d == 100)
        return 0;
    else
        return len - d - 1;
}

void insert_decimal(char a[], int n)
{
    int i, j, l;
    int len = strlen(a);
    char t[MAX];
    if(len < n){
        l = n - len;
        t[0] = '.';
        for(j = 0; j < l; j++)
            t[1 + j] = '0';
        for(i = 0; i < len; i++)
            t[1 + j + i] = a[i];
        t[1 + j + i] = '\0';
    }else{
        l = len - n; 
        j = 0;
        for(i = 0; i < len; i++){
            if(l == i)
                t[j++] = '.';
            t[j++] = a[i];
        }
        t[j] = '\0';
    }
    strcpy(a, t);
}

void pow2(char r[], const char ta[], int n)
{
    if(n == 0)
        strcpy(r, "1");
    else{
        char t[MAX];
        char a[MAX];
        strcpy(a, ta);
        int d = remove_decimal(a);
        strcpy(r, "1");
        for(int i = 0; i < n; i++){
            strcpy(t, r);
            multi(r, t, a);
        }
        insert_decimal(r, d * n);
        remove_heading_zero(r);
        remove_tailing_zero(r);
    }
}


int main(int argc, char* argv[])
{
    char a[MAX];
    char r[MAX];
    int n;
    while(scanf("%s%d", a, &n)==2)
    {
        pow2(r, a, n);
        printf("%s\n", r);
    }
    return 0;
}

