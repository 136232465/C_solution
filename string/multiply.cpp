//leetcode 43
//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2

//time O(n²)



class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size()+num2.size(),'0');        
        for(int i = num1.size()-1; i>=0; --i){
            int carry = 0;
            for(int j=num2.size()-1; j>=0; --j){
                int temp = (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                res[i+j+1] = temp%10 + '0' ;
                carry = temp/10;
            }
            res[i] += carry;
        }
        size_t startpos = res.find_first_not_of("0");
        if (string::npos != startpos) {
        return res.substr(startpos);
        }
        return "0";
    }
};