/*
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (46.69%)
 * Total Accepted:    18.3K
 * Total Submissions: 39.1K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 * 
 * Example 1:
 * 
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * 
 * 
 * 
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
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
    static int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, int> count;
		vector<int> dup;
		int max=0, val, sz_nums=nums.size();
		for (auto i:nums) {
			count[i]++;
			if (max<count[i]) {
				max=count[i];
				val=i;
				dup.clear();
			}
			else if (max==count[i]) {
				dup.push_back(i);
			}
		}
		dup.push_back(val);
		int degree=INT_MAX;
		for (auto one:dup) {
			int start, end;
			for (start=0; start<sz_nums; start++)
				if (nums[start]==one)
					break;
			for (end=sz_nums-1; end>=start; end--)
				if (nums[end]==one)
					break;
			degree = min(degree, end-start+1);
		}
		return degree;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums={2,1,1,2,1,3,3,3,1,3,1,3,2};
	//vector<int> nums={1,2,2,3,1,4,2};
	cout << Solution::findShortestSubArray(nums) << endl;
	return 0;
}
#endif

