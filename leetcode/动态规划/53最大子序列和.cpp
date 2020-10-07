#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int max_res = dp[0];
        //以第i个数字结尾的最大子序列和
        for (int i = 1; i < nums.size();i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if(max_res<dp[i])
            {
                max_res = dp[i];
            }
        }
        return max_res;
    }
};