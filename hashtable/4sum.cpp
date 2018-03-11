// leetcode 454  4sum II
//time O(n2)
//space O£¨n£©
// Given four lists A, B, C, D of integer values,
// compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
		unordered_map<int, int> absum;
		for (auto i : A){
			for (auto j : B){
				++absum[i + j];
			}
		}
		int count = 0;
		for (auto i : C){
			for (auto j : D){
				auto it = absum.find(0 - i - j);
				if (it != absum.end()){
					count += it->second;
				}
			}
		}
		return count;

	}
};