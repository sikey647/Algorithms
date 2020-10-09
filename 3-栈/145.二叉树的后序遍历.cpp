/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> postorderTraversal(TreeNode *root) {
        /*vector<int> res;
        stack<pair<bool, TreeNode *>> tnStack;
        TreeNode *node = root;

        while (!tnStack.empty() || node) {
            while (node) {
                tnStack.push(make_pair(false, node));
                node = node->left;
            }

            node = tnStack.top().second;

            if (tnStack.top().first) {
                res.push_back(node->val);
                tnStack.pop();
                node = nullptr;
            } else {
                tnStack.top().first = true;
                node = node->right;
            }
        }

        return res;*/

        // 转换法
        // 先序遍历：根、左、右
        // 后序遍历：左、右、根
        // 1). 根、右、左   2). 反转：左、右、根
        vector<int> res;
        stack<TreeNode *> tnStack;
        if (!root) return res;

        TreeNode *node = root;
        tnStack.push(node);
        while (!tnStack.empty()) {
            node = tnStack.top();
            tnStack.pop();
            res.push_back(node->val);

            if (node->left) tnStack.push(node->left);
            if (node->right) tnStack.push(node->right);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end
