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
#include <stack>

using namespace std;

#endif

#define SOLUTION2  1

class Solution {
public:
#ifdef SOLUTION1
	static int largestRectangleArea(vector<int>& heights, int start, int end) {
		int size=end-start+1, maxarea=0;
		int min=INT_MAX, pos=0;
		if (size<=0) return 0;
		if (size==1) return heights[start];
		vector<pair<int, int>> range;
		for (int i=start; i<=end; i++)
			if (min>heights[i]) {
				range.clear();
				pos = i;
				min = heights[i];
				if (i>start)
					range.push_back({start,i});
			}
			else if(min==heights[i]) {
				if (i>pos+1)
					range.push_back({pos+1,i});
				pos = i;
			}
		if (end > pos)
			range.push_back({pos+1,end+1});
		maxarea=size*min;
		for (auto r: range) {
			//printf("try between %d-%d\n", r.first, r.second);
			maxarea = max(maxarea, largestRectangleArea(heights, r.first, r.second-1));
		}
		//printf("end=%d, start=%d, min=%d, size=%d\n", end, start, min, size);
		return maxarea;
	}
	static int largestRectangleArea(vector<int>& heights) {
		return largestRectangleArea(heights, 0, heights.size()-1);
	}
#elif SOLUTION2
	static int largestRectangleArea(vector<int>& heights) {
		stack<int> area;
		heights.push_back(0);
		int result = 0;

		for (int i = 0; i < heights.size();) {
			if (area.empty() || heights[i] > heights[area.top()]) {
				area.push(i++);
			} else {
				int tmp = area.top();
				area.pop();
				result = max(result,
						heights[tmp] * (area.empty() ? i : i - area.top() - 1));
			}
		}
		return result;
	}
#endif
};

#ifdef TEST
int main()
{
	//vector<int> heights = {2,1,5,6,2,3};
	//vector<int> heights = {1};
	//vector<int> heights = {0,0,0,0,0,0,0,0,2147483647};
	//vector<int> heights = {2,0,1,0,1,0};
	vector<int> heights = {1,2,3,4,5};
	cout << Solution::largestRectangleArea(heights) << endl;
	return 0;
}
#endif

