#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int r, c, n;

struct PLANT
{
    int x, y;
};
PLANT plants[5001];
PLANT plant;
int searchPath(PLANT secPlant, int dX, int dY);
int main()
{
    int i, j, dX, dY, pX, pY, steps, max = 2;
    //读取行数和列数，x方向向下，y方向向右
    scanf("%d %d", &r, &c);
    //踩踏的水稻总个数
    scanf("%d", &n);
    // 输入踩踏水稻的坐标
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &plants[i].x, &plants[i].y);
    }
    //将水稻按X坐标从小到大排序，x坐标相同按y从小到大排序
    sort(plants, plants + n);

    for (i = 0; i < n - 2; i++) // plant[i]是第一个点
    {
        for (j = i + 1; j < n - 1; j++) // plant[j]是第二个点
        {
            dX = plants[j].x - plants[i].x;
            dY = plants[j].y - plants[j].y;
            //第一个点的前一点
            pX = plants[i].x - dX;
            pY = plants[i].y - dY;
            // 如果第一点的前一点还在稻田里，说明本次选择的第二点导致的dX dY过小
            // 继续进行第二点的循环，取下一点作为第二点
            if (pX < r && pX >= 1 && pY <= c && pY >= 1)
            {
                continue;
            }
            // x方向早过界，本次选择的第二点不成立，
            // 继续枚举第二点指挥导致步长变大，更快越界 不成立，
            // 认为本次选择的第一点不合理
            if (plants[i].x + (max - 1) * dX > r)
            {
                break;
            }
            //判断y方向是否越界,越界后继续枚举下一个
            if (plants[i].y + (max - 1) * dY > c || pY < 1)
            {
                continue;
            }
            steps = searchPath(plants[j], dX, dY);
            if (steps > max)
                max = steps;
        }
        if (max == 2)
            max = 0;
        printf("%d\n", max);
    }
}

//重载<运算符,用于sort对结构体排序
bool operator<(const PLANT &p1, const PLANT &p2)
{
    if (p1.x == p2.x)
    {
        return p1.y < p2.y;
    }
    return p1.x < p2.y;
}

//判断从secPlant点开始，步长为dX dY，最多能走几步
int searchPath(PLANT secPlant, int dX, int dY)
{
    PLANT plant;
    int steps;
    plant.x = secPlant.x + dX;
    plant.y = secPlant.y + dY;
    steps = 2;
    while (plant.x <= r && plant.y >= 1 && plant.y <= c && plant.y >= 1)
    {
        //判断枚举的plant是不是输入中被踩plants中的数据 
        if (!binary_search(plants, plants + n, plant))
        {
            steps = 0;  // 不存在青蛙行走路径，输出0
            break;
        }
        plant.x = plant.x + dX;
        plant.y = plant.y + dY;
        steps++;
    }
    return steps;   // 存在青蛙行走路径输出路径中踩踏的个数
}