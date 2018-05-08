/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (33.97%)
 * Total Accepted:    135.1K
 * Total Submissions: 397.7K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    static TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		struct node {
			int val;
			int placed;
			int index;
			TreeNode *p;
		};
		vector<node> n;
		TreeNode *root=NULL;
		for (auto p: preorder) {
			node tmp={p};
			tmp.index = find (inorder.begin(), inorder.end(), p)-inorder.begin();
			TreeNode *tmpnode = new TreeNode(p);
			if (!tmpnode)
				return NULL;
			tmp.p = tmpnode;
			n.push_back(tmp);
			//printf("tmp: %d,%d,%d, %p\n", tmp.val, tmp.placed, tmp.index, tmp.p);
		}
		int sz_node = n.size();
		if (!sz_node)
			return root;
		root = n[0].p;
		n[0].placed = 1;
		for (int i=0; i<sz_node; i++) {
			TreeNode *cur = n[i].p;
			for (int j=i+1; j<sz_node; j++) {
				TreeNode *next = n[j].p;
				if (n[j].placed)
					break;
				if (!cur->left) {
					if (n[j].index<n[i].index) {
						cur->left = next;
						n[j].placed = 1;
					}
				}
				if (!cur->right) {
					if (n[j].index>n[i].index) {
						cur->right = next;
						n[j].placed = 1;
						break;
					}
				}
			}
		}
		return root;
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
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
    TreeNode* ret = Solution::buildTree(preorder, inorder);
	pr_node(ret);
	return 0;
}
#endif
