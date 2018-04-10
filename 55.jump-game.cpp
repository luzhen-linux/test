/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (29.52%)
 * Total Accepted:    160K
 * Total Submissions: 541.9K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * 
 * Each element in the array represents your maximum jump length at that
 * position. 
 * 
 * 
 * Determine if you are able to reach the last index.
 * 
 * 
 * 
 * For example:
 * A = [2,3,1,1,4], return true.
 * 
 * 
 * A = [3,2,1,0,4], return false.
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
    static bool canJump(vector<int>& nums) {
        
    }
};

#ifdef TEST
int main()
{
	vector<int> nums = {2,3,1,1,4};
	//vector<int> nums = {3,2,1,0,4};
	cout << Solution::canJump(nums) << endl;
	return 0;
}
#endif

