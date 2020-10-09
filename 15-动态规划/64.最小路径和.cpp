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
    // 重复性：坐标(m, n)的最小路径和 = 坐标(m - 1, m)的最小路径和 与 坐标(m, n
    // - 1)的最小路径和 的较小者 + 当前距离值 状态定义：dp[m, n]为坐标(m,
    // n)到右下角(0, 0)的最小路径和 dp方程：
    //  1
    int minPathSum(vector<vector<int>>& grid) {}
};
// @lc code=end
