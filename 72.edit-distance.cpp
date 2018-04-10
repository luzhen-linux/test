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
        
    }
};

#ifdef TEST
int main()
{
	string word1("hello");
	string word2("word");
	cout << Solution::minDistance(word1, word2) << endl;
	return 0;
}
#endif
