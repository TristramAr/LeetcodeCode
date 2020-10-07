/*用一个栈储存各个状态的最小值*/
#include <stack>
#include <iostream>
using namespace std;

class MinStack
{
public:
    void push(int x)
    {
        _data.push(x);     //压缩数据栈
        // 如果_min为空，直接push
        if (_min.empty())
        {
            _min.push(x);
        }
        // 非空，比较大小
        else
        {
            // 新插入值大于栈顶值，保留原值
            if (x > _min.top())
            {
                x = _min.top();  
            }
            _min.push(x);
        }
    }
    void pop()
    {
        _data.pop();
        _min.pop();
    }
    int top()
    {
        return _data.top();
    }
    int getMin()
    {
        return _min.top();
    }
private:
    stack<int> _data; //数据栈
    stack<int> _min;  //最小值栈
};
