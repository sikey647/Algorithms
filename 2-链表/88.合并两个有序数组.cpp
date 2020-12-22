/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <vector>
using namespace std;

// 方法：
//  从后向前比较两个数组元素，较大者，移动到新数组对应的位置。
//  使用 i,j 分别从 nums1[m-1] 和 nums2[n-1] 位置开始比较，
//  取较大者，赋值给 nums[index]，并更新index。

// @lc code=start
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, index = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[index--] = nums1[i--];
            } else {
                nums1[index--] = nums2[j--];
            }
        }
    }
};
// @lc code=end
