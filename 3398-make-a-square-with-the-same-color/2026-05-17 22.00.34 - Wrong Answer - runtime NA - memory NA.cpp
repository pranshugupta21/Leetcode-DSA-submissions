class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& g) {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int c=0;
                if(g[i][j]=='W')c++;
                if(i+1<=2&&g[i+1][j]=='W')c++;
                if(j+1<=2&&g[i][j+1]=='W')c++;
                if(i+1<=2&&j+1<=2&&g[i+1][j+1]=='W')c++;
                if(c>=3)return true;
            }
        }
        return false;
    }
};