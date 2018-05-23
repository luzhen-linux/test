/*
 * [592] Fraction Addition and Subtraction
 *
 * https://leetcode.com/problems/fraction-addition-and-subtraction/description/
 *
 * algorithms
 * Medium (46.01%)
 * Total Accepted:    7.8K
 * Total Submissions: 17.1K
 * Testcase Example:  '"-1/2+1/2"'
 *
 * Given a string representing an expression of fraction addition and
 * subtraction, you need to return the calculation result in string format. The
 * final result should be irreducible fraction. If your final result is an
 * integer, say 2, you need to change it to the format of fraction that has
 * denominator 1. So in this case, 2 should be converted to 2/1.
 * 
 * Example 1:
 * 
 * Input:"-1/2+1/2"
 * Output: "0/1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:"-1/2+1/2+1/3"
 * Output: "1/3"
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:"1/3-1/2"
 * Output: "-1/6"
 * 
 * 
 * 
 * Example 4:
 * 
 * Input:"5/3+1/3"
 * Output: "2/1"
 * 
 * 
 * 
 * Note:
 * 
 * The input string only contains '0' to '9', '/', '+' and '-'. So does the
 * output.
 * Each fraction (input and output) has format ±numerator/denominator. If the
 * first input fraction or the output is positive, then '+' will be omitted.
 * The input only contains valid irreducible fractions, where the numerator and
 * denominator of each fraction will always be in the range [1,10]. If the
 * denominator is 1, it means this fraction is actually an integer in a
 * fraction format defined above. 
 * The number of given fractions will be in the range [1,10].
 * The numerator and denominator of the final result are guaranteed to be valid
 * and in the range of 32-bit int.
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
	static int gcd(int m, int n) {
		return n?gcd(n, m%n):m;
	}
    static string fractionAddition(string expression) {
		string &str=expression;
		int sz_str=str.size(), neg=0, isdenom=0;
		long curnum=0, curdenom=1, num, denom;
		for (int i=0; i<sz_str; i++) {
			char ch=str[i];
			string digit;
			switch (ch) {
				case '+':
					neg = 0;
					isdenom = 0;
					break;
				case '-':
					neg = 1;
					isdenom = 0;
					break;
				case '/':
					isdenom = 1;
					break;
				case '0'...'9':
					digit+=ch;
					while (i<sz_str-1&&str[i+1]>='0'&&str[i+1]<='9') {
						digit+=str[++i];
					}
					if (isdenom) {
						denom = stoi(digit);
						curnum = denom*curnum+num*curdenom;
						curdenom *= denom;
						int tmp = gcd(curnum, curdenom);
						//printf("%ld/%ld, %ld/%ld, gcd2=%d\n", curnum, curdenom, num, denom, tmp);
						curnum /= tmp;
						curdenom /= tmp;
					}
					else if (neg)
						num = -stoi(digit);
					else
						num = stoi(digit);
					break;
			}
		}
		if (curdenom<0) {
			curnum = -curnum;
			curdenom = -curdenom;
		}
		return to_string(curnum)+'/'+to_string(curdenom);
    }
};

#ifdef TEST
int main()
{
	string s="-1/2+1/4+1/3";
	cout << Solution::fractionAddition(s) << endl;
	return 0;
}
#endif
