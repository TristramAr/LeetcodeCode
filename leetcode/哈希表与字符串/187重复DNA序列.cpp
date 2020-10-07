#include <iostream>
#include <vector>
#include <map>
using namespace std;
//方法1
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        map<string, int> word_map;
        vector<string> result;
        for (int i = 0; i < s.length(); i++)
        {
            //substr返回一个从指定位置开始，并具有指定长度的子字符串
            string word = s.substr(i, 10);
            if (word_map.find(word) != word_map.end())
            {
                word_map[word]++;
            }
            else
            {
                word_map[word] = 1;
            }
        }
        map<string, int>::iterator it;
        for (it = word_map.begin(); it != word_map.end(); it++)
        {
            if (it->second > 1)
            {
                result.push_back(it->first);
            }
        }
        return result;
    }
};
//方法2
int g_hash_map[1048576] = {0};
class Solution_2
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> result;
        if (s.length() < 10)
        {
            return result;
        }
        //因为设置的是全局变量，所以每次调用的时候都要进行归零

        for (int i = 0; i < 1048576; i++)
        {
            g_hash_map[i] = 0;
        }
        int char_map[128] = {0};
        char_map['A'] = 0;  //00
        char_map['C'] = 1;  //01
        char_map['G'] = 2;  //10
        char_map['T'] = 3;  //11
        int key = 0;
        for (int i = 9; i >= 0; i--)
        {
            // 从第10各字符倒着读
            //key值左移2个字符（乘4）
            key = (key << 2) + char_map[s[i]];
        }
        g_hash_map[key] = 1;
        for (int i = 10; i < s.length(); i++)
        {
            //先把AAAAACCCCCT右移去掉第一个字符A
            key = key >> 2;
            //添加一个T到最高位
            //先将新字符左移18尾变到最高位，然后和key进行或运算
            key = key | char_map[s[i]] << 18;
            g_hash_map[key]++;
        }
        for (int i = 0; i < 1048576; i++)
        {
            if (g_hash_map[i] > 1)
            {
                result.push_back(change_int_toDNA(i));
            }
        }
        return result;
    }

private:
    string change_int_toDNA(int DNA)
    {
        static const char DNA_CHAR[] = {'A', 'C', 'G', 'T'};
        string str;
        for (int i = 0; i < 10; i++)
        {
            //将int值二进制的最后两位翻译出对应的字母
            //例如85
            //00 00 00 00 00 01 01 01 01 01    85
            //00 00 00 00 00 00 00 00 00 11    3
            //与运算后位 01 ，C字母
            str += DNA_CHAR[DNA & 3];
            //左移2位，去掉最后一个字符
            DNA = DNA >> 2;
        }
        return str;
    }
};
int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution_2 solve;
    vector<string> result = solve.findRepeatedDnaSequences(s);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].c_str() << endl;
    }
    return 0;
}