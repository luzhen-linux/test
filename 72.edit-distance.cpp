/*
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (32.50%)
 * Total Accepted:    112.8K
 * Total Submissions: 347.1K
 * Testcase Example:  '""\n""'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to convert word1 to word2. (each operation is counted as 1 step.)
 * 
 * 
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * 
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
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
	static int minDistance(string word1, string word2) {
#if 0
		map<char, vector<int>> map1;
		map<char, int> count;
		int i=0;
		for (auto c: word1) {
			map1[c].push_back(i++);
			count[c]++;
		}
		char prevch;
		int prev=-1;
		int common=0, distance=0;
		map<int, int> path;
		i=-1;
		for (auto c: word2) {
			i++;
			if (!count[c]) { // 1. not found
				distance++;
				continue;
			}
			int sz_ch = map1[c].size();
			int cur = map1[c][sz_ch-count[c]];
			if (cur>prev) {  // 2. close to the end;
				common++;
				count[c]--;
				distance--;
			}
			else {
				path.erase(prev);
				count[prevch]++;
			}
			path[cur] = i;
			prev=cur;
			prevch = c;
		}
		for (auto c: path)
			cout << c.first << " <=> " << c.second << endl;
		return max(word1.size(), word2.size())-common;
#endif
		int m = word1.length(), n = word2.length();
		vector<int> cur(m + 1, 0);
		for (int i = 1; i <= m; i++)
			cur[i] = i;
		for (int j = 1; j <= n; j++) {
			int pre = cur[0];
			cur[0] = j;
			for (int i = 1; i <= m; i++) {
				int temp = cur[i];
				if (word1[i - 1] == word2[j - 1])
					cur[i] = pre;
				else cur[i] = min(pre + 1, min(cur[i] + 1, cur[i - 1] + 1));
				pre = temp;
			}
		}
		return cur[m]; 
	}
};

#ifdef TEST
int main()
{
	string word1("hello");
	string word2("wold");
	cout << Solution::minDistance(word1, word2) << endl;
	return 0;
}
#endif
