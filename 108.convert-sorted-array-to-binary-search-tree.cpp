/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (44.39%)
 * Total Accepted:    168.9K
 * Total Submissions: 380.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    static TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
		if (end<=start)
			return NULL;
		int mid = start + (end-start)/2;
		TreeNode *ret = new TreeNode(nums[mid]);
		if(!ret)
			return NULL;
		if (mid>start)
			ret->left = sortedArrayToBST(nums, start, mid);
		if (end>mid)
			ret->right = sortedArrayToBST(nums, mid+1, end);
		return ret;
	}
    static TreeNode* sortedArrayToBST(vector<int>& nums) {
		int sz_nums = nums.size();
		if (!sz_nums)
			return NULL;
		return sortedArrayToBST(nums, 0, sz_nums);
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
	vector<int> nums = {-10,-3,0,5,9};
    TreeNode* ret = Solution::sortedArrayToBST(nums);
	pr_node(ret);
	return 0;
}
#endif
