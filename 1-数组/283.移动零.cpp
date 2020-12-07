/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <vector>
using namespace std;

// 思路：（双指针）
//  指针j标记0的位置，指针i进行数组遍历
//  指针i从下标0开始，如果遇到0不做任何处理，直接遍历下一个元素
//  如果遇到非0，与j标记的元素进行交换，并且j移动到下一个位置
//  时间复杂度：O(n)
//  空间复杂度：O(1)

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int j = 0;
         for (int i = 0; i < nums.size(); i++) {
             if (nums[i] != 0) {
                 swap(nums[i], nums[j++]);
             }
         }
    }
};
// @lc code=end

