// 算法题：反转一个单链表
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
#include<iostream>
#include<cstdlib>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *curr = head;
        
        while(curr!=NULL){
            ListNode*temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
};
