#include <iostream>
#include <cassert>
#include <cstdio>
using namespace std;


int main()
{
#ifdef _POJ
    freopen("poj1029.txt","r",stdin);
#endif
    while( true ){
        int N,K;
        if( scanf("%d %d",&N,&K) == EOF )
            break;
        int total = 0;
        bool unfake[1001] = { false };
        int heavy_times[1001] = { 0 };
        int light_times[1001] = { 0 };
        int num[1001];
        int nums;
        for(int k=0; k<K; ++k)
        {
            scanf("%d",&nums);
            for(int i=0; i<2*nums; ++i)
                scanf("%d",&num[i]);
            char tmp;
            scanf(" %c",&tmp);
            assert( tmp == '=' || tmp == '<' || tmp == '>' );
            if( tmp == '=' )
            {
                for(int i=0; i<2*nums; ++i)
                    unfake[ num[i] ] = true;
            }
            else if( tmp == '<' )
            {
                ++total;
                for(int i=0; i<nums; ++i)
                    light_times[ num[i] ]++;
                for(int i=nums; i<2*nums; ++i)
                    heavy_times[ num[i] ]++;
            }
            else if( tmp == '>' )
            {
                ++total;
                for(int i=0; i<nums; ++i)
                    heavy_times[ num[i] ]++;
                for(int i=nums; i<2*nums; ++i)
                    light_times[ num[i] ]++;
            }
        }
        int res_nums = 0;
        int res_ind = -1;
        for(int i=1; i<=N; ++i)
        {
            if( unfake[i] )
                continue;
            if( heavy_times[i] != 0 && light_times[i] != 0 )
                continue;
            else if( heavy_times[i] == 0 && light_times[i] == 0 )  //i既没有出现在等式中也没有出现在> 和<等式中
            {
                if( total == 0 )   //没有不等式
                {
                    ++res_nums;
                    res_ind = i;
                }
            }
            else//heavy_times[i]和light_times[i]当中仅有一个为0另一个为非0
            {
                if( total == heavy_times[i] )
                {
                    ++res_nums;
                    res_ind = i;
                }
                //if( total == light_times[i] )
                else if( total == light_times[i] )
                {
                    ++res_nums;
                    res_ind = i;
                }
            }
        }
        if( res_nums == 1 )
            printf("%d\n",res_ind);
        else
            printf("0\n");
    }
    return 0;
}


