#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        //初始化大小为amount+1的数组，初始值为amount+1
        // 金额amount最多需要amount个硬币（全为1）
        vector<int> dp(amount+1,amount+1);
        // 加入一个dp[0]方便计算
        dp[0] = 0;
        //dp[i]表示凑齐金额i需要的最少零钱个数
        for (int i = 0; i < dp.size(); i++)
        {
            for (int coin : coins)
            {
                if (i - coin < 0)
                {
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        //如果值还为初始值，那说明找不开
        return(dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};