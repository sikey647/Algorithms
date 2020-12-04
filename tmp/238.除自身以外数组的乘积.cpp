/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

#include <vector>
using namespace std;

// 题目分析：
//  限制一：O(n)时间复杂度完成
//  限制二：不能用除法
//
//  提示：输出元素 = 前缀积 * 后缀积
//
//  要求：在常数空间复杂度完成题目
//
// 思路：
//  输出元素 = 前缀积 * 后缀积，那如何计算每个元素的前缀积与后缀积？
//  先用一个数组存放前缀积，再用一个数组存放后缀积，最后两个数组相乘即可得到结果。
//  有点类似递归的思想：每个元素的前缀积 = 前一个元素 * 前一个元素的前缀积，
//  如示例，nums[1] = 1, 前缀积 preNums[1] = 1（首元素前缀积为1），
//  第二元素的前缀积 preNums[2] = nums[1] * preNums[1]
//  ...
//  同理：每个元素后缀积 = 后一个元素 * 后一个元素的的后缀积，
//  如示例，最后一元素的后缀积 postNums[3] = 1
//  倒数第二个元素的后缀积 postNums[2] = nums[3] * postNums[3]
//
//  题目进阶/要求使用常数空间复杂度，并说明输出数组不被视为额外空间。
//  因此我们要充分利用输出数组，如先临时将前缀积放到输出数组，
//  那后缀积怎么请求？
//  使用一个临时变量tmp，存放一个元素的后缀积，
//  如最后一元素的后缀积为1（tmp = 1），计算结果值res[3] *= tmp
//  然后更新下一个元素的后缀积 tmp *= nums[3]
//  以此类推

// @lc code=start
class Solution {
   public:
    // 方法一：O(2n)空间复杂度
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> res(nums.size(), 0);
    //     vector<int> preNums = nums, postNums = nums;

    //     // 计算前缀积
    //     preNums[0] = 1;
    //     for (int i = 1; i < nums.size(); i++) {
    //         preNums[i] = nums[i - 1] * preNums[i - 1];
    //     }

    //     // 计算后缀积
    //     postNums[nums.size() - 1] = 1;
    //     for (int j = nums.size() - 2; j >= 0; j--) {
    //         postNums[j] = nums[j + 1] * postNums[j + 1];
    //     }

    //     // 计算结果
    //     for (int k = 0; k < nums.size(); k++) {
    //         res[k] = preNums[k] * postNums[k];
    //     }

    //     return res;
    // }

    // 方式二：O(1)空间复杂度
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int tmp = 1;  // 存放后缀积

        // 计算前缀积
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            res[i] = nums[i - 1] * res[i - 1];
        }

        // 计算结果
        for (int j = nums.size() - 1; j >= 0; j--) {
            res[j] *= tmp;
            tmp *= nums[j];
        }

        return res;
    }
};
// @lc code=end
