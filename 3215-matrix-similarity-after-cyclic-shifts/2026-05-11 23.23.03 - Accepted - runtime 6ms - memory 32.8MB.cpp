class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        k=k%n;
        int nj=-1;
        vector<vector<int>>grid(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i%2==0){
                   nj=(j-k+n)%n;
                }
                else{
                   nj=(j+k)%n;
                }
                grid[i][nj]=mat[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
             if(grid[i][j]!=mat[i][j]) return false;   
            }
        }
        return true;
    }
};