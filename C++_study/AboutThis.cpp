/*
 * @Description: this指针
 * @Author: feng
 * @Date: 2020-08-22 15:08:50
 * @LastEditTime: 2020-10-02 16:41:05
 * @LastEditors: feng
 */
#include <iostream>
using namespace std;

class Test
{
public:
    static int num;
    // static int num = 0;// error 不能再类中对静态变量进行初始化
    static int sum(int a)
    {
        num += a;
        return num;
    }
    int sum2(int b)
    {
        data += b;
        return this->data;
    }
    private:
        int data;
};
//静态成员变量，类外初始化
int Test::num = 0;
int main()
{
    //对于静态函数
    Test t;
    cout << t.sum(10) << endl;
    cout << t.sum2(10) << endl;
    return 0;
}