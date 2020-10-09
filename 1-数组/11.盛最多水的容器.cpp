/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int maxRes = 0;

        for (int i = 0, j = height.size() - 1; i < j;) {
            // int high = min(height[i++], height[j--]);
            int high = height[i] > height[j] ? height[j--] : height[i++];
            maxRes = max(maxRes, (j - i + 1) * high);
        }

        return maxRes;
    }
};
// @lc code=end
