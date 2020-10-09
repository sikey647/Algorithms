/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        stack<char> charStack;
        unordered_map<char, char> charMap{{')', '('}, {'}', '{'}, {']', '['}};

        for (auto c : s) {
            if (charMap.find(c) != charMap.end()) {
                if (charStack.empty() || charMap[c] != charStack.top()) {
                    return false;
                } else {
                    charStack.pop();
                }
            } else {
                charStack.push(c);
            }
        }

        if (charStack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end
