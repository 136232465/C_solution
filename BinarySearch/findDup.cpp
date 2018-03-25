//leetcode 287
//find the duplicate number
// like the linked list cycle II
//time O(n);



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = nums[0];
        int fast = nums[low];
        while(low != fast){
            low = nums[low];
            fast = nums[nums[fast]];
        }
        low = 0;
        while(low != fast){
            low = nums[low];
            fast = nums[fast];
        }
        return low;
    }
};