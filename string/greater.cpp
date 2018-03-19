//leetcode 556
//next greater element III
//time O(nlogn)


class Solution {
public:
    int nextGreaterElement(int n) {
        auto digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stol(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;        
    }
};