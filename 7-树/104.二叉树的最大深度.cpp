/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <queue>
using namespace std;

class Solution {
   public:
    // 方式一：深度优先搜索
    // int maxDepth(TreeNode *root) {
    //     if (!root) return 0;

    //     return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    // }

    // 方式二：广度优先搜索
    int maxDepth(TreeNode *root) {
        if (!root) return 0;

        int depth = 0;
        queue<TreeNode*> que;

        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            depth++;
        }

        return depth;
    }
};
// @lc code=end
