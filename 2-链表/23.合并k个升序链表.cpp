/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 创建头结点
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        // 小顶堆
        auto greater = [](ListNode *l1, ListNode *l2)->bool{
            return l1->val > l2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(greater)> heap(greater);

        // 将每个链表的头放到
        for (auto list : lists) {
            if (list != nullptr) {
                heap.push(list);
            }
        }

        while (!heap.empty()) {
            ListNode* top = heap.top();
            tail->next = top;
            heap.pop();

            if (top->next) {
                heap.push(top->next);
            }

            tail = tail->next;
        }

        return head->next;
    }
};
// @lc code=end

