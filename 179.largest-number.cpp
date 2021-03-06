/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (23.42%)
 * Total Accepted:    91.3K
 * Total Submissions: 389.6K
 * Testcase Example:  '[1]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
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
    static string largestNumber(vector<int>& nums) {
		string ret;
		vector<string> tmp;
		int all_zero = 1;
		for (auto i:nums) {
			tmp.push_back(to_string(i));
			if (i>0) all_zero = 0;
		}
		if (all_zero)
			return "0";
		sort (tmp.begin(), tmp.end(), [](string a, string b){return a+b>b+a;});
		for (auto s: tmp)
			ret += s;
		return ret;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums {3, 30, 34, 5, 9};
	cout << Solution::largestNumber(nums) << endl;
	return 0;
}
#endif

