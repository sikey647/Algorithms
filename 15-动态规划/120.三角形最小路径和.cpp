/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    // 方法一：自顶向下
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     if (triangle.size() == 0) return 0;
    //     return helper(0, 0, triangle);
    // }

    // int helper(int i, int j, vector<vector<int>>& triangle) {
    //     if (i == triangle.size() - 1) return triangle[i][j];

    //     int left = helper(i + 1, j, triangle);
    //     int right = helper(i + 1, j + 1, triangle);

    //     return min(left, right) + triangle[i][j];
    // }

    // 方法二：自顶向下 + 记忆化
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        vector<vector<int>> v(
            triangle.size(),
            vector<int>(triangle[triangle.size() - 1].size(), 0));
        return helper(0, 0, triangle, v);
    }

    int helper(int i, int j, vector<vector<int>>& triangle,
               vector<vector<int>>& v) {
        if (v[i][j] == 0) {
            if (i == triangle.size() - 1) {
                v[i][j] = triangle[i][j];
            } else {
                int left = helper(i + 1, j, triangle, v);
                int right = helper(i + 1, j + 1, triangle, v);
                v[i][j] = min(left, right) + triangle[i][j];
            }
        }
        return v[i][j];
    }

    // 方法三：自底向上
    // 重复性：坐标(i,j)到底部的最小路径和 = 坐标(i+1,j)到底部的最小路径和 与
    // 坐标(i+1,j+1)到底部的最小路径和 + 当前节点值
    // 状态数组：dp[i][j]坐标(i,j)到底部的最小路径和
    // DP数组：dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j]
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     if (triangle.size() == 0) return 0;
    //     vector<vector<int>> dp = triangle;
    //     for (int i = triangle.size() - 2; i >= 0; i--) {
    //         for (int j = 0; j < triangle[i].size(); j++) {
    //             dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) +
    //             triangle[i][j];
    //         }
    //     }

    //     return dp[0][0];
    // }
};
// @lc code=end
