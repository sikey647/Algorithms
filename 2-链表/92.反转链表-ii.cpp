/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */ 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *node = new ListNode(0), *pre = node, *cur;
        node->next = head;

        for (int i = 0; i < m - 1; i++) {
            pre = cur;
            cur = cur->next;
        }

        for (int i = 0; i < m - n; i++) {
            ListNode *tmp = cur->next;

        }
    }
};
// @lc code=end

