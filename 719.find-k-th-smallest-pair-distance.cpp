/*
 * [719] Find K-th Smallest Pair Distance
 *
 * https://leetcode.com/problems/find-k-th-smallest-pair-distance
 *
 * algorithms
 * Hard (26.26%)
 * Total Accepted:    3.3K
 * Total Submissions: 12.4K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * Given an integer array, return the k-th smallest distance among all the
 * pairs. The distance of a pair (A, B) is defined as the absolute difference
 * between A and B. 
 * 
 * Example 1:
 * 
 * Input:
 * nums = [1,3,1]
 * k = 1
 * Output: 0 
 * Explanation:
 * Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 * 
 * 
 * 
 * Note:
 * 
 * 2 <= len(nums) <= 10000.
 * 0 <= nums[i] < 1000000.
 * 1 <= k <= len(nums) * (len(nums) - 1) / 2.
 * 
 * 
 */
/*
 * [719] Find K-th Smallest Pair Distance
 *
 * https://leetcode.com/problems/find-k-th-smallest-pair-distance
 *
 * algorithms
 * Hard (24.46%)
 * Total Accepted:    3.2K
 * Total Submissions: 12.1K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * Given an integer array, return the k-th smallest distance among all the
 * pairs. The distance of a pair (A, B) is defined as the absolute difference
 * between A and B. 
 * 
 * Example 1:
 * 
 * Input:
 * nums = [1,3,1]
 * k = 1
 * Output: 0 
 * Explanation:
 * Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 * 
 * 
 * 
 * Note:
 * 
 * 2 <= len(nums) <= 10000.
 * 0 <= nums[i] < 1000000.
 * 1 <= k <= len(nums) * (len(nums) - 1) / 2.
 * 
 * 
 */
#ifdef TEST
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class Solution {
public:
	static int smallestDistancePair(vector<int>& nums, int k) {
		std::sort (nums.begin(), nums.end());
		const int n = nums.size();
		int r = nums.back() - nums.front();
		int l = 0;
		while (l<=r) {
			int m = l+(r-l)/2;
			int count = 0, j=0;
			for (int i=0; i<n; ++i) {
				while (j<n && nums[j]-nums[i]<=m) ++j;
				count += j-i-1;
			}
			count >= k?r=m-1:l=m+1;
			/*
			if (count<k)
				l=m+1;
			else if (count>k)
				r=m-1;
			else
				return m;
				*/
		}
		return l;

	}
};
#ifdef TEST
int main()
{
	vector<int> nums={1,3,1};
	int k=1, r;
	r = Solution::smallestDistancePair(nums, k);
	cout << r << endl;
	return 0;
}
#endif


