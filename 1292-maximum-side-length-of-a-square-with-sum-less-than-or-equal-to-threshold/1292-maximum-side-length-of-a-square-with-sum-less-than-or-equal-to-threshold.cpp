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
        int largestlengthsq=0;
       for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
               for(int k=0;k<=min(m-i,n-j);k++){      // k is offset value
                 int r=i+k,c=j+k;
                 int sum=prefix[r][c]-prefix[r][j-1]-prefix[i-1][c]+prefix[i-1][j-1];
                 if(sum<=threshold){
                    largestlengthsq=max(largestlengthsq,k+1);
                 }
                 else{
                    break;
                 }
             }
        }
       }
       return largestlengthsq;

    }
};