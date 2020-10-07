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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path;        //遍历时的路径
        vector<TreeNode *> node_p_path; //储存p节点时的路径
        vector<TreeNode *> node_q_path; //储存q节点时的路径
        int finish = 0;
        preorder(root, p, path, node_p_path, finish);
        path.clear();
        finish = 0;
        preorder(root, q, path, node_q_path, finish);
        int path_len = 0; // 记录较短路径的长度
        if (node_p_path.size() < node_q_path.size())
        {
            path_len = node_p_path.size();
        }
        else
        {
            path_len = node_q_path.size();
        }
        TreeNode *result = 0;
        for (int i = 0; i < path_len; i++)
        {
            if (node_p_path[i] == node_q_path[i])
            {
                result = node_p_path[i];
            }
            
        }
        return result;
    }

private:
    void preorder(TreeNode *node,
                  TreeNode *search,
                  vector<TreeNode *> &path,
                  vector<TreeNode *> &result,
                  int &finish)
    {
        if (!node || finish)
        {
            return;
        }
        path.push_back(node);
        if (node == search)
        {
            finish = 1;
            result = path;
        }
        preorder(node->left, search, path, result, finish);
        preorder(node->right, search, path, result, finish);
        path.pop_back();
    }
};
