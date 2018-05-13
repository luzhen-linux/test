/*
 * [237] Delete Node in a Linked List
 *
 * https://leetcode.com/problems/delete-node-in-a-linked-list/description/
 *
 * algorithms
 * Easy (47.22%)
 * Total Accepted:    199.7K
 * Total Submissions: 423K
 * Testcase Example:  '[0,1]\nnode at index 0 (node.val = 0)'
 *
 * 
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node.
 * 
 * 
 * 
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third
 * node with value 3, the linked list should become 1 -> 2 -> 4 after calling
 * your function.
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    static void deleteNode(ListNode* node) {
		ListNode *prev=NULL;
		while (node) {
			ListNode *next=node->next;
			if (next)
				node->val = next->val;
			else if (prev)
				prev->next =NULL;
			prev = node;
			node = next;
		}
		return;
    }
};

#ifdef TEST
int main()
{
    ListNode l1_3(4), l1_2=(2), l1_1=(1);
    ListNode l2_3(4), l2_2=(3), l2_1=(1);
	l1_2.next = &l1_3; l1_1.next = &l1_2; l1_3.next = &l2_1;
	l2_2.next = &l2_3; l2_1.next = &l2_2;
	Solution::deleteNode(&l2_1);
	ListNode *ret = &l1_1;
	while (ret) {
		cout << ret->val;
		ret = ret->next;
		if (ret)
			cout << "->";
	}
	cout << endl;
	return 0;
}
#endif
