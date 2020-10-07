#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
   void insertSort(vector<int>&nums)
   {
       int len = nums.size();
       if(len<2)
       {
           return;
       }
       for (int i = 1; i < len;i++)
       {
           for (int j = i; j > 0 ;j--)
           {
               //将当前值nums[j]与已排序的（0，j-1）部分对比
               //如果nums[j]<nums[j-1]，交换，不断向左边进行。直到nums[j]>=nums[j-1],停止
               if(nums[j]<nums[j-1])
               {
                   //    swap(nums[j], nums[j - 1]);
                   int temp = nums[j - 1];
                   nums[j - 1] = nums[j];
                   nums[j] = temp;
               }
           }
       }
       return;
   }

};
int main()
{
    vector<int> nums{0,6,5,1,2,4,3,8,12,9,1};
    Solution solve;
    solve.insertSort(nums);
    for(auto i:nums)
    {
        cout << i << " ";
    }
}