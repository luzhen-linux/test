/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (33.65%)
 * Total Accepted:    118.8K
 * Total Submissions: 353.1K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0. So it is possible.
 * 
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0, and to take course 0 you should also have finished course
 * 1. So it is impossible.
 * 
 * Note:
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 * This problem is equivalent to finding if a cycle exists in a directed graph.
 * If a cycle exists, no topological ordering exists and therefore it will be
 * impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 * 
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class Solution {
public:
	static int visit(int course, map<int, set<int>> &req, vector<int> &visited) {
		if (visited[course]==1)
			return -1;
		if (visited[course]==-1)
			return 0;
		visited[course] = 1;
		if (req.find(course)==req.end()) {
			visited[course] = -1;
			return 0;
		}
		set<int> set = req[course];
		for (auto one: set) {
			if (visit(one, req, visited)<0)
				return -1;
		}
		visited[course] = -1;
		return 0;
	}
    static bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		map<int, set<int>> req;
		for (auto each: prerequisites) {
			set<int> set;
			if (req.find(each.first)!=req.end())
				set = req[each.first];
			set.insert(each.second);
			req[each.first] = set;
		}
		/*
		for (auto each: req) {
			cout << each.first << "->" ;
			set<int> set = each.second;
			for (auto one:set)
				cout << one << ",";
			cout << endl;
		}
		*/
		vector<int> visited(numCourses);
		for (auto each: req) {
			if (visit(each.first, req, visited)<0)
				return false;
		}
		return true;
    }
};

#ifdef TEST
int main()
{
	vector<pair<int,int>> prereq{{1,0},{2,0}};
	cout << Solution::canFinish(2, prereq) << endl;
	return 0;
}
#endif
