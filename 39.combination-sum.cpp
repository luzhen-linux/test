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
		static int addNumber (vector<int> &can, vector<int> num, int remain, vector<vector<int>> &ret) {
			int sz_num = num.size();
			if (remain==0) {
				vector<int> tmp;
				for (int i=0; i<sz_num; i++) {
					for (int j=0; j<num[i]; j++)
						tmp.push_back(can[i]);
				}
				ret.push_back(tmp);
				return 0;
			}
			if (remain>=can[sz_num-1]) {
				num[sz_num-1]++;
				addNumber(can, num, remain-can[sz_num-1], ret);
				num[sz_num-1]--;
			}
			else
				return 2;
			if (sz_num<can.size()) {
				num.push_back(0);
				addNumber(can, num, remain, ret);
			}
			return 1;
		}
		static vector<vector<int>> combinationSum(vector<int>& can, int target) {
			vector<vector<int>> ret;
			if (can.size()==0)
				return ret;
			vector<int> num = {0};
			sort(can.begin(), can.end());
			addNumber(can, num, target, ret);
			return ret;
		}
};

#ifdef TEST
int main()
{
	vector<int> candidates={8,7,4,3};
	int target=11;
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
