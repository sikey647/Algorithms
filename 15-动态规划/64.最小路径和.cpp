/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    // 方法一：自顶向下（超时）
    // 重复性：坐标(i,j)的最小路径和 = 坐标(i+1,j)的最小路径和 与
    //          坐标(i,j+1)的最小路径和 的较小者 + 当前距离值
    // int minPathSum(vector<vector<int>>& grid) {
    //     if (grid.size() == 0) return 0;
    //     return helper(0, 0, grid);
    // }

    // int helper(int i, int j, vector<vector<int>>& grid) {
    //     if (i == grid.size() - 1 && j == grid[0].size() - 1) {
    //         return grid[i][j];
    //     } else if (i == grid.size() - 1) {
    //         return helper(i, j + 1, grid) + grid[i][j];
    //     } else if (j == grid[0].size() - 1) {
    //         return helper(i + 1, j, grid) + grid[i][j];
    //     } else {
    //         return min(helper(i + 1, j, grid), helper(i, j + 1, grid)) +
    //                grid[i][j];
    //     }
    // }

    // 方法二：自顶向下 + 记忆化
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        vector<vector<int>> v(grid.size(), vector<int>(grid[0].size(), 0));
        return helper(0, 0, grid, v);
    }

    int helper(int i, int j, vector<vector<int>>& grid,
               vector<vector<int>>& v) {
        if (v[i][j] == 0) {
            if (i == grid.size() - 1 && j == grid[0].size() - 1) {
                v[i][j] = grid[i][j];
            } else if (i == grid.size() - 1) {
                v[i][j] = helper(i, j + 1, grid, v) + grid[i][j];
            } else if (j == grid[0].size() - 1) {
                v[i][j] = helper(i + 1, j, grid, v) + grid[i][j];
            } else {
                v[i][j] =
                    min(helper(i + 1, j, grid, v), helper(i, j + 1, grid, v)) +
                    grid[i][j];
            }
        }
        return v[i][j];
    }

    // 方法三：自底向上
    // 重复性：坐标(i,j)的最小路径和 = 坐标(i+1,j)的最小路径和 与
    //        坐标(i,j+1)的最小路径和 的较小者 + 当前距离值
    // 状态定义：dp[i][j]为坐标(i,j)到右下角(m,n)的最小路径和
    // dp方程：
    //  1、i和j都不是边界：dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j]
    //  2、i是边界：dp[i][j] = dp[i][j+1] + grid[i][j]
    //  3、j是边界：dp[i][j] = dp[i+1][j] + grid[i][j]
    //  4、i和j都是边界：dp[i][j] = grid[i][j]
    // int minPathSum(vector<vector<int>>& grid) {
    //     if (grid.size() == 0) return 0;
    //     int m = grid.size(), n = grid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n, 0));
    //     for (int i = m - 1; i >= 0; i--) {
    //         for (int j = n - 1; j >= 0; j--) {
    //             if (i == m - 1 && j == n - 1) {
    //                 dp[i][j] = grid[i][j];
    //             } else if (i == m - 1) {
    //                 dp[i][j] = dp[i][j + 1] + grid[i][j];
    //             } else if (j == n - 1) {
    //                 dp[i][j] = dp[i + 1][j] + grid[i][j];
    //             } else {
    //                 dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
    //             }
    //         }
    //     }
    //     return dp[0][0];
    // }
};
// @lc code=end
