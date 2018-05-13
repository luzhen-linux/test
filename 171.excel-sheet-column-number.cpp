/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (48.43%)
 * Total Accepted:    162.8K
 * Total Submissions: 336.3K
 * Testcase Example:  '"A"'
 *
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
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

class Solution {
public:
    static int titleToNumber(string s) {
#define NUM_CHARSET 26
		int sz_str = s.size();
		long number = 0;
		long power=1;
		for (int i=sz_str-1; i>=0; i--) {
			int diff = s[i] - 'A' + 1;
			number += diff*power;
			power *= NUM_CHARSET;
		}
		return number;
    }
};

#ifdef TEST
int main()
{
	string s("AAC");
	cout << Solution::titleToNumber(s) << endl;
	return 0;
}
#endif

