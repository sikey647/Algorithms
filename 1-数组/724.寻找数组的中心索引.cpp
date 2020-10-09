/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int pivotIndex(vector<int> &nums) {
        // 2 * leftSum + nums[p] = sum
        int leftSum = 0, sum = 0;
        for (int &num : nums) {
            sum += num;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (leftSum * 2 + nums[i] == sum) return i;
            leftSum += nums[i];
        }

        return -1;
    }
};
// @lc code=end
