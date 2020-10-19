## 数组

#### [1. 两数之和](https://leetcode-cn.com/problems/two-sum/) (快手)

```c++
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> uMap;
    for (int i = 0; i < nums.size(); ++i) {
        int diff = target - nums[i];
        if (uMap.find(diff) != uMap.end())
            return vector<int>{uMap[diff], i};
        uMap[nums[i]] = i;
    }
    return vector<int>{};
}
```

#### [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/) (快手)

#### [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) (快手)

```c++
int maxProfit(vector<int>& prices) {
    if (prices.size() == 0)
        return 0;
    int maxPrice = 0;
    int minPrice = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        minPrice = min(minPrice, prices[i]);
        maxPrice = max(maxPrice, prices[i] - minPrice);
    }
    return maxPrice;
}
```

#### [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/) (快手)

```c++
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i < 0 || nums1[i] < nums2[j]) {
            nums1[k--] = nums2[j--];
        } else {
            nums1[k--] = nums1[i--];
        }
    }
}
```

#### [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) (快手)

```c++
int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int res = nums[0], sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (sum > 0) {
            sum += nums[i];
        } else {
            sum = nums[i];
        }
        res = max(res, sum);
    }
    return res;
}
```

#### [11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/) (快手)

```c++
int maxArea(vector<int>& height) {
    int maxRes = 0;
    for (int i = 0, j = height.size() - 1; i < j;) {
        int high = height[i] > height[j] ? height[j--] : height[i++];
        maxRes = max(maxRes, (j - i + 1) * high);
    }
    return maxRes;
}
```

#### [64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/) (快手)

```c++
int minPathSum(vector<vector<int>>& grid) {
    // 状态定义：dp[i][j]:走到grid[i][j]的最小路径和
    // 转移方程：
    //  1). 不是矩阵边界: i != 0 && j != 0: dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
    //  2). 左边是矩阵边界: i == 0 && j != 0: dp[i][j] = dp[i][j-1] + grid[i][j]
    //  3). 上边是矩阵边界: i != 0 && j == 0: dp[i][j] = dp[i-1][j] + grid[i][j]
    //  4). 左边和上边都是矩阵边界: i == 0 && j == 0: dp[i][j] = grid[i][j]
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else if (i != 0 && j == 0) {
                dp[i][j] = dp[i-1][j] + grid[i][j];
            } else if (i == 0 && j != 0) {
                dp[i][j] = dp[i][j-1] + grid[i][j];
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
    }
    return dp[m-1][n-1];
}
```

```c++
int minPathSum(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i != 0 && j == 0) {
                grid[i][j] += grid[i-1][j];
            } else if (i == 0 && j != 0) {
                grid[i][j] += grid[i][j-1];
            } else {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
    }
    return grid[grid.size()-1][grid[0].size()-1];
}
```

#### [665. 非递减数列](https://leetcode-cn.com/problems/non-decreasing-array/) (快手)

```c++
bool checkPossibility(vector<int>& nums) {
        // case1: 10, 30, 20, 50
        // case2: 10, 30, 5, 50
        int cnt = 0;
        for (int i = 1; i < nums.size() && cnt <= 1; ++i) {
            if (nums[i - 1] > nums[i]) {
                cnt++;
                if (i - 2 < 0 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return cnt <= 1;
    }
```

#### [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/) (快手)

```c++
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> mergeRes;
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    });

    for (auto &interval : intervals) {
        if (mergeRes.empty() || mergeRes.back()[1] < interval[0]) {
            mergeRes.push_back(interval);
        } else {
            mergeRes.back()[1] = max(mergeRes.back()[1], interval[1]);
        }
    }
    return mergeRes;
}
```

#### [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) (快手)

#### [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/) (快手)

```c++
int subarraySum(vector<int>& nums, int k) {
    // 前缀和 + hash记忆
    unordered_map<int, int> uMap;
    uMap[0] = 1;
    int resCnt = 0, pre = 0;
    for (auto &num : nums) {
        pre += num;
        if (uMap.find(pre - k) != uMap.end())
            resCnt += uMap[pre - k];
        uMap[pre]++;
    }
    return resCnt;
}
```

#### [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/) (快手)

#### [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/) (快手)

```c++
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    if (nums.size() == 0) 
        return res;

    int i = 0, j = nums.size() - 1;

    while (i < j) {
        int mid = (i + j) / 2;
        if (nums[mid] < target) {
            i = mid + 1;
        } else {
            j = mid;
        }
    }
    if (nums[i] == target) {
        res[0] = i;
    } else {
        return res;
    }

    j = nums.size() - 1;
    while (i < j) {
        int mid = (i + j) / 2 + 1;
        if (nums[mid] > target) {
            j = mid - 1;
        } else {
            i = mid;
        }
    }

    res[1] = j;
    return res; 
}
```

#### [78. 子集](https://leetcode-cn.com/problems/subsets/) (快手)

#### [15. 三数之和](https://leetcode-cn.com/problems/3sum/) (快手)

#### [152. 乘积最大子数组](https://leetcode-cn.com/problems/maximum-product-subarray/) (快手)

#### [面试题 10.01. 合并排序的数组](https://leetcode-cn.com/problems/sorted-merge-lcci/) (快手)

#### [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) (快手)

#### [724. 寻找数组的中心索引](https://leetcode-cn.com/problems/find-pivot-index/) (快手)

#### [123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/) (快手)

#### [59. 螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/) (快手)

#### [162. 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/) (快手)

#### [41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/) (快手)

#### [54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/) (快手)

#### [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/) (快手)

#### [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/) (快手)

#### [169. 多数元素](https://leetcode-cn.com/problems/majority-element/) (快手)

#### [670. 最大交换](https://leetcode-cn.com/problems/maximum-swap/) (快手)

#### [63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/) (快手)



## 链表

#### [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/) (快手)

```c++
// 迭代
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *pre = nullptr, *cur = head, *tmp = nullptr;
    while (cur != nullptr) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}
```

```c++
// 递归
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}
```

#### [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/) (快手)

```c++
// 递归
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
```

