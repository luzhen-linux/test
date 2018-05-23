/*
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (47.32%)
 * Total Accepted:    40.3K
 * Total Submissions: 85.2K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 * 
 * 
 * Example:
 * 
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 * 
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * 
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
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

#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class Solution {
	public:
		Solution(vector<int> nums):vec(nums) {
		}

		/** Resets the array to its original configuration and return it. */
		vector<int> reset() {
			return vec;
		}

		/** Returns a random shuffling of the array. */
		vector<int> shuffle() {  
			if(vec.size()==0) return {};  
			vector<int> tem(vec);  
			int len = vec.size();  
			for(int i = 0; i < len; i++)  
			{  
				int pos = rand()%(len-i);  
				swap(tem[i+pos], tem[i]);  
			}  
			return tem;  
		}  
	private:  
		vector<int> vec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

#ifdef TEST
int main()
{
	// Init an array with set 1, 2, and 3.
	vector<int> nums {1,2,3};
	Solution *solution = new Solution(nums);

	// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
	solution->shuffle();

	// Resets the array back to its original configuration [1,2,3].
	solution->reset();

	// Returns the random shuffling of array [1,2,3].
	solution->shuffle();
	return 0;
}
#endif
