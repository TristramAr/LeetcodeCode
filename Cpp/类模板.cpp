# include<iostream>
#include<stdio.h>

using namespace std;

template<class T1,class  T2>
class Pair{
    public:
        T1 key;
        T2 value;
        //构造函数
        Pair(T1 k, T2 v) : key(k), value(v){};
        //定义重载运算符， pair类型的引用  只比较大小，不改变值所以const
        bool operator<(const Pair<T1, T2>&p) const;

};

template<class T1,class  T2>
bool Pair<T1,T2>::operator<(const Pair<T1,T2>&p)const
{
    return key < p.key;
}       

int main()
{
    Pair<string, int> student("tom", 19);
    cout << student.key << " " << student.value;
    return 0;
}