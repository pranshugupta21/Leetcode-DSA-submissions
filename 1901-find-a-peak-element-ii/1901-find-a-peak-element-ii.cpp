class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=maxrow(mat,n,m,mid);
            int left=(mid-1>=0)? mat[row][mid-1]:-1;
            int right=(mid<n-1)? mat[row][mid+1]:-1;
            if(mat[row][mid]>left&&mat[row][mid]>right){
                return{row,mid};
            }
           else if(mat[row][mid]>left){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {-1,-1};
    }
   private: int maxrow(vector<vector<int>>& mat,int n,int m,int col){
        int idx=-1;
        int maxele=-1;
        for(int i=0;i<m;i++){
           if(mat[i][col]>maxele){
            maxele=mat[i][col];
            idx=i;
           }
        }
        return idx;
    }
};