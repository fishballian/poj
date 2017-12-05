#include<iostream>
#include<cstdio>
#include<cassert>
using namespace std;
#define MAX 1000


class MinHeap
{
    public:
        void push(const int k)
        {
            insert_heap_tail(k);
        }

        int pop()
        {
            int res = entry[0];
            count--;
            insert_heap(entry[count], 0, count - 1);
            return res;
        }

        bool empty()
        {
            return count == 0;
        }

    private:
        void insert_heap(int current, int low, int high)
        {
            int small = 2 * low + 1;
            while(small <= high)
            {
                if(small + 1 <= count && entry[small + 1] < entry[small])
                    small++;
                if(current <= entry[small])
                    break;
                else
                {
                    entry[low] = entry[small];
                    low = small;
                    small = 2 * low + 1;
                }
            }
            entry[low] = current;
        }

        void insert_heap_tail(int current)
        {
            int low;
            int high = count;
            while(high > 0)
            {
                low = (high - 1) / 2;
                if(entry[low] <= current)
                    break;
                else
                {
                    entry[high] = entry[low];
                    high = low;
                }
            }
            entry[high] = current;
            count++;
        }

        int entry[MAX];
        int count = 0;
};


int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    MinHeap h;
    int i, j;
    int a[1000];
    for(j = 0; j < 1000000; j++)
    {
        for(i = 0; i < 100; i ++)
        {
            a[i] = rand();
            h.push(a[i]);
        }
        qsort(a, 100, sizeof(a[0]), &cmp);
        for(i = 0; i < 100; i++)
        {
            assert(a[i] == h.pop());
        }
    }
    cout << "ok" << rand() << " " << rand() << endl;
    return 0;
}

