/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }

        int i = nums.size() - 2;
        // find: nums[i] < nums[i + 1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 不是最大序列
        if (i >= 0) {
            // find: nums[i] < num[j]
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end
