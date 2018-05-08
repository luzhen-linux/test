/*
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (36.46%)
 * Total Accepted:    161.3K
 * Total Submissions: 442.4K
 * Testcase Example:  '[]'
 *
 * 
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * 
 * 
 * For example,
 * Given
 * 
 * ⁠        1
 * ⁠       / \
 * ⁠      2   5
 * ⁠     / \   \
 * ⁠    3   4   6
 * 
 * 
 * 
 * The flattened tree should look like:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠     \
 * ⁠      3
 * ⁠       \
 * ⁠        4
 * ⁠         \
 * ⁠          5
 * ⁠           \
 * ⁠            6
 * 
 * 
 * click to show hints.
 * 
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child
 * points to the next node of a pre-order traversal.
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
    static void flatten(TreeNode* root) {
		queue<TreeNode*> queue;
		if (!root) return;
		queue.push(root);
		while (!queue.empty()) {
			TreeNode *node = queue.front();
			queue.pop();
			TreeNode *orig_right = node->right;
			if (node->left) {
				queue.push(node->left);
				node->right = node->left;
				TreeNode *insert = node->left;
				while (insert->right)
					insert = insert->right;
				insert->right = orig_right;
				node->left = NULL;
			}
			else if (node->right)
				queue.push(node->right);
		}
		return;
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
	Solution::flatten (&node[0]);
	pr_node(&node[0]);
	return 0;
}
#endif
