#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int left = 0;
        int right = 0;
        int match_num = 0;
        // 记录最短子串的开始位置和长度
        int start = 0;
        int minLen = INT_MAX;   //最大int值不溢出的值
        string res = s;
        unordered_map<char, int> window;
        //构建targetmap
        unordered_map<char, int> target;
        for (char i : t)
            target[i]++;
        while (right < s.size())
        {
            char c1 = s[right];
            // 如果该字符在target中
            if (target.count(c1))
            {
                window[c1]++;
                if (window[c1] == target[c1])
                {
                    match_num++;
                }
            }
            right++;
            while (match_num == target.size())
            {
                if (right - left < minLen)
                {
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if (target.count(c2))
                {
                    window[c2]--;
                    if (window[c2] < target[c2])
                    {
                        match_num--;
                    }
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
