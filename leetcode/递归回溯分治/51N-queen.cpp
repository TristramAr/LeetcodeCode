#include <iostream>
#include <vector>
using namespace std;
// class Solution
// {
// public:
//     vector<vector<string>> solveNQueens(int n)
//     {
//         vector<vector<string>> result; //储存最终结果的数组
//         vector<vector<int>> mark;      //标记棋盘是否可以放置皇后的二维数组
//         vector<string> location;       //存储某个摆放结果。
//         for (int i = 0; i < n; i++)
//         {
//             mark.push_back((vector<int>()));
//             for (int j = 0; j < n; j++)
//             {
//                 mark[i].push_back(0); //mark初始化为0
//             }
//             location.push_back(""); // location初始化为 .
//             location[i].append(n, '.');
//         }
//         generate(0, n, location, result, mark);
//         return result;
//     }

// private:
//     //放置皇后更新mark数组
//     void put_down_the_queen(int x,
//                             int y,
//                             vector<vector<int>> &mark)
//     {
//     //定义方向数组,x:向下，y:向左, 上，下，左，右，左上，左下，右下，右上
//         static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
//         static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
//         mark[x][y] = 1; // x,y位置放置皇后
//         //mark.size()  棋盘的大小
//         for (int i = 0; i < mark.size(); i++) //8个方向，每个方向向外延申1至N-1
//         {
//             for (int j = 0; j < 8; j++)
//             {
//                 int new_x = x + i * dx[j];
//                 int new_y = y + i * dy[j];

//                 if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) //检查新位置是否在棋盘内
//                 {
//                     mark[new_x][new_y] = 1;
//                 }
//             }
//         }
//     }
//     void generate(int k, int n,                   // k表示完成了几个皇后的放置(正在放置第K行皇后)
//                   vector<string> &location,       // 某次结果存储在location
//                   vector<vector<string>> &result, // 最终结果储存在result
//                   vector<vector<int>> &mark)      // 表示棋盘的标记数组
//     {
//         if (k == n)   //当k==n时，代表完成了第0至n-1行皇后的放置，将记录皇后的location数组push进result
//         {
//             result.push_back(location);
//             return;
//         }
//         for (int i = 0; i < n; i++)      //按顺序尝试0至n-1列
//         {
//             if(mark[k][i]==0)
//             {
//                 vector<vector<int>> tmp_mark = mark;   //记录回溯前的mark镜像
//                 location[k][i] = 'Q';
//                 put_down_the_queen(k, i, mark);
//                 generate(k + 1, n, location, result, mark);
//                 mark = tmp_mark;                      // mark 重新赋值为回溯前状态
//                 location[k][i] = '.';
//             }
//         }
//     }
// };
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        //初始化一个空气盘，'Q'表示防止皇后，'.'表示空
        vector<string> board(n, string(n, '.'));
    }

private:
    void backtrack(vector<vector<string>> &res, vector<string> &board, int row, int n)
    {
        if (row == n)
        {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (!isvalid(board, row, col, n))
            {
                continue;
            }
            board[row][col] = 'Q';
            backtrack(res, board, row + 1, n);
            board[row][col] = '.';
        }
    }
    //判断是否可以再（row，col处放置皇后
    bool isvalid(vector<string> &board, int row, int col, int n)
    {
        // 定义方向数组,x:向下，y:向左, 上，下，左，右，左上，左下，右下，右上
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i < 8; j++) // 八个方向
            {
                int x = row + i * dx[j];
                int y = col + i * dy[j];
                // 如果当前位置（row，col）的八个方向上有皇后，这说明该位置不能放置
                if (x >= 0 && x < n && y >= 0 && y < n)
                {
                    if (board[x][y] == 'Q')
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<string>> result;
    Solution solve;
    result = solve.solveNQueens(4);
    for (int i = 0; i < result.size(); i++)
    {
        cout << i << endl;
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j].c_str() << endl;
        }
        cout << endl;
    }
    return 0;
}