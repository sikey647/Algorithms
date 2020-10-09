/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    // 自顶向下（超时）
    // int climbStairs(int n) {
    //     if (n <= 2) return n;
    //     return climbStairs(n - 1) + climbStairs(n - 2);
    // }

    // 自顶向下 + 记忆化
    // int climbStairs(int n) {
    //     vector<int> v(n + 1, 0);
    //     return helper(n, v);
    // }

    // int helper(int n, vector<int> &v) {
    //     if (n <= 2) return n;
    //     if (v[n] == 0) v[n] = helper(n - 1, v) + helper(n - 2, v);
    //     return v[n];
    // }

    // 自底向上
    int climbStairs(int n) {
        // 空间复杂度为O(n)
        // if (n <= 2) return n;
        // vector<int> dp(n + 1, 0);
        // dp[1] = 1, dp[2] = 2;
        // for (int i = 3; i <= n; i++) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];
        // 空间复杂度为O(1)
        if (n <= 2) return n;
        int f1 = 1, f2 = 2, f3 = 0;
        for (int i = 3; i <= n; i++) {
            f3 = f2 + f1;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};
// @lc code=end
