/*
 * [134] Gas Station
 *
 * https://leetcode.com/problems/gas-station/description/
 *
 * algorithms
 * Medium (29.97%)
 * Total Accepted:    101.3K
 * Total Submissions: 338K
 * Testcase Example:  '[4]\n[5]'
 *
 * 
 * There are N gas stations along a circular route, where the amount of gas at
 * station i is gas[i].
 * 
 * 
 * 
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from station i to its next station (i+1). You begin the journey with
 * an empty tank at one of the gas stations.
 * 
 * 
 * 
 * Return the starting gas station's index if you can travel around the circuit
 * once, otherwise return -1.
 * 
 * 
 * 
 * Note:
 * The solution is guaranteed to be unique.
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
    static int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
    }
};

#ifdef TEST
int main()
{
	vector<int> gas{4};
	vector<int> cost{5};
	cout << Solution::canCompleteCircuit(gas, cost) << endl;
	return 0;
}
#endif
