/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
using namespace std;

// 思考：起初没有审清题，想成按index进行下探，数组中每个元素取或不取的情况。
//      忽略了“数组中的数字可以无限重复”，即每一层需要从头遍历数组。
// 重点：一定要画出树形图，直观，有助于解题
// 问题：如何去除重复解？
class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.size() == 0) return res;

        vector<int> sub;
        helper(candidates, target, 0, sub, res);
        return res;
    }

    void helper(vector<int>& candidates, int target, int index,
                vector<int>& sub, vector<vector<int>>& res) {
        // 终止条件
        if (target == 0) {
            res.push_back(sub);
            return;
        } else if (target < 0) {
            return;
        }

        // 处理当前层逻辑 & 递归到下一层
        for (int start = index; start < candidates.size(); start++) {
            sub.push_back(candidates[start]);
            helper(candidates, target - candidates[start], start, sub, res);
            sub.pop_back();
        }
    }
};
// @lc code=end
