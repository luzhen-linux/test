/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals
 *
 * algorithms
 * Medium (31.17%)
 * Total Accepted:    166.2K
 * Total Submissions: 533.3K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 * 
 */
#ifdef TEST
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
#endif

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty()) return {};

		std::sort(intervals.begin(), intervals.end(),
				[](const Interval&a, const Interval&b){return a.start<b.start;});
        
		vector<Interval> ans;
		for (const auto &interval : intervals) {
			if (ans.empty() || interval.start > ans.back().end)
				ans.push_back(interval);
			else
				ans.back().end = max(ans.back().end, interval.end);
		}
		return ans;
    }
};

#ifdef TEST
int main()
{
	vector<Interval> nums={{1, 3}, {2,8}};
	Solution::merge(nums);
	return 0;
}
#endif

