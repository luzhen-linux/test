/*
 * [454] 4Sum II
 *
 * https://leetcode.com/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (47.55%)
 * Total Accepted:    30.1K
 * Total Submissions: 63.3K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * Given four lists A, B, C, D of integer values, compute how many tuples (i,
 * j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 * 
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤
 * N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is
 * guaranteed to be at most 231 - 1.
 * 
 * Example:
 * 
 * Input:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 * 
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
	static int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> hash1, hash2;  
		int ans = 0;  
		for(int i = 0; i < A.size(); i++)  
			for(int j = 0; j < B.size(); j++)  
				hash1[A[i]+B[j]]++;  
		for(int i = 0; i < C.size(); i++)  
		{  
			for(int j = 0; j < D.size(); j++)  
				ans += hash1.count(-C[i] - D[j])? hash1[-C[i] - D[j]]: 0;  
		}  
		return ans;  
	}
};

#ifdef TEST
int main()
{
	vector<int> A = { 1, 2};
	vector<int> B = {-2,-1};
	vector<int> C = {-1, 2};
	vector<int> D = { 0, 2};
	cout << Solution::fourSumCount(A,B,C,D) << endl;
	return 0;
}
#endif
