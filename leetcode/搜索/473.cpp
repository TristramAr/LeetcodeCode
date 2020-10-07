#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
//深搜回溯
class Solution
{
public:
    bool makesquare(vector<int> &nums)
    {
        if(nums.size()<4)
        {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size();i++)
        {
            sum += nums[i];
        }
        if(sum%4)
        {
            return false;
        }
        sort(nums.rbegin(), nums.rend());
        int bucket[4] = {0};
        return generate(0, nums, sum / 4, bucket);

    }

private:
    bool generate(int i,vector<int>&nums,int target, int bucket[])
    {
        if(i>=nums.size())
        {
            return bucket[0] == target && bucket[1] == target &&
                   bucket[2] == target && bucket[2] == target;
        }
        for (int j = 0; j < 4;j++)
        {

            if(bucket[j]+nums[i]>target)
            {
                continue;
            }
            bucket[j] += nums[i];
            if (generate(i + 1,nums,target,bucket))
            {
                return true;
            }
            bucket[j] -= nums[i];
        }
        return false;
    }
};

int main()
{
    vector<int> nums{1, 1, 2, 2, 2};
    Solution solve;
    if(solve.makesquare(nums))
    {
        cout << "yes" << endl;
    }
    return 0;
}
