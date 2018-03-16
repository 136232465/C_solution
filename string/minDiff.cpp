
//leetcode 539
//minimum Time Difference

//time O(nlogn)

// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int minDiff = INT_MAX;
        sort(timePoints.begin(),timePoints.end());
        for (int i = 0;  i <  n; ++i){
            int diff = difftime (timePoints[(i-1+n)%n],timePoints[i]);
            minDiff = min(diff,minDiff);
        }
        return minDiff;
    }
private:
    int difftime(string s1,string s2){
        int s1h = stoi(s1.substr(0,2));
        int s1m = stoi(s1.substr(3,2));
        int s2h = stoi(s2.substr(0,2));
        int s2m = stoi(s2.substr(3,2));
        int res = abs((s2h - s1h)*60 + (s2m - s1m));
        if (res > 720){
            return 1440-res;
        }
        return res;
    }
};