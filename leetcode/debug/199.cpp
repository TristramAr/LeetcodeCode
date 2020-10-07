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

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> view;
        queue<pair<TreeNode *, int>> Q;

        if (root)
        {
            Q.push(make_pair(root, 0));
        }
        while (!Q.empty())
        {
            TreeNode *node = Q.front().first; // 搜索节点
            int layer = Q.front().second;     //待搜索层数
            Q.pop();
            //
            if (view.size() == layer)
            {
                view.push_back(node->val);
            }
            else
            {
                view[layer] = node->val;
            }
            if (node->left)
            {
                Q.push(make_pair(node->left, layer + 1));
            }
            if (node->right)
            {
                Q.push(make_pair(node->right, layer + 1));
            }
        }
        return view;
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
    Solution solve;
    for(auto result:solve.rightSideView(&a))
    {
        cout << result << endl;
    }
    return 0;
}