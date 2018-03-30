/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (33.96%)
 * Total Accepted:    316.6K
 * Total Submissions: 932.3K
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
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
    static bool isValid(string s) {
		map <char, char> m={{'{', '}'},{'(', ')'},{'[', ']'}} ;
		stack<char> stack;
		for (auto c:s) {
			char ch=m[c];
			if (ch)
				stack.push(ch);
			else if (!stack.empty() && stack.top()==c)
				stack.pop();
			else
				return false;
		}
		return stack.empty()?true:false;
    }
};

#ifdef TEST
int main()
{
	string str("]");
	cout << Solution::isValid(str) << endl;
	return 0;
}
#endif
