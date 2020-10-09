/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int index = 0;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[index] != nums[j]) {
                nums[++index] = nums[j];
            }
        }
        return index + 1;
    }
};
// @lc code=end
