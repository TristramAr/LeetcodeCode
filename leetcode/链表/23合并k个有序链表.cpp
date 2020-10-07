#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//方法1，先排序在进行链表连接
//定义比较函数 从小到大排序
bool cmp(const ListNode *a, ListNode *b)
{
    return a->val < b->val;
}

class Solution_1
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> node_vec;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *head = lists[i];
            while (head)
            {
                node_vec.push_back(head);
                head = head->next;
            }
        }
        if (node_vec.size() == 0)
        {
            return NULL;
        }
        sort(node_vec.begin(), node_vec.end(), cmp);
        for (int i = 1; i < node_vec.size(); i++)
        {
            node_vec[i - 1]->next = node_vec[i];
        }
        node_vec[node_vec.size() - 1]->next = NULL;
        return node_vec[0];
    }
};

//方法二，分制超时长了
// 不断二分处理，递归操作
//合并两个链表
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode temp_head(0);
    ListNode *pre = &temp_head;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if (l1)
    {
        pre->next = l1;
    }
    if (l2)
    {
        pre->next = l2;
    }
    return temp_head.next;
}

class Solution_2
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return NULL;
        }
        if (lists.size() == 1)
        {
            return lists[0];
        }
        if (lists.size() == 2)
        {
            return mergeTwoLists(lists[0], lists[1]);
        }
        int mid = lists.size() / 2;
        vector<ListNode *> sub1_lists;
        vector<ListNode *> sub2_lists;
        for (int i = 0; i <= mid; i++)
        {
            sub1_lists.push_back(lists[i]);
        }
        for (int i = mid; i < lists.size(); i++)
        {
            sub2_lists.push_back(lists[i]);
        }
        ListNode *l1 = mergeKLists(sub1_lists);
        ListNode *l2 = mergeKLists(sub2_lists);
        return mergeTwoLists(l1, l2);
    }
};
