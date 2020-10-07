#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> item;
        vector<bool>used(nums.size(),false);
        backtrack(nums, res, used, item);
        return res;
    }
    void backtrack(vector<int>& nums,vector<vector<int>>& res,vector<bool>&used,vector<int>& item)
    {
        if(item.size()==nums.size())
        {
            res.push_back(item);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(used[i])
            {
                continue;
            }
            used[i] = true;
            item.push_back(nums[i]);
            backtrack(nums,res,used,item);
            cout << "yes" << endl;
            used[i] = false;
            item.pop_back();
        }
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    // vector<int> item;
    vector<vector<int>> result;
    Solution solve;
    result = solve.permute(nums);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
