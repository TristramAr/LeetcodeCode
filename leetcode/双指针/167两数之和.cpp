#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int l = 0;
        int r = numbers.size()-1;
        
        while (l<r){
            int temp = numbers[l]+numbers[r];
            if(temp == target){
                result.push_back(l+1);
                result.push_back(r+1);
                return result;
            }
            else if (temp>target)
                r--;
            else 
                l++;
        }
        return vector<int>(-1,-1);
        
    }
};


