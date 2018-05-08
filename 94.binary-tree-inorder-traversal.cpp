/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (49.51%)
 * Total Accepted:    269.8K
 * Total Submissions: 545K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * 
 * For example:
 * Given binary tree [1,null,2,3],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * return [1,3,2].
 * 
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
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
#include <stack>
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
    static vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> stack_node;
		TreeNode *iter=root;
		int skip_left=0;
		while (iter) {
			if (!skip_left && iter->left) {
				stack_node.push(iter);
				iter = iter->left;
				continue;
			}
			ret.push_back(iter->val);
			if (iter->right) {
				skip_left = 0;
				iter = iter->right;
				continue;
			}
			if (stack_node.empty())
				return ret;
			iter = stack_node.top();
			stack_node.pop();
			skip_left = 1;
		}
		return ret;
    }
};

#ifdef TEST
int main()
{
    vector<TreeNode> node{1,2,3};
	node[0].right = &node[1];
	node[1].left = &node[2];
	vector<int> ret = Solution::inorderTraversal(&node[0]);
	for (auto iter:ret)
		cout << iter << endl;
	return 0;
}
#endif
