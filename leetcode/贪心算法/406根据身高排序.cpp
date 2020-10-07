#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 不要用vector的操作方式进行比较
bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] > b[0])
    {
        return true;
    }
    if (a[0]==b[0] && a[1] < b[1])
    {
        return true;
    }
    return false;
}
//运用这个排序方式会出现错误，虽然和上边表示的意思相同但是会出现错误
bool cmp_2(vector<int> &a, vector<int> &b)
{
    if (a.begin() > b.begin())
    {
        return true;
    }
    if (a.begin() == b.begin() && a.back() < b.back())
    {
        return true;
    }
    return false;
}
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), cmp);
        if (people.size() < 2)
        {
            return people;
        }
        vector<vector<int>> result;
        for (int i = 0; i < people.size(); i++)
        {
            if (people[i][1] < i)
            {
                result.insert(result.begin() + people[i][1], people[i]);
            }
            else
            {
                result.push_back(people[i]);
            }
        }
        return result;
    }
};
int main()
{
    vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> result;
    Solution solve;
    result = solve.reconstructQueue(people);
    for(auto item:result)
    {
        for(auto i:item)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}