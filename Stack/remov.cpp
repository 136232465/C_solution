// leetcode 402
// remove k digits
// time O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res ;
        vector<char> numbers;
        int resk = num.size() - k;
        if (k >= num.size()){
            res = "0";
            return res;
        }
        numbers.push_back(num[0]);
        for (int i = 1; i < num.size(); ++i){
            char c = numbers.back();
            while(c > num[i] && k > 0){
                numbers.pop_back();
                --k;
                if (numbers.empty()){
                    break;
                } else {
                    c = numbers.back();
                }
            }
            numbers.push_back(num[i]);
        }
        int j = 0;
        while (numbers[j] == '0'){
            ++j;
        }
        for (int i = j; i < resk; ++i){
            res += numbers[i];
        }
        if (res.empty()){
            return string("0");
        } else {
        return res;
        }
    }
};