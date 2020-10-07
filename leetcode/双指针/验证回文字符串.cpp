#include <iostream>
using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        if (s.size() <= 2)
        {
            return true;
        }
        int left = 0;
        int right = s.size() - 1;
        while (left < right && s[left] == s[right])
        {
            left++;
            right--;
        }
        return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
    }

private:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (i < j && s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }
};