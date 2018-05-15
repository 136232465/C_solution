//leetcode 743
//Network Delay Time


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N+1,INT_MAX);
        int res = 0;
        dist[K] = 0;
        for(int i = 0; i < N; ++i){
            for (auto e : times){
                int u = e[0],v = e[1], w = e[2];
                if(dist[u] != INT_MAX && dist[v] > dist[u]+w){
                    dist[v] = dist[u]+w;
                }                                                                                                   
            }
        }
        for (int i = 1; i <N+1; ++i){
            res = max(res,dist[i]);
        }
        return res == INT_MAX ? -1:res;
    }
};