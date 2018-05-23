/*
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (58.13%)
 * Total Accepted:    112.1K
 * Total Submissions: 192.8K
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
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
	static vector<string> fizzBuzz(int n) {
		vector<string> repl{"Fizz", "Buzz", "FizzBuzz"};
		vector<string> ret;
		for (int i=1; i<=n; i++) {
			if (i%15==0)
				ret.push_back(repl[2]);
			else if (i%5==0)
				ret.push_back(repl[1]);
			else if (i%3==0)
				ret.push_back(repl[0]);
			else
				ret.push_back(to_string(i));
		}
		return ret;
	}
};

#ifdef TEST
int main()
{
	vector<string> ret = Solution::fizzBuzz(20);
	for (auto s:ret)
		cout << s << endl;
	return 0;
}
#endif
