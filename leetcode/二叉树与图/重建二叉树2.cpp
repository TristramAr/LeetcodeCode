#include <iostream>
#include <algorithm>
#include <vector>
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
    //给出搜索二叉树的后续遍历，构建二叉树
public:
    TreeNode *build(vector<int> &backOrder)
    {
        if (backOrder.size() == 0)
        {
            return NULL;
        }
        return buildTree(backOrder, 0, backOrder.size() - 1);
    }

private:
    TreeNode *buildTree(vector<int> &backOrded, int left, int right)
    {
        if (left > right)
        {
            return NULL;
        }
        TreeNode*root = new TreeNode(backOrded[right]);
        if (left == right)
        {
            return root;
        }
        int mid=0;
        for (int i = left; i < right; i++)
        {
            if (backOrded[i] < backOrded[right])
            {
                mid = i;
            }
        }
        root->left = buildTree(backOrded, left, mid);
        root->right = buildTree(backOrded, mid + 1, right-1);   // 最后一个数已经拿走了
        return root;
    }
};
void inetraversal(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    inetraversal(node->left);
    cout << node->val << endl;
    inetraversal(node->right);
}
int main()
{
    vector<int> nums{1,3,2,4,5};
    Solution solve;
    TreeNode*root = solve.build(nums);
    inetraversal(root);
}