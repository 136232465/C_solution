//leetcode 526
//Beautiful Arrangement
//O(n!)

class Solution {
public:
    int countArrangement(int N) {
        vector<bool> visited(N,false);
        int res = 0;
        helpdfs(N-1,res,N,visited);
        return res;
    }
private:
    
    void helpdfs(int n,int& res,int N,vector<bool>& visited){
        if (n == 0){
            ++res;
            return;
        }
        for (int i = 1; i < N+1; ++i){
            if (visited[i-1]==false && (i%(n+1)==0 || (n+1)%i == 0)){
                visited[i-1] = true;
                helpdfs(n-1,res,N,visited);
                visited[i-1] = false;
            }
        }
    }
};