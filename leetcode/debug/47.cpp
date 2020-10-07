#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> item;
        vector<vector<int>> result;
        set<int> path;
        backtrack(nums, result, path, item);
        return result;
    }

private:
    void backtrack(vector<int> &nums, vector<vector<int>> &result, set<int> &path, vector<int> &item)
    {

        if (path.size() == nums.size())
        {
            result.push_back(item);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            //如果路径中包含了改元素，则跳出本次循环
            if (path.find(i) != path.end())
            {
                continue;
            }
            //
            
            if (i > 0 && nums[i] == nums[i - 1] && path.find(i - 1) == path.end())
            {
                continue;
            }

            path.insert(i);
            item.push_back(nums[i]);
            backtrack(nums, result, path, item);
            path.erase(i);
            item.pop_back();
        }
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(3);
    
    // vector<int> item;
    vector<vector<int>> result;
    Solution solve;
    result = solve.permuteUnique(nums);

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
