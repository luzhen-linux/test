/*
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (28.37%)
 * Total Accepted:    113K
 * Total Submissions: 398.4K
 * Testcase Example:  '["18"]'
 *
 * 
 * Evaluate the value of an arithmetic expression in Reverse Polish
 * Notation.
 * 
 * 
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * 
 * 
 * Some examples:
 * 
 * ⁠ ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ⁠ ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 * 
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class Solution {
public:
    static int evalRPN(vector<string>& tokens) {
		int ret=0;
		stack<int> value;
		for (auto s:tokens) {
			int v1, v2, res;
			if (s[1]==0 && (s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/')) {
				if (value.empty())
					return ret;
				v1 = value.top();
				value.pop();
				if (value.empty())
					return ret;
				v2 = value.top();
				value.pop();
				if (s[0]=='+')
					res = v2+v1;
				else if (s[0]=='-')
					res = v2-v1;
				else if (s[0]=='*')
					res = v2*v1;
				else if (s[0]=='/')
					res = v2/v1;
				value.push(res);
				//printf("%d %c %d = %d\n", v1, s[0], v2, res);
			}
			else {
				value.push(stoi(s));
			}
		}
		return value.top();
    }
};

#ifdef TEST
int main()
{
	vector<vector<string>> tokens= {
		{"2", "1", "+", "3", "*"},
		{"4", "13", "5", "/", "+"},
		{"10","6","9","3","+","-11","*","/","*","17","+","5","+"}
	};
	for (auto token: tokens)
		cout << Solution::evalRPN(token) << endl;
	return 0;
}
#endif
