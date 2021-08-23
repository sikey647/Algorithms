/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<vector<int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, board, word, visited, directions)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(int x, int y, int index, vector<vector<char>>& board, string& word,
             vector<vector<bool>>& visited, vector<vector<int>>& directions) {
        if (index == word.size() - 1) {
            return board[x][y] == word[index];
        }

        // 当前节点与字母相等
        if (board[x][y] == word[index]) {
            visited[x][y] = true;
            for (auto& dir : directions) {
                int i = x + dir[0];
                int j = y + dir[1];
                if (i >= 0 && i < board.size() && j >= 0 &&
                    j < board[0].size() && !visited[i][j]) {
                    if (dfs(i, j, index + 1, board, word, visited,
                            directions)) {
                        return true;
                    }
                }
            }
            visited[x][y] = false;
        }

        return false;
    }
};
// @lc code=end
