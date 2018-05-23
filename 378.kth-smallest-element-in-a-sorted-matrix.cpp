/*
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (45.49%)
 * Total Accepted:    57.6K
 * Total Submissions: 126.6K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n2.
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
    static int kthSmallest(vector<vector<int>>& matrix, int k) {
		/*
		int row=martrix.size();
		if (!row)
			return 0;
		if col=matrix[0].size();
		int curidx=0, count=1;
		vector<int> next(row);
		row[0] = 1;
		for (int i=0; i<row; i++) {
			if (curidx
		}
		*/
		int n = matrix.size(), left=matrix[0][0], right=matrix[n-1][n-1];  
		while(left < right)  
		{  
			long mid = (left+right)/2, num = 0;  
			for(int i = 0; i < n; i++)  
			{  
				auto it = upper_bound(matrix[i].begin(), matrix[i].end(), mid);  
				num += it - matrix[i].begin();  
			}  
			if(num < k) left = mid+1;  
			else right = mid;  
		}  
		return left;  
    }
};

#ifdef TEST
int main()
{
	vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,13,15}};
	cout << Solution::kthSmallest(matrix, 8) << endl;
	return 0;
}
#endif
