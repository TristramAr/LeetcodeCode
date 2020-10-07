#include <iostream>
using namespace std;
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 递归的方法不太明白，也不好想
class Solution_1
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }

};
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode new_head(0);
        new_head.next = head;
        ListNode *pre = &new_head;
        while(pre->next&&pre->next->next)
        {
            ListNode *l1 = pre->next;
            ListNode *l2 = pre->next->next;
            //备份l2->next
            ListNode *next = l2->next;
            l2->next = l1;
            l1->next = next;
            pre->next = l2;
            pre = l1;
        }
        return new_head.next;
    }

};

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Solution solve;
    ListNode *head = &a;
    while(head)
    {
        cout << head->val<<"->";
        head = head->next;
    }
    cout << endl;
    ListNode *new_head = solve.swapPairs(&a);
    while(new_head)
    {
        cout << new_head->val << "->";
        new_head = new_head->next;
    }
}