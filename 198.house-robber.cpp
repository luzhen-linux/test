/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (39.91%)
 * Total Accepted:    191.9K
 * Total Submissions: 480.9K
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
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
    static int rob(vector<int>& nums) {
		int sz_nums=nums.size();
		if (sz_nums<=0)
			return 0;
		if (sz_nums<=1)
			return nums[0];
		if (sz_nums<=2)
			return max(nums[0], nums[1]);
		int prev=nums[0], maxrob=max(nums[0],nums[1]);
		//for (auto i:nums) cout << i << " "; cout << endl;
		for (int i=2; i<sz_nums; i++) {
			//printf("%d: %d, %d, %d\n", i, prev, maxrob, nums[i]);
			int tmp=maxrob;
			maxrob = max(prev+nums[i], maxrob);
			prev = tmp;
		}
		return maxrob;
    }
};

#ifdef TEST
int main()
{
	vector <int> nums {12,11,0,4,6,3};
	cout << Solution::rob(nums) << endl;
	return 0;
}
#endif

