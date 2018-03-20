#ifdef TEST
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#endif

class Solution {
public:
	/*
	static double findMedianSortedMultiArrays(vector<vector<int>>& nums1) {
		vector <int> &lp=nums1, &sp=nums2;
		int n1 = nums1.size();
		int n2 = nums2.size();
		int ln = max(n1, n2), sn = min(n1, n2);
		int k = (n1+n2+1)/2; // n1: 5, n2: 4, k: 5
		if (n1<n2) lp = nums2, sp = nums1;
		int l=k-n2-1, h=k-1; // 0, 4
		while (l<h) {
			int m1 = (l+h)/2;  // 2
			int m2 = k-m1-1;   // 2
			if (lp[m1]<sp[m2])
				l=m1+1;
			else
				h=m1;
		}
		return 0;
	}
	*/
	static double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
		if (A.size()>B.size())
			return findMedianSortedArrays(B, A);
		int n1 = A.size();
		int n2 = B.size();
		int i,j;
		// n1 < n2
		int k = (n1+n2+1)/2;
		int l=0, h=n1;
		/*
		cout << "A:";
		for (auto c: A)
			cout << c << " ";
		cout << endl;
		cout << "B:";
		for (auto c: B)
			cout << c << " ";
		cout << endl;
		*/
		if (!n1) {
			if (!n2)
				return 0;
			return  (n2%2)?B[n2/2]:((double)B[n2/2]+(double)B[n2/2-1])/2;
		}
#define A_val(pos)  ((pos<0)?INT_MIN:(pos>=n1)?INT_MAX:A[pos])
#define B_val(pos)  ((pos<0)?INT_MIN:(pos>=n2)?INT_MAX:B[pos])
		while (l<=h) {
			i = (l+h)/2;
			j = k-i-1;
			//printf("[%d,%d] i=%d, j=%d\n", l, h, i, j);
			if (i<n1 && A[i] < B[j])
				l = i+1;
			else if (i>0 && B[j+1] < A[i-1])
				h = i-1;
			else {
				//printf("[%d,%d] [%d,%d]\n", A_val(i-1), A_val(i), B_val(j), B_val(j+1));
				if (!((n1+n2)%2)) {
					double median = max(A_val(i-1),B_val(j))+min(A_val(i),B_val(j+1));
					return median/2;
				}
				//else if (i<1 || j<0)
				//return min(A_val(i),B_val(j+1));
				else
					return max(A_val(i-1),B_val(j));
			}
		}
		return 0;
	}
};

/* vector<int> nums1 = {1,3}, nums2 = {2};
 * k n1 n2 l h m1 m2 
 * 2  2  1 0 1 0  1
 * 2  2  1 
 * 2  2  1 
 */

/* vector<int> nums1 = {1,3,5,7,9}, nums2 = {2,4,6,8};
 *    l h m1 m2 k
 *    0 4 2  2  5
 *    3 4 3  1  5
 *    3 3
 */

#ifdef TEST
int main()
{
	vector<int> nums1 = {4,5}, nums2 = {1,2,3};
	//vector<int> nums1 = {1,2}, nums2 = {3};
	//vector<int> nums1 = {1,2}, nums2 = {3,4};
	//vector<int> nums1 = {1}, nums2 = {1};
	//vector<int> nums1 = {2,3}, nums2 = {};
	//vector<int> nums1 = {1}, nums2 = {};
	//vector<int> nums1 = {1,3}, nums2 = {2};
	//vector<int> nums1 = {1,2,3,4,5}, nums2 = {6,7,8,9};
	//vector<int> nums1 = {1,2,3,4}, nums2 = {5,6,7,8,9};
	//vector<int> nums1 = {1,3,5,7,9}, nums2 = {2,4,6,8};
	double ret = Solution::findMedianSortedArrays(nums1, nums2);
	cout << ret << endl;
	return 0;
}
#endif
