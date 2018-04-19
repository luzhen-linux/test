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
		map<char, vector<int>> map1;
		map<char, int> count;
		int i=0;
		for (auto c: word1) {
			map1[c].push_back(i++);
			count[c]++;
		}
		char prevch;
		int prev=-1;
		int common=0;
		map<int, int> path;
		i=-1;
		for (auto c: word2) {
			i++;
			if (!count[c])
				continue;
			int sz_ch = map1[c].size();
			int cur = map1[c][sz_ch-count[c]];
			if (cur>prev) {
				common++;
				count[c]--;
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
