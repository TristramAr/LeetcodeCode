/*
牛客网上的题目，typora笔记中有记录
*/
#include <iostream>
#include <vector>
using namespace std;
//方向数组上下左右（横Y）
static const int dx[] = {0, 1, 0, -1};
static const int dy[] = {1, 0, -1, 0};
void mazeTrack(int x, int y, vector<vector<int>> &maze,
               vector<vector<int>> &bestPath,
               vector<vector<int>> &curpath,
               vector<vector<int>> &visit)
{
    curpath.push_back({x, y});
    visit[x][y] = 1;
    if (x == maze.size() - 1 && y == maze[0].size() - 1)
    {
        if (bestPath.empty() || curpath.size() < bestPath.size())
            bestPath = curpath;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 0 && tx < maze.size() && ty >= 0 && ty < maze[0].size() && visit[tx][ty] == 0 && maze[tx][ty] == 0)
        {

            mazeTrack(tx, ty, maze, bestPath, curpath, visit);
            visit[tx][ty] = 0;
            curpath.pop_back();
        }
    }
}

int main()
{
    int N, M;                 //分别代表行和列
    vector<vector<int>> maze; //迷宫矩阵

    while (cin >> N >> M)
    {
        maze = vector<vector<int>>(N, vector<int>(M, 0));
        vector<vector<int>> path_temp; //存储当前路径，第一维表示位置
        vector<vector<int>> path_best; //存储最佳路径
        vector<vector<int>> visit(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> maze[i][j];
            }
        }
        mazeTrack(0, 0, maze, path_best, path_temp, visit); //回溯寻找迷宫最短通路
        for (auto i : path_best)
            cout << '(' << i[0] << ',' << i[1] << ')' << endl; //输出通路
    }
    return 0;
}
