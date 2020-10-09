/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        vector<pair<int, int>> pos = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};

        dfs(click[0], click[1], board, pos);

        return board;
    }

    void dfs(int x, int y, vector<vector<char>>& board,
             vector<pair<int, int>>& pos) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return;

        int count = 0;
        if (board[x][y] == 'E') {
            for (auto& p : pos) {
                if (x + p.first >= 0 && y + p.second >= 0 &&
                    x + p.first < board.size() &&
                    y + p.second < board[0].size() &&
                    board[x + p.first][y + p.second] == 'M')
                    count++;
            }

            if (count > 0) {
                board[x][y] = '0' + count;
            } else {
                board[x][y] = 'B';
                for (auto& p : pos) {
                    dfs(x + p.first, y + p.second, board, pos);
                }
            }
        }
    }
};
// @lc code=end
