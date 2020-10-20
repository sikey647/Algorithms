/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>
using namespace std;

// 状态定义：第i天能获取的最大利润
//      dp[i][0]: 第i天不持有股票的最大利润
//      dp[i][1]: 第i天持有股票的最大利润
// DP方程：
//      dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
//      dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i])

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) {
            return 0;
        }

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);  // 注意!
        }

        return dp[prices.size() - 1][0];
    }
};
// @lc code=end
