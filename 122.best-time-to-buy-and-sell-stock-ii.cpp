/*
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (47.75%)
 * Total Accepted:    196.3K
 * Total Submissions: 411.2K
 * Testcase Example:  '[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times). However, you may not engage in multiple transactions at the
 * same time (ie, you must sell the stock before you buy again).
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
    static int maxProfit(vector<int>& prices) {
		int profit=0, prev=INT_MAX;
		for (auto i:prices) {
			if (i>prev)
				profit += i-prev;
			prev = i;
		}
		return profit;
    }
};

#ifdef TEST
int main()
{
	vector<vector<int>> input = {
		{7, 1, 5, 3, 6, 4},
		{7, 6, 4, 3, 1},
	};
	for (auto i:input)
		cout << Solution::maxProfit(i) << endl;
	return 0;
}
#endif
