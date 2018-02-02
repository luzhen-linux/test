/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum
 *
 * algorithms
 * Easy (35.95%)
 * Total Accepted:    684.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
#define SOLUTION2 1

template <typename T>
vector<int> sort_indexes(const vector<T> &v) {

	// initialize original index locations
	vector<int> idx(v.size());
	iota(idx.begin(), idx.end(), 0);

	// sort indexes based on comparing values in v
	sort(idx.begin(), idx.end(),
			[&v](int i1, int i2) {return v[i1] < v[i2];});

	return idx;
}

class Solution {
	public:
		static vector<int> twoSum (vector<int> &nums, int target) {
#ifdef SOLUTION1
			vector<int> index = sort_indexes(nums);
			sort (nums.begin(), nums.end());
			int size = nums.size();
			int l, h, m;
			for (int i=0; i<size; ++i) {
				l = i+1;
				h = size-1;
				m = (l+h)/2;
				while (l<=h) {
					if (nums[i]+nums[m]<target)
						l = m+1;
					else if (nums[i]+nums[m]>target)
						h = m-1;
					else {
						return {index[i], index[m]};
					}
					m = (l+h)/2;
				}
			}
			return {};
#elif SOLUTION2
			unordered_map <int, int> lookup;
			for (int i=0; i<nums.size(); ++i) {
				if (lookup.count(target-nums[i]))
					return {lookup[target-nums[i]], i};
				lookup[nums[i]] = i;
			}
			return {};
#elif SOLUTION3
			map <int, int> m;
			int size = nums.size();
			for (int i=0; i<size; ++i) {
				int other = target-nums[i];
				if (m.find(other)!=m.end()) {
					return {m[other], i};
				}
				m[nums[i]] = i;
			}
			return {};
#endif
		}
};

#ifdef TEST
int main()
{
	vector<int> nums={3, 3};
	int target = 6;
	vector<int> ret = Solution::twoSum(nums, target);
	for (auto c: ret)
		cout << c << endl;
	return 0;
}
#endif