```c++
// 迭代
ListNode *l = new ListNode(0), *head = l;
while (l1 && l2) {
    //ListNode*& node = l1->val < l2->val ? l1 : l2;
    //l->next = node;
    //node = node->next;
    if (l1->val < l2->val) {
        l->next = l1;
        l1 = l1->next;
    } else {
        l->next = l2;
        l2 = l2->next;
    }
    l = l->next;
}
l->next = l1 ? l1 : l2;
return head->next;
```

#### [148. 排序链表](https://leetcode-cn.com/problems/sort-list/) (快手)

#### [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/) (快手)

```c++
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *l = new ListNode(0), *head = l;
    int sum = 0;
    while (l1 || l2) {
        sum /= 10;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        l->next = new ListNode(sum % 10);
        l = l->next;
    }
    if (sum / 10 == 1) l->next = new ListNode(1);
    return head->next;
}
```

#### [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) (快手)

```c++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    ListNode *l1 = headA, *l2 = headB;
    while (l1 != l2) {
        l1 = l1 == nullptr ? headB : l1->next;
        l2 = l2 == nullptr ? headA : l2->next;
    }
    return l1;
}
```

#### [23. 合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/) (快手)

#### [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/) (快手)

#### [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/) (快手)

#### [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/) (快手)

#### [138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/) (快手)

#### [面试题22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/) (快手)

#### [面试题 02.05. 链表求和](https://leetcode-cn.com/problems/sum-lists-lcci/) (快手)

#### [61. 旋转链表](https://leetcode-cn.com/problems/rotate-list/) (快手)

```c++
ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *l1 = dummy, *l2 = dummy;
    int len = 0;

    while (l1->next) {
        len++;
        l1 = l1->next;
    }

    for (int i = 0; i < len - (k % len); i++) {
        l2 = l2->next;
    }

    l1->next = dummy->next;
    dummy->next = l2->next;
    l2->next = nullptr;

    return dummy->next;
}
```

#### [面试题 02.08. 环路检测](https://leetcode-cn.com/problems/linked-list-cycle-lcci/) (快手)



## 双指针

#### [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) (快手)

#### [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/) (快手)

#### [11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/) (快手)

#### [15. 三数之和](https://leetcode-cn.com/problems/3sum/) (快手)

#### [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/) (快手)

#### [面试题 10.01. 合并排序的数组](https://leetcode-cn.com/problems/sorted-merge-lcci/) (快手)

#### [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/) (快手)

#### [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/) (快手)

#### [面试题22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/) (快手)

#### [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/) (快手)

#### [61. 旋转链表](https://leetcode-cn.com/problems/rotate-list/) (快手)

#### [26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/) (快手)

```c++
int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();

    int index = 0;
    for (int j = 1; j < nums.size(); ++j) {
        if (nums[index] != nums[j]) {
            nums[++index] = nums[j];
        }
    }
    return index + 1;
}
```

#### [30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/) (快手)



## 栈

#### [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/) (快手)

```c++
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
```

#### [144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/) (快手)

```c++
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> tnStack;
    
    if (!root) return res;

    tnStack.push(root);
    while (!tnStack.empty()) {
        TreeNode *node = tnStack.top();
        res.push_back(node->val);
        tnStack.pop();

        if (node->right) tnStack.push(node->right);

        if (node->left) tnStack.push(node->left);
    }

    return res;
}
```

#### [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/) (快手)

#### [739. 每日温度](https://leetcode-cn.com/problems/daily-temperatures/) (快手)

```c++
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
```

#### [1047. 删除字符串中的所有相邻重复项](https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/) (快手)

#### [145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/) (快手)

```c++
// 标记法
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<pair<bool, TreeNode *>> tnStack;
    TreeNode *node = root;

    while (!tnStack.empty() || node) {
        while (node) {
            tnStack.push(make_pair(false, node));
            node = node->left;
        }

        node = tnStack.top().second;

        if (tnStack.top().first) {
            res.push_back(node->val);
            tnStack.pop();
            node = nullptr;
        } else {
            tnStack.top().first = true;
            node = node->right;
        }
    }

    return res;
}
```

```c++
vector<int> postorderTraversal(TreeNode *root) {
    // 转换法
    // 先序遍历：根、左、右
    // 后序遍历：左、右、根
    // 1). 根、右、左   2). 反转：左、右、根
    vector<int> res;
    stack<TreeNode *> tnStack;
    if (!root) return res;

    TreeNode *node = root;
    tnStack.push(node);
    while (!tnStack.empty()) {
        node = tnStack.top();
        tnStack.pop();
        res.push_back(node->val);

        if (node->left) tnStack.push(node->left);
        if (node->right) tnStack.push(node->right);
    }

    reverse(res.begin(), res.end());

    return res;
}
```



## 滑动窗口

#### [239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/) (快手)



## 哈希表

#### [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)(快手)

#### [202. 快乐数](https://leetcode-cn.com/problems/happy-number/) (快手)

#### [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) (快手)

```c++
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
```

#### [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/) (快手)

#### [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/) (快手)

```c++
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> numMap = {{0, 1}};
    int resCnt = 0, preSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        preSum += nums[i];
        if (numMap.find(preSum - k) != numMap.end())
            resCnt += numMap[preSum - k];
        numMap[preSum]++;
    }

    return resCnt;
}
```

#### [149. 直线上最多的点数](https://leetcode-cn.com/problems/max-points-on-a-line/) (快手)

#### [36. 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/) (快手)

```c++
// set
bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> rowSet[9], colSet[9], blkSet[9];
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == '.') continue;
            int blkIndex = (i / 3) * 3 + j / 3;
            if (rowSet[i].find(board[i][j]) != rowSet[i].end() ||
                colSet[j].find(board[i][j]) != colSet[j].end() ||
                blkSet[blkIndex].find(board[i][j]) !=
                blkSet[blkIndex].end())
                return false;
            rowSet[i].insert(board[i][j]);
            colSet[j].insert(board[i][j]);
            blkSet[blkIndex].insert(board[i][j]);
        }
    }
    return true;
}
```

