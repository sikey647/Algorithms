/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include <vector>
using namespace std;

// @lc code=start
// 状态定义：dp[i][j][k]为 第i天、是否持有股票情况下，交易k次 获取的最大利润
// DP方程：
//      不持股交易k次：dp[i][0][k] = max(dp[i-1][0][k], dp[i-1][1][k-1] +
//      prices[i]) 持股交易k次： dp[i][1][k] = max(dp[i-1][1][k], dp[i-1][0][k]
//      - prices[i])
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) {
            return 0;
        }

        // 不限制交易次数
        if (k >= prices.size() / 2) {
            int profit = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }

        // 限制交易次数
        vector<vector<vector<int>>> dp(
            prices.size(), vector<vector<int>>(2, vector<int>(k, 0)));

        for (int i = 0; i < prices.size(); i++) {
            dp[i][0][0] = 0;
            dp[i][1][0] = -prices[i];
        }

        for (int c = 0; c < k; c++) {
            dp[0][0][c] = 0;
            dp[0][1][c] = -prices[0];
        }

        for (int i = 1; i < prices.size(); i++) {
            for (int c = 0; c < k; c++) {
                dp[i][0][c] =
                    max(dp[i - 1][0][c], dp[i - 1][1][c - 1] + prices[i]);
                dp[i][1][c] = max(dp[i - 1][1][c], dp[i - 1][0][c] - prices[i]);
            }
        }

        return dp[prices.size() - 1][0][k - 1];
    }
};
// @lc code=end
