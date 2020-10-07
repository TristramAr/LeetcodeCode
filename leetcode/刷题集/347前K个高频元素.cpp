#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> nums_map;   // <nums,record>
        for (int i = 0; i < nums.size(); i++)
        {
            nums_map[nums[i]]++;     
        }
        // priority_queue<int, vector<int>, greater<int>> heap; //最小堆构造方法
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto item : nums_map)
        {
            if (heap.size() < k)
            {
                //根据record排序，所以放在前面便于构建最小堆即<record,nums>
                heap.push(make_pair(item.second,item.first));
            }
            else if (heap.top().first < item.second)
            {
                heap.pop();
                heap.push(make_pair(item.second, item.first));
            }
        }
        vector<int> result;
        while (!heap.empty())
        {
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }
};

int main()
{
    vector<int> nums{1,1,1,2,2,3};
    int k = 2;
    Solution solve;
    vector<int> result = solve.topKFrequent(nums, k);
    for (auto item : result)
    {
        cout << item << " " << endl;
    }
}