```c++
bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][9] = {0}, col[9][9] = {0}, blk[9][9] = {0};
    //vector<vector<int>> row(9, vector<int>(9, 0)), col(9, vector<int>(9, 0)), blk(9, vector<int>(9, 0));
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '0' - 1;
                int k = (i / 3) * 3 + j / 3;
                if (row[i][num] || col[j][num] || blk[k][num]) return false;
                row[i][num] = col[j][num] = blk[k][num] = 1;
            }
        }
    }

    return true;
}
```

#### [204. 计数质数](https://leetcode-cn.com/problems/count-primes/) (快手)

#### [409. 最长回文串](https://leetcode-cn.com/problems/longest-palindrome/) (快手)

#### [138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/) (快手)

#### [26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/) (快手)

#### [739. 每日温度](https://leetcode-cn.com/problems/daily-temperatures/) (快手)

#### [30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/) (快手)

#### [面试题50. 第一个只出现一次的字符](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/) (快手)



## 记忆化

#### [329. 矩阵中的最长递增路径](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/) (快手)



## 树

#### [226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)

```c++
// 递归
TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;

    TreeNode* left = invertTree(root->right);
    TreeNode* right = invertTree(root->left);

    root->left = left;
    root->right = right;
    
    //TreeNode* tmp = root->left;
    //root->left = root->right;
    //root->right = tmp;

    //invertTree(root->left);
    //invertTree(root->right);

    return root;
}

// 迭代

```

#### [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

```c++
// 递归
int maxDepth(TreeNode *root) {
    if (!root) return 0;

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// 迭代
```

#### [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

```c++
// 递归
int minDepth(TreeNode* root) {
    if (!root) return 0;
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    return (!root->left || !root->right) ? leftDepth + rightDepth + 1
        : min(leftDepth, rightDepth) + 1;
}

// 迭代

```

#### [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

```c++
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helper(0, 0, inorder.size() - 1, preorder, inorder);
}

TreeNode* helper(int pStart, int iStart, int iEnd, vector<int>& preorder,
                 vector<int>& inorder) {
    // 1、递归终止条件
    if (pStart > preorder.size() - 1 || iStart > iEnd) return nullptr;

    // 2、处理当前层逻辑
    // 2.1 创建新节点
    TreeNode* root = new TreeNode(preorder[pStart]);
    // 2.2 从中序数组中获取根节点索引
    int iIndex = -1;
    for (int i = iStart; i <= iEnd; ++i) {
        if (inorder[i] == preorder[pStart]) iIndex = i;
    }

    // 下探到下一层
    root->left = helper(pStart + 1, iStart, iIndex - 1, preorder, inorder);
    root->right = helper(pStart + iIndex - iStart + 1, iIndex + 1, iEnd,
                         preorder, inorder);

    return root;
}
```

#### [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/) (快手)

#### [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/) (快手)

```c++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q)
        return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
        return root;

    return left ? left : right; 
}
```

#### [543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/) (快手)

```c++
int diameterOfBinaryTree(TreeNode* root) {
    int nodes = 1;
    depth(root, nodes);
    return nodes - 1;
}

int depth(TreeNode* root, int& nodes) {
    if (!root)
        return 0;
    int leftDepth = depth(root->left, nodes);
    int rightDepth = depth(root->right, nodes);
    nodes = max(nodes, leftDepth + rightDepth + 1);
    return max(leftDepth, rightDepth) + 1;
}
```

#### [450. 删除二叉搜索树中的节点](https://leetcode-cn.com/problems/delete-node-in-a-bst/) (快手)

```c++
int findLeftMax(TreeNode* root) {
    while (root->right)
        root = root->right;
    return root->val;
}

int findRightMin(TreeNode* root) {
    while (root->left)
        root = root->left;
    return root->val;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)
        return root;

    if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else {
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
        } else if (root->right) {
            int target = findRightMin(root->right);
            root->val = target;
            root->right = deleteNode(root->right, target);
        } else if (root->left) {
            int target = findLeftMax(root->left);
            root->val = target;
            root->left = deleteNode(root->left, target);
        }
    }

    return root;
}
```

#### [257. 二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/) (快手)

#### [919. 完全二叉树插入器](https://leetcode-cn.com/problems/complete-binary-tree-inserter/) (快手)

#### [572. 另一个树的子树](https://leetcode-cn.com/problems/subtree-of-another-tree/) (快手)

#### [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) (快手)

#### [590. N叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/) (快手)

#### [112. 路径总和](https://leetcode-cn.com/problems/path-sum/) (快手)

#### [144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/) (快手)

#### [100. 相同的树](https://leetcode-cn.com/problems/same-tree/) (快手)

#### [235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) (快手)

#### [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/) (快手)

#### [114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/) (快手)

```c++
void flatten(TreeNode* root) {
    while (root) {
        if (root->left) {
            TreeNode* pre = root->left;
            while (pre->right)
                pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
    }
}
```

#### [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/) (快手)

```c++
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    _pathSum(root, sum, path, res);
    return res;
}

void _pathSum(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res) {
    if (!root)
        return;

    path.push_back(root->val);
    if (!root->left && !root->right && sum - root->val == 0)
        res.push_back(path);

    _pathSum(root->left, sum - root->val, path, res);
    _pathSum(root->right, sum - root->val, path, res);

    path.pop_back();
}
```

#### [993. 二叉树的堂兄弟节点](https://leetcode-cn.com/problems/cousins-in-binary-tree/) (快手)

#### [145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/) (快手)

#### [1339. 分裂二叉树的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-splitted-binary-tree/) (快手)



## 堆

#### [1046. 最后一块石头的重量](https://leetcode-cn.com/problems/last-stone-weight/) (快手)

#### [239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/) (快手)

#### [155. 最小栈](https://leetcode-cn.com/problems/min-stack/) (快手)

#### [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/) (快手)

#### [23. 合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/) (快手)

#### [378. 有序矩阵中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/) (快手)

#### [407. 接雨水 II](https://leetcode-cn.com/problems/trapping-rain-water-ii/) (快手)



## 分治

#### [50. Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)

