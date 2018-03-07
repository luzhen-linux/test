/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (22.82%)
 * Total Accepted:    237.2K
 * Total Submissions: 1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
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
class Solution {
public:
	static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
#if SOLUTION1
		int n1 = nums1.size();
		int n2 = nums2.size();
		if (n1>n2)
			return findMedianSortedArrays(nums2, nums1);

		int k=(n1+n2-1)/2;
		int l=0, r=min(k, n1);
		while (l<r) {
			int mid1 = l+(r-l)/2;
			int mid2 = k-mid1;
			if (nums1[mid1]<nums2[mid2])
				l = mid1+1;
			else
				r = mid1;
		}
		int a = max(l>0?nums1[l-1]:INT_MIN, k>=l?nums2[k-l]:INT_MIN);
		if ((n1+n2)%2) return (double)a;
		int b = min(l<n1?nums1[l]:INT_MAX, k-l+1<n2?nums2[k-l+1]:INT_MAX);
		return (double)(a+b)/2;
#elif SOLUTION2
		const int n1 = nums1.size();
		const int n2 = nums2.size();
		// Make sure n1 <= n2
		if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

		const int k = (n1 + n2 + 1) / 2;

		int l = 0;
		int r = n1;

		while (l < r) {
			const int m1 = l + (r - l) / 2;
			const int m2 = k - m1;
			if (nums1[m1] < nums2[m2 - 1])
				l = m1 + 1;
			else
				r = m1;
		}

		const int m1 = l;
		const int m2 = k - l;

		const int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1], 
				m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

		if ((n1 + n2) % 2 == 1)
			return c1;    

		const int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1], 
				m2 >= n2 ? INT_MAX : nums2[m2]);

		return (c1 + c2) * 0.5;
#endif
	}
};

#ifdef TEST
int main()
{
	vector<int> nums1 = {1,2}, nums2 = {3,4};
	double ret = Solution::findMedianSortedArrays(nums1, nums2);
	cout << ret << endl;
	return 0;
}
#endif
