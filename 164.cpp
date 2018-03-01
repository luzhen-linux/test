/*
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * Problem:
 *
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 *
 * Try to solve it in linear time/space.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 */

#ifdef TEST
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#endif


class Solution {
public:
    static int maximumGap(vector<int>& nums) {
		const int n = nums.size();
		if (n<=1) return 0;

		const auto mm = minmax_element(nums.begin(), nums.end());
		const int range = *mm.second - *mm.first;
		const int bin_size = range / n+1;
		vector<int> min_vals(n, INT_MAX);
		vector<int> max_vals(n, INT_MIN);
		for (const int num: nums) {
			int index = (num-*mm.first)/bin_size;
			min_vals[index] = min(min_vals[index], num);
			max_vals[index] = max(max_vals[index], num);
		}

		int max_gap = 0;
		int prev_max = max_vals[0];

		for (int i=1; i<n; i++) {
			if (min_vals[i]!=INT_MAX) {
				max_gap = max(max_gap, min_vals[i]-prev_max);
				prev_max = max_vals[i];
			}
		}
		return max_gap;
	}
};

#ifdef TEST
int main()
{
	vector<int> nums={5,0,4,2,12,10};
	int ret = Solution::maximumGap(nums);
	cout << ret << endl;
	return 0;
}
#endif

