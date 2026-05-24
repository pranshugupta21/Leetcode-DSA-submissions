class Solution {
int tryg(vector<vector<int>>grid,int y,int x){
    int n=grid.size();
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if((i==j&&i<=n/2)||(i<=n/2&&i+j==n-1)||(i>=n/2&&j==n/2)){
            if(grid[i][j]!=y)c++;
           }
           else{
            if(grid[i][j]!=x)c++;
           }
        }
    }
    return c;
}
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=2;j>=0;j--){
                if(i!=j){
                  ans=min(ans,tryg(grid,i,j));
                }   
        }
          }   
       return ans;  
    }
};