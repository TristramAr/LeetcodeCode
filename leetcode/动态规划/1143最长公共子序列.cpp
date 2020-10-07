#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.length();
        int len2 = text2.length();
        //dp[i][j] 的含义是：对于 s1[1..i] 和 s2[1..j]，它们的最长公共子序列长度是 dp[i][j]。
        // dp是从0开始的当输入为空字符串的情况
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i < len1 + 1;i++)
        {
            for (int j = 1; j < len2 + 1;j++)
            {
                //这里字符串的索引和dp的索引要搞清楚，字符串的索引是从0开始，dp在此次是从1开始
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};