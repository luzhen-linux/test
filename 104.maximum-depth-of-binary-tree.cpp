/*
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (54.71%)
 * Total Accepted:    319.7K
 * Total Submissions: 584.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its depth = 3.
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

#define SOLUTION2 1
class Solution {
public:
    static int maxDepth(TreeNode* root) {
#if SOLUTION1
		return root?max(maxDepth(root->left), maxDepth(root->right))+1:0;
#elif SOLUTION2
		int maxdepth = 0;
		queue<TreeNode*> qnode;
		queue<int> level;
		if (!root)
			return 0;
		qnode.push(root);
		level.push(1);
		while (!qnode.empty()) {
			TreeNode *front = qnode.front();
			maxdepth = max(level.front(), maxdepth);
			if (front->left) {
				qnode.push(front->left);
				level.push(level.front()+1);
			}
			if (front->right) {
				qnode.push(front->right);
				level.push(level.front()+1);
			}
			qnode.pop();
			level.pop();
		}
		return maxdepth;
#endif
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
    cout << Solution::maxDepth (&node[0]) << endl;
	return 0;
}
#endif
