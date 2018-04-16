/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (31.88%)
 * Total Accepted:    190.1K
 * Total Submissions: 596.3K
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
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
#endif

class Solution {
public:
	static vector<Interval> merge(vector<Interval>& intervals) {
		int size = intervals.size();
		if (!size)
			return {};

		sort(intervals.begin(), intervals.end(),
				[](Interval &a, Interval &b){return a.start<b.start;});

		vector<Interval> ret;
		ret.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i].start <= ret.back().end)
				ret.back().end = max(ret.back().end, intervals[i].end);
			else
				ret.push_back(intervals[i]);
		}
		return ret;
	}
};

#ifdef TEST
int main()
{
	vector<Interval> nums={{1,3},{2,6},{8,10},{15,18}}, ret;
	ret = Solution::merge(nums);
	for (auto c: ret)
		cout << "start: " << c.start << " end: " << c.end << endl;
	return 0;
}
#endif
