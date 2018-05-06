/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (20.29%)
 * Total Accepted:    166.1K
 * Total Submissions: 818.8K
 * Testcase Example:  '""'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 * 
 * 
 * 
 * For example,
 * Given encoded message "12",
 * it could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * 
 * The number of ways decoding "12" is 2.
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
    static int numDecodings(string s) {
		int count=1, size=s.size();
		char right=0;
		if (size==0)
			return 0;
		for (int i=size-1; i>=0; i--) {
			char ch=s[i];
			char left=i>0?s[i-1]:0;
			if (ch=='0') {
				if (left!='1'&&left!='2')
					return 0;
				i--;
				continue;
			}
			if (left=='1')
				count++;
			else if (left=='2') {
				if (ch<'7')
					count++;
			}
		}
		return count;
    }
};

#ifdef TEST
int main()
{
	string s("12");
	cout << Solution::numDecodings(s) << endl;
	return 0;
}
#endif

