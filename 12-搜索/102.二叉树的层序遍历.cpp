/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        dfs(0, root, res);

        return res;
    }

    void dfs(int level, TreeNode* root, vector<vector<int>>& res) {
        if (!root) return;

        if (level == res.size()) res.push_back(vector<int>{});
        res[level].push_back(root->val);

        dfs(level + 1, root->left, res);
        dfs(level + 1, root->right, res);
    }
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     if (!root) return res;

    //     queue<TreeNode*> visited;
    //     visited.push(root);

    //     while (!visited.empty()) {
    //         vector<int> sub;
    //         int size = visited.size();
    //         for (int i = 0; i < size; ++i) {
    //             TreeNode* node = visited.front();
    //             visited.pop();
    //             sub.push_back(node->val);
    //             if (node->left) visited.push(node->left);
    //             if (node->right) visited.push(node->right);
    //         }
    //         if (!sub.empty()) res.push_back(sub);
    //     }

    //     return res;
    // }
};
// @lc code=end
