#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//运用有限状态机                                    
class Solution_1
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int STATE = BEGIN;
        int max_length = 1; // 根据题意摇摆序列最大长度至少为1
        for (int i = 1; i < nums.size(); i++)
        {
            switch (STATE)
            {
            case BEGIN:
            {
                if (nums[i] > nums[i - 1])
                {
                    STATE = UP;
                    max_length++;
                }
                else if (nums[i] < nums[i - 1])
                {
                    STATE = DOWN;
                    max_length++;
                }
                break;
            }
            case UP:
            {
                if (nums[i] < nums[i - 1])
                {
                    STATE = DOWN;
                    max_length++;
                }
                break;
            }
            case DOWN:
            {
                if (nums[i] > nums[i - 1])
                {
                    STATE = UP;
                    max_length++;
                }
                break;
            }
            }
        }
        return max_length;
    }
};

// 通过
//input:1 7 4 9 2 5
//求差值正负：1 ，-1，1，-1，1
//判断两两乘积是否<0 ，是则+1 
class Solution_2 {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> sym;
        int tmp;
        for (int i = 1; i < nums.size(); ++i) {
            tmp = nums[i] - nums[i - 1];
            if (tmp != 0)
                sym.push_back(tmp > 0 ? 1 : -1);
        }
        int res = 1;
        for (int i = 1; i < sym.size(); ++i) {
            if (sym[i] * sym[i - 1] == -1) res += 1;    // 通过判断正负变化
        }
        return sym.empty() ? res : res + 1;             // 这里举例可明白
    } 
};