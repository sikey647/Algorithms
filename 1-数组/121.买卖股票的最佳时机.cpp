/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        int maxPrice = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            minPrice = min(minPrice, prices[i]);
            maxPrice = max(maxPrice, prices[i] - minPrice);
        }

        return maxPrice;
    }
};
// @lc code=end
