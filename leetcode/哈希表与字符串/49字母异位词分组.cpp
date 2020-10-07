#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//方法1
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> word_map;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (word_map.find(str) == word_map.end())
            {
                vector<string> item;
                word_map[str] = item;
            }
            //注意这里map的操作
            word_map[str].push_back(strs[i]);
        }
        //遍历map 的两种方式
        //方式一 迭代器，STL遍历容器的方法
        map<string, vector<string>>::iterator it;
        for (it = word_map.begin(); it != word_map.end(); it++)
        {
            result.push_back((*it).second);
        }
        //方式二
        // for (auto i : word_map)
        // {
        //     result.  (i.second);
        // }
        return result;
    }
};

// 方法二
//统计各个单词中字幕出现的数量，数量相同则为一组
class Solution_2
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<string>> word_map;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> vec;
            change_to_vector(strs[i], vec);
            if (word_map.find(vec) == word_map.end())
            {
                vector<string> item;
                word_map[vec] = item;
            }
            word_map[vec].push_back(strs[i]);
        }
        //遍历map 的两种方式
        //方式一
        map<vector<int>, vector<string>>::iterator it;
        for (it = word_map.begin(); it != word_map.end(); it++)
        {
            result.push_back((*it).second);
        }
        //方式二
        // for (auto i : word_map)
        // {
        //     result.push_back(i.second);
        // }
        return result;
    }

private:
    void change_to_vector(string &str, vector<int> &vec)
    {
        for (int i = 0; i < 26; i++)
        {
            vec.push_back(0);
        }
        for (int i = 0; i < str.length(); i++)
        {
            vec[str[i] - 'a']++;
        }
    }
};
int main()
{
    Solution solve;
    cout << sizeof(solve) << endl;
}