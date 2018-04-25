//leetcode 451
//sort characters by frequency



class Solution {
public:
    string frequencySort(string s) {
        map<char,int> cimap;
        for (auto i : s){
            ++cimap[i];
        }
        vector<vector<char>> cvec(s.size()+1);
        for (auto i : cimap){
            cvec[i.second].push_back(i.first);
        }
        string res;
        for (int i = s.size(); i > 0; --i){
            if (cvec.empty()){
                continue;
            }
            int m = i;
            for (int j = 0; j < cvec[i].size(); ++j){
                string temp(m,cvec[i][j]);
                res += temp;
            }
        }
        return res;
    }
};