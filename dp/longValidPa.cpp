//leetcode 32
//longest valid parentheses
//using stack mark unvalid index;

class Solution {
public:
    int longestValidParentheses(string s) {
        int m = s.size();
        stack<int> index;
        for (int i = 0; i < m; ++i){
            if(s[i] == '('){
                index.push(i);
            } else{
                if (!index.empty()){
                    if(s[index.top()] == '('){
                        index.pop();
                    } else {
                        index.push(i);
                    }
                }   else {
                    index.push(i);
                }
            }
        }
        if (index.empty()){
            return m;
        }
        int res = 0,left = 0, right = m;
        while (!index.empty()){
            left = index.top();
            index.pop();
            res = max(res , right-left-1);
            right = left;
        }
        res = max(res,left);        
        return res;        
    }
};