```c++
double myPow(double x, long n) {
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    return _myPow(x, n);
}

double _myPow(double x, long n) {
    if (n == 0) return 1;
    double half = myPow(x, n / 2);

    return (n % 2 == 0) ? half * half : half * half * x;
}
```

#### [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/) (快手)

#### [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) (快手)

#### [面试题25. 合并两个排序的链表](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/) (快手)

#### [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/) (快手)

#### [23. 合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/) (快手)

#### [240. 搜索二维矩阵 II](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/) (快手)

#### [169. 多数元素](https://leetcode-cn.com/problems/majority-element/) (快手)



## 回溯

#### [17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/) (快手)

```c++
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
```

#### [46. 全排列](https://leetcode-cn.com/problems/permutations/) (快手)

```c++
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sub;
    unordered_map<int, int> numMap;
    for (auto& num : nums) {
        numMap[num]++;
    }
    helper(0, nums.size(), numMap, sub, res);
    return res;
}

void helper(int level, int size, unordered_map<int, int>& numMap,
            vector<int>& sub, vector<vector<int>>& res) {
    // 1、递归终止条件
    if (level == size) {
        res.push_back(sub);
        return;
    }

    for (auto& num : numMap) {
        if (num.second > 0) {
            // 2、处理当前层逻辑
            sub.push_back(num.first);
            num.second--;
            // 3、递归到下一层
            helper(level + 1, size, numMap, sub, res);
            // 4、恢复当前层状态
            sub.pop_back();
            num.second++;
        }
    }
}
```



#### [78. 子集](https://leetcode-cn.com/problems/subsets/) (快手)

```c++
// 递归
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> v;
    helper(0, nums, v, res);

    return res;
}

void helper(int level, vector<int>& nums, vector<int>& v,
            vector<vector<int>>& res) {
    // 递归终止条件
    if (level == nums.size()) {
        res.push_back(v);
        return;
    }

    // 下探到下一层
    helper(level + 1, nums, v, res);

    // 处理当前层
    v.push_back(nums[level]);
    // 下探到下一层
    helper(level + 1, nums, v, res);
    // 恢复当前层状态
    v.pop_back();
}

// 迭代
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back(vector<int>{});

    for (auto& num : nums) {
        vector<vector<int>> sub = res;
        for (auto& v : sub) {
            v.push_back(num);
            res.push_back(v);
        }
    }

    return res;
}
```

#### [784. 字母大小写全排列](https://leetcode-cn.com/problems/letter-case-permutation/) (快手)

#### [77. 组合](https://leetcode-cn.com/problems/combinations/) (快手)

``` c++
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> sub;
    helper(0, k, 1, n, sub, res);
    return res;
}

void helper(int level, int k, int start, int n, vector<int>& sub,
            vector<vector<int>>& res) {
    if (level == k) {
        res.push_back(sub);
        return;
    }

    for (int i = start; i <= n; i++) {
        // 处理当前层逻辑
        sub.push_back(i);
        // 递归到下一层
        helper(level + 1, k, i + 1, n, sub, res);
        // 恢复当前层状态
        sub.pop_back();
    }
}
```

#### [10. 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/) (快手)

#### [51. N 皇后](https://leetcode-cn.com/problems/n-queens/)

```c++
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> sub;
    unordered_set<int> colSet, sumSet, difSet;

    helper(0, n, colSet, sumSet, difSet, sub, res);

    return res;
}

void helper(int row, int n, unordered_set<int>& colSet,
            unordered_set<int>& sumSet, unordered_set<int>& difSet,
            vector<string>& sub, vector<vector<string>>& res) {
    // 递归终止条件
    if (row == n) {
        res.push_back(sub);
        return;
    }

    string str(n, '.');
    for (int col = 0; col < n; col++) {
        if (colSet.find(col) == colSet.end() &&
            sumSet.find(row + col) == sumSet.end() &&
            difSet.find(row - col) == difSet.end()) {
            // 处理当前层逻辑
            str[col] = 'Q';
            colSet.insert(col);
            sumSet.insert(row + col);
            difSet.insert(row - col);
            sub.push_back(str);
            // 递归下一层
            helper(row + 1, n, colSet, sumSet, difSet, sub, res);
            // 恢复当前层
            sub.pop_back();
            colSet.erase(col);
            sumSet.erase(row + col);
            difSet.erase(row - col);
            str[col] = '.';
        }
    }
}
```



## 深度优先搜索

#### [1254. 统计封闭岛屿的数目](https://leetcode-cn.com/problems/number-of-closed-islands/) (快手)

#### [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/) (快手)

#### [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) (快手)

#### [257. 二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/) (快手)

#### [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) (快手)

#### [491. 递增子序列](https://leetcode-cn.com/problems/increasing-subsequences/) (快手)

#### [329. 矩阵中的最长递增路径](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/) (快手)

#### [112. 路径总和](https://leetcode-cn.com/problems/path-sum/) (快手)

#### [100. 相同的树](https://leetcode-cn.com/problems/same-tree/) (快手)

#### [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/) (快手)

#### [114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/) (快手)

#### [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/) (快手)

#### [546. 移除盒子](https://leetcode-cn.com/problems/remove-boxes/) (快手)

#### [1020. 飞地的数量](https://leetcode-cn.com/problems/number-of-enclaves/) (快手)



## 广度优先搜索

#### [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) (快手)

```c++
int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) return 0;

    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == '1') {
                dfs(i, j, grid);
                count++;
            }
        }
    }

    return count;
}

void dfs(int i, int j, vector<vector<char>>& grid) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] == '0')
        return;

    grid[i][j] = '0';
    dfs(i - 1, j, grid);
    dfs(i + 1, j, grid);
    dfs(i, j - 1, grid);
    dfs(i, j + 1, grid);
}
```

#### [407. 接雨水 II](https://leetcode-cn.com/problems/trapping-rain-water-ii/) (快手)

#### [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/) (快手)

#### [993. 二叉树的堂兄弟节点](https://leetcode-cn.com/problems/cousins-in-binary-tree/) (快手)

