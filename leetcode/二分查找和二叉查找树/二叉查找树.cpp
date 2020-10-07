#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

// 二叉查找树种插入节点
void BST_insert(TreeNode *node, TreeNode *insert_node)
{ 
    if(insert_node->val<node->val)
    {
        if(node->left)
        {
            BST_insert(node->left, insert_node);
        }
        else{
            node->left = insert_node;
        }
    }
    else
    {
        if(node->right)
        {
            BST_insert(node->right, insert_node);
        }
        else
        {
            node->right = insert_node;
        }
    }
}

void preorder(TreeNode *node,int layer)
{
    if(!node)
    {
        return;
    }
    for (int i = 0; i < layer;i++)
    {
        cout << "---";
    }
    cout << node->val<<endl;
    preorder(node->left, layer + 1);
    preorder(node->right, layer + 1);
}


//搜索
bool BST_search(TreeNode*node,int value)
{
    //当前节点值为value
    if(value==node->val)
    {
        return true;
    }
    // 当前节点值小于value,在当前节点的左子树上找
    if(value<node->val)
    {
        //左子树不为空，则继续进行递归查找
        if(node->left)
        {
            BST_search(node->left, value);
        }
        else
        {
            return false;
        }
    }
    else 
    {
        if(node->right)
        {
            BST_search(node->right, value);
        }
        else 
        {
            return false;
        }
    }
}

int main()
{
    TreeNode root(8);
    vector<TreeNode* > node_vec;
    int test[] = {3, 10, 1, 6, 15};
    for (auto i:test)
    {
        node_vec.push_back(new TreeNode(i));
    }
    for(auto i:node_vec)
    {
        BST_insert(&root, i);
    }
    preorder(&root, 0);
    if(BST_search(&root,6))
    {
        cout << "6 is in the BST";
    }
    else
    {
        cout << "6 is not in the BST";
    }

    return 0;
}