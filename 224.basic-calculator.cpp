/*
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (28.57%)
 * Total Accepted:    64.3K
 * Total Submissions: 225.3K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * 
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 * 
 * 
 * 
 * 
 * Note: Do not use the eval built-in library function.
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

#define ADD_OP LONG_MAX
#define MINUS_OP LONG_MAX-1
#define OPEN_PAREN LONG_MAX-2

class Solution {
public:
    static int calculate(string str) {
		stack<long> stack;
		int allow_neg=1;
		for (int i=0; i<str.size(); i++) {
			char ch=str[i];
			string digit;
			long op2, res;
			if (isspace(ch)) {
				continue;
			}
			switch (ch) {
				case '(':
					allow_neg=1;
					stack.push(OPEN_PAREN);
					break;
				case '+':
					allow_neg=1;
					stack.push(ADD_OP);
					break;
				case ')':
					allow_neg=0;
					while (!stack.empty()) {
						long op = stack.top();
						if (op==OPEN_PAREN) {
							break;
						}
						stack.pop();
						long op1 = stack.top();
						stack.pop();
						if (op1==OPEN_PAREN) {
							res = op2 = op;
						}
						else if (op==ADD_OP)
							res = op1+op2;
						else if (op==MINUS_OP) 
							res = op1-op2;
					}
					stack.push(res);
					break;
				case '-':
					if (!allow_neg) {
						stack.push(MINUS_OP);
						break;
					}
					digit+=ch;
				case '0'...'9':
					allow_neg=0;
					do {
						digit+=ch;
						if (i<str.size()-1)
							ch = str[i+1];
						else
							break;
						if (ch>='0' && ch<='9') {
							++i;
							continue;
						}
						break;
					} while (1);
					op2 = stol(digit);
					res = op2;
					if (!stack.empty()) {
						long op = stack.top();
						if (op!=OPEN_PAREN) {
							stack.pop();
							long op1 = stack.top();
							stack.pop();
							if (op==ADD_OP)
								res = op1+op2;
							else if (op==MINUS_OP) 
								res = op1-op2;
						}
					}
					stack.push(res);
					break;
			}
		}
		return stack.empty()?-1:(int)stack.top();
    }
};

#ifdef TEST
int main()
{
	string s("( 1+(4+5+12)-3 ) - ( 6+8 )");
	cout << s << " = " << Solution::calculate(s) << endl;
	return 0;
}
#endif
