#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution_1
{
public:
    string removeKdigits(string num, int k)
    {
        vector<int> S;
        string result = "";
        for (int i = 0; i < num.length(); i++)
        {
            //将字符的num转化为整型使用
            int number = num[i] - '0';
            while (S.size() != 0 && k > 0 && S.back() > number)
            {
                S.pop_back();
                k--;
            }
            if (number != 0 || S.size() != 0)
            {
                S.push_back(number);
            }
        }
        while (S.size() != 0 && k > 0)
        {
            S.pop_back();
            k--;
        }
        for (int i = 0; i < S.size(); i++)
        {
            result.append(1, '0' + S[i]); //1表示该字符添加次数
        }
        if (result == "")
        {
            result = "0";
        }
        return result;
    }
};



int main()
{
    Solution_1 solve;
    string result = solve.removeKdigits("124135", 3);
    cout << result << endl;
}