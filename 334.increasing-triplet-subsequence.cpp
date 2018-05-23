/*
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.77%)
 * Total Accepted:    58.1K
 * Total Submissions: 146K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 * 
 * 
 * Formally the function should:
 * Return true if there exists i, j, k  
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 
 * else return false.
 * 
 * 
 * 
 * Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 * 
 * 
 * Examples:
 * Given [1, 2, 3, 4, 5],
 * return true.
 * 
 * 
 * Given [5, 4, 3, 2, 1],
 * return false.
 * 
 * 
 * Credits:Special thanks to @DjangoUnchained for adding this problem and
 * creating all test cases.
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
    static bool increasingTriplet(vector<int>& nums) {
		vector <int> dp;
		vector <int>::iterator it;
		for (auto n: nums) {
			it = lower_bound(dp.begin(), dp.end(), n);
			if (it==dp.end())
				dp.push_back(n);
			else
				*it = n;
		}
		return dp.size()>=3;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums={1, 2, 3, 4, 5};
	//vector<int> nums={5, 4, 3, 2, 1};
	cout << Solution::increasingTriplet(nums) << endl;
	return 0;
}
#endif
