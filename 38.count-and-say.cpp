/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (36.63%)
 * Total Accepted:    185.2K
 * Total Submissions: 505.6K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * 
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
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
    static string countAndSay(int n) {
		if (n<=0)
			return to_string(0);
		string ret = to_string(1);
		for (int i=1; i<n; i++) {
			string tmp;
			int sz = ret.size(), count=0;
			char cur = '\0';
			for (char c:ret)  {
				if (cur==c)
					count++;
				else {
					if (cur) {
						tmp += to_string(count);
						tmp += cur;
					}
					cur = c;
					count = 1;
				}
			}
			if (cur) {
				tmp += to_string(count);
				tmp += cur;
			}
			ret = tmp;
		}
		return ret;
	}
};

#ifdef TEST
int main()
{
	cout << Solution::countAndSay(6) << endl;
	return 0;
}
#endif
