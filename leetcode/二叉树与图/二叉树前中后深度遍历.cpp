#include <iostream>
using namespace std;
struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL){};
};

//前序遍历 先访问根节点，然后左子树 最后右子树
void pretraversal(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    cout << node->val << endl;
    pretraversal(node->left);
    pretraversal(node->right);
}
//中序遍历，先访问左子树，根节点，右子树
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
//后续遍历，先访问左子树，右子树，根节点
void posttraversal(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    posttraversal(node->left);
    posttraversal(node->right);
    cout << node->val << endl;
}

int main()
{
    TreeNode a('A');
    TreeNode b('B');
    TreeNode c('C');
    TreeNode d('D');
    TreeNode e('E');
    TreeNode f('F');
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    posttraversal(&a);
}