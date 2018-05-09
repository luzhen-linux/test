/*
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (18.08%)
 * Total Accepted:    63K
 * Total Submissions: 348.5K
 * Testcase Example:  '1\n5'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * For example,
 * 
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 * 
 * 
 * 
 * Credits:Special thanks to @Shangrila for adding this problem and creating
 * all test cases.
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
    static string fractionToDecimal(int numerator, int denominator) {
        
    }
};

#ifdef TEST
int main()
{
	vector<pair<int,int>> arg{{1,2}, {2,1}, {2,3}};
	for (auto a: arg) {
		cout << Solution::fractionToDecimal(a.first, a.second) << endl;
	}
	return 0;
}
#endif
