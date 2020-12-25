/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include <stack>
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
//  时间复杂度：O(n^2)，枚举所有的柱子为O(n)，查找左右边界为O(n)
//  空间负杂度：O(1)
//
// 解法三：单调栈
//  和解法二思路一样，枚举所有的柱子，并查找左右边界，
//  单调栈特性：（以单调递增栈为例）
//   新元素A入栈时，如果大于等于栈顶元素B或栈为空，则入栈
//   如果小于栈顶元素B，则栈顶元素B出栈，
//   此时新元素A为已出栈元素B的右边界（即右边第一个比元素B小的元素）
//   此时新栈顶元素C为已出栈元素B的左边界（即左边第一个比元素B小的元素）
//   当确定了已出栈元素B的左右边界，就可以执行相关业务逻辑（如计算面积）
//   接着新元素A与新元素C继续进行上述操作，直至枚举所有元素。
//  这道题中，定义一个栈，元素为数组的下标
//  代码模板:
//   stack<int> incrStack;
//   for (int i = 0; i < nums.size(); i++) {
//      while (!incrStack.empty() && nums[incrStack.top()] > nums[i]) {
//          // 记录栈顶为左边界、新元素为右边界
//          incrStack.pop();
//      }
//      incrStack.push(i);
//   }

// @lc code=start
class Solution {
   public:
    // 解法一：（暴力解法）超时
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

    // 解法二：（暴力解法加速）超时
    // int largestRectangleArea(vector<int>& heights) {
    //     int maxArea = 0;

    //     for (int i = 0; i < heights.size(); i++) {
    //         int height = heights[i];

    //         int left = i, right = i;
    //         while (left > 0 && heights[left - 1] >= height) left--;
    //         while (right < heights.size() - 1 && heights[right + 1] >=
    //         height)
    //             right++;

    //         maxArea = max(maxArea, height * (right - left + 1));
    //     }

    //     return maxArea;
    // }

    // 解法三：（单调栈）
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> incrStack;

        for (int i = 0; i < heights.size(); i++) {
            while (!incrStack.empty() &&
                   heights[incrStack.top()] > heights[i]) {
                int height = heights[incrStack.top()];
                incrStack.pop();
                int right = i;
                int left = -1;
                if (!incrStack.empty()) left = incrStack.top();
                maxArea = max(maxArea, height * (right - left - 1));
            }
            incrStack.push(heights[i]);
        }

        while (!incrStack.empty()) {
            int height = heights[incrStack.top()];
            incrStack.pop();
            int right = heights.size();
            int left = -1;
            if (!incrStack.empty()) left = incrStack.top();
            maxArea = max(maxArea, height * (right - left - 1));
        }

        return maxArea;
    }
};
// @lc code=end
