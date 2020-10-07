#include<iostream>
#include<vector>
using namespace std;

struct BSTNode{
    int val;
    int count;     //二叉树中左子树中节点个数
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x) : val(x), left(NULL), right(NULL), count(0){}
};
// 逆序数为该数右侧小于该值的数的个数，
//将原数组逆序插入到二叉树中，每插入一个数， 
//count_small 记录二叉排序树中比insert_node值小的节点个数，即为该值在原来数组中的逆序数
void BST_insert(BSTNode*node,BSTNode*insert_node,int &count_small)
{
    if(insert_node->val<= node->val)
    {
        node->count++;
        if(node->left)
        {
            BST_insert(node->left, insert_node, count_small);
        }
        else
        {
            node->left = insert_node;
        }
    }
    else
    {
        count_small += node->count+1;
        if(node->right)
        {
            BST_insert(node->right, insert_node, count_small);
        }
        else
        {
            node->right = insert_node;
        }
    }
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;  //最终逆序数数组
        vector<BSTNode *> node_vec;  //创建二叉查找树节点池
        vector<int> count;   // 从后向插入过程中，比当前节点值小的count_small数组
        for (int i = nums.size() - 1; i >= 0;i--)
        {
            node_vec.push_back(new BSTNode(nums[i]));
        }
        count.push_back(0); //第一个节点count_small =0;
        for (int i = 1; i < node_vec.size();i++)
        {
            int count_small = 0;
            BST_insert(node_vec[0], node_vec[i], count_small);
            count.push_back(count_small);
        }
        for (int i = node_vec.size() - 1; i >= 0;i--)   //将count数组按照从后向前push进result数组
        { 
            delete node_vec[i];
            result.push_back(count[i]);
        }
        return result;
    }
};
 
int main()
{
    vector<int> nums{5, -7, 9, 1, 3, 5, -1, 1};
    Solution solve;
    vector<int> result = solve.countSmaller(nums);
    for(auto item:result)
    {
        cout << item << " ";
    }
    return 0;
}