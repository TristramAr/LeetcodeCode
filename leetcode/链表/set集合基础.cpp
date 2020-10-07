#include<set>
#include<stdio.h>
int main()
{
    std::set<int> test_set;
    const int A_len = 7;
    const int B_len = 8;
    int a[A_len] = {5, 1, 4, 8, 10, 1, 3};
    int b[B_len] = {2, 7, 6, 3, 1, 6, 0, 1};
    for (int i = 0; i < A_len;i++)
    {
        test_set.insert(a[i]);
    }
    for (int i = 0; i < B_len;i++)
    {
        if(test_set.find(b[i])!=test_set.end())
        {
            printf("b[%d]=%d in array A\n", i, b[i]);
        }
    }
}