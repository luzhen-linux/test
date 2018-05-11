/*
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (19.71%)
 * Total Accepted:    167.9K
 * Total Submissions: 852K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2 // capacity // );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class LRUCache {
private:
	unordered_map<int, int> map;
	deque<int> access;
	int max;
public:
    LRUCache(int capacity) {
		map.clear();
		access.clear();
		max = capacity;
    }
    
    int get(int key) {
		if (map.find(key)==map.end())
			return -1;
		access.erase(find (access.begin(), access.end(), key));
		access.push_front(key);
		return map[key];
    }
    
    void put(int key, int value) {
		if (map.find(key)!=map.end()) {
			map[key] = value;
			access.erase(find (access.begin(), access.end(), key));
			access.push_front(key);
			return;
		}
		if (map.size()==max) {
			map.erase(access[max-1]);
			access.pop_back();
		}
		map[key] = value;
		access.push_front(key);
		return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

#ifdef TEST
int main()
{
	LRUCache cache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // returns 1
	cache.put(3, 3);    // evicts key 2
	cout << cache.get(2) << endl;       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cout << cache.get(1) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3
	cout << cache.get(4) << endl;       // returns 4
	return 0;
}
#endif

