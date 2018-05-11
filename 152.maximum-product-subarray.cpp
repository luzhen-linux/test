/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (26.69%)
 * Total Accepted:    134.9K
 * Total Submissions: 505.5K
 * Testcase Example:  '[-2]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest product.
 * 
 * 
 * 
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
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

class Solution {
public:
    static int maxProduct(vector<int>& nums, int start, int end) {
		if (start>=end)
			return INT_MIN;
		if (end==start+1)
			return nums[start];
		int num_neg=0, start_neg=-1, end_neg=-1;
		long product=1;
		//printf("start=%d, end=%d\n", start, end);
		// -1, 0, -2, 0
		for (int i=start; i<end; i++) {
			if (nums[i]==0) {
				int l = maxProduct(nums, start, i);
				int r = maxProduct(nums, i+1, end);
				return max(0, max(l,r));
			}
			if (nums[i]<0) {
				if (start_neg<0)
					start_neg = i;
				end_neg = i;
				num_neg++;
			}
			product*=nums[i];
		}
		//printf("num_neg=%d,%d,%d\n", num_neg%2, start_neg, end_neg);
		if (num_neg%2) {
			int l = maxProduct(nums, start, end_neg);
			int r = maxProduct(nums, start_neg+1, end);
			return max(l,r);
		}
		return product;
	}
    static int maxProduct(vector<int>& nums) {
		return maxProduct(nums, 0, nums.size());
    }
};

#ifdef TEST
int main()
{
	//vector<int> nums={2,3,-2,4};
	vector<int> nums={-4,-3,-2};
	cout << Solution::maxProduct(nums) << endl;
	return 0;
}
#endif

