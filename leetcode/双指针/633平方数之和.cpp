#include<iostream>
#include<algorithm>
#include<math.h>
using namespace  std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<0)
        {
            return false;
        }
        int left = 0; int right = sqrt(c);
        while(left<=right)
        {
            // long temp = left*left+right*right;
            //防止溢出不求temp 
            if(left*left==c-right*right)
            {
                return true;
            }
            else if(left*left<c-right*right)
            {
                left++;
            }
            else if(left*left>c-right*right)
            {
                right--;
            }
        }
        return false;
    }
};