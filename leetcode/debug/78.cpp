#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result; // 储存最终结果
        vector<int> item;           //回溯时残生的各个子集数组
        // result.push_back(item);     //将空集push进入result
        generate(0, nums, item, result);
        return result;
    }

private:
    void generate(int i,
                  vector<int> &nums,
                  vector<int> &item,
                  vector<vector<int>> &result)
    {
        result.push_back(item);
        for (int j = i; j < nums.size();j++)
        {
            item.push_back(nums[j]);
            generate(j + 1, nums, item, result);
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
    result = solve.subsets(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
        }
        cout << endl;
    }
    return 0;
}