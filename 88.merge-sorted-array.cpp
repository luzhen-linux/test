/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (32.13%)
 * Total Accepted:    226.2K
 * Total Submissions: 703.9K
 * Testcase Example:  '[1]\n1\n[]\n0'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * 
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2. The number of elements
 * initialized in nums1 and nums2 are m and n respectively.
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
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    }
};

#ifdef TEST
int main()
{
	vector<int> nums1 = {1,3,5};
	vector<int> nums2 = {2,4,6};
	Solution::merge(nums1, nums1.size(), nums2, nums2.size());
	for (auto s:nums1)
		cout << s << ", ";
	cout << endl;
	return 0;
}
#endif
