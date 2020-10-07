#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void shellSort(vector<int> &nums)
    {
        int len = nums.size();
        if (len < 2)
        {
            return;
        }
        int gap = len / 2;
        while (gap)
        {
            for (int i = gap; i < len; i++)
            {
                for (int j = i; j > gap; j-=gap)
                {
                    //将当前值nums[j]与已排序的（0，j-1）部分对比
                    //如果nums[j]<nums[j-1]，交换，不断向左边进行。直到nums[j]>=nums[j-1],停止
                    if (nums[j] < nums[j - gap])
                    {
                        //    swap(nums[j], nums[j - gap]);
                        int temp = nums[j - gap];
                        nums[j - gap] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
            gap /= 2;
        }

        return;
    }
};
int main()
{
    vector<int> nums{0, 6, 5, 1, 2, 4, 3, 8, 12, 9, 1};
    Solution solve;
    solve.shellSort(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
}