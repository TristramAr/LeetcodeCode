#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)
        {
            return 0;
        }
        vector<vector<int>> dp;
        //二维数组初始化
        for (int i = 0; i < triangle.size();i++)
        {
            dp.push_back(vector<int>());
            for (int j = 0; j < triangle[i].size();j++)
            {
                dp[i].push_back(0);
            }
        }
        //最下一层,从下往上递归，这里相当于以为dp中的临界条件
        for (int i = 0; i < dp.size();i++)
        {
            dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
        }
        for (int i = dp.size() - 2; i >= 0;i--)
        {
            for (int j = 0; j < dp[i].size();j++)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};