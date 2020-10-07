#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//运用状态机解决股票问题
//股票交易次数k=1;
class Solution_1
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
        {
            return 0;
        }
        // dp[i][0]表示第i天没有持股票的利润，dp[i][1]第i天持有股票的利润(买进股票，自然利润有可能为负)
        int dp[prices.size()][2];
        // 1 表示持有，0 表示没有持有
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            // 第i天没有持有股票，这说明前一天没有持有股票或者前一天持有股票，今天卖了。
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            //第i天持有股票，这说明前一天持有股票或者，今天买入股票。
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};
//不限股票交易次数，求最大利润
class Solution_2
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
        {
            return 0;
        }
        // dp[i][0]表示第i天没有持股票的利润，dp[i][1]第i天持有股票的利润(买进股票，自然利润有可能为负)
        int dp[prices.size()][2];
        // 1 表示持有，0 表示没有持有
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            // 第i天没有持有股票，这说明前一天没有持有股票或者前一天持有股票，今天卖了。
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            //第i天持有股票，这说明前一天持有股票或者，今天买入股票。
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};
// 卖出后隔一天才能继续交易
class Solution_3
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
        {
            return 0;
        }
        int dp[prices.size()][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(0, prices[1] - prices[0]);
        dp[1][1] = max(dp[0][1], -prices[0]);

        for (int i = 2; i < prices.size();i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i-2][0] - prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};
int main()
{
    vector<int> prices{1, 2, 3, 0, 2};
    Solution_1 solve1;
    cout << solve1.maxProfit(prices) << endl;
    Solution_3 solve2;
    cout << solve2.maxProfit(prices) << endl;
}