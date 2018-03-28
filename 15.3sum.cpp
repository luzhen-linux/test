/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.80%)
 * Total Accepted:    307.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#endif
#define SOLUTION2   1
class Solution {
public:
	static vector<vector<int>> threeSum(vector<int>& num) {

#ifdef SOLUTION1
		vector< vector<int> > result;

		//sort the array, this is the key
		sort(num.begin(), num.end());

		int n = num.size();
		for (int i=0; num[i]<0; i++) {
			//skip the duplication
			if (i>0 && num[i-1]==num[i]) continue;
			int a = num[i];
			int low = i+1;
			int high = n-1;
			while ( low < high ) {
				int b = num[low];
				int c = num[high];
				if (a+b+c == 0) {
					//got the soultion
					vector<int> v;
					v.push_back(a);
					v.push_back(b);
					v.push_back(c);
					result.push_back(v);
					// Continue search for all triplet combinations summing to zero.
					//skip the duplication
					while(low<n-1 && num[low]==num[low+1]) low++; 
					while(high>0 && num[high]==num[high-1]) high--; 
					low++;
					high--;
				} else if (a+b+c > 0) {
					//skip the duplication
					while(high>0 && num[high]==num[high-1]) high--;
					high--;
				} else{
					//skip the duplication
					while(low<n-1 && num[low]==num[low+1]) low++;
					low++;
				} 
			}
		}
		return result;
#elif SOLUTION2
		vector<vector<int>> ret;
		int n = num.size(), a, start, end;
		std::sort(num.begin(), num.end());
		for (int i=0; i<n-2; i++) {
			if (i>0 && num[i]==num[i-1]) continue;
			a = num[i];
			if (a>0) return ret;
			start = i+1;
			end = n-1;
			while (start < end) {
				int b = num[start];
				int c = num[end];
				if (a+b+c==0) {
					ret.push_back({a,b,c});
					while (start<n-1 && num[start]==num[start+1]) start++; start++;
					while (end>0 && num[end-1]==num[end]) end--; end--;
				}
				else if (a+b+c>0) {
					while (end>0 && num[end-1]==num[end]) end--; end--;
				}
				else {
					while (start<n-1 && num[start]==num[start+1]) start++; start++;
				}
			}
		}
		return ret;
#endif
	}
};

#ifdef TEST
int main()
{
	vector<int> nums = {1,-1,-1,0};
	vector<vector<int>> ret = Solution::threeSum(nums);
	int j=0;
	for (auto one: ret) {
		cout << j++ << ": ";
		for (auto h: one)
			cout << h << ", ";
		cout << endl;
	}
	return 0;
}
#endif
