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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, 0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode* helper(int pStart, int iStart, int iEnd, vector<int>& preorder,
                     vector<int>& inorder) {
        // 1、递归终止条件
        if (pStart > preorder.size() - 1 || iStart > iEnd) return nullptr;

        // 2、处理当前层逻辑
        // 2.1 创建新节点
        TreeNode* root = new TreeNode(preorder[pStart]);
        // 2.2 从中序数组中获取根节点索引
        int iIndex = -1;
        for (int i = iStart; i <= iEnd; ++i) {
            if (inorder[i] == preorder[pStart]) iIndex = i;
        }

        // 下探到下一层
        root->left = helper(pStart + 1, iStart, iIndex - 1, preorder, inorder);
        root->right = helper(pStart + iIndex - iStart + 1, iIndex + 1, iEnd,
                             preorder, inorder);

        return root;
    }
};
// @lc code=end
