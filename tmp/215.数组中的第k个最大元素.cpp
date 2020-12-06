/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include <algorithm>
#include <vector>
using namespace std;

// 题目分析：
//  未排序数组，第k个最大的元素，且是排序后的第k个最大的元素
//
// 方法一：（暴力思路）
//  先排序，再找第k个最大的元素
//  第k个最大元素，就是第(n-k+1)个最小元素
//
// 方式二：（堆）

// @lc code=start
class Solution {
   public:
    // 方式一：
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
// @lc code=end
