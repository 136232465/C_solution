//leetcode 646 maximum length of pair chain
//dp[i] = max(dp[i],pairs[i][0] > pairs[j][1] ? dp[j] : dp[i-1])

bool help(vector<int> p1,vector<int> p2){
        return p1[0] < p2[0];      
    }
class Solution {    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int m = pairs.size();
        sort(pairs.begin(),pairs.end(),help);
        vector<int> dp(m,1);
        for(int i = 0; i < m; ++i){
            dp[i] = 1;
        }
        int maxres = 1;
        for(int i = 0; i < pairs.size();++i){
            for(int j = 0; j < i;++j){
                if (pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
                dp[i] = max(dp[i-1],dp[i]);
            }
        }
        return dp[m-1];
    }
};