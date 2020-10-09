/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        dfs(0, root, res);
        return res;
    }

    void dfs(int level, TreeNode *root, vector<int> &res) {
        if (!root) return;

        if (level == res.size()) {
            res.push_back(root->val);
        } else {
            if (root->val > res[level]) res[level] = root->val;
        }

        dfs(level + 1, root->left, res);
        dfs(level + 1, root->right, res);
    }
    // vector<int> largestValues(TreeNode *root) {
    //     vector<int> res;
    //     if (!root) return res;

    //     queue<TreeNode *> visited;
    //     visited.push(root);

    //     while (!visited.empty()) {
    //         int size = visited.size();

    //         int max = visited.front()->val;
    //         for (int i = 0; i < size; ++i) {
    //             TreeNode *node = visited.front();
    //             visited.pop();
    //             if (node->val > max) max = node->val;

    //             if (node->left) visited.push(node->left);

    //             if (node->right) visited.push(node->right);
    //         }

    //         res.push_back(max);
    //     }

    //     return res;
    // }
};
// @lc code=end
