#include <iostream>
#include <vector>
using namespace std;
class CountSort
{
public:
    void countSort(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return;
        }
        int max = nums[0];
        for (auto item : nums)
        {
            if (item > max)
            {
                max = item;
            }
        }
        vector<int> bucket(max + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            bucket[nums[i]]++;
        }
        int index = 0;
        int i = 0;
        while (index < nums.size())
        {
            if (bucket[i] != 0)
            {
                nums[index] = i;
                bucket[i]--;
                index++;
            }
            else
            {
                i++;
            }
        }
    }
    void countSort_1(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return;
        }
        int min = nums[0];
        int max = nums[0];
        //找到数组的最大值和最小值
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
            if (nums[i] < min)
            {
                min = nums[i];
            }
        }
        //如果数据不是从0开始的，为了使bucket数组的下标和要排序的数组对应，采用bias变量使原始数据从0开始
        // 这样可以减少内存，例如数据几种在100-150之间，只需要开辟一个size = 51 的计数数组
        vector<int> bucket(max - min + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            bucket[nums[i] - min]++;
        }
        int index = 0;
        int i = 0;
        while (index < nums.size())
        {
            if (bucket[i] != 0)
            {
                nums[index] = i + min;
                bucket[i]--;
                index++;
            }
            else
            {
                i++;
            }
        }
    }
    vector<int> countSort_2(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        if (nums.size() == 0)
        {
            return nums;
        }
        int min = nums[0];
        int max = nums[0];
        //找到数组的最大值和最小值
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
            if (nums[i] < min)
            {
                min = nums[i];
            }
        }
        //如果数据不是从0开始的，为了使bucket数组的下标和要排序的数组对应，采用bias变量使原始数据从0开始
        // 这样可以减少内存，例如数据几种在100-150之间，只需要开辟一个size = 51 的计数数组
        // int bias = 0 - min;
        vector<int> bucket(max - min + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            bucket[nums[i] - min]++;
        }
        //累加数组
        //这时bucket中存储的是数据的排序后的最大位置
        for (int i = 1; i < bucket.size(); i++)
        {
            bucket[i] = bucket[i] + bucket[i - 1];
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result[bucket[nums[i] - min] - 1] = nums[i];
            bucket[nums[i] - min]--;
        }
        return result;
    }
};

int main()
{
    vector<int> nums{3,3,4,4,6,6,6,6,6,5,5,5,5,4,4,2,2,8,8};
    CountSort sort;
    vector<int>result=sort.countSort_2(nums);
    for (auto item : result)
    {
        cout << item << " ";
    }
}