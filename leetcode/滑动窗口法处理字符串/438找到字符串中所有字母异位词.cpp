/*关于滑动窗口法的leetcode总结
https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int left = 0;
        int right = 0;
        // 记录 window 中已经有多少字符符合要求了
        int match_num = 0;
        vector<int> res;
        int start = 0;
        int minLen = INT_MAX;
        unordered_map<char, int> window;
        unordered_map<char, int> target;
        for (auto i : p)
            target[i]++;

        while(right<s.size())
        {
            char c1 = s[right];
            // 哈希表的count函数返回0或1 ，判断是否有被查找元素，而不是对该元素进行计数
            if(target.count(c1))
            {
                window[c1]++;
                if(window[c1]==target[c1])
                {
                    match_num++;
                }
            }
            right++;
            while(match_num==target.size())
            {
                if(right-left==p.size())
                {
                    res.push_back(left);
                }
                char c2 = s[left];
                //如果left指针所指向的字符是目标字符，为了移动left指针，并维护窗口
                //在window map中去掉该字符，
                if(target.count(c2))
                {
                    window[c2]--;
                    // 该情况下匹配字符数减少，不能满足要求。后续将继续移动right指针
                    if(window[c2]<target[c2])
                    {
                        match_num--;
                    }
                }
                left++;
            }
        }
        return res;
    }
};