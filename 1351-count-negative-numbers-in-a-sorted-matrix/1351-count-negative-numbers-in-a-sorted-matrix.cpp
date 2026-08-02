class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int r=0;r<m;r++){
            int c=getneg(grid,r,n);
            count+=(n-c);
        }
        return count;
    }
    private:
    int getneg(vector<vector<int>>&grid,int row,int col){
        int low=0,high=col-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(grid[row][mid]>=0){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
};