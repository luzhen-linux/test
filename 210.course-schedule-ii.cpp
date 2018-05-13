/*
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (30.13%)
 * Total Accepted:    87.7K
 * Total Submissions: 291.1K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 * 
 * For example:
 * 
 * 
 * 2, [[1,0]]
 * 
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0. So the correct course order is [0,1]
 * 
 * 
 * 4, [[1,0],[2,0],[3,1],[3,2]]
 * 
 * There are a total of 4 courses to take. To take course 3 you should have
 * finished both courses 1 and 2. Both courses 1 and 2 should be taken after
 * you finished course 0. So one correct course order is [0,1,2,3]. Another
 * correct ordering is[0,2,1,3].
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 * 
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 * 
 * This problem is equivalent to finding the topological order in a directed
 * graph. If a cycle exists, no topological ordering exists and therefore it
 * will be impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 * 
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

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
	static int dfs (int course, map<int, set<int>> &req, vector<int> &visited, vector<int> &out) {
		if (visited[course]==1)
			return -1;
		if (visited[course]==-1)
			return 0;
		visited[course]=1;
		if (req.find(course)==req.end()) {
			out.push_back(course);
			visited[course]=-1;
			return 0;
		}
		set<int> set=req[course];
		for (auto one: set) {
			if (dfs(one, req, visited, out)<0)
				return -1;
		}
		visited[course]=-1;
		out.push_back(course);
		return 0;
	}
    static vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		map<int, set<int>> req;
		for (auto one:prerequisites) {
			set<int> set;
			if (req.find(one.first)!=req.end())
				set = req[one.first];
			set.insert(one.second);
			req[one.first] = set;
		}
		vector<int> visited(numCourses);
		vector<int> out;
		for (auto course: req) {
			if (dfs(course.first, req, visited, out)<0)
				return {};
		}
		for (int i=0; i<numCourses; i++) {
			if (find(out.begin(), out.end(), i)==out.end())
				out.push_back(i);
		}
		return out;
    }
};

#ifdef TEST
int main()
{
	vector<pair<int,int>> prereq{{1,0},{2,0},{3,1},{3,2}};
	vector<int> ret = Solution::findOrder(4, prereq);
	for (auto i:ret)
		cout << i << ", ";
	cout << endl;
	return 0;
}
#endif
