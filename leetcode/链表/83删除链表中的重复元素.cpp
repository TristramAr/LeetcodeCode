#include <iostream>
using namespace std;
//   Definition for singly-linked list.
/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
输入: 1->1->2
输出: 1->2
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        //可以不用单独拿出来判断，和while循环重复
        // if(head==NULL||head->next==NULL)
        // {
        //     return head;
        // }
        while(cur&&cur->next)
        {
            ListNode *temp = cur->next;
            if(cur->val==temp->val)
            {
                cur->next = temp->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};

int main()
{
    ListNode a(1);
    ListNode b(1);
    ListNode c(3);
    ListNode d(5);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution solve;
    ListNode *head = &a;
    while(head)
    {
        cout << head->val<<"->";
        head = head->next;
    }
    cout << endl;
    ListNode *new_head = solve.deleteDuplicates(&a);
    while(new_head)
    {
        cout << new_head->val << "->";
        new_head = new_head->next;
    }
    

}