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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        // 终止条件
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        // 创建根结点
        TreeNode* root = new TreeNode(postorder[postEnd]);

        // 寻找分结点
        int index = inStart;
        while (inorder[index] != postorder[postEnd]) {
            index++;
        }
        // 中序：左：[inStart, index - 1]、右：[index + 1, inEnd]
        // 后序：左：[postStart, postStart + index - inStart]、右：[postStart + index - inStart + 1， postEnd - 1]
        root->left = helper(inorder, inStart, index - 1, postorder, postStart, postStart + index - 1 - inStart);
        root->right = helper(inorder, index + 1, inEnd, postorder, postStart + index - 1 - inStart + 1, postEnd - 1);

        return root;
    }

    // 中序：左子树、根、右子树
    // 后序：左子树、右子树、根
};
// @lc code=end

