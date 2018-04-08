/*
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (25.84%)
 * Total Accepted:    128.9K
 * Total Submissions: 498.8K
 * Testcase Example:  '[1,2,0]'
 *
 * 
 * Given an unsorted integer array, find the first missing positive integer.
 * 
 * 
 * 
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * 
 * 
 * 
 * Your algorithm should run in O(n) time and uses constant space.
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
    static int firstMissingPositive(vector<int>& nums) {
		int size = nums.size();
		for (int i=0; i<size; i++) {
			if (nums[i]>size || nums[i]<=0) {
				continue;
			}
			//cout << "nums[" << i << "]:" << nums[i] << "  "; for (auto i:nums) cout << i << ", "; cout << endl;
			//printf("[%d] %d <==> [%d] %d\n", i, nums[i], nums[i]-1, nums[nums[i]-1]);
			swap(nums[i], nums[nums[i]-1]);
			while (nums[i]>0&&nums[i]<=i) {
				if (nums[i]==nums[nums[i]-1])
					break;
				//printf("[%d] %d <==> [%d] %d\n", i, nums[i], nums[i]-1, nums[nums[i]-1]);
				swap(nums[i], nums[nums[i]-1]);
			}
		}
		for (int i=0; i<size; i++) {
			if (i!=nums[i]-1)
				return i+1;
		}
		return size+1;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums = {99,94,96,11,92,5,91,89,57,85,66,63,84,81,79,61,74,78,77,30,64,13,58,18,70,69,51,12,32,34,9,43,39,8,1,38,49,27,21,45,47,44,53,52,48,19,50,59,3,40,31,82,23,56,37,41,16,28,22,33,65,42,54,20,29,25,10,26,4,60,67,83,62,71,24,35,72,55,75,0,2,46,15,80,6,36,14,73,76,86,88,7,17,87,68,90,95,93,97,98};
	cout << Solution::firstMissingPositive(nums) << endl;
	for (auto i:nums) cout << i << ", "; cout << endl;
	return 0;
}
#endif
