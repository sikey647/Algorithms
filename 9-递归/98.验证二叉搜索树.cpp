/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }

    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root) {
            return true;
        }

        // 不满足情况
        if ((min && min->val >= root->val) || (max && max->val <= root->val)) {
            return false;
        }

        // 下探
        bool isLeftVaild = helper(root->left, min, root);
        bool isRightVaild = helper(root->right, root, max);

        return isLeftVaild && isRightVaild;
    }
};
// @lc code=end

