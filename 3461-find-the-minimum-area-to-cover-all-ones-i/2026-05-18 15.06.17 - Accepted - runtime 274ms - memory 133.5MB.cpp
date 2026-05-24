class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int x_low=INT_MAX;
        int x_up=INT_MIN;
        int y_low=INT_MAX;
        int y_up=INT_MIN;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    x_low=min(x_low,i);
                    x_up=max(x_up,i);
                    y_low=min(y_low,j);
                    y_up=max(y_up,j);
                }
            }
        }
        return(x_up-x_low+1)*(y_up-y_low+1);
    }
};