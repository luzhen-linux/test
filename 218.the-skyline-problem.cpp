/*
 * [218] The Skyline Problem
 *
 * https://leetcode.com/problems/the-skyline-problem/description/
 *
 * algorithms
 * Hard (28.96%)
 * Total Accepted:    59.6K
 * Total Submissions: 205.7K
 * Testcase Example:  '[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]'
 *
 * A city's skyline is the outer contour of the silhouette formed by all the
 * buildings in that city when viewed from a distance. Now suppose you are
 * given the locations and height of all the buildings as shown on a cityscape
 * photo (Figure A), write a program to output the skyline formed by these
 * buildings collectively (Figure B).
 * 
 * 
 * 
 * ⁠   
 * 
 * 
 * 
 * 
 * ⁠   
 * 
 * 
 * 
 * 
 * 
 * The geometric information of each building is represented by a triplet of
 * integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and
 * right edge of the ith building, respectively, and Hi is its height. It is
 * guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You
 * may assume all buildings are perfect rectangles grounded on an absolutely
 * flat surface at height 0.
 * 
 * For instance, the dimensions of all buildings in Figure A are recorded as: [
 * [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
 * 
 * The output is a list of "key points" (red dots in Figure B) in the format of
 * [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key
 * point is the left endpoint of a horizontal line segment. Note that the last
 * key point, where the rightmost building ends, is merely used to mark the
 * termination of the skyline, and always has zero height. Also, the ground in
 * between any two adjacent buildings should be considered part of the skyline
 * contour.
 * 
 * For instance, the skyline in Figure B should be represented as:[ [2 10], [3
 * 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
 * 
 * Notes:
 * 
 * ⁠The number of buildings in any input list is guaranteed to be in the range
 * [0, 10000].
 * ⁠The input list is already sorted in ascending order by the left x position
 * Li. 
 * ⁠The output list must be sorted by the x position. 
 * ⁠There must be no consecutive horizontal lines of equal height in the output
 * skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not
 * acceptable; the three lines of height 5 should be merged into one in the
 * final output as such: [...[2 3], [4 5], [12 7], ...]
 * 
 * 
 * 
 * Credits:Special thanks to @stellari for adding this problem, creating these
 * two awesome images and all test cases.
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#endif

class Solution {
public:
    static vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int,int>> ret;
		vector<vector<int>> &b=buildings;
		if (b.empty())
			return ret;
		int maxnum=0;
		for (auto one:b)
			maxnum = max(maxnum, one[1]);
		set<int> pos;
		map<int, int> height;
		map<int, int>::iterator it;
		for (auto dim:b) {
			//printf("===%d,%d,%d===\n", dim[0], dim[1], dim[2]);
			pos.insert(dim[0]);
			pos.insert(dim[1]);
			it = height.upper_bound(dim[0]);
			if (it==height.end()) {
				height[dim[0]] = dim[2];
				height[dim[1]] = 0;
				continue;
			}
			--it;
			int prevh=it->second;
			if (it->second<dim[2]) {
				height[dim[0]] = dim[2];
				++it;
			}
			for (++it; it!=height.end() && it->first<dim[1]; ++it ) {
				prevh = it->second;
				if (it->second<dim[2]) 
					it->second = dim[2];
			}
			if (it==height.end())
				height[dim[1]] = 0;
			else if (it->first==dim[1]) 
				height[dim[1]] = it->second;
			else
				height[dim[1]] = prevh;
		}
		int prev=0;
		for (auto one: pos) {
			int h;
			if (height.find(one)!=height.end())
				h = height[one];
			else {
				it = height.upper_bound(one);
				--it;
				h = it->second;
			}
			if (h!=prev)
				ret.push_back({one, h});
			prev = h;
		}
		return ret;
    }
};

#ifdef TEST
int main()
{
	vector<vector<int>> buildings{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
	//vector<vector<int>> buildings{{2,13,10},{10,17,25},{12,20,14}};
	//vector<vector<int>> buildings{{2,13,10},{2,12,9}};
	//vector<vector<int>> buildings{{1,2,1},{1,2,2},{1,2,3}};
	//vector<vector<int>> buildings{{2,4,70},{3,8,30},{6,100,41},{7,15,70},{10,30,102},{15,25,76},{60,80,91},{70,90,72},{85,120,59}};
	//vector<vector<int>> buildings{{6765,184288,53874},{13769,607194,451649},{43325,568099,982005},{47356,933141,123943},{59810,561434,119381},{75382,594625,738524},{111895,617442,587304},{143767,869128,471633},{195676,285251,107127},{218793,772827,229219},{316837,802148,899966},{329669,790525,416754},{364886,882642,535852},{368825,651379,6209},{382318,992082,300642},{397203,478094,436894},{436174,442141,612149},{502967,704582,918199},{503084,561197,625737},{533311,958802,705998},{565945,674881,149834},{615397,704261,746064},{624917,909316,831007},{788731,924868,633726},{791965,912123,438310}};
    vector<pair<int, int>> ret = Solution::getSkyline(buildings);
	for (auto c:ret)
		printf("[%d,%d]\n", c.first, c.second);
	return 0;
}
#endif
