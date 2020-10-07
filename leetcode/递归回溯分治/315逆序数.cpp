#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        //用pair将nums和i绑定
        vector<pair<int, int>> vec;
        vector<int> count;
        for (int i = 0; i < nums.size(); i++)
        {
            vec.push_back(make_pair(nums[i], i));
            count.push_back(0);
        }
        merge_sort(vec, count);
        return count;
    }

private:
    void merge_sort_two_vec(vector<pair<int, int>> &vec1,
                            vector<pair<int, int>> &vec2,
                            vector<pair<int, int>> &result,
                            vector<int> &count)
    {
        int i = 0;
        int j = 0;
        while (i < vec1.size() && j < vec2.size())
        {
            if (vec1[i].first <= vec2[j].first)
            {
                //后有序数组中j的值即为逆序数个数
                // 5，2，1
                count[vec1[i].second] += j;
                result.push_back(vec1[i]);
                i++;
            }
            else
            {
                result.push_back(vec2[j]);
                j++;
            }
        }
        for (; i < vec1.size(); i++)
        {
            count[vec1[i].second] += j;
            result.push_back(vec1[i]);
        }
        for (; j < vec2.size(); j++)
        {
            result.push_back(vec2[j]);
        }
    }
    void merge_sort(vector<pair<int, int>> &vec,
                    vector<int> &count)
    {
        if (vec.size() < 2)
        {
            return;
        }
        int mid = vec.size() / 2;
        vector<pair<int, int>> sub_vec1;
        vector<pair<int, int>> sub_vec2;
        for (int i = 0; i < mid; i++)
        {
            sub_vec1.push_back(vec[i]);
        }
        for (int i = mid; i < vec.size(); i++)
        {
            sub_vec2.push_back(vec[i]);
        }
        merge_sort(sub_vec1, count);
        merge_sort(sub_vec2, count);
        vec.clear();
        merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);
    }
};



int main()
{
    vector<int> a{5, 2, 1}, count;
    Solution Solve;
    count = Solve.countSmaller(a);
    for (auto item : count)
    {
        cout << item << endl;
    }
}