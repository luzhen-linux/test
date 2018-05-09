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
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class Solution {
public:
    static int evalRPN(vector<string>& tokens) {
        
    }
};

#ifdef TEST
int main()
{
	vector<string> tokens={"2", "1", "+", "3", "*"};
	//vector<string> tokens={"4", "13", "5", "/", "+"};
	cout << Solution::evalRPN(tokens) << endl;
	return 0;
}
#endif
