#include <iostream>
#include <vector>
using namespace std;
// 方法一
class QuickSort
{
public:
    //left right 表示数组第一和最后一个元素的索引
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int j = partition(nums, left, right);
        quickSort(nums, left, j - 1);
        quickSort(nums, j + 1, right);
    }

private:
    //切分函数很重要，很多地方都用的着
    int partition_1(vector<int> &nums, int left, int right)
    {
        int base = nums[left];
        int i = left + 1;
        int j = right;
        while (i<=j)
        {
            //当遇到数大于等于基准是返回i。
            while (i <= j && nums[i] <= base)
            {
                i++;
            }

            while (i <= j && nums[j] >= base)
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
    int partition(vector<int> &nums, int left, int right)
    {
        int base = nums[left];
        int i = left - 1;
        int j = right + 1;
        while (true)
        {
            //当遇到数大于等于基准是返回i。
            while (nums[++i] < base && i < right);

            while (nums[--j] > base && j > left);
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


//方法二
int partition(vector<int>&a, int p, int r)
{
    int x = a[r - 1];
    int i = p - 1;
    for (int j = p; j < r - 1; ++j)
    {
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r - 1]);
    return i + 1;
}
void quicksort(vector<int>&a, int p, int r)
{
    if (p < r - 1)
    {
        int q = partition(a, p, r);
        quicksort(a, p, q);
        quicksort(a, q + 1, r);
    }
}
int main()
{
    vector<int> nums{1, 2, 3, 4, 4, 5, 5, 2, 1, 1, 3};
    QuickSort sort;
    sort.quickSort(nums, 0, nums.size() - 1);
    for (auto item : nums)
    {
        cout << item << " ";
    }
}