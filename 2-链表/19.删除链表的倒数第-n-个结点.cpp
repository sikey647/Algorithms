/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 双指针
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n == 0) {
            return head;
        }

        ListNode* dummy = new ListNode(-1, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;

        delete del;

        return dummy->next;
    }
};
// @lc code=end
