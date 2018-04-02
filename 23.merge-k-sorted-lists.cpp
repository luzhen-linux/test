/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (28.06%)
 * Total Accepted:    212.5K
 * Total Submissions: 757.2K
 * Testcase Example:  '[]'
 *
 * 
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
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
    static ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *head=NULL;
		int size = lists.size();
		vector <ListNode*> p(size);
		if (!size) return head;
		int j=-1;
		for (int i=0; i<size; i++) {
			p[i] = lists[i];
			if (p[i] && (!head || head->val>p[i]->val)) {
				head = p[i];
				j = i;
			}
		}
		if (j>=0)
			p[j] = p[j]->next;
		else
			return head;
		ListNode *prev=head;
		while (1) {
			ListNode *cur=NULL;
			j = -1;
			for (int i=0; i<size; i++) {
				if (p[i] && (!cur || cur->val>p[i]->val)) {
					cur = p[i];
					j = i;
				}
			}
			if (j>=0) {
				p[j] = p[j]->next;
				prev->next = cur;
				prev = cur;
			}
			else
				return head;
		}
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
	vector<ListNode*> list={&l1_1, &l2_2};
	ListNode *ret = Solution::mergeKLists(list);
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
