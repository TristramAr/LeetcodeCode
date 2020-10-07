#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
#include <initializer_list>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a.front() < b.front();
}

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
        {
            return 0;
        }
        sort(points.begin(), points.end(), cmp); //按照左端点进行从小到大排序
        int shoot_area_l = points[0][0];         //设计区域左端点
        int shoot_area_r = points[0][1];         //射击区域右端点
        int shoot_num = 1;                       // 非空下至少需要射击一次
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <=shoot_area_r)
            {
                shoot_area_l = points[i][0];
                if(points[i][1]<shoot_area_r)
                {
                    shoot_area_r = points[i][1];
                }
            }
            else
            {
                shoot_num++;
                shoot_area_l = points[i][0];
                shoot_area_r = points[i][1];
            }
        }
        return shoot_num;
    }
};

//方法2
bool cmp_2(vector<int> &a, vector<int> &b)
{
    return a.back() < b.back();
}

class Solution_2
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
        {
            return 0;
        }
        sort(points.begin(), points.end(), cmp_2); //按照左端点进行从小到大排序
        int shoot_area_r = points[0][1];         //射击区域右端点
        int arrows = 1;                       // 非空下至少需要射击一次
        for (int i = 1; i < points.size(); i++)
        {
           if(points[i][0]>shoot_area_r)
           {
               arrows++;
               shoot_area_r = points[i][1];
           }
        }
        return arrows;
    }
};

int main()
{
    vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    Solution_2 solve;
    cout << points[0][0] << endl;
    cout << solve.findMinArrowShots(points);
    return 0;
}