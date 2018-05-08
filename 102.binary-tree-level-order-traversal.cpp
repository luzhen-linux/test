/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (42.41%)
 * Total Accepted:    230K
 * Total Submissions: 542.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
    static vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (!root)
			return ret;
		vector<int> one;
		queue<TreeNode*>  qnode;
		queue<TreeNode*>  qnode2;
		qnode.push(root);
		while (1) {
			if (qnode.empty()) {
				ret.push_back(one);
				one.clear();
				if (qnode2.empty())
					return ret;
				qnode.swap(qnode2);
				continue;
			}
			TreeNode *tmp = qnode.front();
			qnode.pop();
			one.push_back(tmp->val);
			if (tmp->left)
				qnode2.push(tmp->left);
			if (tmp->right)
				qnode2.push(tmp->right);
		}
		return ret;
    }
};

#ifdef TEST
int main()
{
    vector<TreeNode> node{3,9,20,15,7};
	node[0].left = &node[1];
	node[0].right = &node[2];
	node[2].left = &node[3];
	node[2].right = &node[4];
    vector<vector<int>> ret = Solution::levelOrder (&node[0]);
	for (auto one:ret) {
		for (auto iter:one)
			cout << iter << " ,";
		cout << endl;
	}
	return 0;
}
#endif
