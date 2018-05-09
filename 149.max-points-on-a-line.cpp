/*
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (15.19%)
 * Total Accepted:    91.4K
 * Total Submissions: 601.8K
 * Testcase Example:  '[]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
#endif

class Solution {
public:

    static int maxPoints(vector<Point>& points) {
        
    }
};

#ifdef TEST
int main()
{
	vector<Point> points{{1,1}, {2,2}, {3,3}, {2,4}};
	cout << Solution::maxPoints(points) << endl;
	return 0;
}
#endif
