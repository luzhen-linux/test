/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (49.58%)
 * Total Accepted:    99.1K
 * Total Submissions: 199.9K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * 
 * 
 * Note: 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
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
    static vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> count;
		for (auto n: nums)
			count[n]++;
		vector<pair<int,int>> res;
		for (auto one:count) 
			res.push_back({one.first,one.second});
		sort(res.begin(), res.end(), [](pair<int,int> i, pair<int,int> j){return i.second>j.second;});
		vector<int> ret;
		for (int i=0; i<k; i++)
			ret.push_back(res[i].first);
		return ret;
    }
};

#ifdef TEST
int main()
{
	vector<int> nums={1,1,1,2,2,3};
	int k = 2;
	vector<int> ret = Solution::topKFrequent(nums, k);
	for (auto i:ret)
		cout << i << ", ";
	cout << endl;
	return 0;
}
#endif
