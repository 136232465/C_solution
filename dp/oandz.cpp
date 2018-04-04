//leetcode 474 one and zero
//dp[j][k] = max(dp[j][k],dp[j-zerocnt][k-onecnt]+1);
//dp记录该容量下所能容纳的最大物品


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));       
        for(auto i : strs){
            int zerocnt = 0, onecnt = 0;
            for (auto c : i){
                if( c == '0'){
                    ++zerocnt;
                } else {
                    ++onecnt;
                }
            }
           for (int j = m; j >= zerocnt; --j){
               for(int k = n; k >= onecnt; --k){
                   dp[j][k] = max(dp[j][k],dp[j-zerocnt][k-onecnt]+1);//记录当前背包放或不放
               }
           }
        }
        return dp[m][n];
    }
};