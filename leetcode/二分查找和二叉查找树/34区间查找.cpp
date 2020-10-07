#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result;
        result.push_back(left_bound(nums, target));
        result.push_back(right_bound(nums, target));
        return result;
    }

private:
    //找区间左端点
    int left_bound(vector<int> &nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;

        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (target == nums[mid])
            {
                if ( mid == 0||nums[mid - 1] < target ) // 这里必须先判断mid=0，否则，如果mid=0时，先判断nums[mid-1] 会出现数组越界
                {
                    return mid;
                }
                end = mid - 1;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                begin = mid + 1;
            }
        }
        return -1;
    }
    //右端点
    int right_bound(vector<int> &nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;

        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (target == nums[mid])
            { // 举例看看
                if (mid == nums.size() - 1 || nums[mid + 1] > target) //这里必须先判断mid==nums.size()-1;
                {
                    return mid;
                }
                begin = mid + 1;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                begin = mid + 1;
            }
        }
        return -1;
    }
};
class Solution_2
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result;
        result.push_back(left_bound(nums, target));
        result.push_back(right_bound(nums, target));
        return result;
    }

private:
    //找区间左端点
    int left_bound(vector<int> &nums, int target)
    {
        int begin = 0;
        int end = nums.size();

        while (begin < end)   //当begin==end时循环结束
        {
            int mid = (begin + end) / 2;
            if (target == nums[mid])
            {
                end = mid;    //向左缩小边界
            }
            else if (target < nums[mid])
            {
                end = mid ;
            }
            else if (target > nums[mid])
            {
                begin = mid+1;
            }
        }
        //如果target 比所有元素大
        if(begin==nums.size()) 
        {
            return -1;
        }
        // 如果target太小，在搜索区间向左缩小到最后也而没能找到
        return nums[begin]==target? begin:-1;
    }
    //右端点
    int right_bound(vector<int> &nums, int target)
    {
        int begin = 0;
        int end = nums.size();

        while (begin < end)
        {
            int mid = (begin + end) / 2;
            if (target == nums[mid])
            { 
                begin=mid+1;   //向右缩小边界
            }
            else if (target < nums[mid])
            {
                end = mid;
            }
            else if (target > nums[mid])
            {
                begin = mid + 1;
            }
        }
        //如果target比所有元素都笑
        if (begin == 0) return -1;
        //如果target比所有元素都要大，不断向右缩小边界，到最右也没找到 返回 -1；
        return nums[begin-1] == target ? (begin-1) : -1;
    }
};

int main()
{
    vector<int> nums{5, 7, 7, 8, 8, 8, 8, 10,11};
    Solution solve;
    vector<int> result=solve.searchRange(nums, 8);
    for(auto item:result)
    {
        cout << item << endl;
    }
    return 0;
}