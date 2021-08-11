/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sub;

        helper(res, sub, 0, 0, n);

        return res;
    }

    void helper(vector<string>& res, string& sub, int left, int right, int n) {
        // 递归终止条件
        if (left == n && right == n) {
            res.push_back(sub);
        }

        // 处理当前层逻辑
        if(left < n) {
            sub.push_back('(');
            helper(res, sub, left + 1, right, n);
            sub.pop_back();
        }

        if (right < left) {
            sub.push_back(')');
            helper(res, sub, left, right + 1, n);
            sub.pop_back();
        }
    }
};
// @lc code=end

