/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// 题目解析：
//  空间复杂度为O(1)，即不能额外使用新数组
//  因此，这里排除使用新数组的方法
// 
// 方法一：（暴力）（超时）
//  所有元素向后移动1次，重复k次。
//
// 方法二：（环状替换）
//  
// 方法三：（反转）
//  1). 数组反转       [7, 6, 5, 4, 3, 2, 1]
//  2). 前k个元素反转   [5, 6, 7, 4, 3, 2, 1]
//  3). 后n-k元素反转   [5, 6, 7, 1, 2, 3, 4]
//  时间复杂度：n个元素被交换了3次，O(n)

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 方法一：（暴力）（超时）
    // void rotate(vector<int>& nums, int k) {
    //     if (nums.size() <= 1) return ;
    
    //     for (int c = 0; c < k; c++) {
    //         int pre = nums[nums.size() - 1];
    //         for (int i = 0; i < nums.size(); i++) {
    //             int temp = nums[i];
    //             nums[i] = pre;
    //             pre = temp;
    //         }
    //     }
    // }

    // 方法二：（环状替换）
    // void rotate(vector<int>& nums, int k) {

    // }

    // 方法三：（反转）
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + (k % nums.size()));
        reverse(nums.begin() + (k % nums.size()), nums.end());
    }   
};
// @lc code=end

