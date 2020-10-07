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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        int change_len = n - m + 1; //计算需要逆置的节点个数
        ListNode *pre_head = NULL;  //初始化开始逆转的节点的前驱
        ListNode *result = head;    //最终转换后的链表头节点
        while (head && --m)         //将head向前移动m-1个节点 (--m做判断时，是将m-1的结果作为判断值；m--,是用m值作判断，然后再进行m-1)
        {
            pre_head = head; //记录head的前驱
            head = head->next;
        }
        ListNode *modify_list_tail = head; //此时逆转后部分链表的尾节点（原链表需要逆转的起始节点）
        ListNode *new_head = NULL;
        //逆转节点
        while (head && change_len)
        {
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
            change_len--;
        }
        modify_list_tail->next = head;
        if (pre_head)
        {
            pre_head->next = new_head;
        }
        else
        {
            result = new_head;
        }
        return result;
    }
};

//递归法
class Solution_2
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // base case
        if (m == 1)
        {
            return reverseN(head, n);
        }
        // 前进到反转的起点触发 base case
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }

private:
    //反转前N个节点
    ListNode *last = NULL; //用来记录后续节点
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
    ListNode *new_head = solve.reverseBetween(&a, 2, 4);
    while (new_head)
    {
        cout << new_head->val << "->";
        new_head = new_head->next;
    }
}