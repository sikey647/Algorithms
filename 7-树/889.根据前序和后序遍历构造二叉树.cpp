/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */

#include <vector>
using namespace std;

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return helper(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd) {
            return nullptr;
        }

        // 创建根节点（依据先序遍历第一个节点）[根节点、左子树、右子树]
        TreeNode *root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) {
            return root;
        }

        // 查找左/右子树分界点（从中序遍历中查找）[左子树、右子树、根节点]
        // 查找条件：先序遍历中，根节点后面的节点是 左子树的根节点；后序遍历中，左子树的根节点是左右子树的分界点
        int index = postStart;
        while (preorder[preStart + 1] != postorder[index]) {
            index++;
        }
        // index为分界点
        // 后序：左子树 [postStart, index]，右子树 [index + 1, post_end - 1]
        // 先序：左子树 [preStart + 1, preStart + 1 + (index - postStart)]，右子树 [preStart + 1 + (index - postStart) + 1, preEnd]
        root->left = helper(preorder, preStart + 1, preStart + 1 + index - postStart, postorder, postStart, index);
        root->right = helper(preorder, preStart + 1 + index - postStart + 1, preEnd, postorder, index + 1, postEnd - 1);

        return root;
    }

    // 先：root、left、right
    // 中：left、right、root
};
// @lc code=end

