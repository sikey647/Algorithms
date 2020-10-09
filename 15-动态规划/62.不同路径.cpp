/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    // 方法一：自顶向下（超出时间限制）
    // int uniquePaths(int m, int n) {
    //     return helper(m - 1, n - 1);
    // }

    // int helper(int m, int n) {
    //     if (m < 0 || n < 0) return 0;

    //     if (m == 0 || n == 0) return 1;

    //     return helper(m - 1, n) + helper(m, n - 1);
    // }

    // 方法二：自顶向下 + 记忆化
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> v(m, vector<int>(n, 0));
    //     return helper(m - 1, n - 1, v);
    // }

    // int helper(int m, int n, vector<vector<int>>& v) {
    //     if (m < 0 || n < 0) return 0;
    //     if (m == 0 || n == 0) return 1;
    //     if (v[m][n] == 0) v[m][n] = helper(m - 1, n, v) + helper(m, n - 1,
    //     v); return v[m][n];
    // }

    // 方法三：自底向上
    int uniquePaths(int m, int n) {
        // 空间复杂度为O(m*n)
        // if (m < 0 || n < 0) return 0;
        // vector<vector<int>> dp(m, vector<int>(n, 0));

        // for (int i = 0; i < m; i++) {
        //     dp[i][0] = 1;
        // }

        // for (int j = 0; j < n; j++) {
        //     dp[0][j] = 1;
        // }

        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        //     }
        // }

        // return dp[m - 1][n - 1];

        // 空间复杂度为O(1)
        if (m < 0 || n < 0) return 0;
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
// @lc code=end
