/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
//#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        unordered_map<int, int> numMap;
        for (auto& num : nums) {
            numMap[num]++;
        }
        helper(0, nums.size(), numMap, sub, res);
        return res;
    }

    void helper(int level, int size, unordered_map<int, int>& numMap,
                vector<int>& sub, vector<vector<int>>& res) {
        // 1、递归终止条件
        if (level == size) {
            res.push_back(sub);
            return;
        }

        for (auto& num : numMap) {
            if (num.second > 0) {
                // 2、处理当前层逻辑
                sub.push_back(num.first);
                num.second--;
                // 3、递归到下一层
                helper(level + 1, size, numMap, sub, res);
                // 4、恢复当前层状态
                sub.pop_back();
                num.second++;
            }
        }
    }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     vector<int> sub;
    //     unordered_set<int> numSet(nums.begin(), nums.end());
    //     helper(0, nums.size(), nums, numSet, sub, res);
    //     return res;
    // }

    // void helper(int level, int size, vector<int>& nums,
    //             unordered_set<int>& numSet, vector<int>& sub,
    //             vector<vector<int>>& res) {
    //     // 1、递归终止条件
    //     if (level == size) {
    //         res.push_back(sub);
    //         return;
    //     }

    //     for (auto& num : nums) {
    //         if (numSet.find(num) != numSet.end()) {
    //             // 2、处理当前层逻辑
    //             sub.push_back(num);
    //             numSet.erase(num);
    //             // 3、递归到下一层
    //             helper(level + 1, size, nums, numSet, sub, res);
    //             // 4、恢复当前层状态
    //             numSet.insert(num);
    //             sub.pop_back();
    //         }
    //     }
    // }
};
// @lc code=end
