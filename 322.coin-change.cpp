/*
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (26.58%)
 * Total Accepted:    90.3K
 * Total Submissions: 339.6K
 * Testcase Example:  '[1]\n0'
 *
 * 
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * 
 * 
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * 
 * 
 * 
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 * 
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
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
    static int coinChange(vector<int>& coins, int amount) {
    }
};

#ifdef TEST
int main()
{
	vector<int> coins = {1, 2, 5};
	int amount = 11;
    cout << Solution::coinChange(coins, amount) << endl;
	return 0;
}
#endif
