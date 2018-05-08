/*
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (36.65%)
 * Total Accepted:    133.1K
 * Total Submissions: 363K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    static vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		vector<int> one;
		vector<TreeNode*> vnode;
		vector<TreeNode*> vbackup;
		int backward = 0;
		if (!root)
			return ret;
		vnode.push_back(root);
		while (1) {
			if (vnode.empty()) {
				ret.push_back(one);
				one.clear();
				if (vbackup.empty())
					return ret;
				vnode.swap(vbackup);
			}
			if (backward)
				for (int i=vnode.size()-1; i>=0; i--)
					one.push_back(vnode[i]->val);
			for (auto n:vnode) {
				if (!backward)
					one.push_back(n->val);
				if (n->left)
					vbackup.push_back(n->left);
				if (n->right)
					vbackup.push_back(n->right);
			}
			vnode.clear();
			backward = !backward;
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
    vector<vector<int>> ret = Solution::zigzagLevelOrder (&node[0]);
	for (auto one:ret) {
		for (auto iter:one)
			cout << iter << " ,";
		cout << endl;
	}
	return 0;
}
#endif

