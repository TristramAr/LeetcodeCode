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
//方法1
class Solution_1
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        std::set<ListNode *> node_set;
        while (headA)
        {
            node_set.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (node_set.find(headB) != node_set.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};
//方法2
//计算链表长度
int get_list_length(ListNode *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}
//移动间距
ListNode *forward_long_list(int long_len, int short_len, ListNode *head)
{
    //移动一定长度的指针
    int dalta = long_len - short_len;
    while (head && dalta)
    {
        head = head->next;
        dalta--;
    }
    return head;
}
class Solution_2
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int list_A_len = get_list_length(headA);
        int list_B_len = get_list_length(headB);
        if (list_A_len > list_B_len)
        {
            headA = forward_long_list(list_A_len, list_B_len, headA);
        }
        else
        {
            headB = forward_long_list(list_B_len, list_A_len, headB);
        }
        while (headA && headB)
        {
            if (headA == headB)
            {
                return headA;
            }
            headB = headB->next;
            headA = headA->next;
        }
        return NULL;
    }
};

//方法3
/*创建两个指针 pApA 和 pBpB，分别初始化为链表 A 和 B 的头结点。然后让它们向后逐结点遍历。
当 pApA 到达链表的尾部时，将它重定位到链表 B 的头结点 (你没看错，就是链表 B); 类似的，当 pBpB 到达链表的尾部时，将它重定位到链表 A 的头结点。
若在某一时刻 pApA 和 pBpB 相遇，则 pApA/pBpB 为相交结点。
*/
class Solution_3
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }

        ListNode *pA = headA;
        ListNode *pB = headB;
        while(pA!=pB)
        {
            if(pA==NULL)
            {
                pA = headB;
            }
            else
            {
                pA = pA->next;
            }
            if(pB==NULL)
            {
                pB = headA;
            }
            else
            {
                pB = pB->next;
            }
        }
        return pA;
    }
};