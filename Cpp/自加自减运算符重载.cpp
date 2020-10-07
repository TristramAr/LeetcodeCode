#include <iostream>
#include <stdio.h>

using namespace std;

class CDemo
{
private:
    int n;

public:
    CDemo(int i = 0) : n(i) {}
    CDemo operator++();
    CDemo operator++(int);
    operator int() { return n; }
    friend CDemo operator--(CDemo &);
    friend CDemo operator--(CDemo &, int);
};
//前置++
CDemo CDemo::operator++()
{
    n++;
    return *this;
}
//后置++
CDemo CDemo::operator++(int k)
{
    CDemo tmp(*this); //记录修改前的对象
    n++;
    return tmp; //返回修改前的对象
}

//全局函数，不是类的成员函数
//前置
CDemo operator--(CDemo &d)
{
    d.n--;
    return d;
}
//后置
CDemo operator--(CDemo &d, int)
{
    CDemo tmp(d);
    d.n--;
    return tmp;
}
int main()
{
    CDemo d(5);
    cout << (d++) << ","; //等价于 d.operator++(0);
    cout << d << ",";
    cout << (++d) << ","; //等价于 d.operator++();
    cout << d << endl;
    cout << (d--) << ","; //等价于 operator--(d,0);
    cout << d << ",";
    cout << (--d) << ","; //等价于 operator--(d);
    cout << d << endl;
    return 0;
}