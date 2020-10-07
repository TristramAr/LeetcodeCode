#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;        //存储元素的数据域
    ListNode *next; // 存储下一个节点的指针域
};
int main()
{
    //创建5各节点
    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e;
    //给5个节点赋值
    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;
    e.val = 50;
    //连接5个节点
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    ListNode *head = &a;
    while (head)
    {
        printf("%d\n", head->val);
        head = head->next;
    }
}
