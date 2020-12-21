/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include <stack>
using namespace std;

// 思路
//  初始化两个栈，一个普通栈，另一个是辅助栈，存放最小元素
//  push时，普通栈正常入栈，辅助栈则与栈顶元素比较，如果小于栈顶，则入栈
//  pop时，如果两个栈的栈顶相等，则同时出栈，否则只有普通栈出栈
//  获取最小元素时，返回辅助栈的栈顶即可
//
//  时间复杂度：O(1)
//  空间负责度：O(n)

// @lc code=start
class MinStack {
   public:
    stack<int> intStack, minStack;
    MinStack() {}

    void push(int x) {
        intStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!minStack.empty() && !intStack.empty()) {
            if (minStack.top() == intStack.top()) {
                minStack.pop();
            }
            intStack.pop();
        }
    }

    int top() { return intStack.top(); }

    int getMin() { return minStack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
