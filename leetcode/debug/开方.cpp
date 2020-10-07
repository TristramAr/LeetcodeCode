#include<iostream>

class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
        {
            return x;
        }
        int begin = 0;
        int end = x / 2;
        // 注意条件
        while(begin<=end)
        {
            long long mid = (begin + end) / 2;
            long long res = mid * mid;
            if(res==x)
            {
                return mid;
            }
            else if(res<x)
            {
                begin = mid + 1;
            }
            else if(res>x)
            {
                end = mid - 1;
            }

        }
        return end;
    }
};

int main()
{
    Solution Solve;
    std::cout<<Solve.mySqrt(6);
    return 0;
}