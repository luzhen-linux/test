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

#define SOLUTION1 1
class Solution {
	public:
		static int minDistance(string word1, string word2) {
#if SOLUTION1
			map<char, vector<int>> map1;
			map<char, int> count;
			int i=0;
			for (auto c: word1) {
				map1[c].push_back(i++);
				count[c]++;
			}
			//   h e l l o
			// w 1 2 3 4 5
			// o 2 2 3 4 4
			// l 3 3 2 3 4
			// d 4 4 3 3 4
			// 
			//   h e l l o
			// w 1 2 3 4 5
			// o 2 2 3 4 4
			// r 3 3 3 4 5
			// l 4 4 3 3 4
			// d 5 5 4 4 4
			//
			char prevch;
			int prev=-1;
			int common=0;
			map<int, int> path;
			i=-1;
			for (auto c: word2) {
				i++;
				if (!count[c]) { // 1. not found
					continue;
				}
				int sz_ch = map1[c].size();
				int cur = map1[c][sz_ch-count[c]];
				printf("c=%c, cur=%d, prev=%d\n", c, cur, prev);
				cout << "c=" << c << ": ";
				for (auto m:map1[c])
					cout << m << ", ";
				cout << endl;
				if (cur>prev) {  // 2. close to the end;
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
			for (auto c: path) cout << c.first << " <=> " << c.second << endl;
			return max(word1.size(), word2.size())-common;
#elif SOLUTION2
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
#elif SOLUTION3
			if( word1.empty() || word2.empty() ) return( max( word1.size(), word2.size() ) );        
			vector< int > steps( word2.size() + 1, 0 );        
			for( int j = 1; j <= word2.size(); j++ ) steps[j] = j;
			for( int i = 1; i <= word1.size(); i++ ) {                        
				int last = i - 1;
				steps[0] = i;
				for( int j = 1; j <= word2.size(); j++ ) {   
					int tmp = steps[j];                                
					steps[j]++;
					steps[j] = min( steps[j], last + ( word1[ i - 1 ] != word2[ j - 1 ] ) );
					steps[j] = min( steps[j], steps[ j - 1 ] + 1 );
					last = tmp;
				}
			}                
			return( steps[ word2.size() ] );
#endif
		}
};

#ifdef TEST
int main()
{
	string word1("intention");
	string word2("execution");
	cout << word1 << endl << word2 << endl;
	cout << Solution::minDistance(word1, word2) << endl;
	return 0;
}
#endif
