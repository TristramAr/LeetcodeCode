#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
string convert10ToDigit(int num, int digit)
{
    string res = "";
    if (num == 0)
    {
        return "0";
    }
    int flag = 1; //num>0时为1 小于0时为0
    if (num < 0)
    {
        num = -num;
        flag = 0;
    }
    while (num)
    {
        int temp = num % digit;
        if (temp < 10)
        {
            char t = temp + '0';
            res += t;
        }
        else
        {
            char t = temp - 10 + 'a'; // 如 temp = 11 在16进制中为b
            res += t;
        }
        num = num / digit;
    }
    if (flag == 0)
    {
        res += '-';
    }
    reverse(res.begin(), res.end());
    return res;
}
int convertDigitTo10(string digitNum, int digit)
{
    int ans = 0;
    int flag = 1;   //正负数标记
    if(digitNum[0] = '-')
    {
        flag = 0;
        digitNum = digitNum.substr(1, digitNum.length() - 1);
    }
    //这里不是用传统的进制计算方法，而是从高位还原进位过程。例如二进制数111，把最高位加回到此高位，依次叠加。
    for (int i = 0; i < digitNum.size(); i++)          
    {
        char t = digitNum[i];
        if (t >= '0' && t <= '9')
            ans = ans * digit + t - '0';
        else if(t>='a'&&t<='f')           // 这里要注意的，比如输入是16进制的0XA，0和X应该跳过不能计算
            ans = ans * digit + t - 'a' + 10;
    }
    if(flag==0)
    {
        ans = -ans;
    }
    return ans;
}
int main()
{
    // cout << "输入要转换的数  输入进制(1-16)" << endl;
    // int num, digit;
    // cin >> num >> digit;
    // string res = convert10ToDigit(num, digit);
    // cout << res << endl;
    cout << "输入要转换为10进制的(1-16)进制数：";
    cout << endl;
    string digitNum;
    cin >> digitNum;
    cout << "输入进制：";
    int Numdigit;
    cin >> Numdigit;
    cout << convertDigitTo10(digitNum, Numdigit);
}