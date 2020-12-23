/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// 思路：
//  使用栈
//  遍历字符串，字符为左括号，则入栈；
//  如果字符为右括号，则与栈顶元素比较，如果匹配则出栈，则继续下一个字符；
//  如果不匹配或栈为空，则说明为无效括号
//  当遍历完成后，如果栈为空，则说明为有效括号，如果非空，为无效括号

class Solution {
   public:
    bool isValid(string s) {
        stack<char> charStack;
        unordered_map<char, char> charMap = {
            {')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s) {
            if (charMap.find(c) != charMap.end()) {  // 左括号
                if (charStack.empty() || charMap[c] != charStack.top()) {
                    return false;
                } else {
                    charStack.pop();
                }
            } else {  // 右括号
                charStack.push(c);
            }
        }

        return charStack.empty();
    }
};
// @lc code=end
