#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, char> word_map;  //单词刀pattern的映射
        char used[128] = {0};        // 已被映射的pattern字符
        string word;                 //临时保存拆分的单词
        int pos=0;                   //当前指向pattern的位置,
        str.push_back(' ');           //在尾部增加一个空格
        for (int i = 0; i < str.length();i++)
        {
            if(str[i]==' ')
            {
                if(pos == pattern.length())   //没有pattern模板 
                {
                    return false;
                }
                if(word_map.find(word)==word_map.end())   //若单词未出现在哈希映射
                {
                    if(used[pattern[i]])            //如果pattern中的模板已经使用过，必然已经创建了映射
                    {
                        return false;
                    }
                    word_map[word] = pattern[pos];   //建立单词和模板的映射
                    used[pattern[pos]] = 1;
                }
                else
                {
                    if(word_map[word]!=pattern[pos])
                    {
                        return false;
                    }
                }
                word = "";
                pos++;    //处理完一个单词后累加
            }
            else
            {
                word += str[i];
            }
        }
        if(pos!=pattern.length())
        {
            return false;
        }
        return true;
    }
};