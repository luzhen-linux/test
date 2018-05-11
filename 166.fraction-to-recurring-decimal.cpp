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
		string ret;
		long numer=numerator, denom=denominator;
		int neg=0;
		if (!denominator)
			return ret;
		if (!numerator)
			return "0";
		if (numer<0) {
			numer = -numer;
			neg=!neg;
		}
		if (denom<0) {
			denom = -denom;
			neg=!neg;
		}
		if (neg)
			ret += "-";
		ret += to_string(numer/denom);
		unordered_map<int,int> count;
		long remains=numer%denom;
		if (!remains)
			return ret;
		int index=0;
		string decimal(".");
		while (remains) {
			if (count[remains]) {
				return ret+decimal.substr(0, count[remains])+"("+decimal.substr(count[remains])+")";
			}
			count[remains] = ++index;
			decimal += to_string((remains*10)/denom);
			remains = (remains*10)%denom;
		}
		return ret+decimal;
    }
};

#ifdef TEST
int main()
{
	//vector<pair<int,int>> arg{{1,2}, {2,1}, {2,3}, {-2147483648, -1}};
	vector<pair<int,int>> arg{{-1,-2147483648}};
	for (auto a: arg) {
		cout << Solution::fractionToDecimal(a.first, a.second) << endl;
	}
	return 0;
}
#endif
