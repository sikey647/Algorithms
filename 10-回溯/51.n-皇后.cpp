/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> sub;
        unordered_set<int> colSet, sumSet, difSet;

        helper(0, n, colSet, sumSet, difSet, sub, res);

        return res;
    }

    void helper(int row, int n, unordered_set<int>& colSet,
                unordered_set<int>& sumSet, unordered_set<int>& difSet,
                vector<string>& sub, vector<vector<string>>& res) {
        // 递归终止条件
        if (row == n) {
            res.push_back(sub);
            return;
        }

        string str(n, '.');
        for (int col = 0; col < n; col++) {
            if (colSet.find(col) == colSet.end() &&
                sumSet.find(row + col) == sumSet.end() &&
                difSet.find(row - col) == difSet.end()) {
                // 处理当前层逻辑
                str[col] = 'Q';
                colSet.insert(col);
                sumSet.insert(row + col);
                difSet.insert(row - col);
                sub.push_back(str);
                // 递归下一层
                helper(row + 1, n, colSet, sumSet, difSet, sub, res);
                // 恢复当前层
                sub.pop_back();
                colSet.erase(col);
                sumSet.erase(row + col);
                difSet.erase(row - col);
                str[col] = '.';
            }
        }
    }
};
// @lc code=end
