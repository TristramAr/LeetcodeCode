#include <iostream>
#include <vector>
using namespace std;
class MergeSort
{
public:
    void mergeSort(vector<int> &nums, int left, int right)
    {
        if(right<=left)
        {
            return;
        }
        int mid = left+(right-left)/2;
        //递归划分
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums, left, mid,right);
    }

private:
     void merge(vector<int> &nums, int left, int mid, int right)
    {
        int temp[right-left+1];
        int i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid)
        {
            temp[k++] = nums[i++];
        }
        while (j <= right)
        {
            temp[k++] = nums[j++];
        }
        for (i = 0; i < k; i++)
        {
            nums[left++] = temp[i];
        }
    }
};
//非递归
class Solution
{
public:
    void mergeSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i += i)
        {
            int left = 0;
            int mid = left + i - 1;
            int right = mid + i;
            while (right < n)
            {
                merge(nums, left, mid, right);
                left = right + 1;
                mid = left + i - 1;
                right = mid + i;
            }
            if (left < n && mid < n)
            {
                merge(nums, left, mid, n - 1);
            }
        }
    }
private:
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        int temp[right-left+1];
        int i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right)
        {
            if (nums[i] < nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid)
        {
            temp[k++] = nums[i++];
        }
        while (j <= right)
        {
            temp[k++] = nums[j++];
        }
        for (i = 0; i <k; i++)
        {
            nums[left++] = temp[i];
        }
    }
};
int main()
{
    vector<int> nums{1,1};
    MergeSort sort;
    sort.mergeSort(nums,0,nums.size()-1);
    // Solution solve;
    // solve.mergeSort(nums);
    for (auto item : nums)
    {
        cout << item << " ";
    }
}