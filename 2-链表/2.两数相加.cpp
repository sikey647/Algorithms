/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l = new ListNode(0), *head = l;
        int sum = 0;
        while (l1 || l2) {
            sum /= 10;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            l->next = new ListNode(sum % 10);
            l = l->next;
        }
        if (sum / 10 == 1) l->next = new ListNode(1);
        return head->next;
    }
};
// @lc code=end
