/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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

// long（总长度） = a（非环长度） + b（环长度）
// fast: fast指针走过的长度
// slow: slow指针走过的长度

// fast = 2 * slow
// fast = slow + n * b
// => slow = n * b, fast = 2 * n * b
// 设k指针走到入口的长度：k = a + n * b;
// 而slow = n * b，所以还需要走 a 次到达入口
// 新创建一个指针从 head 走 a 次次也达到入口，此时会相遇

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (true) {
            if (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                return nullptr;
            }

            if (fast == slow) {
                break;
            }
        }

        fast = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};
// @lc code=end
