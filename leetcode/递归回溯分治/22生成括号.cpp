#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generate("", n, n, result);
        return result;
    }

private:
    //left 当前可以放置左括号的数量，right 当前可以放置右括号数量(注意都是剩余的数量)
    void generate(string item, int left, int right, vector<string> &result)
    {
        if (left <= 0 && right <= 0)
        {
            result.push_back(item);
            return;
        }
        if (left > 0)
        {
            generate(item + '(', left - 1, right, result);
        }
        if (left < right)
        {
            generate(item + ')', left, right - 1, result);
        }
    }
};
//生成所有括号组合
void generate(string item, int n, vector<string> &result)
{
    if (item.size() >= 2 * n) // 当括号的总数是组数的两倍时
    {
        result.push_back(item);
        return;
    }
    generate(item + '(', n, result);
    generate(item + ')', n, result);
}

int main()
{
    vector<string> result;
    generate("", 2, result);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].c_str() << endl;
    }
}