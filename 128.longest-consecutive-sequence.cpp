/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (38.18%)
 * Total Accepted:    136.6K
 * Total Submissions: 357.8K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * 
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its
 * length: 4.
 * 
 * 
 * Your algorithm should run in O(n) complexity.
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
    static int longestConsecutive(vector<int>& nums) {
		int sz_nums=nums.size(), maxcont=0;
		unordered_map <int, int> map;
		for (int i=0; i<sz_nums; i++) {
			int num = nums[i], cont;
			if (map[num])
				continue;
			cont = map[num] = map[num-1]+1;
			//printf("map[%d]=%d\n", num, map[num]);
			if (map[num+1]) {
				while(map[++num]) {
					cont++;
				}
				map[num-1] = cont;
				//printf("map[%d]=%d, %d\n", num-1, map[num-1], cont);
			}
			maxcont = max(maxcont, cont);
		}
		return maxcont;
    }
};

#ifdef TEST
int main()
{
	//vector<int> nums = {100, 4, 200, 1, 3, 2};
	vector<int> nums = {1,3,5,2,4};
	cout << Solution::longestConsecutive(nums) << endl;
	return 0;
}
#endif
