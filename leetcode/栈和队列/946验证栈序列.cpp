#include<stack>
#include<queue>
#include<vector>
using namespace std;
// 测试序列存在一个队列中,
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n =pushed.size();
        stack<int>_pushed;
        queue<int>_popped;
        for(int i=0;i<n;i++)
        {
            _pushed.push(pushed[i]);
            _popped.push(popped[i]);
            while(!_pushed.empty()&&_pushed.top()==_popped.front())
            {
                _pushed.pop();
                _popped.pop();
            }
        }
        if(!_pushed.empty())
        {
            return false;
        }
        return true;
        
    }
};