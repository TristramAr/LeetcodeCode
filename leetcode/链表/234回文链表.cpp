#include <iostream>
#include <stdio.h>
#include<vector>
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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *mid = mid_node(head);
        ListNode *rNode = reverseNode(mid->next);
        mid->next = rNode;
        ListNode *back = head;
        ListNode *right = mid->next;
        while(right)
        {
            if(right->val!=back->val)
            {
                return false;
            }
            right = right->next;
            back = back->next;
        }
        return true;
    }

private:
    //利用快慢指针找链表的中点
    ListNode *mid_node(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *reverseNode(ListNode *head)
    {
        ListNode *new_head = NULL;
        while(head)
        {
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;
    }
};
class Solution_2
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        vector<int> nums;
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        int len = nums.size()-1;
        int i=0;
        while(i<=nums.size()/2)
        {
            if(nums[i]!=nums[len])
            {
                return false;
            }
            i++;
            len--;
        }
         
        
        return true;
    }
    
};
int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(2);
    ListNode d(1);
    // ListNode e(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    // d.next = &e;
    Solution_2 solve;
    ListNode *head = &a;
    if (solve.isPalindrome(head))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}