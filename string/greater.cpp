
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class Solution{
public:
	int getlong_num(vector<int> dst){
		if (dst.empty()){
			return 0;
		}
		map<int, int> dp;
		dp[0] = 0;
		int sum = 0;
		int res = 0;
		for (int i = 1; i <= dst.size(); ++i){
			sum += dst[i-1];
			auto it = dp.find(sum);
			if (it == dp.end()){
				dp[sum] = i;
			} else {
				res = max(res, i - it->second);
			}
		}
		return res;
	}
};


int main() {
	vector<int> temp = { 0};
	Solution s;
	 int res = s.getlong_num(temp);
	 cout << res << endl;
	 system("pause");
}