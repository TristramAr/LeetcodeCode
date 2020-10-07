#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        TreeNode *temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;

    }
};
int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left = &b;
    a.right = &c;
    Solution solve;
    TreeNode *root = &a;
    solve.invertTree(root);
    cout << root->left->val << endl;
    cout << root->right->val << endl;
}