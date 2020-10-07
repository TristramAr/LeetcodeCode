#include <iostream>
#include <vector>
using namespace std;
// 定义哈希表的长度
const int TABEL_LEN = 10;
//定义链表
struct ListNode
{
    int val;
    ListNode *nextindex;
    ListNode(int x) : val(x), nextindex(NULL) {}
};
//定义哈希表,初始化链表每个key值对应的头节点位空
ListNode *hash_table[TABEL_LEN] = {0};
//将数据用链表结构来表示
vector<ListNode *> node_nums;
int hash_func(int x)
{
    return (x % TABEL_LEN + TABEL_LEN) % TABEL_LEN;
}
void inset(ListNode *node)
{
    int hash_key = hash_func(node->val);
    //头插法 ,将
    node->nextindex = hash_table[hash_key];
    hash_table[hash_key] = node;
}
bool find(int x)
{
    int hash_key = hash_func(x);
    ListNode *head = hash_table[hash_key];
    while (head)
    {
        if (head->val == x)
            return true;
        head = head->nextindex;
    }
    return false;
}
int main()
{
    vector<int> test{1, 1, 4, 9, 20, 30, 150, 500};
    for (int i = 0; i < test.size(); i++)
    {
        node_nums.push_back(new ListNode(test[i]));
    }
    for (int i = 0; i < node_nums.size(); i++)
    {
        inset(node_nums[i]);
    }
    cout << "hash table" << endl;
    for (int i = 0; i < TABEL_LEN;i++)
    {
        cout << '[' << i << ']';
        ListNode *head = hash_table[i];
        while (head)
        {
            cout << "->" << head->val;
            head = head->nextindex;
        }
        cout << endl;
    }
    cout << "search result" << endl;
    for (int i = 0; i < 10; i++)
    {
        if(find(i))  cout << i << " is in the hash table" << endl;
        else cout << i << " is not in the hash table" << endl;
    }
    return 0;
}

// //f方法二
// #include<iostream>
// #include<vector>
// using namespace std;

// const int N = 1010;                  //数据量
// const int TABLE_LEN = 10;            //哈希表大小
// vector<int> hash_table(TABLE_LEN,0); //储存头节点地址
// vector<int> nums(N,0);               // 储存数据
// vector<int> nextindex(N,0);          // 储存出现哈希冲突后的下一个数据在nums数组的位置
// int index = 0;
// int hash_func(int x)
// {
//     return (x % TABLE_LEN + TABLE_LEN) % TABLE_LEN;
// }
// void insert(int x )
// {
//     int hash_key = hash_func(x);
//  	nums[index] = x;                    //将数据储存到nums中
//     nextindex[index] = hash_table[hash_key]; //相当于将
//     hash_table[hash_key] = index++;
// }
// bool find(int x)
// {
//     int hash_key = hash_func(x);
//     for(int i = hash_table[hash_key];i!=-1;i=nextindex[i])
//     {
//         if(nums[i]==x) return true;
//     }
//     return false;
// }
// int main()
// {
//     vector<int> test = {1, 1, 4, 9, 20, 30, 150, 500};
//     for (int i = 0; i < test.size(); i++) insert(test[i]);
//     cout << "hash+table" << endl;
//     for (int i = 0; i < TABLE_LEN; i++)
//     {
//         cout << "[" << i << "]";
//         for (int j = hash_table[i]; j != 0;j = nextindex[j])
//         {
//             cout << "->" << nums[j];
//         }
//         cout << endl;
//     }
//     return 0;
// }