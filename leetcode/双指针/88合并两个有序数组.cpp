#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        int p=0;
        vector<int>nums;
        nums = nums1;
        while(i<m&&j<n)
        {
            if(nums[i]<nums2[j])
            {
                nums1[p] = nums[i];
                i++;
            }
            else
            {
                nums1[p] = nums2[j];
                j++;
            }
            p++;
        }
        while(i<m)
        {
            nums1[p++] = nums[i++];
        }
        while(j<n)
        {
            nums1[p++] = nums2[j++];
        }
    }
};
class Solution_2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int p = m+n-1;
        while(i>=0&&j>=0)
        {
            // if(nums1[i]>nums2[j])
            // {
            //     nums1[p] = nums1[i];
            //     i--;
            // }
            // else
            // {
            //     nums1[p] = nums2[j];
            //     j--;
            // }
            // p--;
            nums1[p--] = (nums1[i--] > nums2[j--]) ? nums1[i--] : nums2[j--];
        }
        while(i>=0)
        {
            nums1[p--] = nums1[i--];
        }
        while(j>=0)
        {
            nums1[p--] = nums2[j--];
        }
    }
};
int main()
{
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    int m = 3;
    int n = 3;
    Solution solve;
    solve.merge(nums1, m, nums2, n);
    for(auto item:nums1)
    {
        cout << item << " ";
    }

}
