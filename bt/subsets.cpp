// leetcode 78
//subsets


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int count = res.size();
            for (int j = 0; j < count; ++j){
                vector<int> temp = res[j];
                res[j].push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};