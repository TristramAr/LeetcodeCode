#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                //1,0,1,1,1,1,1
                if (nums[mid] > nums[begin])
                {
                    if (target >= nums[begin])
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        begin = mid + 1;
                    }
                }

                else if (nums[mid] < nums[begin]) 
                {
                    end = mid - 1;
                }
                else if(nums[mid]==nums[begin])
                {
                    begin = mid + 1;
                }
            }
            else if(target>nums[mid])
            {   //(begin,mid-1)为递增区间
                if(nums[mid]>nums[begin])
                {
                    begin = mid + 1;
                }
                //(mid+1,end) 为递增区间
                else if(nums[mid]<nums[begin])
                {
                    if(target>=nums[begin])
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        begin = mid + 1;
                    }  
                }
                else if(nums[mid]==nums[begin])
                {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};