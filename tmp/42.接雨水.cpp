/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>
#include <stack>
using namespace std;

// 解法一：（暴力）
//  思路：枚举每根柱子，求出每根柱子可接多少水，
//  首先，第一根柱子与最后一个柱子是无法接到水的，
//  因此从第二根柱子枚举到倒数第二根柱子即可。
//  每个柱子可接多少水，得需要知道它左边高于它的最高的柱子
//  与它右边高于它的最高柱子的高度，两者取较小者，即为可接到的雨水
//
//  时间复杂度：O(n^2)，枚举所有柱子为O(n)，查找每个柱子的左右边界为O(n)
//  空间复杂度：O(1)
//
//
// 解法二：（动态规划）
//  暴力解法需要每根柱子都需要遍历左右所有的柱子来找到左右边界
//  其实我们可以先进行一次遍历，把所有的柱子的左右边界都找出来，
//  然后再枚举所有柱子，根据之前已经找出的左右边界求结果即可
//  那如何找出每个柱子的左右高度呢？ 使用动态规划：
//  状态定义1：每个柱子的左边界（左边最大值）
//  DP方程1：left_dp[i] = max(left_dp[i - 1], nums[i])
//  状态定义2：每个柱子的右边界（右边最大值）
//  DP方程2：right_dp[j] = max(right_dp[j + 1], nums[j])
//
//  时间复杂度：O(n)，一次遍历求出所有的柱子的所有高度为O(n)，再枚举所有的柱子为O(n)，没有嵌套
//  空间复杂度：O(n)，需要使用额外的数组存放状态
//
//
// 解法三：（单调栈）（递减）
//  可接到水的条件是，当前的柱子的左边和右边都有比它高的柱子，
//  因此对每个柱子遍历的时候，如果它左边的柱子高于它，后面的柱子高于它，
//  则说明可以存储到水。
//  这里借助单调递减栈，即入栈的每个元素都必须小于等于栈顶元素，否则必须出栈，进行逻辑处理。
//  枚举所有柱子，如果栈为空，或当前柱子A小于等于栈顶柱子B，则柱子B入栈。
//  如果当前柱子A大于栈顶柱子B，说明栈顶柱子B的当前右边界为柱子A，这是柱子B出栈， 
//  这时栈顶为柱子C，栈顶柱子C是大于等于柱子B，所以柱子C为柱子B当前左边界，
//  然后取左右边界的较小者为高度，再减去当前高度，长度为左右边界的距离，
//  根据以上两值就可以求出同一水平可接到的水。
//  重复以上步骤，直接枚举完所有的柱子即可。
//
//  时间复杂度：O(n)，枚举所有柱子为O(n)，每个柱子都出栈与入栈一次为O(1)
//  空间复杂度：O(n)，需要使用额外的栈
//

// @lc code=start
class Solution {
public:
    // 解法一：（暴力）(超时)
    // int trap(vector<int>& height) {
    //     int res = 0;
    //     if (height.size() < 3)
    //         return res;

    //     for (int i = 1; i < height.size() - 1; i++) {
    //         int left = 0, right = 0;

    //         for (int j = i - 1; j >= 0; j--) {
    //             if (height[j] > height[i])
    //                 left = max(left, height[j]);
    //         }

    //         for (int j = i + 1; j < height.size(); j++) {
    //             if (height[j] > height[i])
    //                 right = max(right, height[j]);
    //         }

    //         int minHigh = min(left, right);
    //         if (minHigh > height[i])
    //             res += (minHigh - height[i]);
    //     }

    //     return res;
    // }

    // 解法二：（动态规划）
    // int trap(vector<int>& height) {
    //     int res = 0;
    //     if (height.size() < 3)
    //         return res;

    //     vector<int> left_dp(height.size(), 0), right_dp(height.size(), 0);
    //     left_dp[0] = height[0];
    //     right_dp[height.size() - 1] = height[height.size() - 1];

    //     for (int i = 1; i < height.size(); i++) {
    //         left_dp[i] = max(left_dp[i - 1], height[i]);
    //     }

    //     for (int j = height.size() - 2; j >= 0; j--) {
    //         right_dp[j] = max(right_dp[j + 1], height[j]);
    //     }

    //     for (int k = 1; k < height.size() - 1; k++) {
    //         int minHeight = min(left_dp[k], right_dp[k]);
    //         res += (minHeight - height[k]);
    //     }

    //     return res;
    // }

    // 解法三：（单调递减栈）
    int trap(vector<int>& height) {
        int res = 0;
        if (height.size() < 3)
            return res;

        stack<int> decrStack;
        for (int i = 0; i < height.size(); i++) {
            while (!decrStack.empty() && height[decrStack.top()] < height[i]) {
                int curHeight = height[decrStack.top()];
                decrStack.pop();

                if (decrStack.empty())  break;
                int left = decrStack.top();
                int right = i;

                int subHeight = min(height[left], height[right]) - curHeight;
                res += subHeight * (right - left - 1);
            }

            decrStack.push(i);
        }

        return res;
    }
};
// @lc code=end
