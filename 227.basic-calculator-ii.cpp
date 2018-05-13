/*
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (30.03%)
 * Total Accepted:    63.5K
 * Total Submissions: 211.5K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * 
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 * 
 * 
 * 
 * 
 * Note: Do not use the eval built-in library function.
 * 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

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
#define MULTI_OP LONG_MAX-2
#define DEVID_OP LONG_MAX-3

class Solution {
public:
    static int calculate(string str) {
		vector<long> stack1;
		long op2, res;
		int allow_neg=1;
		for (int i=0; i<str.size(); i++) {
			char ch=str[i];
			string digit;
			if (isspace(ch))
				continue;
			switch (ch) {
				case '+':
					allow_neg=1;
					stack1.push_back(ADD_OP);
					break;
				case '*':
					allow_neg=1;
					stack1.push_back(MULTI_OP);
					break;
				case '/':
					allow_neg=1;
					stack1.push_back(DEVID_OP);
					break;
				case '-':
					if (!allow_neg) {
						stack1.push_back(MINUS_OP);
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
					if (!stack1.empty()) {
						long op = stack1.back();
						if (op==MULTI_OP || op==DEVID_OP) {
							stack1.pop_back();
							long op1 = stack1.back();
							stack1.pop_back();
							if (op==MULTI_OP)
								res = op1*op2;
							else if (op==DEVID_OP) 
								res = op1/op2;
						}
					}
					stack1.push_back(res);
					break;
			}
		}
		res = stack1[0];
		for (int i=1; i<stack1.size(); i+=2) {
			long op = stack1[i];
			long op1 = stack1[i+1];
			if (op==ADD_OP)
				res += op1;
			else if (op==MINUS_OP) 
				res -= op1;
		}
		return res;
    }
};

#ifdef TEST
int main()
{
	//string s(" 3+5 / 2 ");
	string s("0-2147483647");
	cout << s << " = " << Solution::calculate(s) << endl;
	return 0;
}
#endif
