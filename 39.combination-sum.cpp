/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (41.25%)
 * Total Accepted:    211.6K
 * Total Submissions: 513K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T. 
 * 
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * 
 * [
 * ⁠ [7],
 * ⁠ [2, 2, 3]
 * ]
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
    static vector<vector<int>> combinationSum(vector<int>& can, int target) {
		vector<vector<int>> ret;
		std::sort(can.begin(), can.end());
		ret.push_back(can);
		return ret;
    }
};

#ifdef TEST
int main()
{
	vector<int> candidates={2, 3, 6, 7};
	int target=7;
    vector<vector<int>> ret;
	ret = Solution::combinationSum(candidates, target);
	for (auto one:ret) {
		for (auto i:one)
			cout << i << ", ";
		cout << endl;
	}
	return 0;
}
#endif
