#include <stdio.h>
#include <memory.h>
#define MAXIN 75
char board[MAXIN + 2][MAXIN + 2]; //定义矩形板
int minstep, w, h;
int to[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //定义方向
bool mark[MAXIN + 2][MAXIN + 2];                   //定义标记数组，是否走过

void Search(int now_x, int now_y, int end_x, int end_y, int step, int f)
{
    if (step > minstep) // 当前step大于保存的minstep，返回优化策略
        return;
    if (now_x == end_x && now_y == end_y) //到达终点
    {
        if (minstep > step) //更新最小路径数
        {
            minstep = step;
            return;
        }
    }
    for (int i = 0; i < 4; i++) //枚举下一步移动的四个方向
    {
        int x = now_x + to[i][0]; // 得到新的位置
        int y = now_y + to[i][1];
        //T1&&(T1||T2)
        if ((x > -1) && (x < w + 2) && (y > -1) && (y < h + 2)                                                 // 在矩形板内T1
            && (((board[y][x] == ' ') && (mark[y][x] == false)) || ((x == end_x)                               //没有游戏卡，且没有走过T2
                                                                    && (y == end_y) && (board[y][x] == 'X')))) // 到大目标位置T3
        {
            mark[y][x] = true; // 如果新位置，有效标记该位置
            if (f == i)        //如果与前一步同向，步数不累计
            {
                Search(x, y, end_x, end_y, step, i);
            }
            else
            {
                Search(x, y, end_x, end_y, step + 1, i);
            }
            mark[y][x] = false; // 回溯，该位置未走过
        }
    }
}

int main()
{
    int Boardnum = 0;
    while (scanf("%d %d", &w, &h))
    {
        if (w == 0 && h == 0)
            break;
        Boardnum++;
        printf("Board#%d:\n", Boardnum);
        int i, j;
        for (i = 0; i < MAXIN + 2; i++)
        {
            board[0][i] = board[i][0] = ' ';
        }
        for (i = 1; i <= h; i++)
        {
            getchar();
            for (j = 1; j <= w; j++)
            {
                board[i][j] = getchar();
            }
        }
        // 在矩形板最外层增加一圈格子
        for (i = 0; i <= w; i++)
        {
            board[h + 1][i + 1] = ' ';
        }
        for (i = 0; i <= h; i++)
        {
            board[i + 1][w + 1] = ' ';
        }
        int begin_x, begin_y, end_x, end_y, count = 0;
        while (scanf("%d %d %d %d", &begin_x, &begin_y, &end_x, &end_y) && begin_x > 0)
        {
            count++;
            minstep = 100000; //初始化minstep为一个很大的值
            memset(mark, false, sizeof(mark));
            //递归搜索
            Search(begin_x, begin_y, end_x, end_y, 0, -1);
            //输出结果
            if (minstep < 100000)
            {
                printf("Pair %d:%d segments.\n", count, minstep);
            }
            else
            {
                printf("Pair %d:imporssible.\n", count);
            }
            printf("\n");
        }
    }
    return 0;
}