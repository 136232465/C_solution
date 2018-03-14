//leetcode 583
// Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

// Input: "sea", "eat"
// Output: 2


//time O(n²)
//space O（n²）


class Solution {
public:
	int minDistance(string word1, string word2) {
		int maxlenth = 0;
		int **dp = new int*[word1.size() + 1];
		for (int i = 0; i < word1.size() + 1; ++i){
			dp[i] = new int[word2.size() + 1];
		}
		for (int i = 0; i <= word1.size(); ++i){
			for (int j = 0; j <= word2.size(); ++j){
				if (i == 0 || j == 0){
					dp[i][j] = 0;
				}
				else {
					dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		maxlenth = dp[word1.size()][word2.size()];
		for (int i = 0; i < word1.size() + 1; ++i){
			delete[] dp[i];
		}
		delete[] dp;
		return word1.size() + word2.size() - 2 * maxlenth;
	}
};