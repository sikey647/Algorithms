/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size()) {
            return -1;
        }

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int pivot = partition(nums, left, right);
            if (pivot == nums.size() - k) {
                return nums[pivot];
            } else if (pivot < nums.size() - k) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
        
        return -1;
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = right, deal = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < nums[pivot]) {
                swap(nums[i], nums[deal++]);
            }
        }

        swap(nums[deal], nums[pivot]);

        return deal;
    }
};
// @lc code=end

