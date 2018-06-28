//leetcode Given a string S and a string T, count the number of distinct subsequences of T in S.

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie,"ACE"is a subsequence of"ABCDE"while"AEC"is not).

// Here is an example:
// S ="rabbbit", T ="rabbit"

// Return3.

class Solution {
public:v
    int numDistinct(string S, string T) {
        int Tlen = T.size();
        vector<int> array(len+1);
        array[0] = 1;
        for(int i = 1; i < S.size()+1; ++i){
            for(int j = min(i,Tlen);j > 0; --j){
                if(S[i-1] == T[j-1]){
                    array[j] = array[j] + array[j-1];
                }
            }
        }
    }
};

//array[n]记录在T中前n个字符串出现匹配的次数。每当遇到S[i] = T[n]时更新一下array[n]。