#### [279. 完全平方数](https://leetcode-cn.com/problems/perfect-squares/) (快手)

#### [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

```c++
// BFS
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<TreeNode*> visited;
    visited.push(root);

    while (!visited.empty()) {
        vector<int> sub;
        int size = visited.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = visited.front();
            visited.pop();
            sub.push_back(node->val);                
            if (node->left) visited.push(node->left);
            if (node->right) visited.push(node->right);
        }
        if (!sub.empty()) res.push_back(sub);
    }

    return res;
}

// DFS
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    
    dfs(0, root, res);
    return res;
}

void dfs(int level, TreeNode* root, vector<vector<int>>& res) {
    if (!root) return;

    if (level == res.size()) res.push_back(vector<int>{});
    res[level].push_back(root->val);

    dfs(level + 1, root->left, res);
    dfs(level + 1, root->right, res);
}
```

#### [515. 在每个树行中找最大值](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/)

```c++
// bfs
vector<int> largestValues(TreeNode *root) {
    vector<int> res;
    if (!root) return res;

    queue<TreeNode *> visited;
    visited.push(root);

    while (!visited.empty()) {
        int size = visited.size();

        int max = visited.front()->val;
        for (int i = 0; i < size; ++i) {
            TreeNode *node = visited.front();
            visited.pop();
            if (node->val > max) max = node->val;

            if (node->left) visited.push(node->left);

            if (node->right) visited.push(node->right);
        }

        res.push_back(max);
    }

    return res;
}

// dfs
vector<int> largestValues(TreeNode *root) {
    vector<int> res;
    if (!root) return res;
    dfs(0, root, res);
    return res;
}

void dfs(int level, TreeNode *root, vector<int> &res) {
    if (!root) return;

    if (level == res.size()) {
        res.push_back(root->val);
    } else {
        if (root->val > res[level]) res[level] = root->val;
    }

    dfs(level + 1, root->left, res);
    dfs(level + 1, root->right, res);
}
```

#### [433. 最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)

```c++
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
```

#### [127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/)

```c++
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
```

#### [529. 扫雷游戏](https://leetcode-cn.com/problems/minesweeper/)

```c++
vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                 	vector<int>& click) {
    if (board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
    }

    vector<pair<int, int>> pos = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                  {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    dfs(click[0], click[1], board, pos);

    return board;
}

void dfs(int x, int y, vector<vector<char>>& board,
         vector<pair<int, int>>& pos) {
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return;

    int count = 0;
    if (board[x][y] == 'E') {
        for (auto& p : pos) {
            if (x + p.first >= 0 && y + p.second >= 0 &&
                x + p.first < board.size() &&
                y + p.second < board[0].size() &&
                board[x + p.first][y + p.second] == 'M')
                count++;
        }

        if (count > 0) {
            board[x][y] = '0' + count;
        } else {
            board[x][y] = 'B';
            for (auto& p : pos) {
                dfs(x + p.first, y + p.second, board, pos);
            }
        }
    }
}
```





## 贪心算法

#### [1046. 最后一块石头的重量](https://leetcode-cn.com/problems/last-stone-weight/) (快手)

#### [134. 加油站](https://leetcode-cn.com/problems/gas-station/) (快手)

#### [44. 通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/) (快手)



## 二分查找

#### [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/) (快手)

#### [300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/) (快手)

#### [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/) (快手)

#### [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/) (快手)

#### [240. 搜索二维矩阵 II](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/) (快手)

#### [69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/) (快手)

#### [378. 有序矩阵中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/) (快手)

#### [668. 乘法表中第k小的数](https://leetcode-cn.com/problems/kth-smallest-number-in-multiplication-table/) (快手)

#### [162. 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/) (快手)

#### [29. 两数相除](https://leetcode-cn.com/problems/divide-two-integers/) (快手)

#### [50. Pow(x, n)](https://leetcode-cn.com/problems/powx-n/) (快手)



## 动态规划

#### [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/) (快手)

```c++
// 重复性：单词word1(0, i) 与 单词word2(0, j) 最少操作数 = 
//        1). word1[i]与word2[j]相等，单词word1(0, i-1) 与 单词word2(0, j-1) 最少操作数
//        2). word1[i]与word2[j]不相等，单词word1(0, i-1) 与 单词word2(0, j-1) 最少操作数 + 1
//                                    单词word1(0, i) 与 单词word2(0, j-1) 最少操作数 + 1
//                                    单词word1(0, i-1) 与 单词word2(0, j) 最少操作数 + 1
//                                    以上取较小者。
// 状态数组：单词word1(0, i) 与 单词word2(0, j) 最少操作数。
// DP方程：word1[i] == word2[j]: dp[i][j] = dp[i-1][j-1]
//        word1[i] != word2[j]: dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i][j-1])
int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

    for (int i = 1; i <= word1.size(); i++) {
        dp[i][0] = dp[i - 1][0] + 1; 
    }

    for (int j = 1; j <= word2.size(); j++) {
        dp[0][j] = dp[0][j - 1] + 1; 
    }

    for (int i = 1; i <= word1.size(); i++) {
        for (int j = 1; j <= word2.size(); j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }
    }

    return dp[word1.size()][word2.size()];
}
```

#### [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/) (快手)

#### [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) (快手)

#### [300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/) (快手)

```c++
// 状态数组：f[i]为无序的整数数组从0到i个元素中的最长上升子序列的长度
// DP方程： f[i] = max(f[j] + 1), j = {0, ..., i};
int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;

    vector<int> dp(nums.size(), 1);
    int maxLen = 1;

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                maxLen = max(maxLen, dp[i]);
            }
        }
    }

    return maxLen;
}
```

#### [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) 【简单】 (快手)

```c++
// 第i个元素被包含，最大子序列和为多少。 分为第i-1个元素是否被包含两种情况。
// 重复性（分治）：整数数组nums从0到第i个元素中连续子数组最大和 = 
//				整数数组nums从0到第i-1个元素中连续子数组最大和 与 
//              0值 中的较大者 + nums[i]
//				即：max_sum[i] = max(max_sum[i-1], 0) + a[i]
// 状态数组：f[i] 为整数数组nums从0到第i个元素(必须包含第i个元素)中连续子数组最大和
// DP方程：f[i] = max(f[i-1], 0) + a[i]
int maxSubArray(vector<int>& nums) {
    vector<int> dp = nums;
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i-1], 0) + nums[i];
        maxSum = max(dp[i], maxSum);
    }

    return maxSum;
}
```

