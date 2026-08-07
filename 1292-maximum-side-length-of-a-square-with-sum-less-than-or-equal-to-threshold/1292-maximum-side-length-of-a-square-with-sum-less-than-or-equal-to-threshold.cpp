class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>prefix(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){                     // Build the prefix matrix
            for(int j=1;j<=n;j++){
                prefix[i][j]=mat[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }
    
       auto canbesquareside=[&](int side){
        for(int i=1;i+side-1<=m;i++){               // checking side value on every cell of matrix
            for(int j=1;j+side-1<=n;j++){
                int r=i+side-1;
                int c=j+side-1;
                 int sum=prefix[r][c]-prefix[r][j-1]-prefix[i-1][c]+prefix[i-1][j-1];
                 if(sum<=threshold){
                    return true;
                 }
            }
        }
         return false;
       };

       int largestlengthsq=0;
       int low=0,high=min(m,n);
       while(low<=high){                 // binary search
        int mid=(low+high)/2;
        if(canbesquareside(mid)){
            largestlengthsq=mid;
            low=mid+1;
        }
        else high=mid-1;
       }
       return largestlengthsq;
    }
};