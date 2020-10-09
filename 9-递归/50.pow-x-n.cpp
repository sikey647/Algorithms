/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
   public:
    double myPow(double x, long n) {
        if (n == 0) return 1;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return _myPow(x, n);
    }

    double _myPow(double x, long n) {
        if (n == 0) return 1;
        double half = myPow(x, n / 2);

        return (n % 2 == 0) ? half * half : half * half * x;
    }
};
// @lc code=end
