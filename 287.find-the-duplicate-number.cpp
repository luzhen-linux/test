/*
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (44.28%)
 * Total Accepted:    103K
 * Total Submissions: 232.6K
 * Testcase Example:  '[1,1]'
 *
 * 
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 * 
 * 
 * 
 * Note:
 * 
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
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
    static int findDuplicate(vector<int>& num) {
		int sz_nums=num.size();
		for (int i=0; i<sz_nums; i++) {
			if (num[i]-1==i)
				continue;
			if (num[i]==num[num[i]-1])
				return num[i];
			swap(num[i], num[num[i]-1]);
			while (num[i]<i) {
				if (num[i]==num[num[i]-1])
					return num[i];
				swap(num[i], num[num[i]-1]);
			}
		}
		return 0;
    }
};

#ifdef TEST
int main()
{
	//vector<int> nums{1,3,5,7,2,4,6,3};
	vector<int> nums{26,2,9,20,31,7,14,32,37,15,29,6,12,38,48,22,19,45,42,40,1,12,25,36,39,30,35,4,27,12,49,16,47,3,44,41,8,17,21,23,10,43,12,34,24,28,33,13,46,11};
	cout << Solution::findDuplicate(nums) << endl;
	return 0;
}
#endif

