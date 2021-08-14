/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        // 确定根结点
        TreeNode* root = new TreeNode(preorder[preStart]);

        // 查找分结点
        int index = inStart;
        while (inorder[index] != preorder[preStart]) {
            index++;
        }

        // 前序：左子树：[preStart + 1, preStart + index - inStart]，右子树：[preStart + index - inStart + 1, preEnd]
        // 中序：左子树：[inStart, index - 1] 、右子树：[index + 1, inEnd]

        // 递归下一层
        root->left = helper(preorder, preStart + 1, preStart + index - inStart, inorder, inStart, index - 1);
        root->right = helper(preorder, preStart + index - inStart + 1, preEnd, inorder, index + 1, inEnd);

        return root;
    }

    // 前序：根、左子树、右子树
    // 中序：左子树、根、右子树
};
// @lc code=end

