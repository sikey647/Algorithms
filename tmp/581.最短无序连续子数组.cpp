/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
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

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() <= 1) 
            return nums.size();

        int res = 0, left = 0, right = nums.size() - 1;
        //for (int i = 1, j = nums.size() - 2; i <= j; i++, j--)
        // find left min index
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i-1]) {
                left = i - 1;
                break;
            }
        }
        
        // find right max index
        for (int j = nums.size() - 2; j >= 0; j --) {
            if (nums[j] > nums[j+1]) {
                right = j + 1;
                break;
            }
        }
    }
};
// @lc code=end

