# include<stdio.h>
#include<iostream>

using namespace std;
template <class T>
void Swap(T & x,T & y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    int n = 1, m = 5;
    Swap(n, m);
    double i = 1.3, j = 8.1;
    Swap(i, j);
    return 0;   
}