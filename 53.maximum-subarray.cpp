/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (40.26%)
 * Total Accepted:    296.4K
 * Total Submissions: 736.3K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest sum.
 * 
 * 
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
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
	static int maxSubArray(vector<int>& nums) {
#if SOLUTION1
		int size=nums.size();
		int max=INT_MIN, sum=0;
		for (int i=0; i<size; i++) {
			if (sum+nums[i]<=0) {
				sum=0;
				max = nums[i]>max?nums[i]:max;
			}
			else {
				sum += nums[i];
				max = sum>max?sum:max;
			}
		}
		return max;
#elif SOLUTION2
		int preMax = nums[0], curMax = nums[0];
		for (int i = 1; i < nums.size(); i++){
			preMax = max(nums[i], preMax + nums[i]);
			curMax = max(preMax, curMax);
		}
		return curMax;
#endif
	}
};

#ifdef TEST
int main()
{
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	cout << Solution::maxSubArray(nums) << endl;
	return 0;
}
#endif
