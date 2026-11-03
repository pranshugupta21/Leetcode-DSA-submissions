class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.size();
        vector<vector<int>>distinct(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            vector<int>alpha(26,0);
            int dis=0;
            for(int j=i;j<n;j++){
              int x=s[j]-'a';
              if(alpha[x]==0){
                dis++;
                alpha[x]=1;
              }
              distinct[i][j]=dis;     //distinct store number of distinct characters in substring {i,j}
            }
        }
        int total=0;
        for(int j=0;j<n-1;j++){
            int lf[27]={0};
            int rf[27]={0};             // lf[d]: no of leftsubstring having distinct char d
            for(int i=0;i<=j;i++){
                lf[distinct[i][j]]++;
            }
            for(int k=j+1;k<n;k++){
                rf[distinct[j+1][k]]++;
            }
            for(int z=1;z<=26;z++){
                total+=lf[z]*rf[z];
            }
        }
        return total;
    }
};