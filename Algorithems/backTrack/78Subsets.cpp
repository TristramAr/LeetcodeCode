#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
// class Solution
// {
// public:
//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         vector<vector<int>> result; // 储存最终结果
//         vector<int> item;           //回溯时产生的各个子集数组
//         result.push_back(item);     //将空集push进入result
//         generate(0, nums, item, result);
//         return result;
//     }

// private:
//     void generate(int i,
//                   vector<int> &nums,
//                   vector<int> &item,
//                   vector<vector<int>> &result)
//     {
//         if (i >= nums.size()) //递归结束的条件，必须要有，否则会陷入死循环
//         {
//             return;
//         }
//         item.push_back(nums[i]);
//         result.push_back(item);
//         generate(i + 1, nums, item, result);
//         item.pop_back();
//         generate(i + 1, nums, item, result);
//     }
// };
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> tmp;
		getResult(result, nums, 0, tmp);
		return result;
	}

	void getResult(vector<vector<int>>& result, vector<int> nums, 
                   int startPoint, vector<int> tmp) {
		result.push_back(tmp);
		for (int i = startPoint; i < nums.size(); i++) {

            tmp.push_back(nums[i]);
			getResult(result, nums, i + 1, tmp);
			tmp.pop_back();
		}
	}
};
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    // nums.push_back(4);

    // vector<int> item;
    vector<vector<int>> result;
    Solution solve;
    result = solve.subsets(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
        }
        cout << endl;
    }
    return 0;
}