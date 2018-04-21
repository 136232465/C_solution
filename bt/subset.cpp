//leetcode  90
//subsets 



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        sort(nums.begin(),nums.end());
        int length = nums.size();
        for (int i = 0; i < length; ++i){
            int count = 0;
            while (i+count < length && nums[i+count] == nums[i]){
                ++count;
            }
            int cur_size = res.size();
            for (int j=0; j < cur_size; ++j){
                vector<int> temp = res[j];
                for (int k = 0; k < count; ++k){
                    temp.push_back(nums[i+k]);
                    res.push_back(temp);
                }
            }
            i += count-1;
        }
       return res; 
        
    }
    
};