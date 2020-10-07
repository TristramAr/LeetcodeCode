#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//双指针，滑动窗口法
class Solution
{
public:
    string minWindow(string s, string t)
    {
        const int MAX_ARRAY_LEN = 128;
        int map_t[MAX_ARRAY_LEN] = {0};
        int map_s[MAX_ARRAY_LEN] = {0};
        vector<int> vec_t; // 记录t字符串中有哪些字符
        //记录t字符串字符出现个数
        for (int i = 0; i < t.length(); i++)
        {
            map_t[t[i]]++;
        }
        //将字符串t中出现的字符储存在vec_t中
        for (int i = 0; i < MAX_ARRAY_LEN; i++)
        {
            if (map_t[i] >= 0)
            {
                vec_t.push_back(i);
            }
        }
        int window_begin = 0; //最小窗口指针
        string result;        //最小窗口对应到字符串
        for (int i = 0; i < s.length(); i++)
        {
            map_s[s[i]]++;
            while (window_begin < i)
            {
                char begin_ch = s[window_begin];
                if (map_t[begin_ch] == 0) // 该字符不在目标字符串中
                {
                    window_begin++;
                }
                else if (map_s[begin_ch] > map_t[begin_ch])
                {
                    map_s[begin_ch]--;
                    window_begin++;
                }
                else
                {
                    break;
                }
            }
            if (is_window_ok(map_s, map_t, vec_t))
            {
                int new_window_len = i - window_begin + 1;
                if (result == "" || result.length() > new_window_len)
                {
                    //截取new_window_len长度的字符串
                    result = s.substr(window_begin, new_window_len);
                }
            }
        }
        return result;
    }

private:
    // map_s[]当前处理的窗口中区间中的字符数量
    // map_t[]代表字串T的字符数量
    //判断当前窗口中是否包含所有目标
    bool is_window_ok(int map_s[], int map_t[], vector<int> &vec_t)
    {
        for (int i = 0; i < vec_t.size(); i++)
        {
            if (map_s[vec_t[i]] < map_t[vec_t[i]])
            {
                return false;
            }
        }
        return true;
    }
};
//滑动窗口+双map
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int start = 0, minLen = INT_MAX;
        int right = 0;
        int left = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> target;
        for(char i:t)
            target[i]++;
        int match = 0;
        while(right<s.length())
        {
            //如果当前字符是目标
            if(target[s[right]])
            {
                window[s[right]]++;
                if(window[s[right]]==target[s[right]])
                {
                    match++;
                }
            }
            right++;
            while(match==target.size())
            {
                if(right-left<minLen)
                {
                    start = left;
                    minLen = right - left;
                }
                if(target[s[left]])
                {
                    window[s[left]]--;
                    if(window[s[left]]<target[s[left]])
                    {
                        match--;
                    }
                }
                left++;
            }
        }
        return minLen == INT_MAX ?
                "" : s.substr(start, minLen);
    }
};