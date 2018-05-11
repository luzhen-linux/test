/*
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * algorithms
 * Medium (25.18%)
 * Total Accepted:    145.1K
 * Total Submissions: 576.3K
 * Testcase Example:  '{}'
 *
 * 
 * Clone an undirected graph. Each node in the graph contains a label and a
 * list of its neighbors.
 * 
 * 
 * 
 * 
 * OJ's undirected graph serialization:
 * 
 * 
 * Nodes are labeled uniquely.
 * 
 * 
 * We use # as a separator for each node, and , as a separator for node label
 * and each neighbor of the node.
 * 
 * 
 * 
 * 
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 * 
 * 
 * 
 * The graph has a total of three nodes, and therefore contains three parts as
 * separated by #.
 * 
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming
 * a self-cycle.
 * 
 * 
 * 
 * 
 * Visually, the graph looks like the following:
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    /   \
 * ⁠   0 --- 2
 * ⁠        / \
 * ⁠        \_/
 * 
 * 
 * 
 * 
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
#endif

class Solution {
public:
    static UndirectedGraphNode *cloneGraph(UndirectedGraphNode *src,
			map<UndirectedGraphNode*, UndirectedGraphNode*> &map) {
		if (!src)
			return NULL;
		if (!(map.find(src)==map.end()))
			return map[src];
		UndirectedGraphNode* dest = new UndirectedGraphNode(src->label);
		if (!dest)
			return NULL;
		map[src] = dest;
		for (auto n: src->neighbors) {
			UndirectedGraphNode* neighbor = cloneGraph(n, map);
			if (neighbor)
				dest->neighbors.push_back(neighbor);
		}
		return dest;
	}
    static UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		map<UndirectedGraphNode*, UndirectedGraphNode*> map;
		return cloneGraph(node, map);
    }
};

#ifdef TEST
void pr_node(UndirectedGraphNode *node)
{
	if (!node) return;
	cout << node->label << endl;
	for (auto n: node->neighbors) {
		if (n!=node)
			pr_node(n);
	}
}

int main()
{
	vector<UndirectedGraphNode> node{0,1,2};
	node[0].neighbors.push_back(&node[1]);
	node[0].neighbors.push_back(&node[2]);
	node[1].neighbors.push_back(&node[2]);
	node[2].neighbors.push_back(&node[2]);
    UndirectedGraphNode *ret = Solution::cloneGraph(&node[0]);
	pr_node(ret);
	return 0;
}
#endif
