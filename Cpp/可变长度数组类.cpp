#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std ;

class CArray
{
    int size;                               //记录数组元素的个数
    int *ptr;                               //指向动态分配数组
    public:
    CArray(int s =0); //构造函数
    CArray(CArray &a); //复制构造函数
    ~CArray();                                //析构函数
    void push_back(int v);                    // 用于数组尾部添加元素
    CArray &operator = (const CArray &a);     // 赋值运算符
    int length(){return size;}
    int& operator [] (int i)           //用int不行，不支持a[i]=4,用int &可以实现修改;非引用的函数返回值不可以作为左值使用                            
    {
        return ptr[i];
    }
};

CArray::CArray(int s):size(s)
{
    if(s)
    {
        ptr = NULL;
    }
    else
    {
        ptr = new int[s];
    }   
}
CArray::CArray(CArray&a)
{
    if (!a.ptr){
        ptr = NULL;
        size = 0;
        return;
    }
    else
    {
        ptr = new int[a.size];
        memcpy(ptr,a.ptr,sizeof(int)*a.size);
        size = a.size; 
    }
}

CArray::~CArray()
{
    if(ptr)
    {
        delete [] ptr;
    }

}
CArray& CArray::operator=(const CArray&a)   // 返回值为CArry&
{
    if(ptr==a.ptr)
    {
        return *this;   // 返回当前对象的引用,对应CArry&
    }
    if(a.ptr==NULL)
    {
        if(ptr)
        {
            delete[]ptr;
            ptr = NULL;
            size = 0;
            return *this;
        }
    }
    if(size<a.size)
    {
        if(ptr)
        {
            delete[]ptr;
            ptr = new int [a.size];

        }
    }
       memcpy(ptr,a.ptr,sizeof(int)*a.size);
       size = a.size;
       return*this;
}

void CArray::push_back(int v)
{
    if(ptr)
    {
        int*tempPtr = new int[size+1];
        memcpy(tempPtr,ptr,sizeof(int)*size);
        delete[]ptr;
        ptr = tempPtr;
    }
    else
    {
        ptr = new int[1];
    }
    ptr[size++] = v;
    
}

int main()
{
    CArray a;
    for(int i=0;i<5;i++)
    {
        a.push_back(i);
    }
    CArray a2,a3;
    a2=a;
    for(int i=0;i<a.length();++i)
    {
        cout<<a2[i]<<" ";
    }
    a2=a3;
    for(int i = 0;i<a2.length();++i)
   {
       cout<<a2[i]<<" ";
   } 
   cout<<endl;
   a[3]=100;
   CArray a4(a);
   for(int i =0;i<a4.length();++i)
   {
       cout<<a4[i]<<" ";
   }
   return 0;
}