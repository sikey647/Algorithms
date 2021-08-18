/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        queue<TreeNode*> visited;
        visited.push(root);

        while(!visited.empty()) {
            int size = visited.size();
            vector<int> sub;
            for (int i = 0; i < size; i++) {
                TreeNode* node = visited.front();
                visited.pop();
                sub.push_back(node->val);
                if (node->left) {
                    visited.push(node->left);
                }
                if (node->right) {
                    visited.push(node->right);
                }
            }
            if (sub.size() != 0) {
                res.push_back(sub);
            }
        }

        return res;
    }
};
// @lc code=end

