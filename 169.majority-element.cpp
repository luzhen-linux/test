/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element
 *
 * algorithms
 * Easy (47.34%)
 * Total Accepted:    230.8K
 * Total Submissions: 487.6K
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

#define SOLUTION3 1

class Solution {
public:
    static int majorityElement(vector<int>& nums) {
#ifdef SOLUTION1
		unordered_map <int, int> count;
		const int size = nums.size();
		for (auto num: nums) {
			if ( ++count[num]>size/2 )
				return num;
		}
		return -1;
#elif SOLUTION2
		map <int, int> count;
		const int size = nums.size();
		for (auto num: nums) {
			if ( ++count[num]>size/2 )
				return num;
		}
		return -1;
#elif SOLUTION3
		int majority = nums.front();
		int count = 0;

		for (auto num: nums) {
			if (num==majority)
				count ++;
			else if (--count <= 0) {
				count = 1;
				majority = num;
			}
		}
		return majority;
#elif SOLUTION4
#endif
    }
};

#ifdef TEST
int main()
{
	vector<int> nums={1,1,2,2,2};
	int ret = Solution::majorityElement(nums);
	cout << ret << endl;
	return 0;
}
#endif

