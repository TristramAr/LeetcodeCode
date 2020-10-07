#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h> 
#include<assert.h>
#include <algorithm>
using namespace std;
void merge_sort_two_vec(vector<int> &vec_1,
                        vector<int> &vec_2,
                        vector<int> &result)
{
    int i = 0;
    int j = 0;
    while(i<vec_1.size()&&j<vec_2.size())
    {
        if(vec_1[i]<=vec_2[j])
        {
            result.push_back(vec_1[i]);
            i++;
        }
        else{
            result.push_back(vec_2[j]);
            j++;
        }
    }
    for (; i < vec_1.size();i++)
    {
        result.push_back(vec_1[i]);
    }
     for (; j < vec_2.size();j++)
    {
        result.push_back(vec_2[j]);
    }
}
//分而治之
void merge_sort(vector<int> &vec)
{
    if(vec.size()<2)
    {
        return;
    }
    int mid = vec.size()/2;
    //分割数组
    vector<int> vec_1;
    vector<int> vec_2;
    for (int i = 0; i < mid;i++)
    {
        vec_1.push_back(vec[i]);
    }
    for (int i = mid; i < vec.size();i++)
    {
        vec_2.push_back(vec[i]);
    }
    merge_sort(vec_1);
    merge_sort(vec_2);
    vec.clear();
    merge_sort_two_vec(vec_1, vec_2,vec);
}

int main()
{
  
    vector<int> nums{5, 2, 12, 32, 14};
    merge_sort(nums);
    for(auto item:nums)
    {
        cout << item << " ";
    }

    return 0;
}