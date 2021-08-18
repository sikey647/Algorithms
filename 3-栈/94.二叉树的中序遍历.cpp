/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

#include <vector>
#include <stack>
using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
*/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }

        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }

        return res;
    }
};
// @lc code=end

