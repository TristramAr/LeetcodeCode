#include <iostream>
#include <stdio.h>
#include <set>

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_1
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        std::set<ListNode *> node_set;
        while (head)
        {
            if (node_set.find(head) != node_set.end()) // 如果在node_set中没到结尾就找到了，说明有环。
            {
                return head;
            }
            node_set.insert(head);
            head = head->next;
        }
        return NULL;
    }
};
//方法2
class Solution_2
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        std::set<ListNode *> node_set;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = NULL;
        //fast指针走两步，需要在走一步的时候就判断是不是会遇到无环。
        while (fast)             //fast为NULL时结束，无环
        {
            slow = slow->next;
            fast = fast->next;
            if (!fast)          // fast走一步时为空，无环。
            {
                return NULL;
            }
            fast = fast->next;
            if (fast == slow)
            {
                meet = fast;
                break;
            }
        }
        if (meet == NULL)
        {
            return NULL;
        }
        while ((head && meet))
        {
            if (head == meet)
            {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return NULL;
    }
};
