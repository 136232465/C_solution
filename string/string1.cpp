//leetcode 227 Basic Calculator II
//time O(n)


//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non - negative integers, +, -, *, / operators and empty spaces.The integer division should truncate toward zero.
//
//You may assume that the given expression is always valid.
//
//Some examples :
//"3+2*2" = 7
//" 3/2 " = 1
//" 3+5 / 2 " = 5


class Solution {
public:
	int calculate(string s) {
		if (s.empty()){
			return 0;
		}
		s.push_back('+');
		char sign = '+';
		int num = 0;
		vector<int> res;
		for (int i = 0; i < s.length(); ++i){
			if (s[i] == ' '){
				continue;
			}
			if (s[i] >= '0' && s[i] <= '9') num = 10 * num + (s[i] - '0');
			else {
				if (sign == '+') res.push_back(num);
				else if (sign == '-') res.push_back(-num);
				else if (sign == '*') res.back() *= num;
				else res.back() /= num;
				sign = s[i];
				num = 0;
			}
		}
		return accumulate(res.begin(), res.end(), 0);

	}
};