#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;
        sort(candidates.begin(), candidates.end());
         generate(0, candidates, result, item, res_set,0,target);
        return result;
    }

private:
    void generate(int i,
                  vector<int> &nums,
                  vector<vector<int>> &result,
                  vector<int> &item,
                  set<vector<int>> &res_set,
                  int sum,
                  int target)
    {
        if (i >= nums.size()||sum>target)
        {
            return;
        }
        sum += nums[i];
        item.push_back(nums[i]);

        if (sum==target&&res_set.find(item) == res_set.end()) //如果在res_set中没有找到改item,则添加改元素
        {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i + 1, nums, result, item, res_set,sum,target);
        sum = sum - nums[i];   //回溯后减去num[i],并将其从item中删去
        item.pop_back();
        generate(i + 1, nums, result, item, res_set,sum,target);
    }
};

// 该方法超时
class Solution_1
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;
        sort(candidates.begin(), candidates.end());
        result.push_back(item); //push空集
        generate(0, candidates, result, item, res_set);
        vector<vector<int>> target_result;
        for (int i = 0; i < result.size();i++)
        {
            int sum = 0;
            for (int j = 0; j < result[i].size();j++)
            {
                sum += result[i][j];
            }
            if(sum ==target)
            {
                target_result.push_back(result[i]);
            }
        }
        return target_result;
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

        if (res_set.find(item) == res_set.end()) //如果在res_set中没有找到改item,则添加改元素
        {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i + 1, nums, result, item, res_set);
        item.pop_back();
        generate(i + 1, nums, result, item, res_set);
    }
};


