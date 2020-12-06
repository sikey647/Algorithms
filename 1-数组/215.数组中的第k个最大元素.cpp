/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 题目分析：
//  未排序数组，第k个最大的元素，且是排序后的第k个最大的元素
//
// 方法一：（暴力、排序）
//  先排序，再找第k个最大的元素
//  第k个最大元素，就是第(n-k)个最小元素
//  时间复杂度：O(nlogn) 
//
// 方法二：（小顶堆/优先级队列）
//  （方式二）维护一个大小为K的小顶堆，遍历数组，取数组元素与堆顶元素进行比较
//  如果数组元素比堆顶元素大，则删除堆顶元素，将数组元素插入堆中
//  如果数组元素比堆顶元素小，则不做处理，继续遍历下个元素
//  当数组元素遍历完成后，堆中的元素就是前K大的元素
//  堆顶元素是第K大元素
//  空间复杂度：O(k)
//  时间复杂度：遍历数组O(n)，一次堆化是O(logK)，
//  最坏一种情况下，n个元素都入堆一次，时间复杂度为O(nlogK)
//
// 方法三：（分治）
//  利用快速排序的思想，每次partition之后，pivot位置之前的元素都小于等于pivot元素，
//  之后的元素都大于等于pivot元素，即pivot元素所在的位置，是它最终的位置
//  第k个最大元素，就是第(n-k)个最小元素，找到(n-k)最终位置元素即可
//  过程：从特定区间[left, right)区间中随机选一个值pivot，
//  将小于等于它的元素，移动到它的前面，将大于等于它的元素，移动到它的后面，
//  比较pivot下标与(n-k)是否相等，如果相等，返回pivot位置的元素即可
//  如果pivot下标大于(n-k)，更新右边界right，否则更新左边界left
//  然后重复这个过程，直至pivot下标等于(n-k)为止

// @lc code=start
class Solution {
   public:
    // 方法一：（排序）
    // int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() - k];
    // }

    // 方法二：（优先级队列）
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int, vector<int>, greater<int> > heap;

    //     // 方式一：所有元素都入堆，堆的大小维持在K
    //     // for (int i = 0; i < nums.size(); i++) {
    //     //     heap.push(nums[i]);
    //     //     if (heap.size() > k) {
    //     //         heap.pop();
    //     //     }
    //     // }

    //     // 方式二：先维护一个大小为K的堆，数组元素与堆顶元素比较
    //     for (int i = 0; i < k; i++) {
    //         heap.push(nums[i]);
    //     }

    //     for (int i = k; i < nums.size(); i++) {
    //         if (nums[i] > heap.top()) {
    //             heap.pop();
    //             heap.push(nums[i]);
    //         }
    //     }

    //     return heap.top();
    // }

    // 方法三：
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int left = 0, right = nums.size() - 1;

        while (1) {
            int index = partition(nums, left, right, target);
            if (index == target) {
                return nums[target];
            } else if (index < target) {
                left = index + 1;
            } else if (index > target) {
                right = index - 1;
            }
        }
    }

    int partition(vector<int>& nums, int left, int right, int target) {
        int pivot = nums[left];
        int j = left;   // 记录小于pivot最后的位置

        // 分区！！！
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < pivot) {
                j++;
                swap(nums, i, j);    
            }
        }
        swap(nums, left, j);

        return j;
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
// @lc code=end
