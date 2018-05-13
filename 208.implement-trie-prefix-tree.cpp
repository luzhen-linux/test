/*
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (30.78%)
 * Total Accepted:    107.4K
 * Total Submissions: 348.8K
 * Testcase Example:  '["Trie","search"]\n[[],["a"]]'
 *
 * 
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * 
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
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
#include <algorithm>
#include <iostream>

using namespace std;

#endif

class Trie {
public:
	unordered_map<string, int> map;
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		if (word.empty())
			return;
		for (int i=0; i<word.size(); i++)
			map[word.substr(0, i+1)] |= 1;
		map[word] |= 2;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		return map[word]&2;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		return map[prefix]&1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

#ifdef TEST
int main()
{
	string word("hello");
	string prefix("he");
	Trie obj;
	obj.insert(word);
	bool param_2 = obj.search(word);
	bool param_3 = obj.startsWith(prefix);
	cout << param_2 << ", " << param_3 << endl;
	return 0;
}
#endif
