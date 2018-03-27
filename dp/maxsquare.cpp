//leetcode 221 Maximal Square
//dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp;
        for(int i = 0; i < matrix.size();++i){
            vector<int> dpi;
            for(int j = 0; j < matrix[i].size();++j){
                int num = matrix[i][j] - '0';
                dpi.push_back(num);
            }
            dp.push_back(dpi);
        }
        int maxres = 0;
        for(int i = 0; i < dp.size(); ++i){
            for(int j = 0; j < dp[i].size();++j){
                if ( i != 0 && j != 0 && dp[i][j] != 0){
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                maxres = max(dp[i][j],maxres);
            }
        }
        return maxres*maxres;
    }
};