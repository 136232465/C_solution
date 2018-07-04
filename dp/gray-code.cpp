//leetcode gray-code
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> nums;
        int mark = 1;
        nums.push_back(0);
        while(n--){
            int len = nums.size();
            for(int i = len-1; i >= 0; --i){
                nums.push_back(nums[i] + mark);
            }
            mark = mark << 1;
        }
        return res;
    }
};