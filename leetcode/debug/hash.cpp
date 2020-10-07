#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


//整数哈希函数，对表长取余
int hash_func(int key, int table_len)
{
    return key % table_len;      
}
//头插法
//把新结点作为头节点的下一个节点
void insert(ListNode *hash_table[],ListNode *node,int table_len)
{
    int hash_key = hash_func(node->val, table_len);
    cout << "1:"<<hash_table[hash_key]<<endl;
    node->next=hash_table[hash_key];    //hash_table[hash_key] 所指向的节点地址赋给新节点的指向
    hash_table[hash_key] = node;        //再将hash_table[hash_key]指向新节点
    cout << "2:"<<hash_table[hash_key]<<endl;
}

bool search(ListNode  *hash_table[],int value,int table_len)
{
    int hash_key = hash_func(value, table_len);
    ListNode *head = hash_table[hash_key];
    while(head)
    {
        if(head->val==value)
        {
            return true;
        }
        head=head->next;
    }
    return false;
}

int main()
{
    const int TABLE_LEN = 11;
    ListNode *hash_table[TABLE_LEN]={0};
    vector<ListNode *> hash_node_vec;
    int test[8] = {1, 1, 4, 9, 20, 30, 150, 500};
    for (int i = 0; i < 8;i++)
    {
        hash_node_vec.push_back(new ListNode(test[i]));
    }
    for (int i = 0; i < hash_node_vec.size();i++)
    {
        insert(hash_table, hash_node_vec[i], TABLE_LEN);
    }
    cout << "harch table:" << endl;
    for (int i = 0; i < TABLE_LEN;i++)
    {
        cout << '[' << i << ']';
        ListNode *head = hash_table[i];
        while (head)
        {
            cout << "->" << head->val;
            head = head->next;
        }
        cout << endl;
    }
        cout << endl;
    cout << "test search:" << endl;
    for (int i = 0; i < 10; i++)
    {
        if(search(hash_table,i,TABLE_LEN))
        {
            cout << i << " is in the hash table" << endl;
        }
        else
        {
            cout << i << " is not in the hash table" << endl;
        }
    }
    return 0;
}