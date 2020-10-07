#include<iostream>
#include<vector>
using namespace std;

#include<iostream>

class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
        {
            return x;
        }
        int begin = 0;
        int end = x;
        //注意条件为<=
        while(begin<end)
        {
            long long mid = (begin + end) / 2;
            long long res = mid * mid;
            if(res>=x)
                end = mid;
            else
                begin = mid + 1;
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
