/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (47.92%)
 * Total Accepted:    252.5K
 * Total Submissions: 527K
 * Testcase Example:  '[1]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
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
    static int majorityElement(vector<int>& nums) {
		unordered_map<int, int> count;
		int half = nums.size()/2;
		for (auto i:nums) {
			if (++count[i]>half)
				return i;
		}
    }
};

#ifdef TEST
int main()
{
	vector<int> nums{1,1,2,2,2};
	int ret = Solution::majorityElement(nums);
	cout << ret << endl;
	return 0;
}
#endif
