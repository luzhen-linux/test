/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (27.21%)
 * Total Accepted:    137.5K
 * Total Submissions: 505.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * 
 * 
 * For example,
 * Given the following matrix:
 * 
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * 
 * You should return [1,2,3,6,9,8,7,4,5].
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class Solution {
public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		int m = matrix.size();
		if (!m) return ret;
		int n = matrix[0].size();
		if (!n) return ret;
		int i=0, x=0, y=0, dir=0;
		int count=0, total=n*m;
		int op[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
		do {
			ret.push_back(matrix[x][y]);
			if ((dir==0 || dir==2) && ++count==n) {
				dir = (dir+1)%4;
				count =0;
				m--;
			}
			else if ((dir==1||dir==3) && ++count==m) {
				dir = (dir+1)%4;
				n--;
				count =0;
			}
			
			x+=op[dir][0];
			y+=op[dir][1];
		} while (++i<total);
		return ret;
    }
};

#ifdef TEST
int main()
{
	//vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> matrix = {
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
		{10,11,12,13,14,15,16,17,18,19},
		{20,21,22,23,24,25,26,27,28,29},
		{30,31,32,33,34,35,36,37,38,39},
		{40,41,42,43,44,45,46,47,48,49},
		{50,51,52,53,54,55,56,57,58,59},
		{60,61,62,63,64,65,66,67,68,69},
		{70,71,72,73,74,75,76,77,78,79},
		{80,81,82,83,84,85,86,87,88,89},
		{90,91,92,93,94,95,96,97,98,99}
	};
	vector <int> ret = Solution::spiralOrder(matrix);
	for (auto i:matrix) {
		for (auto j:i)
			printf("%2d ", j);
		printf("\n");
	}
	printf("\n\n");
	for (auto i:ret)
		cout << i << ", ";
	cout << endl;
	return 0;
}
#endif
