#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<int> index; //最远到大的位置
        for (int i = 0; i < nums.size(); i++)
        {
            index.push_back(i + nums[i]);
        }
        int jump = 0;
        int max_index = index.front();
        while (jump < nums.size() && jump <= max_index)
        {
            if (max_index < index[jump])
            {
                max_index = index[jump];
            }
            jump++;
        }
        if (jump == nums.size())
        {
            return true;
        }
        return false;
    }
};

//大佬代码
class Solution_2
{
public:
    bool canJump(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k)
                return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};


