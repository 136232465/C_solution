//leetcode 200
//Number of Islands


class Solution {
public:   
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    res++;
                    DFS(grid,i,j);
                }
            }
        }
        return res;
    }
    
private:
    void DFS(vector<vector<char>>& grid,int x,int y){
        grid[x][y] = '0';
        if(x-1 >= 0 && grid[x-1][y] == '1'){
            DFS(grid,x-1,y);
        }
        if(y-1 >=0 && grid[x][y-1] == '1'){
            DFS(grid,x,y-1);
        }
        if(x+1 < grid.size()  && grid[x+1][y] == '1'){
            DFS(grid,x+1,y);
        }
        if(y+1 < grid[0].size()  && grid[x][y+1] == '1'){
            DFS(grid,x,y+1);
        }
    }
};