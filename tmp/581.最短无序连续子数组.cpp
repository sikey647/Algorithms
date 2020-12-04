/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;

// 思考：
//  从左边第一个元素开始往后遍历，如果出现当前元素大于后一个元素，就停止，如i=1（元素6）
//  从右边最后一个元素，开始忘前遍历，如果当前元素小于前一个元素，就停止，如j=5（元素9）
//  找出[i,j]区间内最小元素min、最大元素max：
//      如果min>i-1，则min=i，(最终)
//          否则更新min=i-1
//      如果max<j+1，则max=j，（最终）
//          否则更新max=j+1
//  计算res=max-min+1
//
// 反思：
//  受示例的影响，把思路想复杂了。
//  其实目标就是找出左右边界。
//
// 正确思路是：
// 一、双指针（暴力）：
//  从头开始遍历，先锁定一个位置i，从当前位置向后移动j，
//  如果nums[i]>nums[j]，说明i与j的位置放反了，需要调整。（有点像选择排序）
//  因此，左边界可能是i，右边界可能是j，为什么说可能呢？
//  因为后面没有遍历到的位置的数值可能比当前i的数值还小，
//  同理后面没有遍历到的位置的数值可能比当前j的数值还大。
//  所以左边界取所有要调整i的最小值，右边界取要调整j的最大值。
//  时间复杂度：O(n^2)，空间复杂度：O(1)
//  运行超时了。。。
// 二、排序比较：
//  先进行排序，对比原数组，找出左右边界
//  时间复杂度：O(nlogn)，空间负责度：O(n)
// 三、单调栈（最佳）：
//  单调栈是什么？
//  栈中的元素，按递增顺序或递减顺序排列
//  单调栈有什么性质？
//  单调递增栈可以找到左起第一个比当前数值小的元素
//  单调递减栈可以找到左起第一个比当前数值大的元素
//  解题思路：
//  左边界：使用单调递增栈，当栈中有元素时，比较当前元素nums[i]与栈顶元素stack[top()]，
//  如果当前元素nums[i]大，则直接入栈，
//  否则弹栈，更新left为弹出元素下标，直至当前元素大于栈顶元素，入栈。
//  右边界：使用单调递减栈，当栈中有元素时，比较当前元素nums[j]与栈顶元素stack[top()]，
//  如果当前元素nums[j]小，则直接入栈，
//  否则弹栈，更新right为弹出元素下标，直至当前元素小于栈顶元素，入栈。

class Solution {
   public:
    // 方法一：双指针（超时）
    // int findUnsortedSubarray(vector<int>& nums) {
    //     // 注意：left 不能写成写成 nums.size()-1
    //     //      因为没有办法处理一个元素的case
    //     int left = nums.size(), right = 0;

    //     for (int i = 0; i < nums.size() - 1; i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             if (nums[i] > nums[j]) {
    //                 left = min(left, i);
    //                 right = max(right, j);
    //             }
    //         }
    //     }

    //     return right < left ? 0 : right - left + 1;
    // }

    // 方法二：排序比较
    // int findUnsortedSubarray(vector<int>& nums) {
    //     vector<int> sortNums = nums;
    //     sort(sortNums.begin(), sortNums.end());

    //     int left = nums.size(), right = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (sortNums[i] != nums[i]) {
    //             left = min(left, i);
    //             right = max(right, i);
    //         }
    //     }

    //     return right < left ? 0 : right - left + 1;
    // }

    // 方法三：单调栈
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> numsStack;
        int left = nums.size(), right = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (!numsStack.empty() && nums[i] < nums[numsStack.top()]) {
                left = min(left, numsStack.top());
                numsStack.pop();
            }
            numsStack.push(i);
        }

        numsStack = stack<int>();  // stack<int>().swap(s)
        for (int j = nums.size() - 1; j >= 0; j--) {
            while (!numsStack.empty() && nums[j] > nums[numsStack.top()]) {
                right = max(right, numsStack.top());
                numsStack.pop();
            }
            numsStack.push(j);
        }

        return right < left ? 0 : right - left + 1;
    }
};
// @lc code=end
