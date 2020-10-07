/*
 * @Description: 编程之美，电梯调度算法
 * @Author: feng
 * @Date: 2020-10-01 21:11:59
 * @LastEditTime: 2020-10-02 21:32:17
 * @LastEditors: feng
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> func(vector<int> nPerson, int N)
{
    int sumFloor = 0;
    int res = INT_MAX;
    int targetFloor = -1;
    for (int i = 1; i <= N; i++)
    {
        //第i层以上
        for (int j = i + 1; j <= N; j++)
        {
            sumFloor += nPerson[i] * (j - i);
        }
        //第i层以下
        for (int j = 1; j < i; j++)
        {
            sumFloor += nPerson[i] * (i - j);
        }
        if (targetFloor == -1 || sumFloor < res)
        {
            res = sumFloor;
            targetFloor = i;
        }
    }
}
vector<int> Func2(vector<int> nPerson, int N)
{
    int targetFloor = 1;
    int res;
    //分别表示当前楼层人数，当前楼层以下的人数，当前楼层以上人数.
    //初始条件
    int NNow = nPerson[1];
    int NDown = 0;
    int NUp = 0;
    for (int i = 2; i <= N; i++)
    {
        NUp += nPerson[i];
        res += nPerson[i] * (i - 1);
    }
    //从第二层开始分析，如果向上走能减少楼层数，则继续，
    //反之当前即为最优解
    for (int i = 2; i <= N; i++)
    {
        if (NDown + NNow < NUp)
        {
            targetFloor = i;
            res += (NDown + NNow - NUp);
            NUp -= nPerson[i];
            NNow = nPerson[i];
            NDown += nPerson[i];
        }
        else
            break;
    }