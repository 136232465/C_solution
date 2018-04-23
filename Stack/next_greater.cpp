// leetcode 503 Next greater element II
//time O(n);


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int m = nums.size();
        stack<int> s;
        vector<int> ivec(m,-1);
        for (int i = 0; i < m*2; ++i){
            int num = nums[i % m];
            while(!s.empty() && nums[s.top()] < num){
                ivec[s.top()] = num;
                s.pop();
            }
            if (i < m){
                s.push(i);
            }
        }
        return ivec;
    }
};