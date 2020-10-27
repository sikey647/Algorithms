/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    // 状态定义：第i天能获取的最大利润
    //      dp[i][0]: 第i天不持有股票的最大利润
    //      dp[i][1]: 第i天持有股票的最大利润
    // DP方程：
    //      dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
    //      dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i])
    //      注意：因为题目限制只能交易一次，因此状态只可能从 1 到 0，不可能从 0
    //      到 1 因此，dp[i][1] = max(dp[i-1][1], -prices[i])
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) {
            return 0;
        }

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]);  // 注意!
        }

        return dp[prices.size() - 1][0];
    }
};
// @lc code=end
