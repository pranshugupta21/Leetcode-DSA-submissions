class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& g) {
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                int cw=0,cb=0;
                for(int x=i;x<i+2;x++){
                    for(int y=j;y<j+2;y++){
                      if(g[x][y]=='W')cw++;
                      else cb++;
                    }
                }
                if(cw>=3||cb>=3)return true;
            }
        }
        return false;
    }
};