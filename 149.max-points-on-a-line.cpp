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
#include <set>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
#endif

#define EQU(f1,f2) ((f1>f2-0.000001)&&(f1<f2+0.000001))
#define SAME(f1,f2) (f1.x==f2.x&&f1.y==f2.y)

class Solution {
public:
	static int gcd(int m, int n)
	{
		return n==0?m:gcd(n,m%n);
	}

    static int maxPoints(vector<Point>& points) {
		int maxnum=2;
		int sz_points = points.size();
		if (sz_points<1)
			return 0;
		if (sz_points<2)
			return 1;
		struct {
			int x;
			int y;
		} d[sz_points][sz_points]={};
		for (int i=0; i<sz_points; i++) {
			for (int j=i+1; j<sz_points; j++) {
				int x = points[j].x-points[i].x;
				int y = points[j].y-points[i].y;
				if (x==0)
					y=1;
				else if (y==0)
					x=1;
				else {
					int g = gcd(x,y);
					x /= g;
					y /= g;
				}
				d[i][j] = d[j][i] = {x,y};
				//printf("d[%d][%d] = %d,%d\n", i, j, x,y);
			}
		}
		map<pair<int,int>, int> count;
		for (int i=0; i<sz_points-maxnum; i++) {
			int tmpmax=1, dup=0;
			count.clear();
			for (int j=i+1; j<sz_points; j++) {
				if (SAME(points[i], points[j])) {
					dup++;
					continue;
				}
				tmpmax = max(tmpmax, ++count[{d[i][j].x, d[i][j].y}]+1);
			}
			maxnum = max(maxnum, tmpmax+dup);
		}
		return maxnum;
    }
};

#ifdef TEST
int main()
{
	//vector<Point> points{{1,3}, {1,1}, {2,2}, {3,3}, {2,4}};
	//vector<Point> points{{0,0},{65536,65536},{65536,131072}};
	//vector<Point> points{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
	//vector<Point> points{{-4,1},{-7,7},{-1,5},{9,-25}};
	vector<Point> points{{0,9},{138,429},{115,359},{115,359},{-30,-102},{230,709},{-150,-686},{-135,-613},{-60,-248},{-161,-481},{207,639},{23,79},{-230,-691},{-115,-341},{92,289},{60,336},{-105,-467},{135,701},{-90,-394},{-184,-551},{150,774}};
	cout << Solution::maxPoints(points) << endl;
	return 0;
}
#endif
