/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    // f(x) = G(f(x), num[i])
    // 重复性：数组(0,i)中，包含第i个元素的最长上升子序列的长度 =
    //          opt1:【数组(0,i)中，包含第i个元素的最长上升子序列的长度 + 1】
    //                  nums[i] > nums[i-1]
    //          opt2: 1
    //                  nums[i] <= nums[i-1]
    // 状态定义：数组(0,i)中，包含第i个元素的最长上升子序列的长度
    // DP方程：dp[i] = nums[i] > nums[i-1] ? (dp[i-1] + 1) : 1
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        vector<int> dp(nums.size(), 1);
        int res = dp[0];

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }

        return res;
    }
};
// @lc code=end
