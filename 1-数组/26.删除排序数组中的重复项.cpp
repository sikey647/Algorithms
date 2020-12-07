/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// 题目分析
//  原地 删除重复的元素
//  返回新数组的长度
//  使用O(1)额外的空间
//
// 方法：（双指针）
//  使用j存放新数组元素
//  使用i遍历数组，如果i位置是非重复元素，将该元素值拷贝到j位置上，并将j后移
//  如果i位置是重复元素，不做任何操作，遍历下一个元素值    
//  
//  时间复杂度：O(n)
//  空间复杂度：O(1)

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            // 非重复元素
            if (nums[i] != nums[i - 1]) {
                nums[++j] = nums[i];
            }
        }

        return j + 1;
    }
};
// @lc code=end
