/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
#include <unordered_map>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        /*ListNode *l1 = headA, *l2 = headB;
        while (l1 != l2) {
            l1 = l1 == nullptr ? headB : l1->next;
            l2 = l2 == nullptr ? headA : l2->next;
        }
        return l1;*/
        unordered_map<ListNode *, int> listMap;
        ListNode *l1 = headA, *l2 = headB;
        while (l1) {
            listMap[l1] = 1;
            l1 = l1->next;
        }
        while (l2) {
            if (listMap.find(l2) != listMap.end()) {
                return l2;
            }
            l2 = l2->next;
        }
        return nullptr;
    }
};
// @lc code=end
