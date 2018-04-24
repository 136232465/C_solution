//leetcode 264
//ugly number II


class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0){
            return false;
        }
        if (n == 1){
            return true;
        }
        int i1 = 0, i2 = 0, i3 = 0;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; ++i){
            dp[i] = min(dp[i1]*2,min(dp[i2]*3,dp[i3]*5));
            if (dp[i] == dp[i1]*2){
                ++i1;
            }
            if (dp[i] == dp[i2]*3){
                ++i2;
            }
            if (dp[i] == dp[i3]*5){
                ++i3;
            }
        }
        return dp[n-1];
    }
};
