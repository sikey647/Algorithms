/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// 方法一：（双指针、快慢指针）
//  时间复杂度：
//  空间复杂度：
//
// 方法二：（记忆化）
//  时间复杂度：
//  空间复杂度：

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode *fast = head, *slow = head;
        while (fast && fast->next && slow) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }

        return false;
    }
};
// @lc code=end

