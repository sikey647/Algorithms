/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sub;
        helper(0, k, 1, n, sub, res);
        return res;
    }

    void helper(int level, int k, int start, int n, vector<int>& sub,
                vector<vector<int>>& res) {
        if (level == k) {
            res.push_back(sub);
            return;
        }

        for (int i = start; i <= n; i++) {
            // 处理当前层逻辑
            sub.push_back(i);
            // 递归到下一层
            helper(level + 1, k, i + 1, n, sub, res);
            // 恢复当前层状态
            sub.pop_back();
        }
    }
};
// @lc code=end
