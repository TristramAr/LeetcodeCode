#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;
        sort(nums.begin(), nums.end());
        result.push_back(item); //push空集
        generate(0, nums, result, item, res_set);
        return result;
    }

private:
    void generate(int i,
                  vector<int> &nums,
                  vector<vector<int>> &result,
                  vector<int> &item,
                  set<vector<int>> &res_set)
    {
        if (i >= nums.size())
        {
            return;
        }
        item.push_back(nums[i]);

        if (res_set.find(item) == res_set.end())    //如果在res_set中没有找到改item,则添加改元素
        {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i + 1, nums, result, item, res_set);
        item.pop_back();
        generate(i + 1, nums, result, item, res_set);
    }
};