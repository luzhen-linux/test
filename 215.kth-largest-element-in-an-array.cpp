/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (40.52%)
 * Total Accepted:    200.4K
 * Total Submissions: 494.6K
 * Testcase Example:  '[1]\n1'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <list>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#endif

class Solution {
public:
    static int findKthLargest(vector<int>& nums, int k) {
		if (nums.empty())
			return 0;
		int sz_nums=nums.size();
		if (k<=0 || k>sz_nums)
			return 0;
		if (k>sz_nums/3) {
			sort(nums.begin(), nums.end());
			return nums[sz_nums-k];
		}
		list<int> largest;
		list<int>::iterator it;
		for (int i=0; i<k; ++i) {
			for (it=largest.begin(); it!=largest.end(); ++it)
				if (*it>nums[i])
					break;
			largest.insert(it, nums[i]);
		}
		for (int i=k; i<sz_nums; ++i) {
			if (nums[i] < largest.front())
				continue;
			largest.pop_front();
			for (it=largest.begin(); it!=largest.end(); ++it)
				if (*it>nums[i])
					break;
			largest.insert(it, nums[i]);
		}
		return largest.front();
    }
};

#ifdef TEST
int main()
{
	vector<int> nums{3,2,1,5,6,4};
	cout << Solution::findKthLargest(nums, 2) << endl;
	return 0;
}
#endif
