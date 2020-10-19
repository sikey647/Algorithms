/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    // 重复性：数组(0,i)中，包含第i元素的连续子数组最大和 =
    //          【数组(0,i-1)中，包含第i元素的连续子数组最大和】与 0 的较大者
    //          + nums[i]
    // 状态定义：dp[i] 为数组(0,i)中，包含第i元素的连续子数组最大和
    // DP方程：dp[i] = max(dp[i-1], 0) + nums[i]
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp = nums;
        int res = dp[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], 0) + nums[i];
            res = max(res, dp[i]);
        }

        return res;
    }
};
// @lc code=end
