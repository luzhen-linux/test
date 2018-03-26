/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (37.06%)
 * Total Accepted:    189.4K
 * Total Submissions: 510.9K
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */
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
    static int maxArea(vector<int>& height) {
		int maxarea=0;
		int size = height.size();
		int l=0, r=size-1;
		while (l<r) {
			int hl=height[l], hr=height[r], width=r-l, shortline;
			if (hl>hr) {
				while (height[--r]<hr && r>=0);
				shortline = hr;
			}
			else {
				while (height[++l]<hl && l<size);
				shortline = hl;
			}
			maxarea = max(maxarea, shortline*width);
		}
		return maxarea;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums={1,2,3,4,5,4,3,2,1};
	cout << Solution::maxArea(nums) << endl;
	return 0;
}
#endif
