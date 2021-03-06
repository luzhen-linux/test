/*
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (34.12%)
 * Total Accepted:    86.5K
 * Total Submissions: 253.5K
 * Testcase Example:  '[]\n0'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position.
 * 
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 * 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 * 
 * Note: 
 * You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for
 * non-empty array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

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
    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ret;
		int sz_nums=nums.size();
		if (!sz_nums)
			return ret;
		int maxv=INT_MIN;
		for (int i=0; i<k; i++)
			maxv = max(maxv,nums[i]);
		ret.push_back(maxv);
		for (int i=k; i<sz_nums; i++) {
			if (maxv==nums[i-k]) {
				maxv = INT_MIN;
				for (int j=i-k+1; j<i; j++)
					maxv = max(maxv,nums[j]);
			}
			maxv = max(maxv,nums[i]);
			ret.push_back(maxv);
		}
		return ret;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums={1,3,-1,-3,5,3,6,7};
	vector<int> ret = Solution::maxSlidingWindow(nums,3);
	for (auto s:ret)
		cout << s << ", ";
	cout << endl;
	return 0;
}
#endif
