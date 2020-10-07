/*
 * @Description: 
 * @Author: feng
 * @Date: 2020-02-23 11:48:31
 * @LastEditTime: 2020-09-09 10:20:34
 * @LastEditors: feng
 */
#include<iostream>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int char_map[128] = {0};
        int max_length = 0;
        int flag = 0;      //防止错加
        //用哈希表统计各字符的数目
        for (int i = 0; i < s.length();i++)
        {
            char_map[s[i]]++;
        }
        for (int i = 0; i < 128;i++)
        {
            //如果该字符为偶数个，则全可以用上
            if(char_map[i]%2==0)
            {
                max_length += char_map[i];
            }
            // 若为奇数，剔除一个，其他的接着用
            else
            {
                max_length += char_map[i] - 1;
                flag = 1;
            }

        }
        return max_length + flag;
    }
};
int main()
{
    string s = "abcdcbaa";
    Solution solve;
    cout<<solve.longestPalindrome(s);
    return 0;
}