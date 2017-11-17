#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int Max = 65;

int n, len, stick[Max];
bool flag, vis[Max];

bool cmp(int a, int b){
    return a > b;
}

void dfs(int dep, int now_len, int u){   // dep为当前已被用过的小棒数，u为当前要处理的小棒。
    if(flag) return;
    if(now_len == 0){                    //  当前长度为0，寻找下一个当前最长小棒。
        int k = 0;
        while(vis[k]) k ++;              //  寻找第一个当前最长小棒。
        vis[k] = true;
        dfs(dep + 1, stick[k], k + 1);
        vis[k] = false;
        return;
    }
    if(now_len == len){                  //  当前长度为len，即又拼凑成了一根原棒。
        if(dep == n) flag = true;        //  完成的标志：所有的n根小棒都有拼到了。
        else dfs(dep, 0, 0);
        return;
    }
    for(int i = u; i < n; i ++)
        if(!vis[i] && now_len + stick[i] <= len){
            if(!vis[i-1] && stick[i] == stick[i-1]) continue;      //  不重复搜索：最重要的剪枝。
            vis[i] = true;
            dfs(dep + 1, now_len + stick[i], i + 1);
            vis[i] = false;
        }
}

int main(){
    while(scanf("%d", &n) && n != 0){
        int sum = 0;
        flag = false;
        for(int i = 0; i < n; i ++){
            scanf("%d", &stick[i]);
            sum += stick[i];
        }
        sort(stick, stick + n, cmp);     //  从大到小排序。
        for(len = stick[0]; len < sum; len ++)
            if(sum % len == 0){          //  枚举能被sum整除的长度。
                memset(vis, 0, sizeof(vis));
                dfs(0, 0, 0);
                if(flag) break;
            }
        printf("%d\n", len);
    }
    return 0;
}
