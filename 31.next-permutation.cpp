/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.03%)
 * Total Accepted:    146.2K
 * Total Submissions: 503.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
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
    static void nextPermutation(vector<int>& nums) {
		int size=nums.size();
		for (int i=size-1; i>0; i--)
			if (nums[i]>nums[i-1]) {
				int low=i, high=size-1;
				int sz_tmp = high-i+1;
				if (nums[high]>nums[i-1]) {
					iter_swap(nums.begin()+i-1, nums.begin()+high);
					for (int j=0; j<sz_tmp/2; j++) 
						iter_swap(nums.begin()+i+j, nums.end()-j-1);
					return;
				}
				while (low<=high) {
					int mid = low + (high-low)/2;
					if (nums[mid]<=nums[i-1])
						high = mid-1;
					else
						low = mid+1;
				}
				iter_swap(nums.begin()+i-1, nums.begin()+high);
				for (int j=0; j<sz_tmp/2; j++) 
					iter_swap(nums.begin()+i+j, nums.end()-j-1);
				return;
			}
		for (int i=0; i<size/2; i++) 
			iter_swap(nums.begin()+i, nums.end()-i-1);
		return;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums={2,2,7,5,4,3,2,2,1};
	//vector<int> nums={1,2,3,4};
	for (int i=0; i<24; i++) {
		Solution::nextPermutation(nums);
		for (auto i:nums)
			cout << i << ", ";
		cout << endl;
	}
	return 0;
}
#endif

