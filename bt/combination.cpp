//combinationSum3  leetcode 216

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int cur_sum = 0;
        vector<int> ivec;
        vector<vector<int>> res;
        help(k,n,cur_sum,ivec,res,1);
        return res;
    }
private:
    void help(int k, int n, int cur_sum,vector<int> ivec, vector<vector<int>>& res,int curnum){
        if (k == 0){
            if (cur_sum == n){
                res.push_back(ivec);
            } else {
                return ;
            }
        }
        for (int i = curnum; i <= 9; ++i){
                ivec.push_back(i);
                help(k-1,n,cur_sum+i,ivec,res,i+1);
                ivec.pop_back();
        }
    }
};