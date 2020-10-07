#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0;
        int result = 0;
        string word = "";
        int char_map[128] = {0};
        for (int i = 0; i < s.size();i++)
        {
            char_map[s[i]]++;
            if(char_map[s[i]]==1)//word中没有出现过该字符
            {
                word.push_back(s[i]);
                if(result<word.length())
                {
                    result = word.length();
                }
            }
            else{
                //删去重复字符
                while(begin<i&&char_map[s[i]]>1)
                {
                    char_map[s[begin]]--;
                    begin++;
                }
            }
            word = "";
            for (int j = begin; j <= i;j++)
            {
                word.push_back(s[j]);
            }
        }
        return result;
    }
};
//滑动窗口写法2
class Solution_2 {
public:
    int lengthOfLongestSubstring(string s) {
        int right = 0;
        int left = 0;
        int result = 0;
        unordered_map<char, int> window;
        while(right<s.length())
        {
            window[s[right]]++;
            right++;
            while(window[s[right]]>1)
            {
                window[s[left]]--;
                left++;
            }
        }
        result = max(result, right - left);

    }
};

int main()
{
    string s = "abcccccad";
    Solution_2 solve;
    int result = solve.lengthOfLongestSubstring(s);
    cout << result << endl;
}
