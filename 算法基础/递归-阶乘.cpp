#include<stdio.h>
int Factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n * Factorial(n - 1);
    }
}

int main()
{
    int a, b;
    scanf("%d", &a);
    b = Factorial(a);
    printf("result of n!:%d", b);
}