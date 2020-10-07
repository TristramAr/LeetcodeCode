#include <iostream>
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        //先构建一个头节点，作为归并后链表的头节点， 返回时，返回头节点的下一个节点即 temp_head.next, 因为这里的temp_head 是ListNode对象
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
};

class Solution_2
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode(0), *temp = l3;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
                l3 = l3->next;
                l3->next = NULL;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
                l3 = l3->next;
                l3->next = NULL;
            }
            if (l1 != nullptr)
            {
                l3->next = l1;
            }
            if (l2 != nullptr)
            {
                l3->next = l2;
            }
        }
        return temp->next;
    }
};
