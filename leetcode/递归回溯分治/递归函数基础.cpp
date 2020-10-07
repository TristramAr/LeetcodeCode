#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


void add_to_vector(ListNode *head,vector<int> &vec)
{
    if(!head)    //head为空则返回
    {
        return;
    }
    vec.push_back(head->val);
    add_to_vector(head->next, vec);
}