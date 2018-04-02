/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (36.16%)
 * Total Accepted:    224.4K
 * Total Submissions: 617.8K
 * Testcase Example:  '""'
 *
 * Given a digit string, return all possible letter combinations that the
 * number could represent.
 * 
 * 
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 * 
 * 
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
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

static char phone[10][4]={ 
	{' ',  '\0', '\0', '\0' }, //0
	{'\0', '\0', '\0', '\0' }, //1
	{'a',  'b',  'c',  '\0' }, //2
	{'d',  'e',  'f',  '\0' }, //3
	{'g',  'h',  'i',  '\0' }, //4
	{'j',  'k',  'l',  '\0' }, //5
	{'m',  'n',  'o',  '\0' }, //6
	{'p',  'q',  'r',  's'  }, //7
	{'t',  'u',  'v',  '\0' }, //8
	{'w',  'x',  'y',  'z'  }, //9
};
#define SOLUTION2 1
class Solution {
public:
	static vector<string> letterCombinations(string digits) {
		vector<string> result;

		int size = digits.size();
		if (!size)
			return  result;
		result.push_back("");
		for (int i=0; i<size; i++) {
			char digit=digits.at(i);
			if (digit<'0' || digit>'9')
				continue;
			vector<string> ret;
			for (int j=0; j<4; j++) {
				char ch=::phone[digit-'0'][j];
				if (!ch)
					break;
				for (auto s:result) {
					ret.push_back(s+ch);
				}
			}
			result = ret;
		}
		return result;
	}
};

#ifdef TEST
int main()
{
	string str("23");
	vector<string> ret = Solution::letterCombinations(str);
	for (auto i: ret) {
		cout << "\"" << i << "\", ";
	}
	cout << endl;
	return 0;
}
#endif
