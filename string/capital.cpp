
//leetcode 520 Detect Capital
//Given a word, you need to judge whether the usage of capitals in it is right or not.



class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (char c : word){ 
			if (isupper(c)) ++cnt;
        }
		return !cnt || cnt == word.size() || cnt == 1 && isupper(word[0]);
    }
};