#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    //不开辟新空间，原地操作
    int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0) return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while (j < len)
        {
            if(nums[i]!=nums[j])
            {
                if(j-i>1)
                {
                    nums[i+1] = nums[j];
                    i++; 
                }
            }
            j++;
        }
        return i+1;   //返回数组前i+1个数，即为去重数组
    }
    //STL的find（）函数查找
    vector<int> remove(vector<int>&nums)
    {
        vector<int> res;
        if(nums.size()==0)
            return res;
        for (int i = 0; i < nums.size();i++)
        {
            if (find(res.begin(), res.end(),nums[i])==res.end())
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
int main()
{
    vector<int> nums{1, 1, 1, 2, 3, 4, 4, 5, 5, 2, 1, 1, 3};
    Solution solve;
    // int res = solve.removeDuplicates(nums);
    // for (int i = 0; i < res; i++)
    // {
    //     cout << nums[i]<<" ";
    // }
    vector<int> res = solve.remove(nums);
    for(auto i:res)
    {
        cout << i<<" ";
    }
}