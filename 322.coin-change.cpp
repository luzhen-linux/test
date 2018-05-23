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
#include <climits>

using namespace std;

#endif

class Solution {
public:
    static int coinChange(vector<int>& coins, int sz_coins, int used_coins, int &max_coins, int amount) {
		if (amount==0) {
			max_coins = min(max_coins, used_coins);
			return max_coins;
		}
		if (amount<0)
			return -1;
		if (sz_coins<=0)
			return 0;
		if (used_coins>=max_coins)
			return -2;
		int max_last=min(amount/coins[sz_coins-1], max_coins-used_coins);
		for (int i=max_last; i>=0; i--) {
			int ret = coinChange(coins, sz_coins-1, used_coins+i, max_coins, amount-i*coins[sz_coins-1]);
			if (ret<0)
				break;
		}
		return max_coins;
	}
    static int coinChange(vector<int>& coins, int amount) {
		int sz_coins=coins.size();
		if (!sz_coins)
			return -1;
		sort (coins.begin(), coins.end());
		int max_coins=INT_MAX;
		int ret = coinChange(coins, sz_coins, 0, max_coins, amount);
		return ret==INT_MAX?-1:max_coins;
    }
};

#ifdef TEST
int main()
{
	//vector<int> coins = {1, 2, 5}; int amount = 11;
	//vector<int> coins = {1}; int amount = 1;
	//vector<int> coins = {1,2,5,10}; int amount = 27;
	vector<int> coins = {139,442,147,461,244,225,28,378,371}; int amount = 9914;
    cout << Solution::coinChange(coins, amount) << endl;
	return 0;
}
#endif
