//leetcode 556
//next greater element III
//time O(nlogn)

#include<vector>
#include<algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <hash_set>
using namespace std;

//class Solution {
//public:
//	int maxProduct(int length) {
//		// write your solution here
//		vector<int> dp(length + 1, 0);
//		for (int i = 1; i <= length; ++i){
//			dp[i] = i-1;
//			for (int j = 1; j < i; ++j){
//				dp[i] = max(dp[i], max(dp[i - j],(i-j)) * j);
//			}
//		}
//		return dp[length];
//	}
//};

//class Solution {
//public:
//	queue<int> lay;
// 	
//	string getpath(string s){
//		int len = s.length();
//		if (len < 2){
//			return s;
//		}
//		int first = 0;
//		int second = 1;
//		while (second != len){
//			if (s[first] == '/' && s[second] == '/'){
//				s.erase(s.begin() + second);
//				--len;
//			}
//			else {
//				++first;
//				++second;
//			}
//		}
//		if (s[first] == '/'){
//			s.erase(s.begin() + first);
//		}
//		return s;
//	}
//};
//
//class Solution{
//	public:
//		string trainstr(string s){
//			if (s.empty()){
//				return NULL;
//			}
//			int i = 0, j = 0;
//			for (; i < s.size();){
//				if (s[i] >= '0' && s[i] <= '9'){
//					i += s[i] - '0' +1;
//					s[j] = s[i];
//
//				} else {
//					++i; ++j;
//				}
//			}
//			return s.substr(0, j);
//		}
//		//这是一个句子
//};

string words[12] = { "我", "要", "我要", "找", "嘉兴", "的", "麦当劳", "麦", "劳", "的麦", "当劳", "我要找嘉兴的麦当劳" };
hash_set<string> dict(words, words + 12);
string sentence;


class Solution{
public:
	void trainstr(string s, vector<vector<string>>& res, vector<string>& cursentence){
		if (s.empty()){
			res.push_back(cursentence);
		}
		//string sentence = "我要找嘉兴的麦当劳";
		string temp;
		for (int i = 0; i < s.size(); ++i){
			temp += s[i];
			++i;
			temp += s[i];
			if (dict.find(temp) != dict.end()){
				cursentence.push_back(temp);
				string remain(s.begin()+i+1,s.end());
				trainstr(remain, res, cursentence);
				cursentence.pop_back();
			}
		}		
	}

};


int main(){
	string sentence = "我要找嘉兴的麦当劳";
	string s ;
	Solution obj;
	vector<vector<string>> res;
	vector<string> curcomb;
	obj.trainstr(sentence,res,curcomb);
	//s += sentence[0]+sentence[1];
	//cout << s << endl;
	system("pause");
}
