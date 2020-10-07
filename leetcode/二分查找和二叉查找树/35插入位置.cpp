#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int index=-1; // 插入位置
        while (index==-1)
        {
            int mid = (begin + end) / 2;
            if(target == nums[mid])
            {
                index = mid;
            }
            else if(target<nums[mid])
            {
                if(target>nums[mid-1]||mid==0)    //边界处理
                {
                    index = mid;
                }
                end = mid - 1;
            }
            else if(target>nums[mid])
            {
                if(target<nums[mid+1]||mid==nums.size()-1)  //边界处理
                {
                    index = mid + 1;
                }
                begin = mid + 1;
            }
        }
        return index;
    }
};
int main()
{
    int test[] = {1, 3, 5, 6};
    vector<int> nums;
    Solution solve;
    for (int i = 0; i < 4;i++)
    {
        nums.push_back(test[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        cout << "i=" << i << " "<< "index=" << solve.searchInsert(nums,i) << endl;
    }
    return 0;
}