//leetcode 279 perfect squares
//dp

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        for(int j = 1; j*j <= n;++j){
            dp[j*j] = 1;
        }
        if(dp[n] == 1){
            return 1;
        }
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j*j < i; ++j){
                dp[i] = min(dp[i-j*j]+1,dp[i]);
            }
        }
        return dp[n]; 
    } 
};