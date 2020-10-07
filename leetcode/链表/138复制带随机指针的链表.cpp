#include <iostream>
#include <vector>
#include <map>

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        std::map<Node *, int> node_map; // 地址到节点位置的map
        std::vector<Node *> node_vec;   //根据vector存储节点位置访问指针
        Node *ptr = head;
        int i = 0;
        while (ptr)
        {
            //将新建链表节点push到node_vec,生成新链表节点位置到地址的映射
            node_vec.push_back(new Node(ptr->val));   
            node_map[ptr] = i;     // 存储原链表的地址和位置（序号 第几个节点）
            ptr = ptr->next;       // 移动链表指针
            i++;                  
        }
        node_vec.push_back(0);    // 用于后续链表尾的空节点
        ptr = head;
        i = 0;
        while (ptr)
        {
            node_vec[i]->next = node_vec[i + 1]; //连接新链表指针
            if (ptr->random)
            {
                int id = node_map[ptr->random];
                node_vec[i]->random = node_vec[id];
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};