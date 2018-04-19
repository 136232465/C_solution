//leetcode 22
// generate parentheses



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> res;
        helper(n,0,0,res,s);
        return res;
    }
    
private:
    void helper(int n,int left, int right, vector<string>& res,string s){
        if (left == right && right == n){
            res.push_back(s);
            return ;
        }
        if (left < right || left > n){
            return ;
        }
        helper(n,left+1,right,res,s+'(');
        helper(n,left,right+1,res,s+')');
    }
};