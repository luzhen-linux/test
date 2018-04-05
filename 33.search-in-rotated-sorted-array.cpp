/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (31.91%)
 * Total Accepted:    245.6K
 * Total Submissions: 769.5K
 * Testcase Example:  '[]\n5'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
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
    static int search(vector<int>& nums, int target) {
		int size = nums.size();
		int lo=0, hi=size-1;
		while (lo<=hi) {
			int mid = lo + (hi-lo)/2;
			//printf("%d,%d,%d  %d,%d,%d\n", lo, mid, hi, nums[lo], nums[mid], nums[hi]);
			if (nums[mid]==target)
				return mid;
			else if (nums[mid]>target) {
				if (nums[lo]<=target || nums[lo]>nums[mid])
					hi = mid -1;
				else
					lo = mid +1;
			}
			else if (nums[mid]<target) {
				if (nums[hi]>=target || nums[hi]<nums[mid])
					lo = mid +1;
				else
					hi = mid -1;
			}
		}
		return -1;
    }
};

#ifdef TEST
int main()
{
	vector <int> nums = {4,5,6,7,8,1,2,3};
	int target = 8;
	cout << Solution::search(nums, target) << endl;
	return 0;
}
#endif

