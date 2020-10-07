#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if(nums.size()==0)
        {
            return 0;
        }
        //以第i个元素结尾的最长子序列长度
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int LIS = 1;
        for (int i = 1; i < dp.size(); i++)
        {
            //以第i个元素结尾
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
            if (LIS < dp[i])
            {
                LIS = dp[i];
            }
            
        }
        return LIS;
    }
};

class Solution_2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        if(nums.size()==0)
        {
            return 0;
        }
        vector<int>dp(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
           for(int j=0;j<i;j++)
           {
               if(nums[i]>nums[j])
               {
                   dp[i] = max(dp[i],dp[j]+1);
               }
           }
        }
        for(int i=0;i<dp.size();i++)
        {
            res = max(res,dp[i]);
        }
        return res;
    }
};