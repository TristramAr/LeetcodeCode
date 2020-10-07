#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//宽度优先搜索，按照层从左到右
void BFS_print(TreeNode *root)
{
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        TreeNode *node = Q.front();
        Q.pop();
        cout << node->val << endl;
        if (node->left)
        {
            Q.push(node->left);
        }
        if (node->right)
        {
            Q.push(node->right);
        }
    }
}
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<int> res;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *temp;
        while (!q.empty())
        {
            res.clear();
            int length = q.size();
            for (int i = 0; i < length; i++)
            {
                temp = q.front();
                res.push_back(temp->val);
                q.pop();
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};

int main()
{
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &x;
    f.right = &y;
    BFS_print(&a);
    Solution solve;
    vector<vector<int>> ans = solve.levelOrder(&a);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}