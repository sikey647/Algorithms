/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        // 创建根节点（后序最后一个节点）
        TreeNode *root = new TreeNode(postorder[postEnd]);

        // 查找左子树/右子树边界
        int index = inStart;
        while (inorder[index] != postorder[postEnd]) {
            index++;
        }

        // 中序：左子树 [inStart, index - 1] , 右子树 [index + 1, inEnd]
        // 后序：左子树 [postStart, postStart + index - 1 - inStart] , 右子树 [postStart + index - 1 - inStart + 1, postEnd - 1]
        root->left = helper(inorder, inStart, index - 1, postorder, postStart, postStart + index - 1 - inStart);
        root->right = helper(inorder, index + 1, inEnd, postorder, postStart + index - 1 - inStart + 1, postEnd - 1);

        return root;
    }

    // 后序：左子树、右子树、根节点
    // 中序：左子树、根节点、右子树
};
// @lc code=end

