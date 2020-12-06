/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

#include <vector>
using namespace std;

// 思考：
//  找规律：num二进制中1的个数
//  0: (0)      res[0] = 0  （偶）-
//  1: (1)      res[1] = 1  （奇）
//  2: (10)     res[2] = 1  （偶）-
//  3: (11)     res[3] = 2  （奇）
//  4: (100)    res[4] = 1  （偶）-
//  5: (101)    res[5] = 2  （奇）
//  6: (110)    res[6] = 2  （偶）-
//  7: (111)    res[7] = 3  （奇）
//  8: (1000)   res[8] = 1  （偶）-
//
//  奇数比它前一个偶数中1的个数多1
//  res[i] = res[i - 1] + 1; i % 2 == 1
//
//  偶数向右移动1位（除2），1的个数不变
//  或一个数向左移动1位（乘2），1的个数不变
//  res[i] = res[i/2]; i % 2 == 0
//
//  动态规划问题

// @lc code=start
class Solution {
   public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);

        res[0] = 0;
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 1) {
                res[i] = res[i - 1] + 1;
            } else {
                res[i] = res[i / 2];
            }
        }

        return res;
    }
};
// @lc code=end
