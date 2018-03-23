//leetcode 658 
//Find K Closest Elements


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int second = std::lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        int first = second-1;
        while(k--){
            if (first < 0 || (second < arr.size() && abs(arr[second] - x) < abs(arr[first] - x))){
                ++second;
            }
            else {
                --first;
            }
        }
        return vector<int>(arr.begin()+first+1,arr.begin()+second);
    }
    
};