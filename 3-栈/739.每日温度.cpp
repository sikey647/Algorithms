/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> iStack;
        vector<int> res(T.size(), 0);

        for (int i = 0; i < T.size(); ++i) {
            while (!iStack.empty() && T[i] > T[iStack.top()]) {
                res[iStack.top()] = i - iStack.top();
                iStack.pop();
            }
            iStack.push(i);
        }

        return res;
    }
};
// @lc code=end
