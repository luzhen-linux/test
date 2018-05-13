/*
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (37.23%)
 * Total Accepted:    65.4K
 * Total Submissions: 175.6K
 * Testcase Example:  '[[]]'
 *
 * 
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 * 
 * 
 * 
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 * 
 * 
 * 
 * 
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 * 
 * 
 * 
 * 
 * Write a function to compute the next state (after one update) of the board
 * given its current state.
 * 
 * 
 * Follow up: 
 * 
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
#ifdef TEST
#include <unistd.h>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class Solution {
public:
	static int liveNeighbors(vector<vector<int>> &board, int x,
			int y, int row, int col) {
		int lives=-board[x][y];
		for (int i=x-1; i<=x+1; i++)
			for (int j=y-1; j<=y+1; j++) {
				if (i>=0&&i<row&&j>=0&&j<col)
					lives += board[i][j];
			}
		return lives;
	}
    static void gameOfLife(vector<vector<int>>& board) {
		int row=board.size();
		if (row==0)
			return;
		int col=board[0].size();
		vector<vector<int>> b{board};
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				int lives = liveNeighbors(b, i, j, row, col);
				if (b[i][j]) {
					if (lives<2 || lives>3)
						board[i][j] = 0;
					else
						board[i][j] = 1;
				}
				else if (lives==3)
						board[i][j] = 1;
			}
		}
		return;
    }
};

#ifdef TEST
int main()
{
	vector<vector<int>> board{{1,1,0,0,0,0}, {1,0,0,0,0,0},
		{0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}};
	for (;;) {
		Solution::gameOfLife(board);
		for (auto row:board) {
			for (auto col: row)
				cout << col << " ";
			cout << endl;
		}
		cout << endl;
		sleep(1);
	}
	return 0;
}
#endif

