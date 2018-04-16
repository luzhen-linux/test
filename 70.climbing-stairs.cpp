/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (41.14%)
 * Total Accepted:    239.9K
 * Total Submissions: 583K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * 
 * Note: Given n will be a positive integer.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 2
 * Output:  2
 * Explanation:  There are two ways to climb to the top.
 * 
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 3
 * Output:  3
 * Explanation:  There are three ways to climb to the top.
 * 
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
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
    static int climbStairs(int n) {
		static int ways[1000] = {1,1};
		if (ways[n]) return ways[n];
		ways[n] = climbStairs(n-1)+climbStairs(n-2);
		return ways[n];
    }
};

#ifdef TEST
int main()
{
	cout << Solution::climbStairs(38) << endl;
	return 0;
}
#endif

