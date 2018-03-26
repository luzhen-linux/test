/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (27.22%)
 * Total Accepted:    201.4K
 * Total Submissions: 739.1K
 * Testcase Example:  '""\n1'
 *
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
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

#define SOLUTION2 1
// 0:  P   A   H   N
// 1:  A P L S I I G
// 2:  Y   I   R
//
// 012101210
// 0123210123210
//
class Solution {
public:
    static string convert(string s, int numRows) {
		vector<string> tmp(numRows);

		if (numRows<=1 || numRows>=s.size())
			return s;

#ifdef SOLUTION1
		int pos=0;

		vector<int> tmp_pos(2*numRows-2);
		for (int i=0; i<2*numRows-2; i++) {
			if (i>numRows-1)
				tmp_pos[i] = 2*numRows - 2 - i;
			else
				tmp_pos[i] = i;
		}
		for (int i=0; i<s.size(); i++) {
			tmp[tmp_pos[pos++]] += s.at(i);
			pos %= 2*numRows-2;
		}
#elif SOLUTION2
		int num = s.size();
		for (int i=0; i<num; ) {
			for (int j=0; j<numRows&&i<num; j++)
				tmp[j] += s.at(i++);
			for (int j=numRows-2; j>0&&i<num; j--)
				tmp[j] += s.at(i++);
		}
#endif
		string ret;
		for (int i=0; i<numRows; i++) {
			ret += tmp[i];
		}
		return ret;
    }
};

#ifdef TEST
int main()
{
	string str("PAYPALISHIRING"), ret;
	ret = Solution::convert(str, 3);
	cout << ret << endl;
	return 0;
}
#endif
