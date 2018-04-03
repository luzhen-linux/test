/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (15.76%)
 * Total Accepted:    128.9K
 * Total Submissions: 818.3K
 * Testcase Example:  '0\n1'
 *
 * 
 * Divide two integers without using multiplication, division and mod
 * operator.
 * 
 * 
 * If it is overflow, return MAX_INT.
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#endif

class Solution {
public:
    static int divide(int dividend, int divisor) {
		if (!divisor)
			return INT_MAX;
		int sign=0;
		int64_t ret=0, div = dividend, divs=divisor;
		if (dividend<0) {
			sign++;
			div = 0;
			div = div-dividend;
		}
		if (divisor<0) {
			sign++;
			divs = 0;
			divs = divs-divisor;
		}
		if (div<divs)
			return 0;
		int64_t shift=0;
		int64_t dvs=divs;
		while (div>dvs) {
			dvs = dvs<<1;
			shift++;
		}
		while (1) {
			if (div>=dvs) {
				div-=dvs;
				ret += (int64_t)1<<shift;
			}
			else if (shift==0)
				break;
			if (shift>0) {
				shift--;
				dvs = dvs>>1;
			}
		}
		return sign==1?(-ret<INT_MIN?INT_MAX:-ret):(ret>INT_MAX?INT_MAX:ret);
    }
};

#ifdef TEST
int main()
{
	cout << Solution::divide(-2147483648,-1) << endl;
	return 0;
}
#endif
