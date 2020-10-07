#include<iostream>
#include<stack>
#include<map>
#include <vector>
using namespace std;
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& T) {
//         vector <int> ans (T.size(), 0);
//         stack <int> res;
//         for(int i = T.size()-1; i >= 0; --i)
//         {
//             while(!res.empty() && T[i] >= T[res.top()]) res.pop();
//             if(res.empty())
//                 ans[i] = 0;
//             else
//                 ans[i] = res.top() - i;
//             res.push(i);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> T_index;
        vector<int> result(T.size(),0);
        for(int i = 0 ; i<T.size();i++){
            while(!T_index.empty()&&T[i]>T[T_index.top()]){
                result[T_index.top()]=i-T_index.top();
                T_index.pop();
            }
            // 栈是否为空放在while循环后面，防止while中pop完所有元素。
            if(T_index.empty())
            {
                T_index.push(i);
                // result.push_back(0);
            }
//             温度相等不算
            if(T[i]<=T[T_index.top()]){
                T_index.push(i);
            }
        }
        return result;
    }
}D;
int main()
{
    vector<int> T= {73,74,75,71,69,72,76,73};
    vector<int> result(T.size(),0);
    result= D.dailyTemperatures(T);
    for(int i=0;i<T.size();i++)
    {
        cout << result[i]<<endl;
    }
   
}