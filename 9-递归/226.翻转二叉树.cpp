/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
#include <algorithm>
#include <stack>
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
    // 方式一：递归
    // TreeNode* invertTree(TreeNode* root) {
    //     if (root != nullptr) {
    //         std::swap(root->left, root->right);
    //         invertTree(root->left);
    //         invertTree(root->right);
    //     }

    //     return root;
    // }

    // 迭代
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;

        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if (node) {
                std::swap(node->left, node->right);
                st.push(node->right);
                st.push(node->left);
            }
        }

        return root;
    }
};
// @lc code=end

