/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <limits.h>

#include <vector>
using namespace std;

// @lc code=start
// 状态定义：dp[i][j][k]为 第i天、是否持有股票情况下，交易k次 获取的最大利润
// DP方程：
//  未持股：
//      完成0次交易：dp[i][0][0] = 0
//      完成1次交易：dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][0] + prices[i])
//      完成2次交易：dp[i][0][2] = max(dp[i-1][0][2], dp[i-1][1][1] + prices[i])
//  持股：
//      完成0次交易：dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][0] - prices[i])
//      完成1次交易：dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][1] - prices[i])
//      完成2次交易：dp[i][1][2] 不存在
// 结果：max(0, dp[n-1][0][1], dp[n-i][0][2])

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) {
            return 0;
        }
        vector<vector<vector<int>>> dp(
            prices.size(), vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];  // !
        dp[0][0][2] = -prices[0];  // !
        dp[0][1][0] = -prices[0];
        dp[0][1][1] = -prices[0];  // !

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i]);
            dp[i][0][2] = max(dp[i - 1][0][2], dp[i - 1][1][1] + prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][0] - prices[i]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][1] - prices[i]);
        }

        return max(
            0, max(dp[prices.size() - 1][0][1], dp[prices.size() - 1][0][2]));
    }
};
// @lc code=end
