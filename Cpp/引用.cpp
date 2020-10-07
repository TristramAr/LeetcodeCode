#include<stdio.h>
#include<iostream>
using namespace std;


// 形参改变不会影响实参
void swap_1(int a,int b)
{
    int temp;
    temp = a;
    a = b;
    b= temp;
}
//利用变量地址进行swap
void swap_2(int* a,int* b)
{
    int temp;
    temp = *a;   //a所指向的内容  &a取a的地址，*a 取指针a所指向的内容
    *a = *b;
    *b = temp;
}
//利用引用来交换变量值,引用值的改变也会改变元原来值，二者等价 
void swap_3(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n1=4,n2=8;
    // cout<<"取地址:"<<&n1<<endl;
    swap_3(n1,n2);
    cout<<n1<<endl<<n2<<endl;
    //引用
    int &a = n1;
    //常引用，不能改变变量的值
    const int &b = n1;
    // b = 5;    //编译会出错，常引用不能修改。
    a = 5;   //ok
    //int const*与int *const 的区别

}