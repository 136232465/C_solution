//leetcode: candy
//O(N)

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> dp(n,1);
        for (int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1])
                dp[i] = dp[i-1]+1;
        }
        for(int i = n-1; i > 0; --i){
            if(ratings[i-1] > ratings[i]){
                dp[i-1] = max(dp[i-1],dp[i]+1);
            }
        }
        int result = 0;
        for(int i = 0; i < n; ++i){
            result += dp[i];
        }
        return result;
    }
};