/*
 * @Description: 友元函数，非类的成员函数，但是有和类成员函数的相同的访问权限（即可以访问私有成员变量）
 * @Author: feng
 * @Date: 2020-10-01 12:14:54
 * @LastEditTime: 2020-10-02 16:24:35
 * @LastEditors: feng
 */

#include <iostream>
using namespace std;

class Point
{
public:
    Point(int x, int y);
    //友元函数，不是类的成员函数，但是与成员函数的访问权限相同
    friend ostream &operator<<(ostream &out, const Point &p);

private:
    int x;
    int y;
};
Point::Point(int x, int y) : x(x), y(y) {}

ostream &operator<<(ostream &out,const Point&p)
{
    out << "(" << p.x << "," << p.y << ")" << endl;
    return out;
}
int main()
{
    Point a(1, 2);
    cout << "hello" << endl;
    cout << a << endl;
}