/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) {
            return res;
        }

        string str = "";
        unordered_map<char, string> digitMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        helper(res, str, 0, digits, digitMap);

        return res;
    }

    void helper(vector<string>& res, string& str, int level, string& digits, unordered_map<char, string>& digitMap) {
        if (digits.size() == level) {
            res.push_back(str);
            return;
        }

        char digit = digits[level];
        string& ss = digitMap[digit];

        for (auto& c : ss) {
            str.push_back(c);
            helper(res, str, level + 1, digits, digitMap);
            str.pop_back();
        }
    }
};

// @lc code=end

