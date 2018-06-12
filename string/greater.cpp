#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <map>
using namespace std;

//class Solution{
//public:
//	void getlong_num(vector<int>& vin){
//		int cur = 0, odd = 0, even = 0, tempodd;
//		for (int i = 0; i < vin.size(); ++i){
//			if (vin[i] & 0x01 == 1){
//				even++;
//			}
//		}
//		if (even == vin.size() || even == 0){
//			return;
//		}
//		tempodd = even;
//		for (; cur < tempodd; ++cur){
//			if ((vin[cur] & 0x01) == 0){
//				swap(vin[cur], vin[even]);
//				even++;
//			}	else {
//				if (odd != cur){
//					swap(vin[cur], vin[odd]);
//				}
//				odd++;
//			}		
//		}
//		while ((vin[cur - 1] & 0x01) == 0){
//			swap(vin[cur-1], vin[even]);
//			even++;
//		}
//		return;
//	}
//};

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty() || dict.size() == 0){
			return false;
		}
		return wordBreak(s, dict, 0);
	}
private:
	bool wordBreak(string s, unordered_set<string> &dict, int index){
		if (index == s.size()){
			return true;
		}
		for (int i = index; i < s.size(); ++i){
			string word = s.substr(i, i - index + 1);
			if (dict.count(word) != 0){
				return wordBreak(s, dict, i + 1);
			}
		}
		return false;
	}
};



int main() {
	string s = "cars";
	unordered_set<string> unset;
	unset.insert("car");
	unset.insert("ca");
	unset.insert("rs");
	Solution sou;
	bool res =  sou.wordBreak(s, unset);

	system("pause");
}