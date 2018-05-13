/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (46.69%)
 * Total Accepted:    332.1K
 * Total Submissions: 711.3K
 * Testcase Example:  '[]'
 *
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
#include <stack>
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
    static ListNode* reverseList(ListNode* head) {
		if (!head)
			return NULL;
		stack<ListNode *> stack;
		while (head) {
			stack.push(head);
			head = head->next;
		}
		ListNode *tmp=stack.top();
		head = stack.top();
		tmp->next = NULL;
		stack.pop();
		while (!stack.empty()) {
			tmp->next = stack.top();
			tmp = tmp->next;
			tmp->next = NULL;
			stack.pop();
		}
		return head;
    }
};

#ifdef TEST
int main()
{
    ListNode l1_3(4), l1_2=(2), l1_1=(1);
    ListNode l2_3(4), l2_2=(3), l2_1=(1);
	l1_1.next = &l1_2; l1_2.next = &l1_3; l1_3.next = &l2_1;
	l2_1.next = &l2_2; l2_2.next = &l2_3;
	ListNode *ret = Solution::reverseList(&l1_1);
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
