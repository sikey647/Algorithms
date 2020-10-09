/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> uMap;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (uMap.find(diff) != uMap.end())
                return vector<int>{uMap[diff], i};
            uMap[nums[i]] = i;
        }
        return vector<int>{};
    }
};
// @lc code=end
