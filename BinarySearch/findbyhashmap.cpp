//leetcode 436
//Find Right Interval
// time O(nlogn)


class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int,int> hash;
        vector<int> res;
        for(int i = 0; i < intervals.size(); ++i){
            hash[intervals[i].start] = i;
        }
        for (auto i : intervals){
            auto ite = hash.lower_bound(i.end);
            if (ite != hash.end()){
                res.push_back(ite->second);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};