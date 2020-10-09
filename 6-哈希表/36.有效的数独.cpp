/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*unordered_set<char> rowSet[9], colSet[9], blkSet[9];
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') continue;
                int blkIndex = (i / 3) * 3 + j / 3;
                if (rowSet[i].find(board[i][j]) != rowSet[i].end() ||
                    colSet[j].find(board[i][j]) != colSet[j].end() ||
                    blkSet[blkIndex].find(board[i][j]) !=
                        blkSet[blkIndex].end())
                    return false;
                rowSet[i].insert(board[i][j]);
                colSet[j].insert(board[i][j]);
                blkSet[blkIndex].insert(board[i][j]);
            }
        }
        return true;*/
        int row[9][9] = {0}, col[9][9] = {0}, blk[9][9] = {0};
        // vector<vector<int>> row(9, vector<int>(9, 0)),
        // col(9, vector<int>(9, 0)), blk(9, vector<int>(9, 0));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = (i / 3) * 3 + j / 3;
                    if (row[i][num] || col[j][num] || blk[k][num]) return false;
                    row[i][num] = col[j][num] = blk[k][num] = 1;
                }
            }
        }

        return true;
    }
};
// @lc code=end
