/*
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (39.77%)
 * Total Accepted:    188.8K
 * Total Submissions: 474.7K
 * Testcase Example:  '[2,1]\nnode with value 2\nnode with value 1'
 *
 * 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 * 
 * 
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes v and w as the lowest node in T that has both v
 * and w as descendants (where we allow a node to be a descendant of
 * itself).”
 * 
 * 
 * 
 * ⁠       _______6______
 * ⁠      /              \
 * ⁠   ___2__          ___8__
 * ⁠  /      \        /      \
 * ⁠  0      _4       7       9
 * ⁠        /  \
 * ⁠        3   5
 * 
 * 
 * 
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another
 * example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of
 * itself according to the LCA definition.
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
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)
			return NULL;
		if (root==p || root==q)
			return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left&&right)
			return root;
		if (left)
			return left;
		return right;
    }
};

#ifdef TEST
void pr_node(TreeNode *node)
{
	if (!node) return;
	pr_node(node->left);
	cout << node->val << endl;
	pr_node(node->right);
}

int main()
{
    vector<TreeNode> node{1,2,3,4,5,6};
	node[0].left = &node[1];
	node[0].right = &node[4];
	node[1].left = &node[2];
	node[1].right = &node[3];
	node[4].right = &node[5];
	TreeNode *ret = Solution::lowestCommonAncestor (&node[0], &node[3], &node[2]);
	pr_node(ret);
	return 0;
}
#endif
