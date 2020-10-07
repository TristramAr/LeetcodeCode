#include <iostream>
#include <vector>

using namespace std;
//冒泡排序
class BubbleSort
{
public:
   void bubbleSort(vector<int> &nums)
    {
        int len = nums.size();
        if(len<2)
        {
            return;
        }
        for (int i = 0; i < len;i++)
        {
            bool mark = true;
            for (int j = 0; j < len - i - 1;j++)
            {
                if(nums[j+1]<nums[j])
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    mark = false;
                }
            }
            if(mark)
            {
                return;
            }
        }
    }
};

int main()
{
    vector<int> nums{4,5,1,2,4,3,9,1};
    BubbleSort solve;
    solve.bubbleSort(nums);
    for(auto i:nums)
    {
        cout << i << " ";
    }
}