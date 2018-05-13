/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (26.52%)
 * Total Accepted:    150.1K
 * Total Submissions: 566K
 * Testcase Example:  '0'
 *
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
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
    static int countPrimes(int n) {
		if (n<=0)
			return 0;
		int flaged[n]={};
		int num=0;
		for (int i=2; i<n; i++) {
			if (flaged[i])
				continue;
			num++;
			for (int j=2; j*i<n; j++)
				flaged[j*i] = 1;
		}
		return num;
    }
};

#ifdef TEST
int main()
{
	cout << Solution::countPrimes(100) << endl;
	return 0;
}
#endif
