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
    // 最近重复子问题：第n级台阶 = 第n-1级台阶（爬1步）+ 第n-2级台阶（爬2步）
    int climbStairs(int n) {
        vector<int> v(n + 1, 0);
        return _climbStairs(n, v);
    }

    int _climbStairs(int n, vector<int>& v) {
        if (n == 1 || n == 2) return n;
        if (v[n] == 0) v[n] = _climbStairs(n - 1, v) + _climbStairs(n - 2, v);
        return v[n];
    }
};
// @lc code=end
