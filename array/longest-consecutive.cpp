//leetcode
// neither i+1 nor i-1 has been seen: m[i]=1;

// both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]] to each other;

// only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other;

// only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other.
//time0（n）

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,int> mp;
        int res = 0;
        for(int i : num){
            if(mp[i]){
                continue;
            }
            mp[i] = mp[i+mp[i+1]] = mp[i-mp[i-1]] = mp[i-1]+mp[i+1]+1;
            res = max(res,mp[i]);
        }
        return res;
    }
};