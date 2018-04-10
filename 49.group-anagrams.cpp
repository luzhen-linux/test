/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (38.25%)
 * Total Accepted:    191.1K
 * Total Submissions: 499.5K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 * ⁠ ["ate", "eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note: All inputs will be in lower-case.
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
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ret;
		for (auto str: strs) {
			int found = 0;
			string sorted = str;
			sort(sorted.begin(), sorted.end());
			for (auto &one: ret) {
				if (sorted==one[0]) {
					one.push_back(str);
					found = 1;
					break;
				}
			}
			if (!found) {
				vector<string> tmp {sorted, str};
				ret.push_back(tmp);
			}
		}
		for (auto &one:ret) {
			one.erase(one.begin());
		}
		return ret;
    }
};

#ifdef TEST
int main()
{
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> ret = Solution::groupAnagrams(strs);
	for (auto one:ret) {
		for (auto s:one)
			cout << s << ", ";
		cout << endl;
	}
	return 0;
}
#endif
