/*
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (44.43%)
 * Total Accepted:    101.7K
 * Total Submissions: 229K
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two arrays, write a function to compute their intersection.
 * 
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 * 
 * 
 * Note:
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * 
 * Follow up:
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
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
    static vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector <int> ret;
		int sz1 = nums1.size(), sz2 = nums2.size();
		sort (nums1.begin(), nums1.end());
		sort (nums2.begin(), nums2.end());
		for (int i=0, j=0; i<sz1&&j<sz2; ) {
			if (nums1[i]==nums2[j]) {
				ret.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i]>nums2[j])
				j++;
			else 
				i++;
		}
		return ret;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};
	vector<int> ret = Solution::intersect(nums1, nums2);
	for (auto i: ret)
		cout << i << ", ";
	cout << endl;
	return 0;
}
#endif

