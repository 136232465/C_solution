//leetcode 715 RangeModule

class RangeModule {
public:
    
    void addRange(int left, int right) {
        int n = intval.size();
        vector<pair<int,int>> temp;
        for(int i = 0; i <= n; ++i){
            if(i == n || intval[i].first > right){
                temp.push_back(make_pair(left,right));
                while(i < n){
                    temp.push_back(intval[i++]);
                }
            } else if(intval[i].second < left){
                temp.push_back(intval[i]);
            } else {
                left = min(intval[i].first,left);
                right = max(intval[i].second,right);
            }
        }
        swap(intval,temp);
        
    }
    
    bool queryRange(int left, int right) {
        int n = intval.size();
        int l = 0, r = n-1;
        while(l <= r){
            int m = l+(r-l)/2;
            if(intval[m].first >= right){
                r = m-1;
            }
            else if(intval[m].second <= left){
                l = m+1;
            }
            else {
                return intval[m].first <= left && intval[m].second >= right;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        int n = intval.size();
        vector<pair<int, int>> tmp;
        for (int i = 0; i < n; i++) {
            if (intval[i].second <= left || intval[i].first >= right)
                tmp.push_back(intval[i]);
            else {
                if (intval[i].first < left)  tmp.push_back({intval[i].first, left});
                if (intval[i].second > right) tmp.push_back({right, intval[i].second});
            }
        }
        swap(intval, tmp);
    }
private:
    vector<pair<int,int>> intval;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */