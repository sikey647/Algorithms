/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    // 递归
    double myPow(double x, long n) {
        double res;

        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double half = myPow(x, n / 2);
        if (n % 2 == 0) {   // 偶数
            res = half * half;
        } else {
            res = half * half * x;
        }

        return res;
    }
};
// @lc code=end

