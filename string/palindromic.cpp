//leetcode 647
//Palindromic substring
// Given a string, your task is to count how many palindromic substrings in this string.

// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.



class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i){
            int pre = i,next = i;
            while (s[pre] == s[next] && pre >=0 && next < s.size()){
                ++count;
                --pre;
                ++next;
            }
            pre = i;
            next = i+1;
            while (s[pre] == s[next] && pre >=0 && next < s.size()){
                ++count;
                --pre;
                ++next;
            }
        }
        return count;
    }
};