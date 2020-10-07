#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {

        int max_index = 0;
        int min_jump = 0;
        int end = 0;
        if (nums.size() < 2)
            return 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            max_index = max(max_index, i + nums[i]);

            if (i == end)
            {
                end = max_index;
                min_jump++;
            }
        }
        return min_jump;
    }
};

class Solution_2
{
public:
    int jump(vector<int> &nums)
    {

        if (nums.size() < 2)
        {
            return 0;
        }
        int current_max_index = nums[0]; //当前可到达的最大位置
        int pre_max_max_index = nums[0]; //扫描过程中，各位置可到达的最大位置
        int min_jump = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > current_max_index)
            {
                min_jump++;
                current_max_index = pre_max_max_index;
            }
            if (pre_max_max_index < nums[i] + i)
            {
                pre_max_max_index = nums[i] + i;
            }
        }
        return min_jump;
    }
};