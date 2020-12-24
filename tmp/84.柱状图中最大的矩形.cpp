/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include <vector>
using namespace std;

// 思路
// 解法一：暴力解法
//  枚举左边界：0 < i < n - 1
//  枚举右边界：i < j < n
//  找到左右边界的最低的高度 minHeight
//  面积为 minHeight * (j - i + 1)，取所有值的最小者
//  时间复杂度：O(n^3)， 枚举左右高度为O(n^2)，找最小高度为O(n)
//  空间复杂度：O(1)
//
// 解法二：暴力解法加速
//  枚举每个柱子，查找其左边界与右边界，即第一个比其小的位置，
//  取左右边界的距离，与当前高度，计算出面积，取所有值的最小者
//
// 解法三：单调栈

// @lc code=start
class Solution {
   public:
    // 解法一：（暴力解法）
    // int largestRectangleArea(vector<int>& heights) {
    //     int maxArea = 0;

    //     for (int i = 0; i < heights.size() - 1; i++) {
    //         for (int j = i + 1; j < heights.size(); j++) {
    //             int minHeight = heights[i];
    //             for (int k = i; k <= j; k++)
    //                 minHeight = min(minHeight, heights[k]);
    //             maxArea = max(maxArea, minHeight * (j - i + 1));
    //         }
    //     }

    //     return maxArea;
    // }

    // 解法二：（暴力解法加速）
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];

            int left = i, right = i;
            while (left > 0 && heights[left - 1] >= height) left--;
            while (right < heights.size() - 1 && heights[right + 1] >= height)
                right++;

            maxArea = max(maxArea, height * (right - left + 1));
        }

        return maxArea;
    }
};
// @lc code=end
