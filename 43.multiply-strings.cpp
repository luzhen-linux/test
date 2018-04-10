/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (27.97%)
 * Total Accepted:    134K
 * Total Submissions: 479K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

#endif

class Solution {
public:
    static string multiply(string num1, string num2) {
		int sz_num1 = num1.size(), sz_num2 = num2.size();
		if (!sz_num1 || !sz_num2) return to_string(0);
		vector<int> d(sz_num1+sz_num2+2);
		for (int i=sz_num2-1; i>=0; i--) {
			if ('0'>num2[i] || num2[i]>'9') return to_string(-1);
			int n2 = num2[i]-'0';
			for (int j=sz_num1-1; j>=0; j--) {
				if ('0'>num1[j] || num1[j]>'9') return to_string(-1);
				int n1 = num1[j]-'0';
				d[sz_num2-i+sz_num1-j-2] += n1*n2;
				//printf("d[%d]=%d\n", sz_num2-i+sz_num1-j-2, d[sz_num2-i+sz_num1-j-2]);
			}
		}
		int lastdigit=0;
		for (int i=0; i<d.size(); i++) {
			if (d[i]>=10) {
				d[i+1] += d[i]/10;
				d[i] = d[i]%10;
			}
			else if (d[i]>0)
				lastdigit = i;
		}
		string ret;
		for (int i=lastdigit; i>=0; i--) {
			ret += to_string(d[i]);
		}
		return ret;
    }
};

#ifdef TEST
int main()
{
	cout << Solution::multiply("54263634615765835050350580967174702085668435910635660620616543115335102947659612171353346993516240052", "78935008537672126746299935133570") << endl;;
	return 0;
}
#endif
