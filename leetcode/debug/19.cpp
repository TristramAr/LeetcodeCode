#include <iostream>
using namespace std;
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode new_head(0);
        new_head.next = head;
        int len = get_listNode_len(head);
        int dalta = len - n;
        ListNode *cur = &new_head;
        while(dalta>0)
        {
            dalta--;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return new_head.next;
    }
    private:
    int get_listNode_len(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
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
    while(head)
    {
        cout << head->val<<"->";
        head = head->next;
    }
    cout << endl;
    ListNode *new_head = solve.removeNthFromEnd(&a,2);
    while(new_head)
    {
        cout << new_head->val << "->";
        new_head = new_head->next;
    }
    

}
