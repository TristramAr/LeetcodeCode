#include<stack>
#include<iostream>
using namespace std;

class MyQueue
{
    public:

    //建立临时栈
    void push(int x)
    {
        stack<int> temp_stack;
        while(!_data.empty())
        {
            temp_stack.push(_data.top());
            _data.pop();
        }
        temp_stack.push(x);
        while(!temp_stack.empty())
        {
            _data.push(temp_stack.top());
            temp_stack.pop();
        }
    }

    int pop()
    {
        int x;
        x = _data.top();
        _data.pop();
        return x;
    }
    //返回队列的首元素
    int peek()
    {
        return _data.top();
    }
    bool empty()
    {
        return _data.empty();
    }
    private:
        stack<int> _data;

};