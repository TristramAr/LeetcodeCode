#include <iostream>
#include <stdio.h>
using namespace std;
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *reverseN(ListNode *head, int n)
    {
        ListNode *new_head = NULL;
        ListNode *head_tmp = head;
        while (head && n--)
        {
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        head_tmp->next = head;
        return new_head;
    }
};
//递归法，宏观考虑，就只有三个节点，反转前两个
class Solution_2
{
public:
    ListNode *reverseN(ListNode *head, int n)
    {
        if (n == 1) //n=1时反转一个元素，也就是它本身，这个时候要记录它后面的节点。
        {

            last = head->next; //记录第n+1个节点
            return head;
        }
        ListNode *next = reverseN(head->next, n - 1); // 反转以head->next为头节点的前n-1个元素
        head->next->next = head;
        head->next = last;
        return next;
    }

private:
    ListNode *last = NULL; //用来记录后续节点
};

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(5);
    ListNode e(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution solve;
    ListNode *head = &a;
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
    ListNode *new_head = solve.reverseN(&a, 2);
    while (new_head)
    {
        cout << new_head->val << "->";
        new_head = new_head->next;
    }
}