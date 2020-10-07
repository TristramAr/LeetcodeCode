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
//int转字符串
void change_int_to_string(int val, string &str_val)
{
    string tmp;
    while (val)
    {
        tmp += val % 10 + '0';
        val = val / 10;
    }
    for (int i = tmp.length() - 1; i >= 0; i--) // 逆序转换
    {
        str_val += tmp[i];
    }
    str_val += '#'; //对于转换后的数字后添加一个#
}
//前序遍历，并储存为字符串
void BST_preorder(TreeNode *node, string &data)
{
    if (!node)
    {
        return;
    }
    string str_val;
    change_int_to_string(node->val, str_val);
    data += str_val;
    BST_preorder(node->left, data);
    BST_preorder(node->right, data);
}

//前序打印
void preorder_print(TreeNode *node,int layer)
{
    if(!node)
    {
        return;
    }
    for (int i = 0; i < layer;i++)
    {
        cout << "---";
    }
    cout << node->val << endl;
    preorder_print(node->left, layer + 1);
    preorder_print(node->right, layer + 1);
}
//二叉查找树的构建 插入
void BST_insert(TreeNode*node,TreeNode*insert_node)
{
    if (insert_node->val<node->val)
    {
        if(node->left)
        {
            BST_insert(node->left, insert_node);
        }
        else
        {
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


class Codec
{
public:
    // Encodes a tree to a single string.
    // 编码阶段
    string serialize(TreeNode *root)
    {
        string data;
        BST_preorder(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    //解码阶段
    TreeNode *deserialize(string data)
    {

        //解析字符串
        if (data.length() == 0)
        {
            return NULL;
        }
        vector<TreeNode *> node_vec;
        int val = 0;
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == '#')
            {
                node_vec.push_back(new TreeNode(val));
                val = 0;
            }
            else
            {
                val = val * 10 + data[i] - '0';
            }
        }
        //将解析号的值插入到二叉查找树
        for (int i = 1; i < node_vec.size();i++)
        {
            BST_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];
    }
};

int main()
{

    TreeNode a(8);
    TreeNode b(3);
    TreeNode c(10);
    TreeNode d(1);
    TreeNode e(6);
    TreeNode f(15);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    Codec solve;
    string data = solve.serialize(&a);
    cout << data.c_str() << endl;
    TreeNode *root = solve.deserialize(data);
    preorder_print(root,0);
    return 0;
}