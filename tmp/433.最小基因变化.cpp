/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> haved(bank.begin(), bank.end());

        if (!haved.count(end)) {
            return -1;
        }

        int step = 0;
        queue<string> visited;
        visited.push(start);
        haved.erase(start);

        while (!visited.empty()) {
            int size = visited.size();
            for (int i = 0; i < size; i++) {
              string str = visited.front();
              visited.pop();
              if (str == end) {
                  return step;
              }
              change(str, visited, haved);
            }
            step++;
        }

        return -1;
    }

    void change(string str, queue<string>& visited, unordered_set<string>& haved) {
        for (int i = 0; i < str.size(); i++) {
            char t = str[i];
            for (char c : string("ACGT")) {
                str[i] = c;
                if (haved.count(str)) {
                    visited.push(str);
                    haved.erase(str);
                }
            }
            str[i] = t;
        }
    }
};
// @lc code=end

