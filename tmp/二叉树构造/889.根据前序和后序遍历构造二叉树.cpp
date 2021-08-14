/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

#include <vector>
using namespace std;

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return helper(preorder, 0, preorder.size() - 1, postorder, 0, preorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) {
            return root;
        }

        // 前序：根、左子树、右子树
        // 后序：左子树、右子树、根
        
        // 寻找左子树的根节点
        int index = 0;
        while (postorder[index] != preorder[preStart + 1]) {
            index++;
        }

        // 后续：左子树：[postStart, index]、右子树：[index + 1, postEnd - 1]
        // 前序：左子树：[preStart + 1, preStart + 1 + index - postStart]、右子树：[preStart + 1 + index - postStart + 1, preEnd]
        root->left = helper(preorder, preStart + 1, preStart + 1 + index - postStart, postorder, postStart, index);
        root->right = helper(preorder, preStart + 1 + index - postStart + 1, preEnd, postorder, index + 1, postEnd - 1);

        return root;
    }
};
// @lc code=end

