/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;

        helper(res, sub, candidates, 0, target);

        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& sub, vector<int>& candidates, int index, int target) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                sub.push_back(candidates[i]);
                helper(res, sub, candidates, i, target - candidates[i]);
                sub.pop_back();
            }
        }
    }
};
// @lc code=end

