/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    // 一、方法一：一维
    // 重复性：i个房子能够偷窃到的最高金额 =
    //          opt1: i-1个房子能够偷窃到的最高金额
    //              （第i个房子不偷）
    //          opt2: i-2个房子能够偷窃到的最高金额 + 第i个房子的金额
    //              （第i个房子偷）
    //      以上两者取较大者
    // 状态定义：dp[i] 为i个房子能够偷窃到的最高金额
    // DP方程：dp[i] = max(dp[i-1], dp[i-2] + nums[i])
    // int rob(vector<int>& nums) {
    //     if (nums.size() == 0) return 0;

    //     if (nums.size() == 1) return nums[0];

    //     vector<int> dp(nums.size(), 0);
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0], nums[1]);

    //     for (int i = 2; i < nums.size(); i++) {
    //         dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    //     }

    //     return dp[nums.size() - 1];
    // }

    // 二、方法二：二维
    // 重复性：i个房子能够偷窃到的最高金额 =
    //          opt1:【第i个房子不偷时能够偷窃到的最高金额】
    //          opt2:【第i个房子偷时能够偷窃到的最高金额】
    //      以上两者取较大者
    //          【第i个房子偷时能够偷窃到的最高金额】 =
    //              【第i-1个房子不偷时能够偷窃到的最高金额】+ 【第i个房子金额】
    //          【第i个房子不偷时能够偷窃到的最高金额】=
    //              【第i-1个房子偷时能够偷窃到的最高金额】与
    //              【第i-1个房子不偷时能够偷窃到的最高金额】的较大者
    // 状态定义：dp[i][0] 为第i个房子不偷时能够偷窃到的最高金额
    //          dp[i][1] 为第i个房子偷时能够偷窃到的最高金额
    // DP方程：dp[i][0] = max(dp[i-1][0], dp[i-1][1])
    //          dp[i][1] = dp[i-i][0] + nums[i]
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        if (nums.size() == 1) return nums[0];

        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }

        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
// @lc code=end
