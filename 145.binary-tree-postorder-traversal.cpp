/*
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (42.04%)
 * Total Accepted:    173.8K
 * Total Submissions: 413.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree [1,null,2,3],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * 
 * return [3,2,1].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
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
    static vector<int> postorderTraversal(TreeNode* root) {
        
    }
};

#ifdef TEST
int main()
{
    vector<TreeNode> node{1,2,3,4,5,6};
	node[0].left = &node[1];
	node[0].right = &node[4];
	node[1].left = &node[2];
	node[1].right = &node[3];
	node[4].right = &node[5];
	vector <int> ret = Solution::postorderTraversal(&node[0]);
	for (auto one: ret) {
		cout << one << ", ";
	}
	cout << endl;
	return 0;
}
#endif

