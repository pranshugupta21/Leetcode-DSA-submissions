class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    private:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char num='1';num<='9';num++){
                     if(isvalid(board,i,j,num)){
                        board[i][j]=num;
                        if(solve(board)){
                            return true;
                        }
                        board[i][j]='.';
                     }
                    }
                    return false;  // after trying all possibilities
                }
            }
        }
        return true; // if all board position has been checked
    }
    bool isvalid(vector<vector<char>>& board,int row,int col ,char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c) return false; // checking row
            if(board[i][col]==c) return false; // checking column
           int sub_matrix_row=(3*(row/3)+i/3);
           int sub_matrix_col=(3*(col/3)+i%3);
           if(board[sub_matrix_row][sub_matrix_col]==c) return false;
        }
        return true;
    }
};