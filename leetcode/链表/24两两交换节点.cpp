#include <iostream>
using namespace std;
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
    //宏观看递归，这里递归实现的是交换链表的两个节点，然后返回交换后的头节点
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};
//迭代法
class Solution_2
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode new_head(0);   
        new_head.next = head;
        ListNode *pre = &new_head;
        while (pre->next && pre->next->next)
        {
            ListNode *first_node = pre->next;
            ListNode *second_node = pre->next->next;
            
            ListNode *temp = second_node->next;    // 备份
            second_node->next = first_node;        //交换
            first_node->next = temp;             
            pre->next = second_node;               //连接到反转后的头节点
            pre = first_node;                      //移动pre指针
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
    Solution_2 solve;
    ListNode *head = &a;
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
    ListNode *new_head = solve.swapPairs(&a);
    while (new_head)
    {
        cout << new_head->val << "->";
        new_head = new_head->next;
    }
}