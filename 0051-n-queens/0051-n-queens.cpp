class Solution {
public:
    bool issafe(vector<string>&boards,int row,int col,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0&&col>=0){
            if(boards[row][col]=='Q')return false;         //upper diagonal
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0){
            if(boards[row][col]=='Q') return false;     // left-row
            col--;
        }
        row=duprow;
        col=dupcol;
         while(row<n && col>=0){
            if(boards[row][col]=='Q') return false;      // lower diagonal
            col--;
            row++;
        }
        return true;
    }
    void rec(vector<vector<string>>&ans,vector<string>&boards,int col,int n){
        if(col==n){
            ans.push_back(boards);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(boards,row,col,n)){
                boards[row][col]='Q';
                rec(ans,boards,col+1,n);
                boards[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>>ans;
       vector<string>boards(n,string(n,'.'));
       int col=0;
      rec(ans,boards,col,n);
      return ans;
    }
};