#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int cookies = 0;
        while (count < g.size()&&cookies<s.size())
        {
            if(s[cookies]>=g[count])
            {
                count++;
            }
                cookies++;    //无论是否满足都要+1；
        }
        return count;
    }
};