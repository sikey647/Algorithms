/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>{});

        for (auto& num : nums) {
            vector<vector<int>> sub = res;
            for (auto& v : sub) {
                v.push_back(num);
                res.push_back(v);
            }
        }

        return res;
    }
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     vector<int> v;
    //     helper(0, nums, v, res);

    //     return res;
    // }

    // void helper(int level, vector<int>& nums, vector<int>& v,
    //             vector<vector<int>>& res) {
    //     // 递归终止条件
    //     if (level == nums.size()) {
    //         res.push_back(v);
    //         return;
    //     }

    //     helper(level + 1, nums, v, res);

    //     // 处理当前层
    //     v.push_back(nums[level]);
    //     // 下探到下一层
    //     helper(level + 1, nums, v, res);
    //     // 恢复当前层状态
    //     v.pop_back();
    // }
};
// @lc code=end
