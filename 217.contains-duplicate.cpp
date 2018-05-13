/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (46.99%)
 * Total Accepted:    207.9K
 * Total Submissions: 442.4K
 * Testcase Example:  '[]'
 *
 * 
 * Given an array of integers, find if the array contains any duplicates. Your
 * function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class Solution {
public:
    static bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> map;
		for (auto i:nums) {
			if (map.count(i))
				return true;
			map[i]=1;
		}
		return false;
    }
};

#ifdef TEST
int main()
{
	vector <int> nums{1,2,3,4,1};
	cout << Solution::containsDuplicate(nums) << endl;
	return 0;
}
#endif
