#include <iostream>
#include <vector>
#include <stack>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        //借助set来查找，降低时间复杂度
        unordered_set<int> my_set(nums.begin(),nums.end());
        int res = 0;
        for(auto num:nums)
        {
            //如果没有比当前值小的数，则以这个数开头，查找连续序列
            if(my_set.count(num-1)==0)
            {
                int next = num+1;
                while(my_set.count(next))
                {
                    next++;
                }
                res = max(res,next-num);
            }
            
        }
        return res;
    }
};
int main()
{
    vector<int> nums{100, 4, 200, 1, 3, 2};
    Solution solve;
    cout<<  solve.longestConsecutive(nums);
    return 0;
}