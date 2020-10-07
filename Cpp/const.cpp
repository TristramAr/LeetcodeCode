//https://blog.csdn.net/qq_33248019/article/details/89462405
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    //int const*p 等价于const int*,const作用于*p,说明*p不能改，即指针p所指对象的值不能改  常量指针，const作用的是值。
    //可以修改指针所指向的对象，不能修改指针所指向对象的值
    int a = 10;
    int b = 20;
    int c = 55;
    int const *p = &a;
    const int *q = &b;
    p = &c;
    q = &c; //可以修改所指向对象
    // *q = 12;
    // *p = 13;  //不可修改所指向对象的值

    //int *const p, const 作用域p,即指针不能改， 指针常量，const作用于指针。
    //可以改变所指向对象储存的值；不可以改变所指向对象。
    int *const p1 = &a;
    int *const q1 = &b;
    // p1 = &c;
    *p1 = 3;
    cout << p1 << endl;
    cout << a << endl;
}