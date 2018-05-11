/*
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (38.84%)
 * Total Accepted:    147.9K
 * Total Submissions: 380.7K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return
 * its index.
 * 
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 * 
 * You may imagine that num[-1] = num[n] = -∞.
 * 
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function
 * should return the index number 2.
 * 
 * click to show spoilers.
 * 
 * Note:
 * Your solution should be in logarithmic complexity.
 * 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#endif

class Solution {
public:
    static int findPeakElement(vector<int>& nums) {
		int i, prev=INT_MIN, sz_nums=nums.size();
		for (i=0; i<sz_nums; i++) {
			if (nums[i]<prev)
				break;
			prev = nums[i];
		}
		return i-1;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums = {1, 2, 3, 1};
	cout << Solution::findPeakElement(nums) << endl;
	return 0;
}
#endif

