class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
       int maxcovered=0,currcovered=0,n=tiles.size();
       int i=0,j=0;
       while(i<n && maxcovered<carpetLen){
        int carpetend=tiles[i][0]+carpetLen-1;  // placing the carpet on the 1st of ith tile 
          if(j<n && tiles[j][1]<=carpetend){
           currcovered+=tiles[j][1]-tiles[j][0]+1; //summing up the nexttile
           maxcovered=max(maxcovered,currcovered);
           j++;

          }
          else{
            int partial_covered=0;
            if(j<n){  // if at the last tile
             partial_covered=max(0,carpetend-tiles[j][0]+1);
            }
            maxcovered=max(maxcovered,currcovered+partial_covered);
            currcovered-=tiles[i][1]-tiles[i][0]+1; // moving the ith tile 
            i++;
          }
        }
        return maxcovered;
    }
};