class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        if(n==1) return boxGrid;
        for(int i=0;i<m;i++){
                int x=i,y=x+1;
                while(y<=n){
                   if(boxGrid[i][x]=='#'&&boxGrid[i][y]=='.'){
                    swap(boxGrid[i][x],boxGrid[i][y]);
                    if(x!=0){
                    x--;
                    y--;
                    }
                   } 
                   else {
                    x++;
                    y++;
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