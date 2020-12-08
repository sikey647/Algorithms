/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <vector>
using namespace std;

// 题目解析
//  需要考虑进位的情况
//  [9]     ->   [1,0]
//  [9,9]   ->   [1,0,0]
//  [9,9,9] ->   [1,0,0,0]
//  方法：将首元素改为1，最后新增一个元素0

// @lc code=start
class Solution {
public:
    // 方法一：
    // vector<int> plusOne(vector<int>& digits) {
    //     int flag = 1;
    //     for (int i = digits.size() - 1; i >= 0 ; i--) {
    //         int num = digits[i] + flag;
    //         flag = num / 10;
    //         digits[i] = num % 10;
    //     }
        
    //     if (flag) {
    //         digits[0] = 1;
    //         digits.push_back(0);  
    //     }

    //     return digits; 
    // }

    // 方法二：
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0 ; i--) {
            //digits[i] = ++digits[i] % 10;
            //if (digits[i] != 0) {
            if (++digits[i] %= 10 ) {
                return digits;
            }
        }

        digits[0] = 1;
        digits.push_back(0);

        return digits;
    }
};
// @lc code=end

