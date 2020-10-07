#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string findLongestWord(string s, vector<string>& d) { 
        int res_len = 0;
        string result;
        for(int i =0;i<d.size();i++)
        {
            if(is_word(s,d[i]))
            {
                if(d[i].length()>res_len)
                {
                    res_len = d[i].length();
                    result = d[i];
                }
                if(d[i].length()==res_len)
                {
                    if(d[i][0]<result[0])
                    {
                        result = d[i];
                    }
                }
            }
        }
        return result;
    }

private:
    bool is_word(string s, string word)
    {
        if (s.size() < word.size())
        {
            return false;
        }
        int i = 0;
        int j = 0;
        while (i < s.size())
        {
            if (s[i] == word[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j == word.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};