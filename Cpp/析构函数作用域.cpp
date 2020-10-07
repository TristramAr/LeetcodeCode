#include<iostream>
#include<stdio.h>
using namespace std;

class Demo {
    int id;
    public:
    //构造函数
    Demo( int i ){
    id = i;
    cout << "id=" << id << "Constructed" << endl;
    }
    //析构函数
    ~Demo(){
    cout << "id=" << id << "Destructed" << endl;             //析构函数，释放内存，相当于delete
    }
};

Demo d1(1);
void Func(){
    static Demo d2(2);       //静态变量在整个程序结束后进行内存释放，也就是最后调用析构函数
    Demo d3(3);
    cout << "Func"<< endl;
}
int main (){
    Demo d4(4);
    d4 = 6;
    cout << "main" << endl;
    {
        Demo d5(5);              //在该作用域中进行构造函数和析构函数的调用
    }
    Func();
    cout << "main ends" << endl;
    return 0;
}