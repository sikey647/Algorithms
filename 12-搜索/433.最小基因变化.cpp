/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (bank.size() == 0) return -1;

        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.count(end) == 0) return -1;

        int step = 0;
        queue<string> visited;
        visited.push(start);
        bankSet.erase(start);

        while (!visited.empty()) {
            int size = visited.size();
            for (int i = 0; i < size; ++i) {
                string str = visited.front();
                visited.pop();

                if (str == end) return step;

                change(str, visited, bankSet);
            }

            step++;
        }

        return -1;
    }

    void change(string str, queue<string>& visited,
                unordered_set<string>& bankSet) {
        for (int i = 0; i < str.size(); i++) {
            char t = str[i];
            for (char c : string("ACGT")) {
                str[i] = c;
                if (bankSet.count(str)) {
                    visited.push(str);
                    bankSet.erase(str);
                }
            }
            str[i] = t;
        }
    }
};
// @lc code=end
