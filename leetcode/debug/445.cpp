#include <iostream>
#include<stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *tmp = NULL;
        stack<int> L1 = trans_to_stack(l1);
        stack<int> L2 = trans_to_stack(l2);
        int carry = 0;  //进位
        int n1 = 0;
        int n2 = 0;
        int sum = 0;
        if(L1.empty())
        {
            return l2;
        }
        if(L2.empty())
        {
            return l1;
        }
        //l1 l2  carray 有任意一个存在即可继续进行循环
        //当carry不为0，即有进位是需要继续进行
        while(!L1.empty()||!L2.empty()||carry)
        {
            if(L1.empty())
            {
                 n1 = 0;
            }
            else
            {
                n1 = L1.top();
                L1.pop();
            }
              if(L2.empty())
            {
                 n2 = 0;
            }
            else
            {
                n2 = L2.top();
                L2.pop();
            }
            sum = n1 + n2 + carry;
            tmp = new ListNode (sum%10);
            //前插法，新节点都插入到头节点的后面
            tmp->next = head.next;
            head.next = tmp;
            carry = sum / 10;
        }
        return head.next;
    }

    stack<int> trans_to_stack(ListNode *head)
    {
        stack<int> l1;
        while(head)
        {
            l1.push(head->val);
            head = head->next;
        }
        return l1;
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
    ListNode *l1 = &d;
    ListNode *l2 = &d;
    Solution solve;
    ListNode *head = solve.addTwoNumbers(l1, l2);
    while(head)
    {
        cout << head->val << "->";
        head = head->next;
    }
}