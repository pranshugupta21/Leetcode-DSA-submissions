class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int res=0;
        for(int startrow=0;startrow<m;startrow++){
            vector<int>v(n,1);
            for(int endrow=startrow;endrow<m;endrow++){
                for(int col=0;col<n;col++){
                v[col]=v[col]&mat[endrow][col];   // v[col] already stores the result of AND operations on all previously selected rows.
                }
                 res+=countones1D(v);
            }
           
        }
        return res;
    }
    private: 
    int countones1D(vector<int>&v){
        int n=v.size();
        int count=0,c=0;
        for(int i=0;i<n;i++){
             c=(v[i]==0 ?0:c+1);
             count+=c;
            }
        return count;
        }
};