//leetcode 56
//merge intervals


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool isort(Interval t1,Interval t2){
    return t1.start < t2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),isort);
        vector<Interval> res;
        for (auto i : intervals){
            if (res.empty()){
                res.push_back(i);
            }
            Interval temp = res.back();
            if (temp.end >= i.start){
                temp.end = max(temp.end,i.end);
                res.pop_back();
                res.push_back(temp);
            } else {
                res.push_back(i);
            }
            
        }
        return res;
    }
};