/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers
 *
 * algorithms
 * Medium (28.04%)
 * Total Accepted:    380.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *r, *h=NULL;
		int carry=0;
		while (l1||l2||carry) {
			ListNode *p = new ListNode(0);
			if (!p) return NULL;
			if (!h) h=p;
			else r->next = p;
			if (carry) p->val++;
			if (l1) {
				p->val += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				p->val += l2->val;
				l2 = l2->next;
			}
			carry = p->val/10;
			p->val %= 10;
			r = p;
		}
		return h;
    }
};

#ifdef TEST
int main()
{
	/*
    ListNode a1(2), a2(4), a3(3), *p1=&a1;
    ListNode b1(5), b2(6), b3(4), *p2=&b1;
	a1.next = &a2;
	a2.next = &a3;
	b1.next = &b2;
	b2.next = &b3;
	*/
	ListNode *p1 = new ListNode(5), *p2=NULL;
	ListNode *ret = Solution::addTwoNumbers(p1, p2);
	while (ret) {
		cout << ret->val << endl;
		ret = ret->next;
	}
	return 0;
}
#endif

