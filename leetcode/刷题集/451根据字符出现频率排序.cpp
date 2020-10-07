#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> s_map;
        for (auto item : s)
        {
            s_map[item]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> heap;  //最大堆
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto item : s_map)
        {
            heap.push(make_pair(item.second, item.first));
        }
        string result = "";
        while (!heap.empty())
        {
            int k = heap.top().first;
            while (k--)
            {
                result += heap.top().second;
            }
            heap.pop();
        }
        return result;
    }
};
int main()
{
    string s = "tree";
    Solution solve;
    string res = solve.frequencySort(s);
    cout << res << endl;


}