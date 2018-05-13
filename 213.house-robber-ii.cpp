/*
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (34.59%)
 * Total Accepted:    73.7K
 * Total Submissions: 213K
 * Testcase Example:  '[]'
 *
 * Note: This is an extension of House Robber.
 * 
 * After robbing those houses on that street, the thief has found himself a new
 * place for his thievery so that he will not get too much attention. This
 * time, all houses at this place are arranged in a circle. That means the
 * first house is the neighbor of the last one. Meanwhile, the security system
 * for these houses remain the same as for those in the previous street. 
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
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
		if (nums.empty())
			return 0;
		if (nums.size()==1)
			return nums[0];
		int prev, rob1, rob2;
		prev = rob1 = nums[0];
		for (int i=2; i<nums.size()-1; i++) {
			int tmp = rob1;
			rob1 = max(prev+nums[i], rob1);
			prev = tmp;
		}
		prev = rob2 = 0;
		for (int i=1; i<nums.size(); i++) {
			int tmp = rob2;
			rob2 = max(prev+nums[i], rob2);
			prev = tmp;
		}
		return max(rob1, rob2);
    }
};

#ifdef TEST
int main()
{
	vector<int> nums{1,2,1,1};
	cout << Solution::rob(nums) << endl;
	return 0;
}
#endif
