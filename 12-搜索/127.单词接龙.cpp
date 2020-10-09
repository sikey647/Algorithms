/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        if (wordList.size() == 0) return 0;

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return 0;

        int len = 1;
        queue<string> visited;
        visited.push(beginWord);

        while (!visited.empty()) {
            int size = visited.size();
            for (int i = 0; i < size; ++i) {
                string str = visited.front();
                visited.pop();

                if (str == endWord) return len;

                change(str, visited, wordSet);
            }
            len++;
        }

        return 0;
    }

    void change(string str, queue<string>& visited,
                unordered_set<string>& wordSet) {
        for (int i = 0; i < str.size(); ++i) {
            char t = str[i];
            for (int j = 0; j < 26; ++j) {
                str[i] = 'a' + j;
                if (wordSet.count(str)) {
                    visited.push(str);
                    wordSet.erase(str);
                }
            }
            str[i] = t;
        }
    }
};
// @lc code=end
