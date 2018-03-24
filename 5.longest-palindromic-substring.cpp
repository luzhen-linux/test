/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.18%)
 * Total Accepted:    296.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * 
 * 
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

//  #b#a#a#b#d#
//  01234567890

class Solution {
public:
    static string longestPalindrome(string s) {
		int mlen=0, start, n=s.size();

		for (int i=0; i<2*n+1; i++) {
			int len=(i%2), j=2-!(i%2);
			for (; i>=j && i<=2*n-j && s.at((i-j)/2)==s.at((i+j)/2); j+=2) {
				len+=2;
				//printf("i=%d, j=%d, len=%d,  [%d]%c vs [%d]%c\n", i, j, len,
						//(i-j)/2, s.at((i-j)/2), (i+j)/2, s.at((i+j)/2));
			}
			//printf("i=%d, j=%d\n", i, j);
			if (len>mlen) {
				mlen = len;
				start = (i-mlen)/2;
				//printf("%d:  %d,%d, %s\n", __LINE__, start, mlen, s.substr(start, mlen).c_str());
			}
		}
        
		return s.substr(start, mlen);
    }
};

#ifdef TEST
int main()
{
	string str("cbbd");
	cout << Solution::longestPalindrome(str) << endl;
	return 0;
}
#endif
