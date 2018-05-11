/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.88%)
 * Total Accepted:    150.5K
 * Total Submissions: 581.4K
 * Testcase Example:  '{}'
 *
 * 
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * 
 * 
 * Return a deep copy of the list.
 * 
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
#endif

class Solution {
public:
    static RandomListNode *copyRandomList(RandomListNode *head) {
		map<RandomListNode*, RandomListNode*> map;
		RandomListNode *tmp;
		for (RandomListNode *node=head; node; node=node->next) {
			tmp = new RandomListNode(node->label);
			if (!tmp)
				return NULL;
			map[node] = tmp;
		}
		for (RandomListNode *node=head; node; node=node->next) {
			tmp = map[node];
			tmp->next = map[node->next];
			tmp->random = map[node->random];
		}
		return map[head];
    }
};

#ifdef TEST
int main()
{
	vector<RandomListNode> node{3,4,5};
	node[0].next = &node[1];
	node[0].random = &node[2];
	node[1].next = &node[2];
	node[1].random = &node[0];
	node[2].random = &node[1];
	RandomListNode *ret = Solution::copyRandomList(&node[0]);
	while (ret) {
		cout << ret->label << endl;
		ret = ret->next;
	}
	return 0;
}
#endif
