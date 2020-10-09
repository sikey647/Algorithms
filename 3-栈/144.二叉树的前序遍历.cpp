/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> tnStack;

        if (!root) return res;

        tnStack.push(root);

        while (!tnStack.empty()) {
            TreeNode *node = tnStack.top();
            res.push_back(node->val);
            tnStack.pop();

            if (node->right) tnStack.push(node->right);

            if (node->left) tnStack.push(node->left);
        }

        return res;
    }
};
// @lc code=end
