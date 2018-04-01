//leetcode 152
//Maximum Product Subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxres = nums[0];
        int imax = nums[0], imin = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] < 0){
                int temp = imax;
                imax = imin;
                imin = temp;
            }
            imax = max(imax*nums[i],nums[i]);
            imin = min(imin*nums[i],nums[i]);
            maxres = max(maxres,imax);
        }
        return maxres;
    }
};