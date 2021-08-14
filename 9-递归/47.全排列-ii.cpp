/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include <vector>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        // key: num, val: cnt
        map<int, int> nmap;
        for (auto& n : nums) {
            nmap[n]++;
        }
        helper(res, sub, nmap, nums);
        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& sub, map<int, int>& nmap, vector<int>& nums) {
        if (sub.size() == nums.size()) {
            res.push_back(sub);
            return;
        }

        for (auto& pair : nmap) {
            if (pair.second > 0) {
                sub.push_back(pair.first);
                pair.second--;
                helper(res, sub, nmap, nums);
                pair.second++;
                sub.pop_back();
            }
        }
    }
};
// @lc code=end

