//leetcode 556
//next greater element III
//time O(nlogn)

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		vector<vector<int>> dp;
		for (int i = 0; i < matrix.size(); ++i){
			vector<int> dpi;
			for (int j = 0; j < matrix[i].size(); ++j){
				int num = matrix[i][j] - '0';
				dpi.push_back(num);
			}
			dp.push_back(dpi);
		}
		int maxres = 0;
		for (int i = 0; i < dp.size(); ++i){
			for (int j = 0; j < dp[i].size(); ++j){
				if (i != 0 && j != 0 && dp[i][j] != 0){
					dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
				}
				maxres = max(dp[i][j], maxres);
			}
		}
		return maxres*maxres;
	}
};

void main(){
	vector<vector<char>> src(2, vector<char>(4,'1'));
	Solution s;
	s.maximalSquare(src);
}
