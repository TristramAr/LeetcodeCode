#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//就是保证当前area要使其更有利于避免相交，
//也就是保证当前区间更小，area_r小点。
//方法1从起点的贪心算法
bool cmp(vector<int> &a, vector<int> &b)
{
    return a.front() < b.front();
}
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        if (intervals.size() < 2)
        {
            return 0;
        }
        int area_r = intervals[0][1];
        int area_l = intervals[0][0];
        int remove_num = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < area_r)
            {
                remove_num++;
                if (intervals[i][1] < area_r)   // 
                {
                    area_r = intervals[i][1];
                    area_l = intervals[i][0];
                }
            }
            else
            {
                area_r = intervals[i][1];
                area_l = intervals[i][0];
            }
        }
        return remove_num;
    }
};
//方法2从终点的贪心算法
bool cmp_2(vector<int> &a, vector<int> &b)
{
    return a.back() < b.back();
}
class Solution_2
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp_2);
        if (intervals.size() < 2)
        {
            return 0;
        }
        int area_end = intervals[0][1];
        int remove_num = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0]<area_end)
            {
                remove_num++;
                // area_end = intervals[i][1];
            }
            else
            {
                area_end = intervals[i][1];
            }

        }
        return remove_num;
    }
};

int main()
{
    vector<vector<int>> intervals{{1, 100}, {11, 22},{1,11},{2,12}};
    Solution_2 Solve;
    cout << Solve.eraseOverlapIntervals(intervals);
    return 0;
}