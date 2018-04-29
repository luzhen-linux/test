/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (27.54%)
 * Total Accepted:    114.6K
 * Total Submissions: 416K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
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
	static int largestRectangleArea(vector<int>& heights) {
		int size=heights.size(), end=size-1, maxarea=0;
		int min=INT_MAX, pos=0;
		if (size<=0) return 0;
		if (size==1) return heights[0];
		for (int i=0; i<=end; i++)
			if (min>heights[i]) {
				pos = i;
				min = heights[i];
			}
		vector<int> subset;
		maxarea=size*min;
		subset.assign(heights.begin(), heights.begin()+pos);
		maxarea = max(maxarea, largestRectangleArea(subset));
		//printf("pos=%d, min=%d\n", pos, min);
		subset.assign(heights.begin()+pos+1, heights.end());
		maxarea = max(maxarea, largestRectangleArea(subset));
		//printf("end-pos=%d, min=%d\n", end-pos, min);
		return maxarea;
	}
};

#ifdef TEST
int main()
{
	//vector<int> heights = {2,1,5,6,2,3};
	//vector<int> heights = {1};
	//vector<int> heights = {0,0,0,0,0,0,0,0,2147483647};
	vector<int> heights = {2,0,1,0,1,0};
	cout << Solution::largestRectangleArea(heights) << endl;
	return 0;
}
#endif

