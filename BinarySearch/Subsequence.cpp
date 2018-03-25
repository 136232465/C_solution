//leetcode 392
//is subsequence
//time O(n);
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0;
        int ti = 0;
        for(;si < s.size() && ti < t.size();){
            if(s[si] == t[ti]){
                ++si;
                ++ti;
            }   else {
                ++ti;
            }
        }
        if (si == s.size()){
            return true;
        }
        return false;
    }
};