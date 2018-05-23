/*
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (37.41%)
 * Total Accepted:    50.7K
 * Total Submissions: 135.4K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * 
 * Example 1:
 * 
 * nums = [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 * 
 * 
 * Return 4
 * 
 * The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * nums = [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * 
 * 
 * 
 * 
 * Return 4
 * 
 * The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not
 * allowed.
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
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
    static int longestIncreasingPath(vector<vector<int>>& matrix,
			vector<vector<int>>&visited, int i, int j, int m, int n, int &maxval) {
		if (visited[i][j])
			return visited[i][j];
		int val = matrix[i][j];
		vector<int> ret(4); // up, right, down, left
		if (i>0 && val<matrix[i-1][j])
			ret[0] = longestIncreasingPath(matrix, visited, i-1, j, m, n, maxval);
		if (j<n-1 && val<matrix[i][j+1])
			ret[1] = longestIncreasingPath(matrix, visited, i, j+1, m, n, maxval);
		if (i<m-1 && val<matrix[i+1][j])
			ret[2] = longestIncreasingPath(matrix, visited, i+1, j, m, n, maxval);
		if (j>0 && val<matrix[i][j-1])
			ret[3] = longestIncreasingPath(matrix, visited, i, j-1, m, n, maxval);
		visited[i][j] = *max_element(ret.begin(), ret.end())+1;
		//printf("visited[%d][%d]=%d\n", i, j, visited[i][j]);
		maxval = max(visited[i][j], maxval);
		return visited[i][j];
	}
    static int longestIncreasingPath(vector<vector<int>>& matrix) {
		int row = matrix.size();
		if (!row)
			return 0;
		int col = matrix[0].size();
		vector<vector<int>> visited(row, vector<int>(col));
		int maxval=0;
		for (int i=0; i<row; i++)
			for (int j=0; j<col; j++)
				longestIncreasingPath(matrix, visited, i, j, row, col, maxval);
		return maxval;
    }
};

#ifdef TEST
int main()
{
	//vector<vector<int>> matrix{{9,9,4}, {6,6,8}, {2,1,1}};
	vector<vector<int>> matrix{{0},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12},{13},{14},{15},{16},{17},{18},{19}};
	cout << Solution::longestIncreasingPath(matrix) << endl;
	return 0;
}
#endif
