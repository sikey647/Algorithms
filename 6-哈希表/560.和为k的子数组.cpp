/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> numMap = {{0, 1}};
        int resCnt = 0, preSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            preSum += nums[i];
            if (numMap.find(preSum - k) != numMap.end())
                resCnt += numMap[preSum - k];
            numMap[preSum]++;
        }

        return resCnt;
    }
};
// @lc code=end
