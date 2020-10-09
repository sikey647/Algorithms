/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;
        unordered_map<char, string> letterMap = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        helper(0, "", letterMap, digits, res);
        return res;
    }

    void helper(int level, string s, unordered_map<char, string>& letterMap,
                string& digits, vector<string>& res) {
        // terminal
        if (level == digits.size()) {
            res.push_back(s);
            return;
        }

        // process
        string& str = letterMap[digits[level]];
        for (auto& c : str) {
            // drill down
            helper(level + 1, s + c, letterMap, digits, res);
        }

        // reverse status
    }
};
// @lc code=end
