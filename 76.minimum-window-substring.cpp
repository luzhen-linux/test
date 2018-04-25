/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (26.71%)
 * Total Accepted:    142.1K
 * Total Submissions: 532.2K
 * Testcase Example:  '"a"\n"a"'
 *
 * 
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * 
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * 
 * 
 * Minimum window is "BANC".
 * 
 * 
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * 
 * 
 * If there are multiple such windows, you are guaranteed that there will
 * always be only one unique minimum window in S.
 * 
 */
#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

#endif

#define SOLUTION1 1
class Solution {
	public:
		static string minWindow(string S, string T) {
#ifdef SOLUTION1
			int sz_s = S.size();
			int sz_t = T.size();
			if (!sz_t || !sz_s || sz_t>sz_s)
				return "";
			map<char, vector<int>> map_t;
			int i=0;
			for (auto c: T) {
				map_t[c].push_back(i++);
			}
			map<char, vector<int>> map_c=map_t;
			struct status {
				int pos;
				int next;
				int nextidx=-1;
				int previdx=-1;
			};
			vector<struct status> st(sz_t);
			int win_len=-1, win_start=-1, win_end=-1;
			int count=0, maxpos=sz_s-1, minpos=0, prev_idx=-1;
			i = 0;
			for (int j=0; j<sz_t; j++) {
				st[j].nextidx=-1;
				st[j].previdx=-1;
			}

			for (auto c: S) {
				int idx=-1;
				if (map_t.count(c)) {
					if (!map_c[c].empty()) {
						if (sz_t==1)
							return T;
						idx = map_c[c].front();
						map_c[c].erase(map_c[c].begin());
						count++;
					}
					else {
						int minpos=INT_MAX;
						for(auto id:map_t[c]) {
							if (st[id].pos<minpos) {
								idx = id;
								minpos = st[id].pos;
							}
						}
					}
					st[idx].pos = i;
					if (count>=sz_t) {
						printf("**** c=%c, idx=%d, i=%d, next=%d\n", c, idx, i, st[idx].next);
						if (win_end<0) {
							win_start = INT_MAX;
							for (int j=0; j<sz_t; j++) {
								win_start = min(win_start, st[j].pos);
							}
							win_end = i;
							win_len = i-win_start;
						}
						else if (st[idx].previdx!=-1) {
							st[st[idx].previdx].nextidx = st[idx].nextidx==-1?idx:st[idx].nextidx;
							st[st[idx].previdx].next = st[idx].next==-1?i:st[idx].next;
						}
						else {
							if (st[idx].next!=-1 && i-st[idx].next<win_len) {
								win_len = i-st[idx].next;
								win_start = st[idx].next;
								win_end = i;
							}
							if (st[idx].nextidx!=-1)
								st[st[idx].nextidx].previdx = -1;
						}
					}
					else {
						if (st[idx].previdx!=-1) {
							st[st[idx].previdx].nextidx = st[idx].nextidx==-1?idx:st[idx].nextidx;
							st[st[idx].previdx].next = st[idx].next==-1?i:st[idx].next;
						}
					}
					st[idx].previdx = prev_idx;
					if (prev_idx!=-1) {
						st[prev_idx].next = i;
						st[prev_idx].nextidx = idx;
					}
					prev_idx=idx;
					printf("c=%c, idx=%d, i=%d, %d,%d,%d,%d\n", c, idx, i, st[idx].pos, st[idx].next, st[idx].nextidx, st[idx].previdx);
					st[idx].next = -1;
					st[idx].nextidx = -1;
				}
				i++;
			}
			if (win_start<0)
				return "";
			printf("%d,%d,%d\n", win_start, win_end, win_len);
			return S.substr(win_start, win_len+1);
#elif SOLUTION2
			string win;
			if (S.size()<=0 || T.size()<=0 || T.size() > S.size()) return win;
			/*
			 * Declare two "hash map" for ASCII chars
			 *   f[]: represents the char found in string S
			 *   m[]: stores the chars in string T
			 */    
			const int MAX_CHARS = 256;
			int f[MAX_CHARS], m[MAX_CHARS];

			const int NOT_EXISTED   = -1;
			const int NOT_FOUND     =  0;
			memset(m, NOT_EXISTED, sizeof(m));
			memset(f, NOT_EXISTED, sizeof(f));

			/* 
			 *  Go through the T, and inital the m[] and f[] 
			 *  Notes: a same char can be appeared multiple times.
			 */
			for(int i=0; i<T.size(); i++) {
				m[T[i]]==NOT_EXISTED ? m[T[i]]=1 : m[T[i]]++ ; 
				f[T[i]] = NOT_FOUND; 
			}

			int start =-1;
			int winSize = INT_MAX;
			int letterFound = 0;
			int begin = 0;
			for(int i=0; i<S.size(); i++) {
				/* if S[i] is existed in T*/ 
				if ( m[S[i]] != NOT_EXISTED ){
					char ch = S[i];
					f[ch]++;

					/* if one char has been found enough times, then do not do letterFound++ */
					if (f[ch] <= m[ch]) {
						letterFound++;
					}
					if ( letterFound >= T.size() ) {
						/* 
						 * Find the beginning of the window
						 * 1) f[S[begin]] == NOT_EXISTED  ===> the char at the `begin` is not in T
						 * 2) f[S[begin]] > m[S[begin]]   ===> a same char appeared more than excepted.
						 */
						while ( f[S[begin]] == NOT_EXISTED || f[S[begin]] > m[S[begin]] ) { 
							if ( f[S[begin]] > m[S[begin]] ) {
								f[S[begin]]--;
							}   
							begin++;
						}
						/* Calculate the minimized window size */
						if(winSize > i - begin + 1){
							start = begin;
							winSize = i - begin + 1;
						}     

					}

				}
			}

			if (start>=0 && winSize>0) {
				win = S.substr(start, winSize);
			}
			return win;
#endif
		}
};

#ifdef TEST
int main()
{
	string s("abcabdebac");
	string t("cea");
	cout << s << endl;
	cout << t << endl;
	cout << Solution::minWindow(s, t) << endl;
	return 0;
}
#endif
