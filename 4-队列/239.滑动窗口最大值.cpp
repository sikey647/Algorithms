/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include <vector>
#include <deque>

using namespace std;

// 解法一：暴力
//  时间复杂度：O(k * n)
//  空间复杂度：O(n - k + 1)
//
// 解法二：单调队列（递减）
//  单调递减队列：
//  元素A入队时，如果队列为空，或小于等于队头元素B，则入队，
//  否则队头元素出队，直至元素A小于等于队头元素，或队列为空
//  时间复杂度：
//  空间复杂度：

// @lc code=start

class DecrQueue {
public:
    DecrQueue() = default;
    ~DecrQueue() = default;

    void push(int x) {
        while (!m_deque.empty() && x > m_deque.back())
            m_deque.pop_back();
        m_deque.push_back(x);
    }

    void pop(int x) {
        if (!m_deque.empty() && m_deque.front() == x)
            m_deque.pop_front();
    }

    int max() {
        return m_deque.front();
    }

private:
    deque<int> m_deque;
};

class Solution {
public:
    // 解法一：暴力
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> res;

    //     for (int i = 0; i < nums.size() - k + 1; i++) {
    //         int maxNum = INT16_MIN;
    //         for (int j = i; j < i + k; j++) {
    //             maxNum = max(maxNum, nums[j]);
    //         }
    //         res.push_back(maxNum);
    //     }

    //     return res;
    // }

    // 解法二：单调队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        DecrQueue deq;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                deq.push(nums[i]);
            } else {
                deq.push(nums[i]);
                res.push_back(deq.max());
                deq.pop(nums[i - k + 1]);
            }
        }

        return res;
    }
};
// @lc code=end

