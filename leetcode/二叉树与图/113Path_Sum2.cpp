#include <iostream>
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
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> result;
        vector<int> path;
        int path_sum = 0;
        preorder(root, path_sum, sum, path, result);
        return result;
    }

private:
    void preorder(TreeNode *node, int &path_sum, int sum,
                  vector<int> &path,
                  vector<vector<int>> &result)
    {
        if (!node)
        {
            return;
        }
        //没遍历一个几点即更新 路径path和path_sum
        path_sum += node->val;
        path.push_back(node->val);
        if (path_sum == sum && !node->left&&!node->right)
        {
            result.push_back(path);
        }
        preorder(node->left, path_sum, sum, path, result);
        preorder(node->right, path_sum, sum, path, result);
        path_sum -= node->val;
        path.pop_back();
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
    Solution solve;
    vector<vector<int>> result = solve.pathSum(&a, 22);
    for (auto i:result)
    {
        for(auto item:i)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}