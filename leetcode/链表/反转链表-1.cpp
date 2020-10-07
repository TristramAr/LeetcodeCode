#include <iostream>
#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//双指针迭代方法
class Solution_1
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *new_head = NULL;  //指向新链表表头的指针
        while(head)
        {
            ListNode *next = head->next;   // 备份head->next
            head->next = new_head;         // 修改head指针
            new_head = head;               // 移动new_head指针
            head = next;                   // 移动head指针
        }
        return new_head;  
    }
};
//递归方法
class Solution_2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)    // 这里head==NULL必须在前，不然head为空时先判断head->next不就是扯淡了吗？
        {
            return head;
        }
        ListNode *next = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return next;
    }
    
};
int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution_2 solve;
    ListNode *head = &a;
    printf("before reverse:\n");
    while (head)
    {
        printf("%d\n", head->val);
        head = head->next;
    }
    head = solve.reverseList(&a);
    printf("after reverse:\n");
    while (head)
    {
        printf("%d\n", head->val);
         head = head->next;

    }
    
}