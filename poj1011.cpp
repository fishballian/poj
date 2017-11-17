#include <iostream>
#include <cstring>
 
using namespace std;
 
int in[51]; //长度为i的片段个数
int length; //棒子的原始长度
int finish; //终止标志（非0即终止）
/**
 * 遍历
 * @param count 棒子的总数（如果为0，则结束）
 * @param len 目前检查的棒子长度的剩余量
 * @param plen 现在检查的片段长度
 */
void check(int count, int len, int plen)
{
    --in[plen]; //取一个长度是plen的片段来用
    if (count == 0)
        finish = 1;
    if (!finish)
    {
        len -= plen;
        if (len != 0)
        {
            int next_plen = min(len, plen); //剪枝策略：用plen去凑len，next_plen必须是较小者
            for (; next_plen > 0; --next_plen)
                if (in[next_plen])  //有剩余
                    check(count, len, next_plen);
        }
        else
        {
            //片段长度最大为50
            int max = 50;
            while (!in[max])
                --max;
            check(count - 1, length, max);
        }
    }
    ++in[plen]; //恢复原始状态
}
 
 
int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        memset(in, 0, sizeof(in));
        int sum = 0;
        int max = 0;
        finish = 0;
        while (n--)
        {
            int b;
            scanf("%d", &b);
            ++in[b];
            sum += b;
            if (max < b)
                max = b;
        }
        length = max;
        while (true)
        {
            if (sum % length == 0)
                check(sum / length, length, max);
            if (finish)
                break;
            ++length;
        }
        printf("%d\n", length);
    }
}
