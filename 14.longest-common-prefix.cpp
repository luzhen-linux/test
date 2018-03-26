/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.63%)
 * Total Accepted:    258.3K
 * Total Submissions: 817.7K
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
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
    static string longestCommonPrefix(vector<string>& strs) {
		int size = strs.size();
		if (size<1) return "";
		if (size<2) return strs[0];

		int min_sz=INT_MAX;
		for (int i=0; i<strs.size(); i++) {
			int sz = strs[i].size();
			min_sz = min(min_sz, sz);
		}
		string first=strs[0];
		for (int j=0; j<min_sz; j++) {
			for (int i=0; i<strs.size(); i++) {
				if (strs[i].at(j)!=first.at(j)) {
					printf("[%d,%d] %c, %c\n", i, j, strs[i].at(j), first.at(j));
					return first.substr(0,j);
				}
			}
		}
		return first.substr(0, min_sz);
	}
};

#ifdef TEST
int main()
{
	vector<string> str = {"aaa", "aa", "a"};
	cout << Solution::longestCommonPrefix(str) << endl;
	return 0;
}
#endif
