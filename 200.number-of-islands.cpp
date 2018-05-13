/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (36.52%)
 * Total Accepted:    166.7K
 * Total Submissions: 456.5K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 11110110101100000000
 * Answer: 1
 * Example 2:
 * 11000110000010000011
 * Answer: 3
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

#define SOLUTION2 1
//#define DEBUG 1

class Solution {
public:
	static int dfs(vector<vector<char>>&grid, int i, int m, int j, int n)
	{
		if (i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')
			return 0;
		grid[i][j] = '0';
		dfs(grid, i-1, m, j, n);
		dfs(grid, i+1, m, j, n);
		dfs(grid, i, m, j-1, n);
		dfs(grid, i, m, j+1, n);
		return 0;
	}
    static int numIslands(vector<vector<char>>& grid) {
#if SOLUTION1
		int row=grid.size();
		if (!row)
			return 0;
		int col=grid[0].size();
		vector<vector<int>> num(row, vector<int>(col));
		set<int> nums;
		int numisland=1;
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				if (grid[i][j]=='1') {
					if (j>0 && num[i][j-1]) 
						num[i][j] = num[i][j-1];
					if (i>0 && num[i-1][j]) {
						if (!num[i][j])
							num[i][j] = num[i-1][j];
						else if (num[i][j]<num[i-1][j]) {
							nums.erase(num[i-1][j]);
						}
						else if (num[i][j]>num[i-1][j]) {
							nums.erase(num[i][j]);
							int tmp = num[i][j], jj=j;
							while (jj>=0 && num[i][jj]==tmp)
							   num[i][jj--] = num[i-1][j];
						}
					}
					if (!num[i][j]) {
						nums.insert(numisland);
						num[i][j] = numisland++;
					}
				}
			}
		}
		return nums.size(); 
#elif SOLUTION2
		int row=grid.size();
		if (!row)
			return 0;
		int col=grid[0].size();
		int numisland=0;
		for (int i=0; i<row; i++)
			for (int j=0; j<col; j++)
				if (grid[i][j]=='1') {
					numisland++;
					dfs(grid, i, row, j, col);
				}
		return numisland;
#endif
    }
};

#ifdef TEST
int main()
{
	//vector<vector<char>> grid{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
	//vector<vector<char>> grid{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
	//vector<vector<char>> grid{{'1','1','1'},{'0','1','0'},{'1','1','1'}};
	//vector<vector<char>> grid{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
	//vector<vector<char>> grid{ {'1','1','1','1','1','1','1','1','1'}, {'1','0','0','0','0','0','0','0','1'}, {'1','0','1','0','1','0','1','0','1'}, {'1','0','1','1','1','1','1','0','1'}, {'1','0','1','0','1','0','1','0','1'}, {'1','0','0','0','0','0','0','0','1'}, {'1','1','1','1','1','1','1','1','1'}};
	vector<vector<char>> grid{
		//    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19
			{'1','0','1','1','0','0','1','0','1','1','1','1','0','1','0','1','1','1','1','0'}, //6
			{'0','1','0','0','1','0','1','0','1','1','1','1','1','1','0','1','1','0','1','1'}, //7
			{'1','0','0','1','0','1','0','1','0','1','1','0','1','1','1','0','0','1','1','0'}, //11
			{'0','1','1','0','0','1','1','0','1','1','1','1','0','0','1','0','0','0','1','1'}, //12
			{'1','1','0','1','0','0','1','0','0','0','1','0','1','0','1','1','1','0','1','1'}, //14
			{'0','0','0','0','1','0','1','1','0','0','1','0','0','1','0','1','1','1','1','0'}, //15
			{'1','0','1','1','1','1','0','1','1','0','1','1','0','1','1','1','0','0','1','0'}, //15
			{'0','1','1','0','0','0','1','0','0','1','0','1','1','1','0','0','1','1','0','1'}, //18
			{'0','0','0','0','1','1','0','1','0','0','1','1','0','1','0','0','1','0','1','0'}, //21
			{'0','0','1','1','1','0','1','0','1','0','1','1','1','0','1','1','1','1','1','0'}, //21
			{'1','0','1','0','1','1','1','0','1','1','1','0','1','0','1','0','1','0','1','1'}, //20
			{'0','0','1','1','1','1','0','1','1','1','0','1','0','0','0','1','1','1','0','1'}, //21
			{'1','1','1','0','0','0','0','0','1','1','0','1','1','1','0','1','1','1','1','0'}, //21
			{'0','0','1','1','1','0','0','1','0','0','1','1','1','1','1','1','0','1','1','0'}, //21
			{'0','0','0','1','1','0','0','0','0','1','1','0','1','0','0','1','1','1','1','1'}, //21
			{'0','1','1','1','0','1','0','0','1','1','1','1','1','0','1','1','1','0','0','1'}, //22
			{'0','0','0','0','1','1','1','1','0','0','0','0','1','0','0','0','0','1','1','0'}, //23
			{'1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1','1','1'}, //23
			{'0','1','0','0','1','0','0','1','1','1','1','1','1','0','1','0','1','1','1','1'}, //23
			{'0','0','1','1','1','1','1','0','0','0','1','1','1','1','1','1','0','1','1','0'}}; //23
	cout << Solution::numIslands(grid) << endl;
	return 0;
}
#endif
