/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum > 0) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end
