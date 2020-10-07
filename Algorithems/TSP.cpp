/**
   @回溯-旅行商(TSP)问题
*/
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
int n;                //城市个数
int a[MAX][MAX];      //城市间距离
int x[MAX];           //记录路径
int bestx[MAX] = {0}; //记录最优路径
int bestp = 63355;    //最短路径长
int cp = 0;           //当前路径长
// 0 2 6 5
// 2 0 4 4
// 6 4 0 2
// 5 4 2 0
void backpack(int t)
{
    if (t > n)
    {
        if ((a[x[n]][1]) && (a[x[n]][1] + cp < bestp))
        {
            bestp = a[x[n]][1] + cp;
            for (int i = 1; i <= n; i++)
            {
                bestx[i] = x[i];
            }
        }
    }
    else
    {
        for (int i = t; i <= n; i++)
        {
            /*约束为当前节点到下一节点的长度不为0,限界为走过的长度+当前要走的长度之和小于最优长度*/
            if ((a[x[t - 1]][x[i]]) && (cp + a[x[t - 1]][x[i]] < bestp))
            {
                swap(x[t], x[i]);
                cp += a[x[t - 1]][x[t]];
                backpack(t + 1);
                cp -= a[x[t - 1]][x[t]];
                swap(x[t], x[i]);
            }
        }
    }
}
int main()
{
    cout << "输入城市个数:" << endl;
    cin >> n; //顶点数
    for (int i = 1; i <= n; i++)
    {
        x[i] = i;
    }
    cout << "输入城市之间的距离(0表示城市间不通):" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    backpack(2);
    cout << "最少旅行费用为: " << bestp << endl;
    cout << "旅行路径为:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << bestx[i] << " ";
    }
    cout << bestx[1];
    return 0;
}
//动态规划法
// int getAns(vector<vector<int>> &nums)
// {
//     const int MAX = 0x0fffffff;
//     int n = nums.size();
//     int stateNum = 1 << (n - 1); //即2的n次方，也就是第n个城市
//     // dp[i][j]中的j是一个二进制形式的数，表示经过城市的集合，如111表示经过了城市1,2,3,排除了城市0 dp[0][{1,2,3}] 即为所求
//     // dp[i][j]表示从城市i出发，经过j集合中的城市所需最小花费n

//     vector<vector<int>> dp(n, vector<int>(stateNum, MAX));
//     for (int i = 0; i < n; i++)
//     {
//         dp[i][0] = nums[i][0]; //每个城市会到起点的花费
//     }
//     // 这里j不仅是dp表的列坐标值，j的二进制表示城市相应城市是否在子集中
//     for (int j = 1; j < stateNum; j++)
//     {
//         //从i出发，去集合j的城市
//         for (int i = 0; i < n; i++)
//         {
//             //查看集合j的第i位是否为1，为1说明待走集合中包含起点，
//             // 该方式错误，跳过（例如d[1][{1}]，d[2][{1,2}]）
//             if ((j >> (i - 1) & 1 == 1))
//             {
//                 continue;
//             }
//             //如果j >> (i - 1) & 1 == 0,则表示从城市i出发，经过集合j的城市，回到起点0所需花费
//             //尝试去k城市，
//             for (int k = 1; k < n; k++)
//             {
//                 //待走集合最终没有当前城市，跳过。
//                 if ((j >> (k - 1) & 1) == 0)
//                 {
//                     continue;
//                 }
//                 if (dp[i][j] > nums[i][k] + dp[k][j ^ (1 << (k - 1))])

//                 {
//                     //dp[k][j ^ (1 << (k - 1))]表示从k城市出发，经过子集不包含k城市的路径，返回起点的花费。
//                     //dp[2][{1,3}] =min(nums[2][1]+dp[1][{3}],nums[2][3]+dp[3][{1}])
//                     //即 dp[2][5] = min(nums[2][1]+dp[1][4],nums[2][3]+dp[3][1])
//                     // j ^ (1 << (k - 1)),去掉原来集合j中的城市k，得到的新集合
//                     dp[i][j] = nums[i][k] + dp[k][j ^ (1 << (k - 1))];
//                 }
//             }
//         }
//     }
//     return dp[0][(1 << (n - 1)) - 1]; //dp[0][7]   7:0111
// }
// int main()
// {
//     int n;
//     while (cin >> n)
//     {
//         vector<vector<int>> edges(n, vector<int>(n, 0));
//         int x;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cin >> edges[i][j];
//             }
//         }
//         cout << getAns(edges) << endl;
//     }
//     return 0;
// }