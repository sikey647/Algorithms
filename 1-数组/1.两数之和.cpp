/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

// 题目分析
//  注意：是返回元素下标，而不是元素值
//
// 方法一：（暴力）
//  时间复杂度：O(n^2)
// 
// 方法二：（记忆化map）
//  缓存之前的值，每次不需要从头遍历
//  使用map存放之前遍历过的元素，key为元素值，value为下标i
//  每次取到新元素后，计算差值：diff = target - nums[i]
//  如果map中存在diff，则返回diff的下标与当前下标i
// 
//  时间复杂度：一次遍历，O(n)
//  空间复杂度：使用map存放遍历过的元素，O(n)

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;

        if (nums.size() < 2) return res;

        // key: nums[i], value: i
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (hashMap.find(diff) != hashMap.end()) {
                res.push_back(hashMap[diff]);
                res.push_back(i);
                return res;
            }
            hashMap[nums[i]] = i;
        }

        return res;
    }
};
// @lc code=end
