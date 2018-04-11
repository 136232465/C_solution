//leetcode 304 Range sum query 2D-immutable



class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> matrix) {
        
        int row = matrix.size();
        int col = row == 0 ? 0 : matrix[0].size();
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for (int i = 1; i <= row; ++i){
            for(int j = 1; j <= col; ++j){
                sums[i][j] =  matrix[i-1][j-1] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] + sums[row1][col1] - sums[row2+1][col1] - sums[row1][col2+1];
    }
};