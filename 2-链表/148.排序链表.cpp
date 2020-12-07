/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */


// @lc code=start
/**
 * Definition for singly-linked list.
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// 题目分析：
//  链表 升序 排序
//  要求：时间复杂度：O(nlog)，空间复杂度：O(k) 常数时间复杂度
//
// 方法一：（递归法）
//  归并排序，
//  将两个链表从中间位置分开，分别对两个子链表进行排序，然后合并两个有序的链表
//  如何分链表？分到什么条件为止？如何合并？
//  分链表方式： 使用快慢双指针
//  终止条件：子链表只有一个节点
//  合并：双指针法合并
//  因为递归调用函数，空间复杂度是 O(logn)
//
// 方式二：（子底向上合并）
//  待补充。。。。

class Solution {
public:
    // 方法一
    ListNode* sortList(ListNode* head) {
        // 判断终止条件
        if (!head || !head->next) {
            return head;
        }

        // 拆分链表
        ListNode *fast = head->next, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *tmp = slow->next;
        slow->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(tmp);

        // 合并链表
        ListNode *h = new ListNode(0);
        ListNode *res = h;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                h->next = left;
                left = left->next;
            } else {
                h->next = right;
                right = right->next;
            }
            h = h->next;
        }

        h->next = (left != nullptr ? left : right);

        return res->next;
    }
};
// @lc code=end

