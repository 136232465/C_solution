//leetcode 275
//binary search

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0;
        int len = citations.size();
        int right = len-1;
        while (left <= right) {
            int mid = (right-left)/2+left;
            if(citations[mid] == (len-mid)){
                return citations[mid];
            }
            if(citations[mid] < (len-mid)){
                left = mid+1;
            }    else {
                right = mid -1;
            }         
        }
        return len - (right+1);
    }
};