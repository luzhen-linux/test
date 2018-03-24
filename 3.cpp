/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.63%)
 * Total Accepted:    443.1K
 * Total Submissions: 1.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

//  abcbcbba
//  01234567

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
		int start=-1, longest=0;
		vector<int> nums(256);
		fill(nums.begin(), nums.end(), -1);
		for (int i=0; i<s.size(); i++) {
			unsigned char ch = s.at(i);
			if (nums[ch]>start)
				start = nums[ch];
			else
				longest = max(longest, i-start);
			//printf("%d, start=%d, nums[%d]=%d, longest=%d\n", i, start, ch, nums[ch], longest);
			nums[ch] = i;
		}
		return longest;
    }
};

#ifdef TEST
int main()
{
	string str="abcabcbb";
	cout << str << endl;
	int ret = Solution::lengthOfLongestSubstring(str);
	cout << ret << endl;
	return 0;
}
#endif

