/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        _generateParenthesis(0, 0, n, s, res);
        return res;
    }

    void _generateParenthesis(int left, int right, int n, string& s,
                              vector<string>& res) {
        // 递归终止条件
        if (left == n && right == n) {
            res.push_back(s);
            return;
        }

        if (left < n) {
            // 处理当前层逻辑
            s.push_back('(');

            // 下探到下一层
            _generateParenthesis(left + 1, right, n, s, res);

            // 清理当前层
            s.pop_back();
        }

        if (right < left) {
            // 处理当前层逻辑
            s.push_back(')');

            // 下探到下一层
            _generateParenthesis(left, right + 1, n, s, res);

            // 清理当前层
            s.pop_back();
        }
    }
};
// @lc code=end
