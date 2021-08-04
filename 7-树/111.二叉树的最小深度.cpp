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
    // 合并版本
    // int minDepth(TreeNode *root) {
    //     if (!root) return 0;
    //     int leftDepth = minDepth(root->left);
    //     int rightDepth = minDepth(root->right);

    //     return (!root->left || !root->right) ? leftDepth + rightDepth + 1
    //                                          : min(leftDepth, rightDepth) + 1;
    // }

    // 深度优先遍历
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);

        if (root->left == nullptr) {
            return minRight + 1;
        }

        if (root->right == nullptr) {
            return minLeft + 1;
        }

        return min(minLeft, minRight) + 1;
    }
};
// @lc code=end
