/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <vector>
#include <algorithm>
using namespace std;

// 注意：
//  不可以包含重复的三元组！！！
// 
// 方法一：（暴力）
//  时间复杂度：O(n^3)
//
// 方法二：（排序 + 双指针）
//  思路是 先固定一个数，再去调节另外两个数。
//  先将数组排序，判断边界条件：如果最后一个元素值小于0，则直接返回结果。
//
//  使用i从头开始遍历数组，遍历到倒数第2个位置为止，
//  需要判断2种情况，如果当前元素大于0，则直接退出遍历，返回结果。
//  如果当前元素与上一个元素的值相同，则跳过，遍历下一个元素
//
//  使用left从i的后面开始向后移动，使用right从数组最后开始向前移动，
//  在 left < right 的条件下，先计算三者之和 sum，
//  如果 sum > 0，则向前移动 right，
//      需要考虑 right 位置的值会有重复，因此需要跳过重复的值。
//  如果 sum < 0，则向后移动 left，
//      需要考虑 left 位置的值会有重复，因此需要跳过重复的值。
//  如果 sum = 0，将三者添加到结果集中，并更新 left 和 right，
//      同使需要考虑 left、right 位置的值可能会重复，因此需要跳过重复的值。
//
//  时间复杂度：数组排序是O(nlogn)，数组遍历是O(n)，双指针是O(n)
//  整体是 O(nlogn) + O(n) * O(n) = O(nlogn) + O(n^2) = O(n^2)

// @lc code=start
class Solution {
public:
    // 方法一：（暴力）
    // vector<vector<int> > threeSum(vector<int>& nums) {
    //     vector<vector<int> > res;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); i++) {
    //             for (int k = j + 1; k < nums.size(); k++) {
    //                 if (nums[i] + nums[j] + nums[k] == 0) {
    //                     res.push_back(vector<int>{i, j , k});
    //                 }
    //             }
    //         }
    //     }

    //     return res;
    // }

    // 方法二：（排序 + 双指针）
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;

        if (nums.size() < 3) return res;

        // 先排序
        sort(nums.begin(), nums.end());

        // 如果最大的元素小于0，就不存在结果
        if (nums[nums.size() - 1] < 0) return res;


        for (int i = 0; i < nums.size() - 2; i++) {
            // 如果当前元素大于0，那么后面所以也都大于0，就不存在结果
            if (nums[i] > 0) break;

            // 考虑重复的情况
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // 定义双指针，查找结果
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    // right 左移，考虑重复情况
                    while (left < right && nums[right] == nums[--right]);
                } else if (sum < 0) {
                    // left 右移，考虑重复情况
                    while (left < right && nums[left] == nums[++left]);
                } else {
                    // 存放结果
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // left 右移，考虑重复情况
                    while (left < right && nums[left] == nums[++left]);
                    // right 左移，考虑重复情况
                    while (left < right && nums[right] == nums[--right]);
                }
            }
        }

        return res;
    }
};


