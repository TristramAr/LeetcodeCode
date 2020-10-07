#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
   bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board,word,i,j,1)) return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, string word,
             int i, int j, int num)
    {
        static const int dx[] = {-1, 1, 0, 0}; // "const int []" 类型的成员不能包含类内初始值设定项
        static const int dy[] = {0, 0, -1, 1};
        //能找到所有字母
        if (num == word.length())   //此时代表完成了word中所有字符的查找，即（0-word.length()-1）的字符。
        {
            return true;
        }
        //备份当前的位置的字符，并修改为*标记已经查找过
        char temp = board[i][j];
        board[i][j] = '/';
        //四个方向
        for (int k = 0; k < 4; k++)
        {
            int d_x = dx[k] + i; // 新的i值
            int d_y = dy[k] + j; // 新的j值
            if (d_x >= 0 && d_x < board.size() && d_y >= 0 && d_y < board[0].size() && word[num] == board[d_x][d_y])
            {
                if (dfs(board, word, d_x, d_y, num + 1))
                    return true;
            }
        }
        //恢复该位置原来的字符，方便下一基点查找
        board[i][j] = temp;
        return false;
    }
};
