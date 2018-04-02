/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (47.85%)
 * Total Accepted:    202.1K
 * Total Submissions: 422.5K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

#define SOLUTION2 1

class Solution {
public:
    static vector<string> generateParenthesis(int n) {
		vector <string> output;
#ifdef SOLUTION1
		if (n>0)
			dfs (1, 0, n, "(", output);
#elif SOLUTION2
		int left=0, right=0;
		if (n>0)
			output.push_back("(");
		for (int i=1; i<2*n; i++) {
			if (i==2*n-1) {
				for (auto s:output)
					s+=')';
				break;
			}
			vector <string> newout;
			if (left<n) {
				for (auto s:output)
					newout.push_back(s+'(');
				left++;
			}
			if (right<left) {
				for (auto s:output)
					newout.push_back(s+')');
				right ++;
			}
			output = newout;
		}
		return output;
#endif
    }
#ifdef SOLUTION1
	static int dfs (int left, int right, int n, string path, vector<string> &output) {
		if (left<right || left>n)
			return 1;
		if (path.size()==2*n-1) {
			path += ')';
			output.push_back(path);
			return 0;
		}
		dfs (left+1, right, n, path+'(', output);
		dfs (left, right+1, n, path+')', output);
		return 2;
	}
#endif
};

#ifdef TEST
int main()
{
	int n=3;
    vector<string> ret = Solution::generateParenthesis(3);
	cout << ret.size() << endl;
	for (auto s:ret)
		cout << s << endl;
	return 0;
}
#endif

