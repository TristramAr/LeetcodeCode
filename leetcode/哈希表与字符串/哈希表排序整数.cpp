#include <iostream>
using namespace std;
/*
针对非负整数进行排序
通过数组小标进行进行排序
对于哈希表的长度要大于非负整数的最大值
针对数量多但是最大值不大的排序高效
例如1-1000范围内右10万个数
*/
int main()
{
    int random[10] = {999, 1, 444, 7, 20, 9, 1, 3, 7, 7};
    int hash_map[1000] = {0};
    for (int i = 0; i < 10; i++)
    {
        hash_map[random[i]]++;
    }
    for (int i = 0; i < 1000;i++)
    {
        //对于相等的数据无法输出
        // if (hash_map[i]>0)
        // {
        //     cout << i << endl;
        // }
        for (int j = 0; j < hash_map[i];j++)
        {
            cout << i << endl;
        }
    }
}