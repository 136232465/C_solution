//leetcode 67
//add binary
//time O(n)

#include <string>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		int tag = 0;
		string res;
		for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || tag == 1; --i, --j){
			if (i >= 0){
				tag = tag + a[i] - '0';
			}
			if (j >= 0){
				tag = tag + b[j] - '0';
			}
			res = char(tag % 2 + '0') + res;
			tag = tag / 2;
		}
		return res;
	}
};