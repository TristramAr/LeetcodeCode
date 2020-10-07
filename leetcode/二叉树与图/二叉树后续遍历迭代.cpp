#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *cur;
        while (!s.empty())
        {
            cur = s.top();
            s.pop();
            if (!cur->left && !cur->right)
            {
                res.push_back(cur->val);
            }
            else
            {
                TreeNode *left = cur->left;
                TreeNode *right = cur->right;
                cur->left = NULL;
                cur->right = NULL;
                s.push(cur);
                if (right)
                {
                    s.push(right);
                }
                if (left)
                {
                    s.push(left);
                }
            }
        }
        return res;
    }
};
class Solution_2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        TreeNode*pre = NULL;
        while(cur||!s.empty())
        {
            while(cur)
            {
                s.push(cur);
                cur =cur->left;
            }
            cur = s.top();
            if(cur->right==NULL||cur->right == pre)
            {
                res.push_back(cur->val);
                s.pop();
                pre=cur;
                cur = NULL;
            }
            else
            {
                cur = cur->right;
            }
        }
        return res;
        
    }
};
int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    Solution_2 solve2;
    vector<int> res2 = solve2.postorderTraversal(&a);
    for(auto i :res2)
    {
        cout << i << " ";
    }
    cout << endl;
    // Solution solve1;
    // vector<int> res1 = solve1.postorderTraversal(&a);
    // for(auto i :res1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
}