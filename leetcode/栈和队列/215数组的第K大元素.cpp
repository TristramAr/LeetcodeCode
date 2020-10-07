#include <stdio.h>
#include <queue>
#include<iostream>
using namespace std;

// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         //维护一个有k个元素的最小堆，最终堆顶元素即为所求
//         priority_queue<int, vector<int>, greater<int>> Q;   //最小堆
//         for (int i = 0; i < nums.size();i++)
//         {
//             if(Q.size()<k)
//             {
//                 Q.push(nums[i]);
//             }
//             else if(Q.top()<nums[i])
//             {
//                 Q.pop();
//                 Q.push(nums[i]);
//             }
//         }
//         return Q.top();
//     }
//     int findKthLargest_2(vector<int> &nums,int k)
//     {
//         priority_queue<int, vector<int>, less<int>> Q;   // 最大堆
//         for (int i = 0; i < nums.size();i++)
//         {
//             Q.push(nums[i]);
//         }
//         while (k-1)
//         {
//             Q.pop();
//             k--;
//         }
//         return Q.top();
//         }
// };
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int left = 0;
        int right = nums.size()-1;
        int target = nums.size()-k;
        while(left<right)
        {
            int j = partition(nums,left,right);
            if(j == target)
            {
                break;
            }
            else if(j<target)
            {
                left = j+1;
            }
            else if(j>target)
            {
                right = j-1;
            }
        }
        return nums[target];

    }
private:
    int partition(vector<int>&nums,int left,int right)
    {
        int base = nums[left];
        int i = left + 1;
        int j = right;
        while (true)
        {
            //当遇到数大于等于基准是返回i。
            while (i <= j && nums[i] < base)
            {
                i++;
            }

            while (i <= j && nums[j] > base)
            {
                j--;
            }
            if (i >= j)
            {
                break;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        nums[left] = nums[j];
        nums[j] = base;
        return j;
    }
};
int main()
{
    vector<int> nums{3, 2, 1, 5, 6, 4,7};
    int k = 2;
    Solution solve;
    int result=solve.findKthLargest(nums, k);
    cout << result << endl;
}