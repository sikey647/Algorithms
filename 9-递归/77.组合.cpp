/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sub;
        helper(res, sub, 1, n, k);
        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& sub, int level, int n, int k) {
        // 递归终止条件
        if (sub.size() == k) {
            res.push_back(sub);
            return;
        }

        // 处理当前层逻辑 & 递归到下一层 & 恢复当前层
        for (int i = level; i <= n; i++) {
            sub.push_back(i);
            helper(res, sub, i + 1, n, k);
            sub.pop_back();
        }
    }
};
// @lc code=end

