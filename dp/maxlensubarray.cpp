//leetcode 718
//maximum length of repeate subarray
//maxres = max(maxres,dp[j] = A[i] == B[j] ? dp[j+1]+1:0)//通过dp数组记录之前有几个字符串是连续相等的


class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        vector<int>dp(n+1,0);
        int maxres = 0;
        for(int i = m-1; i >= 0; --i){
            for(int j = 0; j < n; ++j){
                maxres = max(maxres,dp[j] = A[i] == B[j] ? dp[j+1]+1:0);
            }
        }
        return maxres;
    }
};