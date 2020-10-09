/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
   public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *l1 = dummy, *l2 = dummy;
        int len = 0;

        while (l1->next) {
            len++;
            l1 = l1->next;
        }

        for (int i = 0; i < len - (k % len); i++) {
            l2 = l2->next;
        }

        l1->next = dummy->next;
        dummy->next = l2->next;
        l2->next = nullptr;

        return dummy->next;
    }
};
// @lc code=end
