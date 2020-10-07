#include<stdio.h>
#include<iostream>
using namespace std;
//判断熄灯矩阵为5x6的熄灯问题 
int puzzle[6][8], press[6][8];
bool guess()
{
    int c, r;
    // 根据给定的puzzle数组和枚举的press第一行，计算出press的其他行
    //每一盏灯经过周围奇数次按下后会改变状态，经过偶数次按下后不会改变状态。
    //例如开始值为0，经过本身即上左右四个键偶数次的改变，值还为0，该值下方的键无需按下
    // 奇数次改变，值变为1，下一行该列的键就需要按下。
    for (r = 1; r < 5;r++)
    {
        for (c = 1; c < 7;c++)
        {
            press[r + 1][c] = (puzzle[r][c] + press[r][c] + press[r - 1][c] 
            + press[r][c - 1] + press[r][c + 1]) % 2;
        }
    }
    // 判断所计算的press数组能否熄灭第
    for (c = 1; c < 7;c++)
    {
        if((press[5][c-1]+press[5][c]+press[5][c+1]+press[4][c])%2!=puzzle[5][c])
        {
            return false;
        }  
    }
    return true;
}

void enumerate()
{
    int c;
    // bool success;
    for (c = 1; c < 7;c++)
    {
        press[1][c] = 0;
    }

    //模拟二进制的方法，进行枚举press第一行数据,这个很厉害
    //0 0 0 0 0 0 
    //1 0 0 0 0 0 
    //0 1 0 0 0 0 
    //1 1 0 0 0 0
    //0 0 1 0 0 0 
    //1 0 1 0 0 0
    //...
    while (guess() == false)
    {
        press[1][1]++;
        c = 1;
        while(press[1][c]>1)
        {
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }
    }
    return;
}

int main()
{
    int cases, i, r, c;
    scanf("%d", &cases);
    // cin>>cases;
    for (r = 0; r < 6;r++)
    {
        press[r][0] = press[r][7] = 0;
    }
    for (c = 0; c < 7;c++)
    {
        press[0][c] = 0;
    }
    for (i = 0; i < cases;i++)
    {
        press[0][c] = 0;
    }
    for (i = 0; i < cases;i++)
    {
        for (r = 1; r < 6;r++)
        {
            for (c = 1; c < 7;c++)
            {
                scanf("%d", &puzzle[r][c]);
            }
        }
        enumerate();
        printf("PUZZLE#%d\n", i + 1);
        for (r = 1; r < 6;r++)
        {
            for (c = 1; c < 7;c++)
            {
                printf("%d", press[r][c]);
                printf("\n");
            }
        }
    }
    return 0;
}