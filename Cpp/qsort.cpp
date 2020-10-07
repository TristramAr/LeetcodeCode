#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define NUM 5

int MyCompare(const void* elem1,const void* elem2)
{
    unsigned int* p1,*p2;
    p1 = (unsigned int*)elem1;
    p2 = (unsigned int*)elem2;
    return (*p1%10) -(*p2 % 10);
}

int main()
{
    unsigned int array[NUM] = {12,11,34,42,9};
    qsort(array, NUM, sizeof(unsigned int), MyCompare);
    for (int i = 0; i < NUM; i++){   
        // printf("%d\n",array[i]);
        cout<<array[i]<<endl;
    }
    
    return 0;
}