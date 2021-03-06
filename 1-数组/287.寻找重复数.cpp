/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <vector>
using namespace std;

// 题目分析：
//  整数数组nums：
//  1). 元素个数为 n + 1
//  2). 每个元素的取值范围 1 <= nums[i] <= n，
//
// 联想：
//  nums = [1, 2, 3, 4, 5]，有5个元素
//  1 <= nums[i] <= 4，所以 nums 中是不会有 5 这个元素的，肯定会有重复的
//  这个有点像抽屉原理：4个抽屉，装5个球，肯定有一个抽屉装了2个球，但是有点不一样。
//  可以理解为：有5个抽屉，4种编号的球，肯定有抽屉放相同编号的球。（构成了重复条件）
//  现在问题就是找到哪种编号的球放在多个抽屉里？
//
// 说明：
//  只有一个重复的数字，但它可能重复出现多次。
//  即只有一种编号的球，会放在多个抽屉里（两个或多个）。
//
// 要求：
//  1). 不能修改原数组      -- 不能原地排序
//  2). 时间复杂度为O(1)    -- 不能借助map或原地哈希
//  3). 时间复杂度小于O(n)   -- 不能暴力求解
//
// 方法一：（二分法 + 抽屉原理）
//  随机选一个编号的球，如果小于等于这个编号的球的个数，超过编号本身，
//  就说明这个编号之前的球，包括这个编号的球，肯定会有重复编号，要不然数量是不会超过编号本身的，
//  最多也就是编号本身的数量。
//  因此就缩小了查找范围，之后，再按照这个思路进行查找。
//  如：随机挑选一个编号为3的球，找出编号小于等于3号的球的个数，如果等于4，
//  就说明3号之前的球，包括3号球，肯定有重复的编号。
//  按照这个思路，从1-3号球之间，再随机选一个编号，进行查找。
//  终止条件是什么？
//  借助二分查找的思想，当前左右边界相等时，即共同指向一个元素时，那这个元素就是重复的。
//
// 方法二：（双指针）
//  借助快慢指针，类似于判断链表是否有环，如果有环会两个指针会指向同一个位置。
//  如果有重复元素，快慢指针都会指向同一个元素。

// @lc code=start
class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            // find cnt : x >= mid
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }

            // 确定重复元素范围
            if (cnt > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
// @lc code=end
