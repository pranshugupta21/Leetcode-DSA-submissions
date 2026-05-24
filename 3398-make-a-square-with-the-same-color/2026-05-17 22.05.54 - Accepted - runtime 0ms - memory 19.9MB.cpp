class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& g) {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int cw=0,cb=0;
                if(g[i][j]=='W')
                    cw++;
                    else{
                    cb++;
                    }
                if(i+1<=2&&g[i+1][j]=='W')cw++;
                if(i+1<=2&&g[i+1][j]=='B')cb++;
                if(j+1<=2&&g[i][j+1]=='W')cw++;
                if(j+1<=2&&g[i][j+1]=='B')cb++;
                if(i+1<=2&&j+1<=2&&g[i+1][j+1]=='W')cw++;
                if(i+1<=2&&j+1<=2&&g[i+1][j+1]=='B')cb++;
                if(cw>=3||cb>=3)return true;
            }
        }
        return false;
    }
};