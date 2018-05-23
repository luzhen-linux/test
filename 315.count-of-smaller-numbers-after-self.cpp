/*
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (34.98%)
 * Total Accepted:    45.5K
 * Total Submissions: 130.1K
 * Testcase Example:  '[5,2,6,1]'
 *
 * 
 * You are given an integer array nums and you have to return a new counts
 * array.
 * The counts array has the property where counts[i] is 
 * the number of smaller elements to the right of nums[i].
 * 
 * 
 * Example:
 * 
 * 
 * Given nums = [5, 2, 6, 1]
 * 
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 * 
 * 
 * Return the array [2, 1, 1, 0].
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
    static vector<int> countSmaller(vector<int>& nums) {
		int sz_nums=nums.size();
		vector<int> ret(sz_nums);
		for (int i=sz_nums-1; i>=0; i--) {
			for (int j=i+1; j<sz_nums; j++)
				if (nums[i]>nums[j]) {
					ret[i] = ret[j]+1;
					for (int k=j+1; k<sz_nums; k++)
						if (nums[k]>=nums[j] && nums[k]<nums[i])
							ret[i]++;
						else
							break;
					break;
				}
		}
		return ret;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums={5, 2, 6, 1};
	vector<int> ret = Solution::countSmaller(nums);
	for (auto i:ret)
		cout << i << ", ";
	cout << endl;
	return 0;
}
#endif
