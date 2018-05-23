/*
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (35.79%)
 * Total Accepted:    24.3K
 * Total Submissions: 67.9K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * s = "aaabb", k = 3
 * 
 * Output:
 * 3
 * 
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "ababbc", k = 2
 * 
 * Output:
 * 5
 * 
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
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
    static int longestSubstring(string s, int k) {
		if (s.size()<k)
			return -1;
		unordered_map<char, int> count;
		for (auto c:s)
			count[c]++;
		int any=0;
		for (auto each: count)
			if (each.second>=k)
				count[each.first] = 0;
			else
				any=1;
		if (!any)
			return s.size();
		int sz_s=s.size(), maxval=-1, start=0, cont=0, len;
		for (int i=0; i<sz_s; i++) {
			if (count[s[i]]) {
				len = i-start;
				cont=0;
				if (len>=k)
					maxval = max(maxval, longestSubstring(s.substr(start, len), k));
				start=i;
			}
			else
				cont++;
		}
		len = sz_s-start;
		if (len>=k)
			maxval = max(maxval, longestSubstring(s.substr(start, len), k));
		return maxval;
	}
};

#ifdef TEST
int main()
{
	string s = "bbaaacbd";
	int k = 3;
	cout << Solution::longestSubstring(s, k) << endl;
	return 0;
}
#endif
