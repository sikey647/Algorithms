/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        return (!root->left || !root->right) ? leftDepth + rightDepth + 1
                                             : min(leftDepth, rightDepth) + 1;
    }
};
// @lc code=end
