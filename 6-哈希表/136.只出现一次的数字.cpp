/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> cntMap;

        for (auto num : nums) {
            cntMap[num]++;
        }

        for (auto& itr : cntMap) {
            if (itr.second == 1) return itr.first;
        }

        return -1;
    }
};
// @lc code=end
