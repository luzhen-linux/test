/*
 * [611] Valid Triangle Number
 *
 * https://leetcode.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (42.01%)
 * Total Accepted:    16.5K
 * Total Submissions: 39.3K
 * Testcase Example:  '[2,2,3,4]'
 *
 * Given an array consists of non-negative integers,  your task is to count the
 * number of triplets chosen from the array that can make triangles if we take
 * them as side lengths of a triangle.
 * 
 * Example 1:
 * 
 * Input: [2,2,3,4]
 * Output: 3
 * Explanation:
 * Valid combinations are: 
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array won't exceed 1000.
 * The integers in the given array are in the range of [0, 1000].
 * 
 * 
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
    static int triangleNumber(vector<int>& nums) {
		int sz_nums=nums.size(), count=0;
		sort(nums.begin(), nums.end());
		for (int i=0; i<sz_nums-2; i++) {
			for (int j=i+1; j<sz_nums-1; j++) {
				for (int k=j+1; k<sz_nums; k++) {
					if (nums[k]<nums[i]+nums[j]) {
						count++;
					}
					else
						break;
				}
			}
		}
		return count;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums={2,2,3,4};
	cout << Solution::triangleNumber(nums) << endl;
	return 0;
}
#endif
