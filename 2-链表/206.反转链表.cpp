/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */

// 方法一：（迭代）
//  后一个节点的指针，指向前一个节点
//  使用三个指针，pre记录前一个节点，cur记录当前节点，post后一个节点
//  遍历链表，终止条件是 cur 不为空  
//  
//  空间复杂度：  
//
// 方法二：（递归）
//  

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
   public:
    // 方法一：（迭代）
    // ListNode* reverseList(ListNode* head) {
    //     if (!head) return head;

    //     ListNode *pre = nullptr, *cur = head, *post = nullptr;

    //     while (cur) {
    //         post = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = post;
    //     }

    //     return pre;
    // }

    // 方法二：（递归）
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *h = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return h;
    }
};
// @lc code=end
