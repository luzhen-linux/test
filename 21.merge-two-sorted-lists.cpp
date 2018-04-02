/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (40.93%)
 * Total Accepted:    329.4K
 * Total Submissions: 804.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
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
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head, *prev;
		if (!l1) return l2;
		if (!l2) return l1;
		if (l1->val>l2->val) {
			prev = head = l2;
			l2 = l2->next;
		}
		else {
			prev = head = l1;
			l1 = l1->next;
		}
		while (l1&&l2) {
			ListNode *next;
			if (l1->val>l2->val) {
				next = l2;
				l2 = l2->next;
			}
			else {
				next = l1;
				l1 = l1->next;
			}
			prev->next = next;
			prev = next;
		}
		if (l1)
			prev->next = l1;
		if (l2)
			prev->next = l2;
		return head;
    }
};

#ifdef TEST
int main()
{
    ListNode l1_3(4), l1_2=(2), l1_1=(1);
    ListNode l2_3(4), l2_2=(3), l2_1=(1);
	l1_2.next = &l1_3; l1_1.next = &l1_2;
	l2_2.next = &l2_3; l2_1.next = &l2_2;
	ListNode *ret = Solution::mergeTwoLists(&l1_1, &l2_1);
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
