#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int island_num = 0;
        vector<vector<int>> mark;
        //二维数组初始化的方法
        for (int i = 0; i < grid.size();i++)
        {
            mark.push_back(vector<int>());
            for (int j = 0; j < grid[i].size();j++)
            {
                mark[i].push_back(0);
            }
        }
        for (int i = 0; i < grid.size();i++)
        {
            for (int j = 0; j < grid[i].size();j++)
            {
                if(mark[i][j]==0&&grid[i][j]=='1')
                {
                    DFS(mark, grid, i, j);
                    island_num++;
                }
            }
        }
        return island_num;
    }

private:
    //深度优先搜索
    void DFS(vector<vector<int>> &mark,
             vector<vector<char>> &grid,
             int x, int y)
    {
        mark[x][y] = 1;
        //方向数组上下左右（横Y）
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newX >= mark.size() || 
                newY < 0 || newY >= mark[newX].size())
            {
                continue; //跳出本次循环，进行下一次循环。忽略掉瞒住if条件的情况
            }
            //如果当前位置是岛屿，且该位置没有探索过，则在该位置继续进行递归探索
            if (grid[newX][newY] == '1' && mark[newX][newY] == 0)
            {
                DFS(mark, grid, newX, newY);
            }
        }
    }
    //宽度优先搜索
    void BFS(vector<vector<int>> &mark,
             vector<vector<char>> &grid,
             int x, int y)
    {
        //上下左右
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        queue<pair<int, int>> Q; //宽度优先搜索队列
        Q.push(make_pair(x, y));
        mark[x][y] = 1;
        while (!Q.empty())
        {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                //忽略地图边界位置
                if (newX < 0 || newX >= mark.size() ||
                    newY < 0 || newY >= mark[newX].size())
                {
                    continue; //跳出本次循环，进行下一次循环。忽略掉瞒住if条件的情况
                }
                //如果新位置没有搜索过，且为陆地
                if (mark[newX][newY]==0&&grid[newX][newY]=='1')
                {
                    //压入该位置刀宽度搜索队列
                    Q.push(make_pair(newX, newY));
                    mark[newX][newY] = 1;
                }
            }
        }
    }
};


int main()
{
    vector<vector<char>> grid;
    char str[10][10] = {"11100", "11000", "00100", "00011"};
    for (int i = 0; i < 4;i++)
    {
        grid.push_back(vector<char>());
        for (int j = 0; j < 5;j++)
        {
            grid[i].push_back(str[i][j]);
        }
    }
    Solution Solve;
    cout << grid.size() << endl;
    cout << Solve.numIslands(grid) << endl;
    return 0;
}