#### [64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/) (快手)

```c++
// 方法一：自顶向下（超时）
// 重复性：坐标(i,j)的最小路径和 = 坐标(i+1,j)的最小路径和 与
//          坐标(i,j+1)的最小路径和 的较小者 + 当前距离值
int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0) return 0;
    return helper(0, 0, grid);
}

int helper(int i, int j, vector<vector<int>>& grid) {
    if (i == grid.size() - 1 && j == grid[0].size() - 1) {
        return grid[i][j];
    } else if (i == grid.size() - 1) {
        return helper(i, j + 1, grid) + grid[i][j];
    } else if (j == grid[0].size() - 1) {
        return helper(i + 1, j, grid) + grid[i][j];
    } else {
        return min(helper(i + 1, j, grid), helper(i, j + 1, grid)) +
            grid[i][j];
    }
}

// 方法二：自顶向下 + 记忆化
int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0) return 0;
    vector<vector<int>> v(grid.size(), vector<int>(grid[0].size(), 0));
    return helper(0, 0, grid, v);
}

int helper(int i, int j, vector<vector<int>>& grid,
           vector<vector<int>>& v) {
    if (v[i][j] == 0) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            v[i][j] = grid[i][j];
        } else if (i == grid.size() - 1) {
            v[i][j] = helper(i, j + 1, grid, v) + grid[i][j];
        } else if (j == grid[0].size() - 1) {
            v[i][j] = helper(i + 1, j, grid, v) + grid[i][j];
        } else {
            v[i][j] =
                min(helper(i + 1, j, grid, v), helper(i, j + 1, grid, v)) +
                grid[i][j];
        }
    }
    return v[i][j];
}

// 方法三：自底向上
// 重复性：坐标(i,j)的最小路径和 = 坐标(i+1,j)的最小路径和 与
//        坐标(i,j+1)的最小路径和 的较小者 + 当前距离值
// 状态定义：dp[i][j]为坐标(i,j)到右下角(m,n)的最小路径和
// dp方程：
//  1、i和j都不是边界：dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j]
//  2、i是边界：dp[i][j] = dp[i][j+1] + grid[i][j]
//  3、j是边界：dp[i][j] = dp[i+1][j] + grid[i][j]
//  4、i和j都是边界：dp[i][j] = grid[i][j]
int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 && j == n - 1) {
                dp[i][j] = grid[i][j];
            } else if (i == m - 1) {
                dp[i][j] = dp[i][j + 1] + grid[i][j];
            } else if (j == n - 1) {
                dp[i][j] = dp[i + 1][j] + grid[i][j];
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }
    }
    return dp[0][0];
}
```

#### [1027. 最长等差数列](https://leetcode-cn.com/problems/longest-arithmetic-sequence/) (快手)

#### [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) (快手)

```c++
// 重复性：到达第n阶台阶方法数量 = 到达第n-1阶台阶方法数量 + 到达第n-2阶台阶方法数量
// 状态数组：f(n) 到达第n阶台阶方法数量
// DP方程：f(n) = f(n-1) + f(n-2)
int climbStairs(int n) {
    if (n <= 2)
        return n;

    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// 简化，只存f(n-1)和f(n-2)的状态即可
int climbStairs(int n) {
    if (n <= 2)
        return n;

    int a = 1, b = 2, res = 0;
    for (int i = 3; i <= n; i++) {
        res = a + b;
        a = b;
        b = res;
    }

    return res;
}

// 递归 + 记忆化
// 最近重复子问题：第n级台阶 = 第n-1级台阶（爬1步）+ 第n-2级台阶（爬2步）
int climbStairs(int n) {
    vector<int> v(n + 1, 0);
    return _climbStairs(n, v);
}

int _climbStairs(int n, vector<int>& v) {
    if (n == 1 || n == 2) return n;
    if (v[n] == 0) v[n] = _climbStairs(n - 1, v) + _climbStairs(n - 2, v);
    return v[n];
}
```

#### [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) (快手)

#### [1049. 最后一块石头的重量 II](https://leetcode-cn.com/problems/last-stone-weight-ii/) (快手)

#### [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) 【中等】 (快手)

```c++
// 重复性（分治）：凑成总金额为amount所需最少硬币数量 = 
//              凑成总金额为amount-k所需最少硬币数量(k = {1, 2, 5}) 中最小者 + 1 
// 				即：problem[n] = min(problem[n-k]) + 1, k={1, 2, 5}
// 状态数组：f[n]为凑成总金额为i所需最少硬币数量
// DP方程：f[n] = min(f[n-k]) + 1, k = {1, 2, 5}
int coinChange(vector<int>& coins, int amount) {
    int maxAmount = amount + 1;
    vector<int> dp(amount + 1, maxAmount);
    dp[0] = 0;

    for (int i = 0; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
              	dp[i] = min(dp[i], dp[i - coins[j]] + 1); 
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}
```

#### [面试题14- I. 剪绳子](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/)(快手)

#### [152. 乘积最大子数组](https://leetcode-cn.com/problems/maximum-product-subarray/) (快手)

