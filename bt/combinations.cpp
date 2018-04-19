//leetcode 77
//combinations


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ivec;
        vector<vector<int>> res;
        help(n,k,1,ivec,res);
        return res;
    }
private:
    void help(int n, int k, int cur_num,vector<int>& ivec, vector<vector<int>>& res){
        if (k == 0){
            res.push_back(ivec);
            return ;
        }
        for (int i = cur_num; i <= n; ++i){
            ivec.push_back(i);
            help(n,k-1,i+1,ivec,res);
            ivec.pop_back();
        }
        
    }
};