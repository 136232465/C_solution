// word search leetcode 79


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[i].size(); ++j){
                if (helper(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
              
    }
private:
    bool helper(vector<vector<char>> board,int m,int n,string word,int k){
        if(k == word.size()){
            return true;
        } 
        else if (m < 0 || m == board.size() || n == board[0].size() || n < 0 || board[m][n] != word[k]){
            return false;
        }
        char temp = board[m][n];
        board[m][n] = '*';
        bool res = helper(board,m-1,n,word,k+1) || helper(board,m,n-1,word,k+1) || helper(board,m+1,n,word,k+1) || helper(board,m,n+1,word,k+1);
        board[m][n] = temp;
        return res;
        
    }
};