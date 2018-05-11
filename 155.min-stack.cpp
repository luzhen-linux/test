/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (31.05%)
 * Total Accepted:    179.7K
 * Total Submissions: 578.8K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#endif

class MinStack {
private:
	stack<int> value;
	stack<int> minval;
	int cur_min;
public:
    /** initialize your data structure here. */
    MinStack() {
		cur_min = INT_MAX;
    }
    
    void push(int x) {
		value.push(x);
		cur_min = min(cur_min, x);
		minval.push(cur_min);
    }
    
    void pop() {
		if (!value.empty()) {
			value.pop();
			minval.pop();
			cur_min = minval.empty()?INT_MAX:minval.top();
		}
    }
    
    int top() {
		return value.top();
    }
    
    int getMin() {
		return minval.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

#ifdef TEST
int main()
{
	MinStack minStack{};
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;   // Returns -3.
	minStack.pop();
	cout << minStack.top() << endl;      // Returns 0.
	cout << minStack.getMin() << endl;   // Returns -2.
	return 0;
}
#endif