```c++
// 由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值
// 状态数组：Max[i]为整数数组nums从0到第i个元素连续子数组最大乘积
//         Min[i]为整数数组nums从0到第i个元素连续子数组最小乘积
// DP方程：Max[i] = max(Max[i-1] * nums[i], nums[i], Min[i-1] * nums[i])
//        Min[i] = min(Min[i-1] * nums[i], nums[i], Max[i-1] * nums[i])
int maxProduct(vector<int>& nums) {
    vector<int> maxDP = nums, minDP = nums;
    int maxRes = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        maxDP[i] = max(maxDP[i - 1] * nums[i], max(nums[i], minDP[i - 1] * nums[i]));
        minDP[i] = min(minDP[i - 1] * nums[i], min(nums[i], maxDP[i - 1] * nums[i]));
        maxRes = max(maxDP[i], maxRes);
    }
    
    return maxRes;
}

// 简化，只保存最近max和min的状态即可
int maxProduct(vector<int>& nums) {
    int maxRes = nums[0], maxDP = nums[0], minDP = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int preMaxDP = maxDP;
        maxDP = max(maxDP * nums[i], max(nums[i], minDP * nums[i]));
        minDP = min(minDP * nums[i], min(nums[i], preMaxDP * nums[i]));
        maxRes = max(maxDP, maxRes);
    }

    return maxRes;
}
```

#### [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) 【中等】(快手)

```c++
// 重复子问题：(i,j)坐标格子的路径数 = (i-1,j)坐标格子的路径数 + (i,j-1)坐标格子的路径数
// 状态数组：f[m][n] 为 (m,n)坐标格子的路径数
// DP方程：f[m][n] = f[m-1][n] + f[m][n-1]
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      	dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
      	dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++) {
      	for (int j = 1; j < n; j++) {
        	dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      	}
    }
    return dp[m - 1][n - 1];
}

// 简化
// DP方程：dp[j] = dp[j] + dp[j - 1] （只存放前状态值）
int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          	dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

// 自顶向下（超出时间限制）
int uniquePaths(int m, int n) {
    return helper(m - 1, n - 1);
}

int helper(int m, int n) {
    if (m < 0 || n < 0) return 0;
    if (m == 0 || n == 0) return 1;

    return helper(m - 1, n) + helper(m, n - 1);
}

// 自顶向下 + 记忆化
int uniquePaths(int m, int n) {
    vector<vector<int>> v(m, vector<int>(n, 0));
    return helper(m - 1, n - 1, v);
}

int helper(int m, int n, vector<vector<int>>& v) {
    if (m < 0 || n < 0) return 0;
    if (m == 0 || n == 0) return 1;
    if (v[m][n] == 0) v[m][n] = helper(m - 1, n, v) + helper(m, n - 1,
                                                             v); return v[m][n];
}
```

#### [139. 单词拆分](https://leetcode-cn.com/problems/word-break/) (快手)

#### [516. 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/) (快手)

#### [123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/) (快手)

#### [面试题47. 礼物的最大价值](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/) (快手)

#### [1397. 找到所有好字符串](https://leetcode-cn.com/problems/find-all-good-strings/) (快手)

#### [546. 移除盒子](https://leetcode-cn.com/problems/remove-boxes/) (快手)

#### [63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/) (快手)

```c++
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        if(obstacleGrid[i][0])
            break;
        dp[i][0] = 1;   
    }
    for (int j = 0; j < n; j++) {
        if(obstacleGrid[0][j])
            break;
        dp[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (!obstacleGrid[i][j])
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n - 1];
}
```

#### [44. 通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/) (快手)

#### [1339. 分裂二叉树的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-splitted-binary-tree/) (快手)

#### [10. 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/) (快手)

#### [279. 完全平方数](https://leetcode-cn.com/problems/perfect-squares/) (快手)

#### [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/) 【中等】

```c++
// 重复性：字符串text1的子串(0,i) 和 字符串text2的子串(0,j) 最长公共子序列长度 = 
    //    1). 字符串text1的子串(0,i-1) 和 字符串text2的子串(0,j-1) 最长公共子序列长度 + 1 
    //       （text1第i个字符与text2第j个字符相同）
    //    2). 字符串text1的子串(0,i-1) 和 字符串text2的子串(0,j) 最长公共子序列长度 与
    //        字符串text1的子串(0,i) 和 字符串text2的子串(0,j-1) 最长公共子序列长度 中的较大者
    //        （text1第i个字符与text2第j个字符不同）
    // 状态数组：f[i][j] = 字符串text1的子串(0,i) 和 字符串text2的子串(0,j) 最长公共子序列长度
    // DP方程：s1[m-1] != s2[n-1]: LCS[s1, s2] = Max(LCS[s1-1, s2], LCS[s1, s2-1])
    //        s1[m-1] == s2[n-1]: LCS[s1, s2] = LCS[s1-1, s2-1] + 1
int longestCommonSubsequence(string text1, string text2) {
    if (text1.empty() || text2.empty())
      	return 0;

    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <=n; j++) {
            if (text1[i-1] != text2[j-1]) {
              	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            } else {
              	dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }

    return dp[m][n];
}
```

#### [120. 三角形最小路径和](https://leetcode-cn.com/problems/triangle/) 【中等】

```c++
// 重复性（分治）：坐标(i,j)自顶向下最小路径和 = 坐标(i+1,j)自顶向下最小路径和 与 
//              坐标(i+1,j+1)自顶向下最小路径和 中的较小者 + 
//              坐标(i,j)结点值
//         	 	problem[i][j] = min(problem[i+1][j], problem[i+1][j+1]) + a[i][j]
// 状态数组：f[i][j] 为坐标(i,j)自顶向下最小路径和
// DP方程：f[i][j] = min(f[i+1][j], f[i+1][j+1]) + a[i][j]
int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp = triangle;

    for (int i = dp.size() - 2; i >=0; i--) {
        for (int j = 0; j < dp[i].size(); j++) {
          	dp[i][j] += min(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    return dp[0][0];
}
```

#### [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/) 【简单】

