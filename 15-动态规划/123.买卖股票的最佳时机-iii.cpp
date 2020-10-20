/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <vector>
using namespace std;

// @lc code=start
// 状态定义：dp[i][j][k]为 第i天、是否持有股票情况下，交易k次 获取的最大利润
// DP方程：
//  未持股：
//      dp[i][0][0] = 0
//      dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][0] + prices[i])
//      dp[i][0][2] = max(dp[i-1][0][2], dp[i-1][1][1] + prices[i])
//  持股：
//      dp[i][1][0] = 0

class Solution {
   public:
    int maxProfit(vector<int>& prices) {}
};
// @lc code=end
