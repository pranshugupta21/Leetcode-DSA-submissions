class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        for(int i=0;i<m;i++){
            int slot=n-1;
            for(int j=n-1;j>=0;j--){
               if(boxGrid[i][j]=='*'){
                slot=j-1;
               } 
               else if(boxGrid[i][j]=='#'){
                boxGrid[i][j]='.';
                boxGrid[i][slot]='#';
                slot--;
               }
            }
        }
        vector<vector<char>>g(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                g[j][i]=boxGrid[i][j];
            }
        }
        for(int i=0;i<n;i++){
            int l=0,r=m-1;
            while(l<r){
                swap(g[i][l],g[i][r]);
                l++;
                r--;
            }
        }
        return g;        
    }
};