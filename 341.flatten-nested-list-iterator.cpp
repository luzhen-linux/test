/*
 * [341] Flatten Nested List Iterator
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator/description/
 *
 * algorithms
 * Medium (43.12%)
 * Total Accepted:    61K
 * Total Submissions: 141.4K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 * 
 * By calling next repeatedly until hasNext returns false, the order of
 * elements returned by next should be: [1,1,2,1,1].
 * 
 * 
 * 
 * Example 2:
 * Given the list [1,[4,[6]]],
 * 
 * By calling next repeatedly until hasNext returns false, the order of
 * elements returned by next should be: [1,4,6].
 * 
 * 
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class NestedInteger {
	private:
		vector<int> list;
	public:
		NestedInteger(int nlist) {
			list.push_back(nlist);
		}
		NestedInteger(vector<int> nlist) {
			list = nlist;
		}
		// Return true if this NestedInteger holds a single integer, rather than a nested list.
		bool isInteger() const;

		// Return the single integer that this NestedInteger holds, if it holds a single integer
		// The result is undefined if this NestedInteger holds a nested list
		int getInteger() const;

		// Return the nested list that this NestedInteger holds, if it holds a nested list
		// The result is undefined if this NestedInteger holds a single integer
		const vector<NestedInteger> &getList() const;
};
#endif

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        
    }

    int next() {
        
    }

    bool hasNext() {
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

#ifdef TEST
int main()
{
	vector<NestedInteger> nestedList; //={{1,1}, 2, {1,1}};
	NestedIterator i(nestedList);
	while (i.hasNext()) cout << i.next();
	return 0;
}
#endif
