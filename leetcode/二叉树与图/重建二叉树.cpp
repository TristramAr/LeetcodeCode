#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cstdio>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rebuild(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    TreeNode*rebuild(vector<int>::iterator preBegin,vector<int>::iterator preEnd,
                    vector<int>::iterator inBegin,vector<int>::iterator inEnd)
    {
        if(inBegin==inEnd)
        {
            return NULL;
        }
        //当前根节点位前序遍历的第一个元素
        TreeNode*cur = new TreeNode(*preBegin);
        //查找中序遍历中根节点的位置.
        // TreeNode*root;
        auto root = find(inBegin,inEnd,*preBegin);
        auto len = root - inBegin;
        //3|9|20,15,7
        //9|3|15,20,7
        cur->left = rebuild(preBegin+1,preBegin+len+1,inBegin,inBegin+len);
        cur->right = rebuild(preBegin+len+1,preEnd,inBegin+len+1,inEnd);
        return cur;
    }

};

int main()
{
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    Solution solve;
    solve.buildTree(preorder, inorder);
}
