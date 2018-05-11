/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (35.08%)
 * Total Accepted:    242.6K
 * Total Submissions: 691.7K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
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
    static bool hasCycle(ListNode *head) {
		if (!head)
			return 0;
		ListNode *next=head;
		ListNode *nextnext=head->next;
		while (next && nextnext) {
			if (next==nextnext)
				return 1;
			if (!nextnext->next)
				return 0;
			next = next->next;
			nextnext = nextnext->next->next;
		}
		return 0;
    }
};

#ifdef TEST
int main()
{
    ListNode l1_3(4), l1_2=(2), l1_1=(1);
	l1_2.next = &l1_3; l1_1.next = &l1_2;
	cout << Solution::hasCycle(&l1_1) << endl;
	return 0;
}
#endif

