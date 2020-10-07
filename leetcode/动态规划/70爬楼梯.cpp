#include <iostream>
#include <vector>
using namespace std;

//递归暴力枚举，超时
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
        {
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

class Solution_2
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 3, 0);  // 定义一个N+3大小的数组，初始化为0
                                   //设置n+3不用判断n=1和n=0的时候 
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};