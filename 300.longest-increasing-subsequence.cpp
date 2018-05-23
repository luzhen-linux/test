/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (38.89%)
 * Total Accepted:    119.8K
 * Total Submissions: 308K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * 
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length
 * is 4. Note that there may be more than one LIS combination, it is only
 * necessary for you to return the length.
 * 
 * 
 * Your algorithm should run in O(n2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity? 
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
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
    static int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int sz_nums=nums.size();
#if SOLUTION1 
		vector<int> len(sz_nums,1);
		for (int i=0; i<sz_nums; i++)
			for (int j=0; j<i; j++)
				if (nums[i]>nums[j]) {
					len[i] = max(len[i], len[j]+1);
				}
		//for (int i=0; i<sz_nums; i++) printf("%d, %d\n", nums[i], len[i]);
		return *max_element(len.begin(), len.end());
#elif SOLUTION2
		vector<int> dp;
		for (int i=0; i<sz_nums; i++) {
			vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), nums[i]);
			if (it!=dp.end())
				*it = nums[i];
			else
				dp.push_back(nums[i]);
		}
		return dp.size();
#endif
    }
};

#ifdef TEST
int main()
{
	//vector<int> nums={4,10,4,3,8,9};
	//vector<int> nums={10,9,2,5,3,7,101,18};
	vector<int> nums={1,3,6,7,9,4,10,5,6};
	cout << Solution::lengthOfLIS(nums) << endl;
	return 0;
}
#endif
