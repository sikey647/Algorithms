/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;

        if (m == 0 || n == 0) {
            return false;
        }

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }

            matrix[i][j] > target ? j-- : i++;
        }

        return false;
    }
};
// @lc code=end
