#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        int a = path(root, sum);
        int b = path(root->left, sum);
        int c = path(root->right,sum);
        return a+b+c;
        
    }
private:
    int path(TreeNode*node,int sum)
    {
        if(node==NULL) return 0;
        int res = 0;
        if(node->val==sum)  
        {
            res++;
        }
        res+=path(node->left,sum-node->val)+path(node->right,sum-node->val);
        return res;
    }
};

int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    a.right = &b;
    b.right = &c;
    c.right = &d;
    d.right = &e;
    Solution solve;
    int result = solve.pathSum(&a,3);
    cout << result << endl;
    return 0;
}
