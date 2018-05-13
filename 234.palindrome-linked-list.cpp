/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (33.42%)
 * Total Accepted:    152.3K
 * Total Submissions: 455.8K
 * Testcase Example:  '[]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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

#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class Solution {
public:
    static bool isPalindrome(ListNode* head) {
		string forward;
		string backward;
		ListNode *node=head, *prev=NULL;
		while (node) {
			ListNode *tmp=node->next;
			forward += to_string(node->val);
			node->next = prev;
			prev = node;
			node = tmp;
		}
		node = prev;
		while (node) {
			backward += to_string(node->val);
			node = node->next;
		}
		return (forward==backward);
    }
};

#ifdef TEST
int main()
{
    ListNode l1_3(1), l1_2=(2), l1_1=(1);
    ListNode l2_3(4), l2_2=(3), l2_1=(1);
	l1_2.next = &l1_3; l1_1.next = &l1_2;
	l2_2.next = &l2_3; l2_1.next = &l2_2;
	cout << Solution::isPalindrome(&l1_1) << endl;
	return 0;
}
#endif