```c++
// 一、方法一：一维
// 重复性：i个房子能够偷窃到的最高金额 =
//          opt1: i-1个房子能够偷窃到的最高金额
//              （第i个房子不偷）
//          opt2: i-2个房子能够偷窃到的最高金额 + 第i个房子的金额
//              （第i个房子偷）
//      以上两者取较大者
// 状态定义：dp[i] 为i个房子能够偷窃到的最高金额
// DP方程：dp[i] = max(dp[i-1], dp[i-2] + nums[i])
int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    if (nums.size() == 1) return nums[0];

    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[nums.size() - 1];
}

// 二、方法二：二维
// 重复性：i个房子能够偷窃到的最高金额 =
//          opt1:【第i个房子不偷时能够偷窃到的最高金额】
//          opt2:【第i个房子偷时能够偷窃到的最高金额】
//      以上两者取较大者
//          【第i个房子偷时能够偷窃到的最高金额】 =
//              【第i-1个房子不偷时能够偷窃到的最高金额】+ 【第i个房子金额】
//          【第i个房子不偷时能够偷窃到的最高金额】=
//              【第i-1个房子偷时能够偷窃到的最高金额】与
//              【第i-1个房子不偷时能够偷窃到的最高金额】的较大者
// 状态定义：dp[i][0] 为第i个房子不偷时能够偷窃到的最高金额
//          dp[i][1] 为第i个房子偷时能够偷窃到的最高金额
// DP方程：dp[i][0] = max(dp[i-1][0], dp[i-1][1])
//          dp[i][1] = dp[i-i][0] + nums[i]
int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    if (nums.size() == 1) return nums[0];

    vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + nums[i];
    }

    return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
}
```

#### [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)

```c++
// 状态数组：f[i]为字符串从0到i个字符中解码方法总数。
// DP方程：
// s[i] == 0 :
//  s[i-1]s[i] <= 26: (两者为整体，不可拆分; s[i-1] == 1 or s[i-1] == 2): 
//      f[i] = f[i-2]
// s[i] != 0 :
//  s[i-1]s[i] <= 26: (两者可拆，也可为整体; s[i-1] == 1 or s[i-1] == 2, s[i] <= 6)
//      f[i] = f[i-1] + f[i-2]
//  s[i-1]s[i] > 26: (两者必拆; s[i-1] == 2 and s[i] > 6)
//      f[i] = f[i-1] 
int numDecodings(string s) {
    if (s[0] == '0')
        return 0;

    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0') {
            if (s[i - 1] == '1' or s[i - 1] == '2') {
                dp[i + 1] = dp[i - 1];
            }
        } else {
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i + 1] = dp[i] + dp[i - 1];
            } else {
                dp[i + 1] = dp[i];
            }
        }
    }

    return dp[s.size()];
}
```



## 并查集

#### [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) (快手)



## 位运算

#### [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/) (快手)

#### [78. 子集](https://leetcode-cn.com/problems/subsets/) (快手)

#### [784. 字母大小写全排列](https://leetcode-cn.com/problems/letter-case-permutation/) (快手)

#### [169. 多数元素](https://leetcode-cn.com/problems/majority-element/) (快手)



## 排序

#### [148. 排序链表](https://leetcode-cn.com/problems/sort-list/) (快手)

#### [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/) (快手)

#### [315. 计算右侧小于当前元素的个数](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/) (快手)



## 拓扑排序

#### [329. 矩阵中的最长递增路径](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/) (快手)



## 字符串

#### [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)

```c++
vector<string> generateParenthesis(int n) {
    vector<string> res;
    _generateParenthesis(0, 0, n, "", res);
    return res;
}

void _generateParenthesis(int left, int right, int n, string s,
                          vector<string>& res) {
    if (left == n && right == n) {
        res.push_back(s);
        return;
    }

    if (left < n) 
        _generateParenthesis(left + 1, right, n, s + "(", res);
    if (right < left)
        _generateParenthesis(left, right + 1, n, s + ")", res);
}
```

#### [165. 比较版本号](https://leetcode-cn.com/problems/compare-version-numbers/) (快手)

#### [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/) (快手)

#### [17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/) (快手)

#### [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) (快手)

#### [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/) (快手)

#### [468. 验证IP地址](https://leetcode-cn.com/problems/validate-ip-address/) (快手)

#### [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/) (快手)

#### [415. 字符串相加](https://leetcode-cn.com/problems/add-strings/) (快手)

#### [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/) (快手)

#### [459. 重复的子字符串](https://leetcode-cn.com/problems/repeated-substring-pattern/) (快手)

#### [6. Z 字形变换](https://leetcode-cn.com/problems/zigzag-conversion/) (快手)

#### [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) (快手)

#### [722. 删除注释](https://leetcode-cn.com/problems/remove-comments/) (快手)

#### [44. 通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/) (快手)

#### [10. 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/) (快手)

#### [30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/) (快手)



## 数学

#### [7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/) (快手)

#### [149. 直线上最多的点数](https://leetcode-cn.com/problems/max-points-on-a-line/) (快手)

#### [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/) (快手)

#### [69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/) (快手)

#### [面试题14- I. 剪绳子](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/) (快手)

#### [204. 计数质数](https://leetcode-cn.com/problems/count-primes/) (快手)

#### [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) (快手)

#### [29. 两数相除](https://leetcode-cn.com/problems/divide-two-integers/) (快手)

#### [50. Pow(x, n)](https://leetcode-cn.com/problems/powx-n/) (快手)

#### [168. Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/) (快手)

#### [171. Excel表列序号](https://leetcode-cn.com/problems/excel-sheet-column-number/) (快手)

#### [面试题 02.05. 链表求和](https://leetcode-cn.com/problems/sum-lists-lcci/) (快手)

#### [670. 最大交换](https://leetcode-cn.com/problems/maximum-swap/) (快手)

#### [面试题43. 1～n整数中1出现的次数](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/) (快手)

#### [279. 完全平方数](https://leetcode-cn.com/problems/perfect-squares/) (快手)

#### [179. 最大数](https://leetcode-cn.com/problems/largest-number/) (快手)



## 设计

#### [146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/) (快手)

#### [155. 最小栈](https://leetcode-cn.com/problems/min-stack/) (快手)



## 其他

#### [384. 打乱数组](https://leetcode-cn.com/problems/shuffle-an-array/) (快手)

#### [470. 用 Rand7() 实现 Rand10()](https://leetcode-cn.com/problems/implement-rand10-using-rand7/) (快手) 

#### [315. 计算右侧小于当前元素的个数](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/) (快手)

#### [1050. 合作过至少三次的演员和导演](https://leetcode-cn.com/problems/actors-and-directors-who-cooperated-at-least-three-times/) (快手)

