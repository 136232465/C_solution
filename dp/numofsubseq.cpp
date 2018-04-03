//leetcode 673
//number of longest increasing subsequence


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        int max_len = 1,res = 0;
        vector<int> len(N,1);
        vector<int> cnt(N,1);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    if(len[i] == len[j]+1){
                        cnt[i] += cnt[j];
                    }
                    if(len[i] < len[j]+1){
                        len[i] = len[j]+1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if(max_len == len[i])res += cnt[i];
            if(max_len < len[i]){
                max_len = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
};