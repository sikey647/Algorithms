/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int> charMap;
        for (int start = 0, end = 0; end < s.size(); ++end) {
            if (charMap.find(s[end]) != charMap.end()) {
                start = max(start, charMap[s[end]] + 1);
            }
            charMap[s[end]] = end;
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};
// @lc code=end
