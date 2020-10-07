/*
 * @Description: 
 * @Author: feng
 * @Date: 2020-10-01 21:11:59
 * @LastEditTime: 2020-10-04 09:22:19
 * @LastEditors: feng
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverseList(ListNode *pHead, int k)
{
    ListNode *right = pHead;
    ListNode *left = pHead;
    ListNode *prev = pHead;
    for (int i = 0; i < k; i++)
    {
        if (right != nullptr)
            right = right->next;
        else
            return left;
    }
    ListNode *head = left; //备份当前头节点，也是反转后的尾节点
    while (left != right)
    {
        ListNode *pNext = left->next;
        left->next = prev;
        prev = left;
        left = pNext;
    }
    //将此时的尾节点和后续反转的头节点相连
    head->next = reverseList(right, k);
    return prev;
}
int main()
{
    ListNode new_head(0);
    ListNode *pre = &new_head;
    vector<int> data;
    int num;
    while (cin >> num)
    {
        data.push_back(num);
    }
    for (int i = 0; i < data.size() - 1; i++)
    {
        ListNode *temp = new ListNode(data[i]);
        pre->next = temp;
        pre = pre->next;
    }
    int k = data[data.size() - 1];
    ListNode *head = new_head.next;
    head = reverseList(new_head.next, k);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}