/*
 * [324] Wiggle Sort II
 *
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (26.41%)
 * Total Accepted:    37.9K
 * Total Submissions: 143.7K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * 
 * ⁠   Given an unsorted array nums, reorder it such that
 * ⁠   nums[0] < nums[1] > nums[2] < nums[3]....
 * 
 * 
 * 
 * ⁠   Example:
 * ⁠   (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5,
 * 1, 6]. 
 * ⁠   (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3,
 * 1, 2].
 * 
 * 
 * 
 * ⁠   Note:
 * ⁠   You may assume all input has valid answer.
 * 
 * 
 * 
 * ⁠   Follow Up:
 * ⁠   Can you do it in O(n) time and/or in-place with O(1) extra space?
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
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
	static void wiggleSort(vector<int>& nums) {
		nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());  
		int len=nums.size(), low=0, high=len-1, mid =nums[len/2], i=0;  
		auto index = [=](int pos){ return (1+pos*2)%(len|1); };  
		//for (auto n:nums) cout << n << ", "; cout << endl;
		while(i <= high)  
		{  
			//printf("%d,%d  %d,%d, %d,%d\n", i, index(i), low, high, nums[index(i)], mid);
			if(nums[index(i)] > mid) swap(nums[index(i++)], nums[index(low++)]);  
			else if(nums[index(i)]<mid) swap(nums[index(i)],nums[index(high--)]);  
			else i++;  
			//for (auto n:nums) cout << n << ", "; cout << endl;
		} 
	}
};

#ifdef TEST
int main()
{
	vector<int> nums={1, 5, 1, 1, 6, 4};
	for (auto n:nums) cout << n << ", "; cout << endl;
	Solution::wiggleSort(nums);
	for (auto n:nums) cout << n << ", "; cout << endl;
	return 0;
}
#endif
