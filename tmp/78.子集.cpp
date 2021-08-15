/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 方式一：递归
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     vector<int> sub;

    //     helper(res, sub, nums, 0);

    //     return res;
    // }

    // void helper(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums, int level) {
    //     if (level == nums.size()) {
    //         res.push_back(sub);
    //         return;
    //     }

    //     helper(res, sub, nums, level + 1);
    //     sub.push_back(nums[level]);
    //     helper(res, sub, nums, level + 1);
    //     sub.pop_back();
    // }

    // 方式二
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>{});

        for (auto& num : nums) {
            vector<vector<int>> tmp = res;
            for (auto& sub : tmp) {
                sub.push_back(num);
                res.push_back(sub);
            }
        }

        return res;
    }
};
// @lc code=end

