#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    string findLongestWord(string s, vector<string> &d)
    {
        string res;
        int res_len = 0;
        for (int i = 0; i < d.size(); i++)
        {
            if (is_word(s, d[i]))
            {
                if (d[i].length() > res_len)
                {
                    res_len = d[i].length();
                    res = d[i];
                }
                 if(d[i].length()==res_len)
                {
                    if(d[i][0]<res[0])
                    {
                        res = d[i];
                    }
                }
            }
        }
        return res;
    }

private:
    bool is_word(string s, string word)
    {
        int i = 0;
        int j = 0;
        while (i < s.length())
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
int main()
{
    vector<string> d{"ba","ab","a","b"};
    string s = "bab";
    Solution solve;
    string res = solve.findLongestWord(s, d);
    for (auto item : res)
    {
        cout << item << " ";
    }
}
