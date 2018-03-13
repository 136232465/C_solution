//leetcode 696 Count binary substrings

// Give a string s, count the number of non-empty (contiguous) substrings that have 
// the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
// Input: "00110011"
// Output: 6


// time O(n);

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prelen = 0;
        int curlen = 1;
        int res = 0;
        for(int i = 1; i < s.size(); ++i){
            if (s[i] == s[i-1]){
                curlen++;
            }
            else {
                prelen = curlen;
                curlen = 1;
            }
            if(prelen >= curlen){
                    ++res;
                }
        }
        return res;
    }
};