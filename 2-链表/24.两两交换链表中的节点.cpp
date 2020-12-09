/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 方法一：（迭代）
//  时间复杂度：O(n)
//  空间负责度：O(1)  
//
// 方法二：（递归）
//  时间复杂度：O(n)
//  空间复杂度：O(n)，主要取决于递归调用栈空间

class Solution {
public:
    // 方法一：（递归）
    // ListNode* swapPairs(ListNode* head) {
    //     if (!head || !head->next) return head;

    //     ListNode *post = head->next;
    //     head->next  = swapPairs(post->next);
    //     post->next = head;

    //     return post;
    // }

    // 方法二：（迭代）
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre = new ListNode(0);
        pre->next = head;

        ListNode *cur = pre;

        while (cur->next && cur->next->next) {
            ListNode *node1 = cur->next;
            ListNode *node2 = cur->next->next;

            cur->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            cur = node1;
        }

        return pre->next;
    }
};
// @lc code=end

