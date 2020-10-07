#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        //建立两个空节点
        ListNode more_head = NULL;
        ListNode less_head = NULL;
        //建立两个指针指向两个空节点
        ListNode *more_ptr = &more_head;
        ListNode *less_ptr = &less_head;
        while (head)
        {
            if (head->val < x)
            {
                less_ptr->next = head;
                less_ptr = head;
            }
            else
            {
                more_ptr->next = head;
                more_ptr = head;
            }
            head = head->next;
        }
        less_ptr->next = more_head.next;
        more_ptr->next = NULL;
        return less_head.next;
    }
};