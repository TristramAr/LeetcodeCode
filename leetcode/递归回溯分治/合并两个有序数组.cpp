#include <iostream>
#include <vector>
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
     for (; j < vec_1.size();j++)
    {
        result.push_back(vec_2[j]);
    }
}