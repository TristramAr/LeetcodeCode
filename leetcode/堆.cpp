#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> big_heap;  //默认构造最大堆
    priority_queue<int, vector<int>, greater<int>> small_heap;  //最小堆构造方法 
    priority_queue<int, vector<int>, less<int>> big_heap2;      //最大堆构造方法
    if(big_heap.empty())
    {
        printf("big_heap is empty!");
    }
    int test[] = {2, 5, 3, 66, 12, 5234, 123};
    for (int i = 0; i <7;i++)
    {
        big_heap.push(test[i]);
    }
    printf("big_heap.top= %d\n", big_heap.top());
    for (int i = 0; i < 3;i++)
    {
        big_heap.pop();
    }
    printf("big_heap.top = %d\n", big_heap.top());
    printf("big_heap.size()= %d\n", big_heap.size());
    return 0;
}