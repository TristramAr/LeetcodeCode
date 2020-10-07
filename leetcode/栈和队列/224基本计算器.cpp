#include <stdio.h>
#include <stack>
#include <string>
using namespace std;
void compute(stack<int> &number_stack,
             stack<char> &operation_stack)
{
    if (number_stack.size() < 2)
    {
        return;
    }
    int num2 = number_stack.top();
    number_stack.pop();
    int num1 = number_stack.top();
    number_stack.pop();
    if (operation_stack.top() == '+')
    {
        number_stack.push(num1 + num2);
    }
    else if (operation_stack.top() == '-')
    {
        number_stack.push(num1 - num2);
    }
    operation_stack.pop();
}
class Solution
{
public:
    int calculate(string s)
    {
        static const int STATE_BEGIN = 0;
        static const int NUMBER_STATE = 1;
        static const int OPERSTION_STATE = 2;
        stack<char> operation_stack;
        stack<int> number_stack;
        int number = 0;
        int STATE = STATE_BEGIN;
        int compute_flag = 0;
        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            //有限状态自动机
            switch (STATE)
            {
            case STATE_BEGIN:
                if (s[i] >= '0' && s[i] <= '9')
                {
                    STATE = NUMBER_STATE;
                }
                else
                {
                    STATE = OPERSTION_STATE;
                }
                i--;  //退格操作，方便后续状态中将字符压入相应栈中 
                break;
            case NUMBER_STATE:
                if (s[i] >= '0' && s[i] <= '9')
                {
                    number = number * 10 + s[i] - '0';
                }
                else
                {
                    number_stack.push(number);
                    if (compute_flag == 1)
                    {
                        compute(number_stack, operation_stack);
                    }
                    number = 0;
                    i--;
                    STATE = OPERSTION_STATE;
                }
                break;
            case OPERSTION_STATE:
                if (s[i] == '+' || s[i] == '-')
                {
                    operation_stack.push(s[i]);
                    compute_flag = 1;
                }
                else if (s[i] == '(')
                {
                    STATE = NUMBER_STATE;
                    compute_flag = 0;
                }
                else if (s[i] >= '0' && s[i] <= '9')
                {
                    STATE = NUMBER_STATE;
                    i--;
                }
                else if (s[i] == ')')
                {
                    compute(number_stack, operation_stack);
                }
                break;
            }
        }
        if (number != 0)
        {
            number_stack.push(number);
            compute(number_stack, operation_stack);
        }
        if (number == 0 && number_stack.empty())
        {
            return 0;
        }
        return number_stack.top();
    }
};

int main()
{
    string s = "1+212-(14+(5-6))";
    Solution solve;
    printf("%d\n", solve.calculate(s));
    return 0;
}